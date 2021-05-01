#include "env/cartpole.h"

#include <random>

namespace rl_example {
namespace env {

cartpole::cartpole() { state_.resize(obs_dim); }

void cartpole::reset() {
  std::uniform_real_distribution<> dis(-0.05, 0.05);

  for (size_t i = 0; i < obs_dim; ++i) {
    state_[i] = dis(rd_gen_);
  }

  steps_beyond_done_ = false;
  is_done_ = false;
}

void cartpole::step(const action_t action) {
  if (action < 0 || action > 1) {
    throw std::runtime_error("unknown action " + std::to_string(action));
  }

  const double x = state_[0];
  const double x_dot = state_[1];
  const double theta = state_[2];
  const double theta_dot = state_[3];

  double force;
  if (action == 0) {
    force = -force_mag_;
  } else {
    force = force_mag_;
  }

  const auto costheta = std::cos(theta);
  const auto sintheta = std::sin(theta);

  const auto temp =
      (force + polemass_length_ * std::pow(theta_dot, 2) * sintheta) /
      total_mass_;
  const auto thetaacc =
      (gravity_ * sintheta - costheta * temp) /
      (length_ * (4.0 / 3.0 - masspole_ * std::pow(costheta, 2) / total_mass_));
  const auto xacc = temp - polemass_length_ * thetaacc * costheta / total_mass_;

  state_[0] = x + tau_ * x_dot;
  state_[1] = x_dot + tau_ * xacc;
  state_[2] = theta + tau_ * theta_dot;
  state_[3] = theta_dot + tau_ * thetaacc;

  if (std::abs(state_[0]) > x_threshold_ ||
      std::abs(state_[2]) > theta_threshold_radians_) {
    is_done_ = true;
  }

  if (!is_done_) {
    reward_ = 1.0;
  } else if (!steps_beyond_done_) {
    steps_beyond_done_ = true;
    reward_ = 1.0;
  } else {
    reward_ = 0.0;
  }
}

}  // namespace env
}  // namespace rl_example
