#pragma once
#include <sdlraycaster.h>

namespace sdlraycaster {
class PointLight : public BasicLight {
 public:
     PointLight(vec3 hue,vec3 location):BasicLight{hue,location}{

     }

 private:


};

}  // namespace sdlraycaster
