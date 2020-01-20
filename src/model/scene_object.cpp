
#include "model.h"
#include "scene_object.h"
#include "sdlraycaster.h"
#include <glm/gtx/matrix_operation.hpp>

namespace sdlraycaster {

std::vector<Vertex> SceneObject::GetWorldCordinates() const {
  std::vector<Vertex> pts{};

  for (auto const &p : model_.GetAllVertices()) {
    //caculate new normal aka normal transform:
    //
    //pts.push_back(Vertex{(rotation_ * scale_* p.GetPoint()) + location_});
    pts.push_back(Vertex{composite_matrix_ *p.GetPoint(),normal_transform_matrix_*p.GetNormal()});
    //pts.push_back(Vertex{composite_matrix_ *p.GetPoint(),normal_transform_matrix_*p.GetNormal()});
  }
  return pts;
}
void SceneObject::RotateZ(float degrees) {
  // rotate the model by degrees anticlockwise
  float phi = glm::radians(degrees);
  float float_rotation_matrix_z[16] = {
      glm::cos(phi), glm::sin(phi), 0, 0, //
      //
      -1 * glm::sin(phi), glm::cos(phi), 0, 0, //
      //
      0, 0, 1, 0, //
      //
      0, 0, 0, 1 //
  };

  // y axis rotation;
  glm::mat4 rotation_matrix = glm::make_mat4(float_rotation_matrix_z);
  rotation_matrix_ = rotation_matrix;
  updateCompositeMatrix();
}
void SceneObject::RotateY(float degrees) {
  // rotate the model by degrees anticlockwise
  float phi = glm::radians(degrees);
  float float_rotation_matrix_y[16] = {
      glm::cos(phi), 0, -1 * glm::sin(phi), 0, //
      //
      0, 1, 0, 0, //
      //
      glm::sin(phi), 0, glm::cos(phi), 0, //
      //
      0, 0, 0, 1 //
  };

  // y axis rotation;
  glm::mat4 rotation_matrix = glm::make_mat4(float_rotation_matrix_y);
  rotation_matrix_ = rotation_matrix;
  updateCompositeMatrix();
}

} // namespace sdlraycaster
