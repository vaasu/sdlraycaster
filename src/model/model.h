#pragma once

#include <vector>

#include "sdlraycaster.h"
#include "world_element.h"
#include "vertex.h"
#include <glm/gtx/normal.hpp>

namespace sdlraycaster {
class Model : public WorldElement{
public:
  std::vector<Vertex> GetAllVertices() const { return vertices_; }
  // points need to be counterclockwise for normal to face you
  void AddTriangleFace(vec3 p1, vec3 p2, vec3 p3) {
    // easy way:
    vec3 normal = glm::triangleNormal(p1, p2, p3);
    // add points to the model,
    vertices_.push_back(Vertex{p1, normal});
    vertices_.push_back(Vertex{p2, normal});
    vertices_.push_back(Vertex{p3, normal});
    // compute normal for all vertex, normalize, modify the vertex data

    //
  }
  // points need to be counterclockwise for normal to face you
  void AddQuad(vec3 top_right, vec3 top_left, vec3 bottom_left,
               vec3 bottom_right) {
    AddTriangleFace(top_right, bottom_left, bottom_right);
    AddTriangleFace(top_right, top_left, bottom_left);
  }

};
} // namespace sdlraycaster
