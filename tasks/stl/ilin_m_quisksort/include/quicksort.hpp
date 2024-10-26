// Copyright 2024 Ilin Maksim
#pragma once

#include <algorithm>
#include <random>
#include <string>
#include <vector>

#include "core/task/include/task.hpp"

namespace ilin_m_quicksort_stl {

std::vector<int> getRandomVec(int n);
bool checkOrder(const std::vector<int>& vec);
void quickSort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
std::vector<int> mergeVecs(std::vector<int> arr1, std::vector<int> arr2);
void quickSortSimpleMerge(std::vector<int>* vec, int parts, bool parallel = true);

class QuisksortSTLTaskSequential : public ppc::core::Task {
 public:
  explicit QuisksortSTLTaskSequential(std::shared_ptr<ppc::core::TaskData> taskData_) : Task(std::move(taskData_)) {}
  bool pre_processing() override;
  bool validation() override;
  bool run() override;
  bool post_processing() override;

 private:
  std::vector<int> input_{};
};

class QuisksortSTLTaskParallel : public ppc::core::Task {
 public:
  explicit QuisksortSTLTaskParallel(std::shared_ptr<ppc::core::TaskData> taskData_) : Task(std::move(taskData_)) {}
  bool pre_processing() override;
  bool validation() override;
  bool run() override;
  bool post_processing() override;

 private:
  std::vector<int> input_{};
};

}  // namespace ilin_m_quicksort_stl
