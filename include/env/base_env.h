#pragma once

#include <random>
#include <vector>

#include "datatype.h"
#include "util.h"

namespace rl_example {
namespace env {

class base_env {
 public:
  base_env() : rd_gen_(get_random_generator()) {}

  ~base_env() = default;

  virtual void step(const action_t) = 0;
  virtual void reset() = 0;
  virtual size_t observation_dim() const = 0;
  virtual size_t action_size() const = 0;

  const state_t &get_state() const { return state_; };
  reward_t get_reward() const { return reward_; };
  bool is_done() const { return is_done_; };

 protected:
  bool is_done_ = false;
  reward_t reward_ = 0.0;
  std::mt19937 rd_gen_;
  state_t state_;
};

}  // namespace env
}  // namespace rl_example
