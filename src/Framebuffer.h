
#ifndef SRC_FRAMEBUFFER_H_
#define SRC_FRAMEBUFFER_H_
#include <stdint.h>
#include <cstdlib>
#include <vector>

namespace sdlraycaster {
class Framebuffer {
 private:
  int width;
  int height;

 public:
  void putPixel(int x, int y, uint32_t color);
  void clear(uint32_t color);
  Framebuffer(int w, int h);
  std::vector<uint32_t> img{};
};
}  // namespace sdlraycaster
#endif