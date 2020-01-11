#pragma once
#include "model.h"
#include "sdlraycaster.h"

namespace sdlraycaster {
class SceneObject {
 public:
  SceneObject(const Model& m, glm::vec4 l) : model_{m}, location_{l} {
    rotation_ = glm::mat4(1.0);
  }
  Model model_;
  glm::vec4 location_;
  glm::mat4 rotation_;  // rotation matrix
  std::vector<glm::vec3> GetWorldCordinates() const;
  void RotateZ(float degrees);
  void RotateY(float degrees);

 private:
};

}  // namespace sdlraycaster