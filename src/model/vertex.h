#pragma once

#include <vector>

#include "sdlraycaster.h"

using namespace glm;

namespace sdlraycaster {
class Vertex {

public:
  Vertex(const Vertex& v) = default;
  Vertex(vec4 pt, vec3 norm, vec2 texture)
      : point_{pt}, normal_{norm}, texture_coord_{texture} {}

  Vertex(vec3 pt) : point_{vec4{pt, 1.0}} {}
  Vertex(vec3 pt,vec3 normal) : point_{vec4{pt, 1.0}},normal_{normal} {}

  void SetNormal(vec3 new_norm) { normal_ = new_norm; }

  vec4 GetPoint() const { return point_; }
  vec3 GetNormal() const { return normal_; }
  vec2 GetTextureCoordinates() const { return texture_coord_; }
  void ColorVetex(Rgb color) { color_ = color;}

protected:
  /* homogeneous coordinates */
  vec4 point_{};

  /* normal of vertex */
  vec3 normal_{};

  /* texture coords */
  vec2 texture_coord_{};
  Rgb color_{};
};
} // namespace sdlraycaster
