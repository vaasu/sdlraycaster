#include "world.h"
namespace sdlraycaster {

std::vector<glm::vec4> World::PerpsectiveProject(unsigned int d) {
  std::vector<glm::vec4> output{};
  float float_projection_matrix[16] = {
      1.0, 0,   0,   0,                            //
      0,   1.0, 0,   0,                            //
      0,   0,   1.0, static_cast<float>(-1.0 / d), //
      0,   0,   0,   0                             //

  };
  glm::mat4 projection_matrix = glm::make_mat4(float_projection_matrix);

  // memcpy(glm::value_ptr(projection_matrix), float_projection_matrix,
  //        sizeof(float_projection_matrix));

  for (auto const &o : objects_) {
    for (auto const &world_point : o.GetWorldCordinates()) {
      // glm::vec4 point = glm::vec4(world_point, 1.0);
      auto tmp = projection_matrix * world_point.GetPoint();

      output.push_back(tmp);
    }
  }
  return output;
}
void World::Tick() {
  static float degree = 0.0;
  float phi = glm::radians(degree);

  objects_[0].RotateY(degree);
  degree += 1.0;
  if (degree > 360.0)
    degree = 0.0;
}
} // namespace sdlraycaster
