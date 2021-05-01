#include "env/mountain_car.h"

namespace rl_example {
namespace env {

mountain_car::mountain_car() { state_.resize(obs_dim); }

void mountain_car::step(const action_t action) {
  if (action < 0 || action > 2) {
    throw std::runtime_error("unknown action " + std::to_string(action));
  }

  auto position = state_[0];
  auto velocity = state_[1];

  velocity += (action - 1) * force_ + std::cos(3.0 * position) * (-gravity_);
  velocity = std::clamp(velocity, -max_speed_, max_speed_);
  position += velocity;
  position = std::clamp(position, min_position_, max_position_);

  if (position <= min_position_ && velocity < 0) {
    velocity = 0;
  }

  if (position >= goal_position_ && velocity >= goal_velocity_) {
    is_done_ = true;
  }

  reward_ = -1.0;

  state_[0] = position;
  state_[1] = velocity;
}

void mountain_car::reset() {
  std::uniform_real_distribution<> dis(-0.6, -0.4);
  state_[0] = dis(rd_gen_);
  state_[1] = 0.0;

  is_done_ = false;
  reward_ = 0.0;
}

}  // namespace env
}  // namespace rl_example
