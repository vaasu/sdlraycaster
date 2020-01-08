#include "utils.h"
#include <glm/ext.hpp>
#include <glm/glm.hpp>

namespace sdlraycaster {
uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b,
                    const uint8_t a) {
  return (a << 24) + (b << 16) + (g << 8) + r;
}
glm::vec4 homogenize(glm::vec4 v) {
  return glm::vec4(v.x / v.w, v.y / v.w, v.z / v.w, 1.0f);
}
}  // namespace sdlraycaster
