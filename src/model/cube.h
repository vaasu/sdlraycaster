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
    points_.push_back({1, -1, 1});
    points_.push_back({1, 1, 1});
    points_.push_back({-1, -1, 1});

    // seocond triangle:
    points_.push_back({1, 1, 1});
    points_.push_back({-1, 1, 1});
    points_.push_back({-1, -1, 1});

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