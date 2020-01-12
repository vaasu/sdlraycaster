#pragma once

#include <vector>

#include "sdlraycaster.h"

namespace sdlraycaster {
class Model {
 public:
  std::vector<glm::vec3> GetAllPoints() const { return points_; }

 protected:
  // number of points are multiples of three as they describe a triangle
  // points on a triangle are added in counterclockwise direction
  std::vector<glm::vec3> points_;
};
}  // namespace sdlraycaster