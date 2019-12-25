#include "framebuffer.h"
#include <iostream>
#include "utils.h"

namespace sdlraycaster {
void Framebuffer::clear(uint32_t color) {}
void Framebuffer::putPixel(int x, int y, Rgb color) {
  putPixel(x, y, {color.r, color.g, color.b, 255});
}
void Framebuffer::putPixel(int x, int y, Rgba color) {
  std::size_t start_index = 4 * (y * width_ + x);
  // std::size_t start_index = x * height_ + y;
  if (start_index >= framebuffer_size_) {
    std::cout << "wrong index";
    return;
  }
  fb_data_[start_index] = color.r;
  fb_data_[start_index + 1] = color.g;
  fb_data_[start_index + 2] = color.b;
  fb_data_[start_index + 3] = color.a;
  // img[y * width + x] = color;
  // img.assign(width * height, pack_color(255, 255, 255));
}
void Framebuffer::DrawLine(screen_coord start, screen_coord end, Rgba color) {}
void Framebuffer::DrawVLineDown(screen_coord start, int length, Rgb color) {
  for (int i = 0; i < length; i++) {
    putPixel(start.x, start.y + i, color);
  }
}

}  // namespace sdlraycaster