#include "model.h"
#include "sdlraycaster.h"
#include <glm/gtx/normal.hpp>

namespace sdlraycaster {
#if 0
void Model::AddTriangleFace(vec3 p1, vec3 p2, vec3 p3) {
  // easy way:
  vec3 normal = glm::triangleNormal(p1, p2, p3);
  // add points to the model,
  vertices_.push_back(Vertex{p1, normal});
  vertices_.push_back(Vertex{p2, normal});
  vertices_.push_back(Vertex{p3, normal});
  // compute normal for all vertex, normalize, modify the vertex data

  //
}
#endif
} // namespace sdlraycaster
