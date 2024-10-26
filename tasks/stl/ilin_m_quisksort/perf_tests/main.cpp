// Copyright 2024 Ilin Maksim
#include <gtest/gtest.h>

#include <vector>

#include "core/perf/include/perf.hpp"
#include "stl/ilin_m_quisksort/include/quicksort.hpp"

TEST(stl_ilin_m_quicksort_perf, test_pipeline_run) {
  // const int count = 1000;

  // // Create data
  // std::vector<int> in = ilin_m_quisksort_seq::getRandomVec(count);
  // std::vector<int> out(count, 0);

  // // Create TaskData
  // std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  // taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  // taskDataSeq->inputs_count.emplace_back(in.size());
  // taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  // taskDataSeq->outputs_count.emplace_back(out.size());

  // // Create Task
  // auto testTaskSequential = std::make_shared<ilin_m_quisksort_seq::QuisksortSequential>(taskDataSeq);

  // // Create Perf attributes
  // auto perfAttr = std::make_shared<ppc::core::PerfAttr>();
  // perfAttr->num_running = 10;
  // const auto t0 = std::chrono::high_resolution_clock::now();
  // perfAttr->current_timer = [&] {
  //   auto current_time_point = std::chrono::high_resolution_clock::now();
  //   auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(current_time_point - t0).count();
  //   return static_cast<double>(duration) * 1e-9;
  // };

  // // Create and init perf results
  // auto perfResults = std::make_shared<ppc::core::PerfResults>();

  // // Create Perf analyzer
  // auto perfAnalyzer = std::make_shared<ppc::core::Perf>(testTaskSequential);
  // perfAnalyzer->pipeline_run(perfAttr, perfResults);
  // ppc::core::Perf::print_perf_statistic(perfResults);
  // ASSERT_TRUE(ilin_m_quisksort_seq::checkOrder(out));
}

TEST(stl_ilin_m_quicksort_perf, test_task_run) {
  // const int count = 1000;

  // // Create data
  // std::vector<int> in = ilin_m_quisksort_seq::getRandomVec(count);
  // std::vector<int> out(count, 0);

  // // Create TaskData
  // std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  // taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  // taskDataSeq->inputs_count.emplace_back(in.size());
  // taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  // taskDataSeq->outputs_count.emplace_back(out.size());

  // // Create Task
  // auto testTaskSequential = std::make_shared<ilin_m_quisksort_seq::QuisksortSequential>(taskDataSeq);

  // // Create Perf attributes
  // auto perfAttr = std::make_shared<ppc::core::PerfAttr>();
  // perfAttr->num_running = 10;
  // const auto t0 = std::chrono::high_resolution_clock::now();
  // perfAttr->current_timer = [&] {
  //   auto current_time_point = std::chrono::high_resolution_clock::now();
  //   auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(current_time_point - t0).count();
  //   return static_cast<double>(duration) * 1e-9;
  // };

  // // Create and init perf results
  // auto perfResults = std::make_shared<ppc::core::PerfResults>();

  // // Create Perf analyzer
  // auto perfAnalyzer = std::make_shared<ppc::core::Perf>(testTaskSequential);
  // perfAnalyzer->task_run(perfAttr, perfResults);
  // ppc::core::Perf::print_perf_statistic(perfResults);
  // ASSERT_TRUE(ilin_m_quisksort_seq::checkOrder(out));
}

// int main(int argc, char **argv) {
//   testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
