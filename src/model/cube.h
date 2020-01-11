#pragma once

#include <vector>

#include "model.h"
#include "sdlraycaster.h"

namespace sdlraycaster {
class Cube : public Model {
 public:
  Cube() {
    points_.push_back({-0.5, -0.5, 0.5});
    points_.push_back({-0.5, 0.5, 0.5});
    points_.push_back({0.5, 0.5, 0.5});
    points_.push_back({0.5, -0.5, 0.5});

    points_.push_back({-0.5, -0.5, -0.5});
    points_.push_back({-0.5, 0.5, -0.5});
    points_.push_back({0.5, 0.5, -0.5});
    points_.push_back({0.5, -0.5, -0.5});
  }

 private:
};
}  // namespace sdlraycaster