#pragma once

#include <vector>

#include "sdlraycaster.h"
#include "vertex.h"

namespace sdlraycaster {
class WorldElement {
public:
  std::vector<Vertex> GetAllVertices() const { return vertices_; }


protected:
  // number of points are multiples of three as they describe a triangle
  // points on a triangle are added in counterclockwise direction
  std::vector<Vertex> vertices_;
};
} // namespace sdlraycaster
