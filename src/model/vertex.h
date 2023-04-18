#pragma once

#include <vector>

#include "sdlraycaster.h"

using namespace glm;

namespace sdlraycaster {
class Vertex {

public:
  Vertex(const Vertex& v) = default;
  Vertex(vec4 pt, vec3 norm, vec2 texture,vec3 color)
      : point_{pt}, normal_{glm::vec4{norm,0.0}}, texture_coord_{texture}, color_{color} {}

  Vertex(vec3 pt) : point_{vec4{pt, 1.0}} {}
  Vertex(vec3 pt,vec3 normal) : point_{vec4{pt, 1.0}},normal_{glm::vec4{normal,0.0}} {}
  Vertex(vec3 pt,vec3 normal,vec3 color) : point_{vec4{pt, 1.0}},normal_{glm::vec4{normal,0.0}},color_{color} {}

  //this might not be used
  void SetNormal(vec4 new_norm) { normal_ = new_norm; }

  vec4 GetPoint() const { return point_; }
  void SetPoint(vec4 pt) { point_ =pt; }
  vec4 GetNormal() const { return normal_; }
  vec2 GetTextureCoordinates() const { return texture_coord_; }
  void ColorVertex(vec3 color) { color_ = color;}
  vec3 GetColor() const {return color_;}

protected:
  /* homogeneous coordinates */
  vec4 point_{};

  /* normal of vertex */
  vec4 normal_{};

  /* texture coords */
  vec2 texture_coord_{};
  vec3 color_{};
};
} // namespace sdlraycaster
