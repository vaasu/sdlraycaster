#include <algorithm>
#include <iostream>

#include "rasterizer.h"
#include "sdlraycaster.h"

namespace sdlraycaster {
void Rasterizer::Rasterize(const Vec2vec& screen_space_coordinates,
                           Framebuffer& fb) {
  // rasterization
  for (int i = 0; i < screen_space_coordinates.size(); i += 3) {
    glm::vec2 p0 = screen_space_coordinates[i + 0];
    glm::vec2 p1 = screen_space_coordinates[i + 1];
    glm::vec2 p2 = screen_space_coordinates[i + 2];

    // compute bounding box of triangle
    int min_x = static_cast<int>(std::min<float>({p0.x, p1.x, p2.x}));
    int max_x = static_cast<int>(std::max<float>({p0.x, p1.x, p2.x}));

    int min_y = static_cast<int>(std::min<float>({p0.y, p1.y, p2.y}));
    int max_y = static_cast<int>(std::max<float>({p0.y, p1.y, p2.y}));

    // compute edge function constants for each edge in triangle:
    // edge p0 -- p1:
    auto edge_p0p1 = ComputeEdge(p0, p1);
    auto edge_p1p2 = ComputeEdge(p1, p2);
    auto edge_p2p0 = ComputeEdge(p2, p0);

    for (int i = min_x; i <= max_x; i++) {
      for (int j = min_y; j <= max_y; j++) {
        // check if the pixel i,y is inside the triangle
        auto pt = glm::vec2(i, j);
        // tie break rule aka top-left rule is not yet implemented
        if (edge_p0p1(pt) >= 0 && edge_p1p2(pt) >= 0 && edge_p2p0(pt) >= 0) {
          fb.putPixel(i, fb.GetHeight() - j, Rgba{255, 0, 255, 227});
        }
      }
    }
    fb.putPixel(p0.x, fb.GetHeight() - p0.y, Rgba{255, 0, 0, 255});
    fb.putPixel(p1.x, fb.GetHeight() - p1.y, Rgba{0, 255, 0, 255});
    fb.putPixel(p2.x, fb.GetHeight() - p2.y, Rgba{255, 255, 255, 255});

    // compute bounding box of pixel version of it
  }
}
std::function<double(glm::vec2)> Rasterizer::ComputeEdge(glm::vec2 p0,
                                                         glm::vec2 p1) {
  // lambda capture by value as p1 or p2 might change in iterations
  return [=](glm::vec2 pt) -> double {
    return (-1 * (p1.y - p0.y) * (pt.x - p0.x)) +  // x
           (p1.x - p0.x) * (pt.y - p0.y);
  };
}
}  // namespace sdlraycaster