#pragma once
#include <functional>
#include "framebuffer.h"
#include "sdlraycaster.h"
#include "model/vertex.h"
namespace sdlraycaster {
class Rasterizer {
 public:
  void Rasterize(const std::vector<Vertex>& screen_space_coordinates, Framebuffer& fb);

  Rgba ComputeMaterialColor(const std::vector<Vertex>& projected_points,float lambda_0, float lambda_1, float lambda_2);

 private:
  std::function<double(glm::vec2)> ComputeEdge(glm::vec2 p0, glm::vec2 p1);
  glm::vec2 ClipSpaceToScreenSpace(glm::vec4 p,unsigned int width,unsigned int height);
};

}  // namespace sdlraycaster
