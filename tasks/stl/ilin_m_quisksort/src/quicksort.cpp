// Copyright 2024 Ilin Maksim
#include "stl/ilin_m_quisksort/include/quicksort.hpp"

#include <omp.h>

#include <functional>
#include <iterator>
#include <thread>

using namespace std::chrono_literals;

std::vector<int> ilin_m_quicksort_stl::getRandomVec(int n) {
  std::random_device dev;
  static std::mt19937 gen(dev());
  std::vector<int> vec(n);
  std::generate(vec.begin(), vec.end(), [] { return gen() % 100; });
  return vec;
}

bool ilin_m_quicksort_stl::checkOrder(const std::vector<int>& vec) {
  for (auto iter = vec.begin(); iter != std::prev(vec.end()); ++iter) {
    if (*iter > *(iter + 1)) {
      return false;
    }
  }
  return true;
}

void swapElements(std::vector<int>::iterator a, std::vector<int>::iterator b) { std::iter_swap(a, b); }

std::vector<int>::iterator partition(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
  // Choose the last element as the pivot
  auto pivot = end - 1;
  auto i = begin - 1;  // Index of smaller element

  for (auto j = begin; j != end - 1; ++j) {
    // If current element is smaller than or equal to pivot
    if (*j <= *pivot) {
      i++;                 // increment index of smaller element
      swapElements(i, j);  // Swap elements at i and j
    }
  }
  swapElements(i + 1, pivot);  // Swap the pivot element with the greater element at i+1
  return i + 1;                // Return the iterator to the pivot's final position
}

void ilin_m_quicksort_stl::quickSort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
  if (begin >= end - 1) {  // Base case: 0 or 1 element(s) in the range
    return;                // Already sorted
  }

  // Partition the vector and get the pivot's final position
  auto pivot = partition(begin, end);

  // Recursively sort the sub-vectors
  quickSort(begin, pivot);    // Sort elements before the pivot
  quickSort(pivot + 1, end);  // Sort elements after the pivot
}

std::vector<int> ilin_m_quicksort_stl::mergeVecs(std::vector<int> arr1, std::vector<int> arr2) {
  int n1 = static_cast<int>(arr1.size());
  int n2 = static_cast<int>(arr2.size());

  int i = 0;
  int j = 0;
  int k = 0;

  std::vector<int> arr3(n1 + n2);

  while (i < n1 && j < n2) {
    if (arr1[i] < arr2[j])
      arr3[k++] = arr1[i++];
    else
      arr3[k++] = arr2[j++];
  }

  while (i < n1) arr3[k++] = arr1[i++];
  while (j < n2) arr3[k++] = arr2[j++];

  return arr3;
}

void ilin_m_quicksort_stl::quickSortSimpleMerge(std::vector<int>* vec, int parts, bool parallel) {
  std::vector<std::vector<int>> vecs(parts);
  int grainsize = static_cast<int>((*vec).size()) / parts;

  if (grainsize >= 1) {
    quickSort(vec->begin(), vec->end());
    return;
  }

  for (int i = 0; i < parts - 1; i++) {
    auto first = (*vec).begin() + grainsize * i;
    auto last = (*vec).begin() + grainsize * (i + 1);

    vecs[i] = std::vector<int>(first, last);
  }
  vecs.back() = std::vector<int>((*vec).begin() + grainsize * (parts - 1), (*vec).end());

  if (parallel) {
    std::vector<std::thread> threads;
    for (int i = 0; i < parts; i++) {
      threads.push_back(std::thread([&vecs, i]() { quickSort(vecs[i].begin(), vecs[i].end()); }));
    }
    for (auto&& thread : threads) {
      thread.join();
    }
  } else {
    for (auto&& elem : vecs) {
      quickSort(elem.begin(), elem.end());
    }
  }

  (*vec) = vecs[0];

  for (auto iter = vecs.begin() + 1; iter != vecs.end(); ++iter) {
    (*vec) = mergeVecs((*vec), *iter);
  }
}

bool ilin_m_quicksort_stl::QuisksortSTLTaskSequential::pre_processing() {
  internal_order_test();
  // Init value for input and output

  input_.reserve(taskData->inputs_count[0]);
  std::copy(reinterpret_cast<int*>(taskData->inputs[0]),
            reinterpret_cast<int*>(taskData->inputs[0]) + taskData->inputs_count[0], std::back_inserter(input_));

  return true;
}

bool ilin_m_quicksort_stl::QuisksortSTLTaskSequential::validation() {
  internal_order_test();
  return taskData->inputs_count[0] == taskData->outputs_count[0];
}

bool ilin_m_quicksort_stl::QuisksortSTLTaskSequential::run() {
  internal_order_test();

  ilin_m_quicksort_stl::quickSort(input_.begin(), input_.end());
  // for (auto el : res) {
  //   std::cout << el << "\n";
  // }
  // std::this_thread::sleep_for(20ms);
  return true;
}

bool ilin_m_quicksort_stl::QuisksortSTLTaskSequential::post_processing() {
  internal_order_test();
  std::copy(input_.begin(), input_.end(), reinterpret_cast<int*>(taskData->outputs[0]));
  return true;
}

bool ilin_m_quicksort_stl::QuisksortSTLTaskParallel::pre_processing() {
  internal_order_test();
  // Init value for input and output

  input_.reserve(taskData->inputs_count[0]);
  std::copy(reinterpret_cast<int*>(taskData->inputs[0]),
            reinterpret_cast<int*>(taskData->inputs[0]) + taskData->inputs_count[0], std::back_inserter(input_));

  return true;
}

bool ilin_m_quicksort_stl::QuisksortSTLTaskParallel::validation() {
  internal_order_test();
  return taskData->inputs_count[0] == taskData->outputs_count[0];
}

bool ilin_m_quicksort_stl::QuisksortSTLTaskParallel::run() {
  internal_order_test();

  ilin_m_quicksort_stl::quickSortSimpleMerge(&input_, omp_get_max_threads());
  return true;
}

bool ilin_m_quicksort_stl::QuisksortSTLTaskParallel::post_processing() {
  internal_order_test();
  std::copy(input_.begin(), input_.end(), reinterpret_cast<int*>(taskData->outputs[0]));
  return true;
}
