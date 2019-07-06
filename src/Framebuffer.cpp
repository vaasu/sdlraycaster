#include "Framebuffer.h"
namespace sdlraycaster {
void Framebuffer::putPixel(int x, int y, uint32_t color) {
  img[y * width + x] = color;
}
Framebuffer::Framebuffer(int w, int h) {
  width = w;
  height = h;
  img.assign(width * height, 0);
}
}  // namespace sdlraycaster