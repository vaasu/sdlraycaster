#pragma once
#include <sdlraycaster.h>

namespace sdlraycaster {
class BasicLight {
public:
    BasicLight(vec3 hue, vec3 location):hue_{hue},location_{location}{}
protected:
  vec3 hue_{};
  vec3 location_{};
};

} // namespace sdlraycaster
