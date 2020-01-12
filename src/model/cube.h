#pragma once

#include <vector>

#include "model.h"
#include "sdlraycaster.h"

namespace sdlraycaster {
class Cube : public Model {
  // model world, in model world, up is y, x is rihgt, neg z is looking foward
 public:
  Cube() {
    // front face

    // first triangle
    float scale = 0.5;
    points_.push_back({1 * scale, -1 * scale, 1 * scale});
    points_.push_back({1 * scale, 1 * scale, 1 * scale});
    points_.push_back({-1 * scale, -1 * scale, 1 * scale});

    // seocond triangle:
    points_.push_back({1 * scale, 1 * scale, 1 * scale});
    points_.push_back({-1 * scale, 1 * scale, 1 * scale});
    points_.push_back({-1 * scale, -1 * scale, 1 * scale});

    // left face
    // back face
    // right face
    // top face
    // bottom face

    /*
     points_.push_back({-0.5, -0.5, 0.5});
     points_.push_back({-0.5, 0.5, 0.5});
     points_.push_back({0.5, 0.5, 0.5});
     points_.push_back({0.5, -0.5, 0.5});

     points_.push_back({-0.5, -0.5, -0.5});
     points_.push_back({-0.5, 0.5, -0.5});
     points_.push_back({0.5, 0.5, -0.5});
     points_.push_back({0.5, -0.5, -0.5});
     */
  }

 private:
};
}  // namespace sdlraycaster