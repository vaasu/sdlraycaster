#include <glm/ext.hpp>
#include <glm/glm.hpp>

#include "sdlraycaster.h"

namespace sdlraycaster {

glm::vec4 homogenize(glm::vec4 v) {
  return glm::vec4(v.x / v.w, v.y / v.w, v.z / v.w, 1.0f);
}

}  // namespace sdlraycaster
