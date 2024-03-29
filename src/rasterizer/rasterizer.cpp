#include <algorithm>
#include <iostream>

#include "sdlraycaster.h"
#include "rasterizer.h"

namespace sdlraycaster {
void Rasterizer::Rasterize(const std::vector<Vertex>& projected_points,
                           Framebuffer& fb) {
  // rasterization
  for (int i = 0; i < projected_points.size(); i += 3) {
    glm::vec2 p0{ClipSpaceToScreenSpace(projected_points[i + 0].GetPoint(),
                                        fb.GetWidth(), fb.GetHeight())};
    glm::vec2 p1{ClipSpaceToScreenSpace(projected_points[i + 1].GetPoint(),
                                        fb.GetWidth(), fb.GetHeight())};
    glm::vec2 p2{ClipSpaceToScreenSpace(projected_points[i + 2].GetPoint(),
                                        fb.GetWidth(), fb.GetHeight())};

    //    glm::vec4 p1 projected_points[i + 1];
    //   glm::vec4 p2 projected_points[i + 2];

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

          //colorization using barycentric coordinates
          //using description from https://www.scratchapixel.com/lessons/3d-basic-rendering/rasterization-practical-implementation/rasterization-stage

          auto normalizing_constant = edge_p1p2(p0);

          auto lambda_0 = edge_p1p2(pt)/normalizing_constant;
          auto lambda_1 = edge_p2p0(pt)/normalizing_constant;
          auto lambda_2 = edge_p0p1(pt)/normalizing_constant;

          fb.putPixel(i, fb.GetHeight() - j, ComputeMaterialColor(projected_points,lambda_0,lambda_1,lambda_2));
        }
      }
    }
    // fb.putPixel(((p0.x/p0.w)+1) *(fb.GetWidth()/2), (fb.GetHeight() -
    // ((p0.y/p0.w)+1)*(fb.GetHeight()/2)), Rgba{255, 0, 0, 255});
    // fb.putPixel(((p1.x/p0.w)+1) *(fb.GetWidth()/2), (fb.GetHeight() -
    // ((p1.y/p0.w)+1)*(fb.GetHeight()/2)), Rgba{255, 0, 0, 255});
    // fb.putPixel(((p2.x/p0.w)+1) *(fb.GetWidth()/2), (fb.GetHeight() -
    // ((p2.y/p0.w)+1)*(fb.GetHeight()/2)), Rgba{255, 0, 0, 255});
    fb.putPixel(p1.x, fb.GetHeight() - p1.y, Rgba{0, 255, 0, 255});
    fb.putPixel(p2.x, fb.GetHeight() - p2.y, Rgba{255, 255, 255, 255});

    // compute bounding box of pixel version of it
  }
}
Rgba Rasterizer::ComputeMaterialColor(const std::vector<Vertex>& projected_points,float lambda_0, float lambda_1, float lambda_2){
  auto color =  ((lambda_0 * projected_points[0].GetColor()[0]) + (lambda_1 * projected_points[1].GetColor()[0])
                         + (lambda_2 * projected_points[2].GetColor()[0]));
  // auto color =  ((lambda_0 * projected_points[0].GetColor()[0]) );

  sf::Uint8 red  = 255 * color;

  // std::cerr << "red = "  << unsigned(lambda_0) << std::endl;
    // std::cerr << "p[0][blue]= " << projected_points[0].GetColor()[2] << std::endl;

  if (projected_points[0].GetColor()[0] > 0.5){
    std::cerr << "lambda 0 = " << lambda_0  << std::endl;
    std::cerr << "color = " << projected_points[0].GetColor()[0]  << std::endl;
    throw 3;
  }
  auto a = Rgba{red,0,0,0};
  return a;
}
std::function<double(glm::vec2)> Rasterizer::ComputeEdge(glm::vec2 p0,
                                                         glm::vec2 p1) {
  // lambda capture by value as p1 or p2 might change in iterations
  return [=](glm::vec2 pt) -> double {
    return (-1 * (p1.y - p0.y) * (pt.x - p0.x)) +  // x
           (p1.x - p0.x) * (pt.y - p0.y);
  };
}

glm::vec2 Rasterizer::ClipSpaceToScreenSpace(glm::vec4 p, unsigned int width,
                                             unsigned int height) {
  return vec2{// x-cordinate:
              ((p.x / p.w) + 1) * (width / 2),
              // y-cordinate
              ((p.y / p.w) + 1) * (height / 2)};
}
}  // namespace sdlraycaster
