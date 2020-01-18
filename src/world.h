#pragma once
#include <vector>

#include <glm/ext.hpp>
#include <glm/glm.hpp>

#include "sdlraycaster.h"

#include "model/model.h"

#include "model/cube.h"
#include "model/heart.h"
#include "model/scene_object.h"

namespace sdlraycaster {

class World {
 public:
  World() {
     AddModel(Cube(), {4.0, -1.0, -10.0, 0.0});
    //AddModel(Heart(), {4.0, -1.0, -10.0, 0.0});
    // AddModel(Cube(), {-3.0, -1.0, -10.0});
  }
  void AddModel(const Model& model, glm::vec4 location) {
    objects_.push_back(SceneObject(model, location));
  };
  std::vector<SceneObject> GetAllSceneObjects() { return objects_; }
  std::vector<glm::vec4> PerpsectiveProject(unsigned int d);
  void Tick();

 private:
  std::vector<SceneObject> objects_;
};
}  // namespace sdlraycaster
