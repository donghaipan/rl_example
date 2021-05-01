#pragma once

#include "base_env.h"

namespace rl_example {
namespace env {

class mountain_car final : public base_env {
 public:
  mountain_car();
  virtual void step(const action_t) override final;
  virtual void reset() override final;

  virtual size_t observation_dim() const override final { return obs_dim; }
  virtual size_t action_size() const override final { return num_action; }

 private:
  constexpr static size_t obs_dim = 2;
  constexpr static size_t num_action = 3;

  const double min_position_ = -1.2;
  const double max_position_ = 0.6;
  const double max_speed_ = 0.07;
  const double goal_position_ = 0.5;
  const double goal_velocity_ = 0.0;
  const double force_ = 0.001;
  const double gravity_ = 0.0025;
};

}  // namespace env
}  // namespace rl_example
