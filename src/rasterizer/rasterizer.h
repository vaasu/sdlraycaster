#pragma once
#include "framebuffer.h"
#include "sdlraycaster.h"
namespace sdlraycaster {
class Rasterizer {
 public:
  void Rasterize(const Vec2vec& screen_space_coordinates, Framebuffer& fb);

 private:
};

}  // namespace sdlraycaster