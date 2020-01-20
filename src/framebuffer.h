#pragma once
#include <cstdint>
#include <cstdlib>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "sdlraycaster.h"
namespace sdlraycaster {
class Framebuffer {
 public:
  void putPixel(int x, int y, Rgb color);
  void putPixel(unsigned int x, unsigned int y, Rgba color);
  void DrawLine(screen_coord start, screen_coord end, Rgba color);
  void DrawVLineDown(screen_coord start, int length, Rgb color);
  void clear(uint32_t color);
  Framebuffer(int w, int h)
      : width_{w}, height_{h}, framebuffer_size_{h * w * 4} {
    fb_data_.reserve(framebuffer_size_);
    fb_data_.assign(framebuffer_size_, 0);
    fb_texture_.create(width_, height_);  // todo: error check
    fb_sprite_.setTexture(fb_texture_);
  };
  const sf::Sprite& getSprite() const { return fb_sprite_; };
  void UpdateTexture() { fb_texture_.update(fb_data_.data()); }
  int GetHeight() const { return height_; }
  int GetWidth() const { return width_; }

 private:
  int width_;
  int height_;
  int framebuffer_size_;
  std::vector<sf::Uint8> fb_data_{};
  sf::Texture fb_texture_;
  sf::Sprite fb_sprite_;
};

}  // namespace sdlraycaster
