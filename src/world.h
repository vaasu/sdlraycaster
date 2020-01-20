#pragma once
#include <vector>

#include <glm/ext.hpp>
#include <glm/glm.hpp>

#include "sdlraycaster.h"

#include "model/model.h"

#include "lighting/basic_light.h"
#include "model/cube.h"
#include "model/heart.h"
#include "model/scene_object.h"
#include "lighting/point_light.h"

namespace sdlraycaster {

class World {
public:
  World() {
    AddModel(Cube(), {0.0, -1.0, -10.0, 0.0});
    AddLight(PointLight(vec3{1,0,0},vec3{2,4,-9}));
      /*
    for (int x = 0; x < 4;x++){
    for (int y = 0; y < 4;y++){
        AddModel(Cube(), {x*2,y*2, -50.0, 0.0});

    }
    }
    */
  }
  void AddModel(const Model &model, glm::vec4 location) {
    objects_.push_back(SceneObject(model, location));
  };
  std::vector<SceneObject> GetAllSceneObjects() { return objects_; }
  std::vector<Vertex> PerpsectiveProject(unsigned int d);
  void AddLight(const BasicLight &light) { lights_.push_back(light); }
  std::vector<BasicLight> GetAllLights() { return lights_; }
  void Tick();

private:
  std::vector<SceneObject> objects_{};
  std::vector<BasicLight> lights_{};
};
} // namespace sdlraycaster
