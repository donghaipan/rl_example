#pragma once

#include <chrono>
#include <random>

namespace rl_example {

inline std::mt19937 get_random_generator() {
  auto time_ns = static_cast<long unsigned int>(
      std::chrono::high_resolution_clock::now().time_since_epoch().count());
  std::seed_seq seed{time_ns};
  return std::mt19937(seed);
}

}  // namespace rl_example
