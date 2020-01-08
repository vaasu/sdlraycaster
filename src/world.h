#pragma once
#include <vector>

#include <glm/ext.hpp>
#include <glm/glm.hpp>

#include "utils.h"

namespace sdlraycaster {
class Model {
 public:
  std::vector<glm::vec3> GetAllPoints() const { return points_; }

 protected:
  std::vector<glm::vec3> points_;
};

class Cube : public Model {
 public:
  Cube() {
    // points_.push_back({0, 0, 0});
    // points_.push_back({0, 1, 0});
    // points_.push_back({1, 1, 0});
    // points_.push_back({1, 0, 0});

    // points_.push_back({0, 0, 1});
    // points_.push_back({0, 1, 1});
    // points_.push_back({1, 1, 1});
    // points_.push_back({1, 0, 1});

    points_.push_back({-0.5, -0.5, 0.5});
    points_.push_back({-0.5, 0.5, 0.5});
    points_.push_back({0.5, 0.5, 0.5});
    points_.push_back({0.5, -0.5, 0.5});

    points_.push_back({-0.5, -0.5, -0.5});
    points_.push_back({-0.5, 0.5, -0.5});
    points_.push_back({0.5, 0.5, -0.5});
    points_.push_back({0.5, -0.5, -0.5});
  }

 private:
};
class SceneObject {
 public:
  SceneObject(const Model& m, glm::vec4 l) : model_{m}, location_{l} {
    rotation_ = glm::mat4(1.0);
  }
  Model model_;
  glm::vec4 location_;
  glm::mat4 rotation_;  // rotation matrix
  std::vector<glm::vec3> GetWorldCordinates() const {
    std::vector<glm::vec3> pts{};

    for (auto const& p : model_.GetAllPoints()) {
      pts.push_back((rotation_ * glm::vec4(p, 1.)) + location_);
    }
    return pts;
  }
  void RotateZ(float degrees) {
    // rotate the model by degrees anticlockwise
    float phi = glm::radians(degrees);
    float float_rotation_matrix_z[16] = {
        glm::cos(phi), glm::sin(phi), 0, 0,  //
        //
        -1 * glm::sin(phi), glm::cos(phi), 0, 0,  //
        //
        0, 0, 1, 0,  //
        //
        0, 0, 0, 1  //
    };

    // y axis rotation;
    glm::mat4 rotation_matrix = glm::make_mat4(float_rotation_matrix_z);
    rotation_ = rotation_matrix;
  }
  void RotateY(float degrees) {
    // rotate the model by degrees anticlockwise
    float phi = glm::radians(degrees);
    float float_rotation_matrix_y[16] = {
        glm::cos(phi), 0, -1 * glm::sin(phi), 0,  //
        //
        0, 1, 0, 0,  //
        //
        glm::sin(phi), 0, glm::cos(phi), 0,  //
        //
        0, 0, 0, 1  //
    };

    // y axis rotation;
    glm::mat4 rotation_matrix = glm::make_mat4(float_rotation_matrix_y);
    rotation_ = rotation_matrix;
  }

 private:
};

class World {
 public:
  World() {
    AddModel(Cube(), {4.0, -1.0, -10.0, 0.0});
    // AddModel(Cube(), {-3.0, -1.0, -10.0});
  }
  void AddModel(const Model& model, glm::vec4 location) {
    objects_.push_back(SceneObject(model, location));
  };
  std::vector<SceneObject> GetAllSceneObjects() { return objects_; }
  std::vector<glm::vec4> PerpsectiveProject(unsigned int d) {
    static float degree = 0.0;
    float phi = glm::radians(degree);

    // y axis rotation;
    float float_rotation_matrix[16] = {
        glm::cos(phi), 0, -1 * glm::sin(phi), 0,  //
        //
        0, 1, 0, 0,  //
        //
        glm::sin(phi), 0, glm::cos(phi), 0,  //
        //
        0, 0, 0, 1  //
    };
    // z axis rotation
    float float_rotation_matrix_z[16] = {
        glm::cos(phi), glm::sin(phi), 0, 0,  //
        //
        -1 * glm::sin(phi), glm::cos(phi), 0, 0,  //
        //
        0, 0, 1, 0,  //
        //
        0, 0, 0, 1  //
    };
    objects_[0].RotateY(degree);
    degree += 0.50;
    if (degree > 360.0) degree = 0.0;

    // y axis rotation;
    glm::mat4 rotation_matrix = glm::make_mat4(float_rotation_matrix_z);

    std::vector<glm::vec4> output{};
    float float_projection_matrix[16] = {
        1.0, 0,   0,   0,                             //
        0,   1.0, 0,   0,                             //
        0,   0,   1.0, static_cast<float>(-1.0 / d),  //
        0,   0,   0,   0                              //

    };
    glm::mat4 projection_matrix = glm::make_mat4(float_projection_matrix);

    // memcpy(glm::value_ptr(projection_matrix), float_projection_matrix,
    //        sizeof(float_projection_matrix));

    for (auto const& o : objects_) {
      for (auto const& world_point : o.GetWorldCordinates()) {
        glm::vec4 point = glm::vec4(world_point, 1.0);
        auto tmp = projection_matrix * point;

        output.push_back(projection_matrix * point);
      }
    }
    return output;
  }

 private:
  std::vector<SceneObject> objects_;
};
}  // namespace sdlraycaster