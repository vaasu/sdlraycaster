#pragma once

#include <vector>

#include "model.h"
#include "sdlraycaster.h"

namespace sdlraycaster {
class Heart : public Model {
  // model world, in model world, up is y, x is rihgt, neg z is looking foward
 public:
  Heart() {
    using vec2 = glm::vec2;
    using vec3 = glm::vec3;
    // left side:
    MakeSquare(vec2(1, 2), vec2(2, 3));
    MakeSquare(vec2(2, 2), vec2(3, 3));

    MakeSquare(vec2(0, 1), vec2(1, 2));
    MakeSquare(vec2(1, 1), vec2(2, 2));
    MakeSquare(vec2(2, 1), vec2(3, 2));
    MakeSquare(vec2(3, 1), vec2(4, 2));

    MakeSquare(vec2(0, 0), vec2(1, 1));
    MakeSquare(vec2(1, 0), vec2(2, 1));
    MakeSquare(vec2(2, 0), vec2(3, 1));

    MakeSquare(vec2(0, -1), vec2(1, 0));
    MakeSquare(vec2(1, -1), vec2(2, 0));

    MakeSquare(vec2(0, -2), vec2(1, -1));
    MakeRemaining();

    // symmetry:
    MakeSquare(vec2(-2, 2), vec2(-1, 3));
    MakeSquare(vec2(-3, 2), vec2(-2, 3));

    MakeSquare(vec2(-1, 1), vec2(0, 2));
    MakeSquare(vec2(-2, 1), vec2(-1, 2));
    MakeSquare(vec2(-3, 1), vec2(-2, 2));
    MakeSquare(vec2(-4, 1), vec2(-3, 2));

    MakeSquare(vec2(-1, 0), vec2(-2, 1));
    MakeSquare(vec2(-2, 0), vec2(-1, 1));
    MakeSquare(vec2(-3, 0), vec2(0, 1));

    MakeSquare(vec2(-2, -1), vec2(-1, 0));
    MakeSquare(vec2(-1, -1), vec2(0, 0));

    MakeSquare(vec2(-1, -2), vec2(0, -1));
  }

 private:
  void MakeSquare(glm::vec2 bottom_left, glm::vec2 top_right) {
    points_.push_back(
        glm::vec3(scale_ * bottom_left.x, scale_ * bottom_left.y, scale_ * z_));
    points_.push_back(
        glm::vec3(scale_ * top_right.x, scale_ * top_right.y, scale_ * z_));
    points_.push_back(
        glm::vec3(scale_ * bottom_left.x, scale_ * top_right.y, scale_ * z_));
    //
    points_.push_back(
        glm::vec3(scale_ * bottom_left.x, scale_ * bottom_left.y, scale_ * z_));
    points_.push_back(
        glm::vec3(scale_ * top_right.x, scale_ * bottom_left.y, scale_ * z_));
    points_.push_back(
        glm::vec3(scale_ * top_right.x, scale_ * top_right.y, scale_ * z_));
  }
  void MakeRemaining() {
    using vec3 = glm::vec3;

    points_.push_back(vec3(scale_ * 0, scale_ * 2, scale_ * z_));
    points_.push_back(vec3(scale_ * 1, scale_ * 2, scale_ * z_));
    points_.push_back(vec3(scale_ * 1, scale_ * 3, scale_ * z_));

    points_.push_back(vec3(scale_ * 3, scale_ * 2, scale_ * z_));
    points_.push_back(vec3(scale_ * 4, scale_ * 2, scale_ * z_));
    points_.push_back(vec3(scale_ * 3, scale_ * 3, scale_ * z_));

    points_.push_back(vec3(scale_ * 3, scale_ * 0, scale_ * z_));
    points_.push_back(vec3(scale_ * 4, scale_ * 1, scale_ * z_));
    points_.push_back(vec3(scale_ * 3, scale_ * 1, scale_ * z_));

    points_.push_back(vec3(scale_ * 2, scale_ * -1, scale_ * z_));
    points_.push_back(vec3(scale_ * 3, scale_ * 0, scale_ * z_));
    points_.push_back(vec3(scale_ * 2, scale_ * 0, scale_ * z_));

    points_.push_back(vec3(scale_ * 1, scale_ * -2, scale_ * z_));
    points_.push_back(vec3(scale_ * 2, scale_ * -1, scale_ * z_));
    points_.push_back(vec3(scale_ * 1, scale_ * -1, scale_ * z_));

    points_.push_back(vec3(scale_ * 0, scale_ * -2, scale_ * z_));
    points_.push_back(vec3(scale_ * 0, scale_ * -3, scale_ * z_));
    points_.push_back(vec3(scale_ * 1, scale_ * -2, scale_ * z_));

    // symmetry
    points_.push_back(vec3(scale_ * 0, scale_ * 2, scale_ * z_));
    points_.push_back(vec3(scale_ * -1, scale_ * 3, scale_ * z_));
    points_.push_back(vec3(scale_ * -1, scale_ * 2, scale_ * z_));

    points_.push_back(vec3(scale_ * -3, scale_ * 2, scale_ * z_));
    points_.push_back(vec3(scale_ * -3, scale_ * 3, scale_ * z_));
    points_.push_back(vec3(scale_ * -4, scale_ * 2, scale_ * z_));

    points_.push_back(vec3(scale_ * -3, scale_ * 0, scale_ * z_));
    points_.push_back(vec3(scale_ * -3, scale_ * 1, scale_ * z_));
    points_.push_back(vec3(scale_ * -4, scale_ * 1, scale_ * z_));

    points_.push_back(vec3(scale_ * -2, scale_ * -1, scale_ * z_));
    points_.push_back(vec3(scale_ * -2, scale_ * 0, scale_ * z_));
    points_.push_back(vec3(scale_ * -3, scale_ * 0, scale_ * z_));

    points_.push_back(vec3(scale_ * -1, scale_ * -2, scale_ * z_));
    points_.push_back(vec3(scale_ * -1, scale_ * -1, scale_ * z_));
    points_.push_back(vec3(scale_ * -2, scale_ * -1, scale_ * z_));

    points_.push_back(vec3(scale_ * 0, scale_ * -3, scale_ * z_));
    points_.push_back(vec3(scale_ * 0, scale_ * -2, scale_ * z_));
    points_.push_back(vec3(scale_ * -1, scale_ * -2, scale_ * z_));
  }
  float scale_{0.1};
  float z_{1};
};
}  // namespace sdlraycaster