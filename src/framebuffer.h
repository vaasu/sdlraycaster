
#ifndef SRC_FRAMEBUFFER_H_
#define SRC_FRAMEBUFFER_H_
#include <stdint.h>
#include <cstdlib>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "utils.h"
namespace sdlraycaster {
class Framebuffer {
 private:
  int width_;
  int height_;
  int framebuffer_size_;
  // std::unique_ptr<sf::Uint8[]> fb_data_{nullptr};
  std::vector<sf::Uint8> fb_data_{};
  sf::Texture fb_texture_;
  sf::Sprite fb_sprite_;

  int i = 0;
  int update = 0;

 public:
  void putPixel(int x, int y, Rgb color);
  void putPixel(int x, int y, Rgba color);
  void DrawLine(screen_coord start, screen_coord end, Rgba color);
  void DrawVLineDown(screen_coord start, int end, Rgb color);
  void clear(uint32_t color);
  Framebuffer(int w, int h)
      : width_{w}, height_{h}, framebuffer_size_{h * w * 4} {
    // fb_data_ = std::make_unique<sf::Uint8[]>(width_ * height_ * 4);
    fb_data_.reserve(framebuffer_size_);
    fb_data_.assign(framebuffer_size_, 255);
    fb_texture_.create(width_, height_);  // todo: error check
    fb_sprite_.setTexture(fb_texture_);
  };
  const sf::Sprite& getSprite() const { return fb_sprite_; };
  void UpdateTexture() { fb_texture_.update(fb_data_.data()); }
};

}  // namespace sdlraycaster
#endif