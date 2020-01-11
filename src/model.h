#pragma once

#include <vector>

#include "sdlraycaster.h"

namespace sdlraycaster {
class Model {
 public:
  std::vector<glm::vec3> GetAllPoints() const { return points_; }

 protected:
  std::vector<glm::vec3> points_;
};
}  // namespace sdlraycaster