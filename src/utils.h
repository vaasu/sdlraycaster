

#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_
#include <stdint.h>
#include <SFML/Graphics.hpp>

namespace sdlraycaster {
uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b,
                    const uint8_t a = 255);
struct Rgba {
  sf::Uint8 r{0};
  sf::Uint8 g{0};
  sf::Uint8 b{0};
  sf::Uint8 a{0};
};
struct Rgb {
  sf::Uint8 r{0};
  sf::Uint8 g{0};
  sf::Uint8 b{0};
};
struct screen_coord {
  int x{0};
  int y{0};
};
struct world_coord {
  float x{0};
  float y{0};
  float z{0};
};
}  // namespace sdlraycaster

#endif