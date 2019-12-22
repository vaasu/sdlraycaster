#include "Framebuffer.h"
#include <iostream>
#include "Utils.h"
namespace sdlraycaster {
void Framebuffer::clear(uint32_t color) {
  std::fill(img.begin(), img.end(), color);
}
void Framebuffer::putPixel(int x, int y, uint32_t color) {
  // img[y * width + x] = color;
  img.assign(width * height, pack_color(255, 255, 255));
}
Framebuffer::Framebuffer(int w, int h) {
  width = w;
  height = h;
  img.assign(width * height, pack_color(0, 0, 0));
  // std::fill(img.begin(), img.end(), 0);
}
}  // namespace sdlraycaster