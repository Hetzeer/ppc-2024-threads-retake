// Copyright 2024 Ilin Maksim
#include <gtest/gtest.h>

#include <vector>

#include "seq/ilin_m_quisksort/include/quicksort.hpp"

TEST(ilin_m_quicksort_seq, Sort_Vec_10) {
  const int count = 10;

  // Create data
  std::vector<int> in = ilin_m_quisksort_seq::getRandomVec(count);
  std::vector<int> out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  // Create Task
  ilin_m_quisksort_seq::QuisksortSequential testTaskSequential(taskDataSeq);
  ASSERT_EQ(testTaskSequential.validation(), true);
  testTaskSequential.pre_processing();
  testTaskSequential.run();
  testTaskSequential.post_processing();
  
  ASSERT_TRUE(ilin_m_quisksort_seq::checkOrder(out));
}

TEST(ilin_m_quicksort_seq, Sort_Vec_20) {
  const int count = 20;

  // Create data
  std::vector<int> in = ilin_m_quisksort_seq::getRandomVec(count);
  std::vector<int> out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  // Create Task
  ilin_m_quisksort_seq::QuisksortSequential testTaskSequential(taskDataSeq);
  ASSERT_EQ(testTaskSequential.validation(), true);
  testTaskSequential.pre_processing();
  testTaskSequential.run();
  testTaskSequential.post_processing();
  
  ASSERT_TRUE(ilin_m_quisksort_seq::checkOrder(out));
}

TEST(ilin_m_quicksort_seq, Sort_Vec_100) {
  const int count = 100;

  // Create data
  std::vector<int> in = ilin_m_quisksort_seq::getRandomVec(count);
  std::vector<int> out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  // Create Task
  ilin_m_quisksort_seq::QuisksortSequential testTaskSequential(taskDataSeq);
  ASSERT_EQ(testTaskSequential.validation(), true);
  testTaskSequential.pre_processing();
  testTaskSequential.run();
  testTaskSequential.post_processing();
  
  ASSERT_TRUE(ilin_m_quisksort_seq::checkOrder(out));
}

TEST(ilin_m_quicksort_seq, Sort_Vec_500) {
  const int count = 500;

  // Create data
  std::vector<int> in = ilin_m_quisksort_seq::getRandomVec(count);
  std::vector<int> out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  // Create Task
  ilin_m_quisksort_seq::QuisksortSequential testTaskSequential(taskDataSeq);
  ASSERT_EQ(testTaskSequential.validation(), true);
  testTaskSequential.pre_processing();
  testTaskSequential.run();
  testTaskSequential.post_processing();
  
  ASSERT_TRUE(ilin_m_quisksort_seq::checkOrder(out));
}

TEST(ilin_m_quicksort_seq, Sort_Vec_1000) {
  const int count = 1000;

  // Create data
  std::vector<int> in = ilin_m_quisksort_seq::getRandomVec(count);
  std::vector<int> out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  // Create Task
  ilin_m_quisksort_seq::QuisksortSequential testTaskSequential(taskDataSeq);
  ASSERT_EQ(testTaskSequential.validation(), true);
  testTaskSequential.pre_processing();
  testTaskSequential.run();
  testTaskSequential.post_processing();
  
  ASSERT_TRUE(ilin_m_quisksort_seq::checkOrder(out));
}