#pragma once
#include <vector>

namespace rl_example {

using state_t = std::vector<double>;
using action_t = int;
using reward_t = double;

struct config {
  size_t initial_exploration;
  size_t batch_size;
  size_t log_interval;
  size_t replay_capicity;
  size_t update_target_interval;
  size_t train_episode;
  size_t test_episode;
  double gamma;
  double lr;
  double goal_score;
  // random exploration prob
  double initial_epsilon;
  double epsilon_decay;
  double min_epsilon;
};

struct transition {
  bool is_masked;
  action_t action;
  double reward;
  state_t curr_state;
  state_t next_state;
};

}  // namespace rl_example
