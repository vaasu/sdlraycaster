#pragma once
#include <functional>
#include "framebuffer.h"
#include "sdlraycaster.h"
namespace sdlraycaster {
class Rasterizer {
 public:
  void Rasterize(const Vec2vec& screen_space_coordinates, Framebuffer& fb);

 private:
  std::function<double(glm::vec2)> ComputeEdge(glm::vec2 p0, glm::vec2 p1);
};

}  // namespace sdlraycaster