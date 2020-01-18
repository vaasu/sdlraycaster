#pragma once
#include "model.h"
#include "sdlraycaster.h"

namespace sdlraycaster {
class SceneObject {
public:
  SceneObject(const Model &m, glm::vec3 l) : model_{m}  {
    translation_matrix_[3][0] = l.x;
    translation_matrix_[3][1] = l.y;
    translation_matrix_[3][2] = l.z;
    updateCompositeMatrix();
  }
  Model model_;

  glm::mat4 translation_matrix_{glm::mat4{1.0}};
  glm::mat4 rotation_matrix_{glm::mat4{1.0}}; // rotation matrix
  glm::mat4 scaling_matrix_{glm::mat4{1.0}};    // scaling
  glm::mat4 composite_matrix_{};
  glm::mat4 normal_transform_matrix_{};

  std::vector<Vertex> GetWorldCordinates() const;
  void RotateZ(float degrees);
  void RotateY(float degrees);

private:
  void updateCompositeMatrix() {
      composite_matrix_ = translation_matrix_*rotation_matrix_*scaling_matrix_;
      // while this works, book says calculating adjoint shall be better
      normal_transform_matrix_ = glm::inverseTranspose(composite_matrix_);

  }
};

} // namespace sdlraycaster
