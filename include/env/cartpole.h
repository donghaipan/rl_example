#pragma once

#include <cmath>
#include <ostream>

#include "base_env.h"

namespace rl_example {
namespace env {

class cartpole final : public base_env {
 public:
  cartpole();

  virtual void step(const action_t) override final;
  virtual void reset() override final;

  virtual size_t observation_dim() const override final { return obs_dim; }
  virtual size_t action_size() const override final { return num_action; }

 private:
  static constexpr size_t num_action = 2;
  static constexpr size_t obs_dim = 4;
  const double gravity_ = 9.8;
  const double masscart_ = 1.0;
  const double masspole_ = 0.1;
  const double total_mass_ = masspole_ + masscart_;
  const double length_ = 0.5;
  const double polemass_length_ = masspole_ + length_;
  const double force_mag_ = 10.0;
  const double tau_ = 0.02;

  const double theta_threshold_radians_ = 12.0 * 2.0 * M_PI / 360.0;
  const double x_threshold_ = 2.4;

  bool steps_beyond_done_ = false;
};

}  // namespace env
}  // namespace rl_example
