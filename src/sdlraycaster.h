

#pragma once

#include <stdint.h>
#include <SFML/Graphics.hpp>

#include <glm/ext.hpp>
#include <glm/glm.hpp>

namespace sdlraycaster {
using Vec2vec = std::vector<glm::vec2>;
using Vec3vec = std::vector<glm::vec3>;
using Vec4vec = std::vector<glm::vec4>;

glm::vec4 homogenize(glm::vec4 v);
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
