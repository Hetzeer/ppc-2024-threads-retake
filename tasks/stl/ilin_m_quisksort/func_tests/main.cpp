// Copyright 2024 Ilin Maksim
#include <gtest/gtest.h>
#include <omp.h>

#include <vector>

#include "stl/ilin_m_quisksort/include/quicksort.hpp"

TEST(ilin_m_quicksort_stl, Sort_Vec_10) {
  const int count = 10;

  // Create data
  std::vector<int> in = ilin_m_quicksort_stl::getRandomVec(count);
  std::vector<int> seq_out(count, 0);
  std::vector<int> par_out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataSeq->outputs_count.emplace_back(seq_out.size());

  // Create Task
  ilin_m_quicksort_stl::QuisksortSTLTaskSequential testTaskSequential(taskDataSeq);
  ASSERT_EQ(testTaskSequential.validation(), true);
  testTaskSequential.pre_processing();
  testTaskSequential.run();
  testTaskSequential.post_processing();

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataPar = std::make_shared<ppc::core::TaskData>();
  taskDataPar->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataPar->inputs_count.emplace_back(in.size());
  taskDataPar->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataPar->outputs_count.emplace_back(seq_out.size());

  // Create Task
  ilin_m_quicksort_stl::QuisksortSTLTaskParallel testTaskParallel(taskDataPar);
  ASSERT_EQ(testTaskParallel.validation(), true);
  testTaskParallel.pre_processing();
  testTaskParallel.run();
  testTaskParallel.post_processing();

  ASSERT_TRUE(ilin_m_quicksort_stl::checkOrder(seq_out));
  ASSERT_TRUE(ilin_m_quicksort_stl::checkOrder(par_out));
}

TEST(ilin_m_quicksort_stl, Sort_Vec_100) {
  const int count = 100;

  // Create data
  std::vector<int> in = ilin_m_quicksort_stl::getRandomVec(count);
  std::vector<int> seq_out(count, 0);
  std::vector<int> par_out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataSeq->outputs_count.emplace_back(seq_out.size());

  // Create Task
  ilin_m_quicksort_stl::QuisksortSTLTaskSequential testTaskSequential(taskDataSeq);
  ASSERT_EQ(testTaskSequential.validation(), true);
  testTaskSequential.pre_processing();
  testTaskSequential.run();
  testTaskSequential.post_processing();

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataPar = std::make_shared<ppc::core::TaskData>();
  taskDataPar->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataPar->inputs_count.emplace_back(in.size());
  taskDataPar->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataPar->outputs_count.emplace_back(seq_out.size());

  // Create Task
  ilin_m_quicksort_stl::QuisksortSTLTaskParallel testTaskParallel(taskDataPar);
  ASSERT_EQ(testTaskParallel.validation(), true);
  testTaskParallel.pre_processing();
  testTaskParallel.run();
  testTaskParallel.post_processing();

  ASSERT_TRUE(ilin_m_quicksort_stl::checkOrder(seq_out));
  ASSERT_TRUE(ilin_m_quicksort_stl::checkOrder(par_out));
}

TEST(ilin_m_quicksort_stl, Sort_Vec_1000) {
  const int count = 1000;

  // Create data
  std::vector<int> in = ilin_m_quicksort_stl::getRandomVec(count);
  std::vector<int> seq_out(count, 0);
  std::vector<int> par_out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataSeq->outputs_count.emplace_back(seq_out.size());

  // Create Task
  ilin_m_quicksort_stl::QuisksortSTLTaskSequential testTaskSequential(taskDataSeq);
  ASSERT_EQ(testTaskSequential.validation(), true);
  testTaskSequential.pre_processing();
  testTaskSequential.run();
  testTaskSequential.post_processing();

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataPar = std::make_shared<ppc::core::TaskData>();
  taskDataPar->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataPar->inputs_count.emplace_back(in.size());
  taskDataPar->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataPar->outputs_count.emplace_back(seq_out.size());

  // Create Task
  ilin_m_quicksort_stl::QuisksortSTLTaskParallel testTaskParallel(taskDataPar);
  ASSERT_EQ(testTaskParallel.validation(), true);
  testTaskParallel.pre_processing();
  testTaskParallel.run();
  testTaskParallel.post_processing();

  ASSERT_TRUE(ilin_m_quicksort_stl::checkOrder(seq_out));
  ASSERT_TRUE(ilin_m_quicksort_stl::checkOrder(par_out));
}

TEST(ilin_m_quicksort_stl, Sort_Vec_10000) {
  const int count = 10000;

  // Create data
  std::vector<int> in = ilin_m_quicksort_stl::getRandomVec(count);
  std::vector<int> seq_out(count, 0);
  std::vector<int> par_out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataSeq->outputs_count.emplace_back(seq_out.size());

  // Create Task
  ilin_m_quicksort_stl::QuisksortSTLTaskSequential testTaskSequential(taskDataSeq);
  ASSERT_EQ(testTaskSequential.validation(), true);
  testTaskSequential.pre_processing();
  testTaskSequential.run();
  testTaskSequential.post_processing();

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataPar = std::make_shared<ppc::core::TaskData>();
  taskDataPar->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataPar->inputs_count.emplace_back(in.size());
  taskDataPar->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataPar->outputs_count.emplace_back(seq_out.size());

  // Create Task
  ilin_m_quicksort_stl::QuisksortSTLTaskParallel testTaskParallel(taskDataPar);
  ASSERT_EQ(testTaskParallel.validation(), true);
  testTaskParallel.pre_processing();
  testTaskParallel.run();
  testTaskParallel.post_processing();

  ASSERT_TRUE(ilin_m_quicksort_stl::checkOrder(seq_out));
  ASSERT_TRUE(ilin_m_quicksort_stl::checkOrder(par_out));
}

TEST(ilin_m_quicksort_stl, Sort_Vec_50000) {
  const int count = 50000;

  // Create data
  std::vector<int> in = ilin_m_quicksort_stl::getRandomVec(count);
  std::vector<int> seq_out(count, 0);
  std::vector<int> par_out(count, 0);

  // std::cout << omp_get_max_threads() << " 123\n";

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataSeq->outputs_count.emplace_back(seq_out.size());

  // Create Task
  ilin_m_quicksort_stl::QuisksortSTLTaskSequential testTaskSequential(taskDataSeq);
  ASSERT_EQ(testTaskSequential.validation(), true);
  testTaskSequential.pre_processing();

  double start_seq = omp_get_wtime();
  testTaskSequential.run();
  double finish_seq = omp_get_wtime();
  
  testTaskSequential.post_processing();

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataPar = std::make_shared<ppc::core::TaskData>();
  taskDataPar->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataPar->inputs_count.emplace_back(in.size());
  taskDataPar->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataPar->outputs_count.emplace_back(seq_out.size());

  // Create Task
  ilin_m_quicksort_stl::QuisksortSTLTaskParallel testTaskParallel(taskDataPar);
  ASSERT_EQ(testTaskParallel.validation(), true);
  testTaskParallel.pre_processing();

  double start_par = omp_get_wtime();
  testTaskParallel.run();
  double finish_par = omp_get_wtime();

  testTaskParallel.post_processing();

  ASSERT_TRUE(ilin_m_quicksort_stl::checkOrder(seq_out));
  ASSERT_TRUE(ilin_m_quicksort_stl::checkOrder(par_out));

  std::cout << "Seq    time: " << finish_seq - start_seq << std::endl;
  std::cout << "OpenMP time: " << finish_par - start_par << std::endl;
}