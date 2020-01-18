#include <iostream>

#include "map.h"
#include "sdlraycaster.h"
#include "window.h"
#include "world.h"

#ifdef USE_GLM_MATH
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

#else
// todo write the math  library
#error "glm required"
#include "matrix.h"
#endif

namespace sdlraycaster {

void Window::HandleEvents() {
  sf::Event ev;
  window_.pollEvent(ev);
  if (ev.type == sf::Event::Closed) {
    window_.close();
    isRunning_ = false;
  }
}
void Window::Render() {
  window_.clear();
  window_.draw(fb_.getSprite());
  window_.display();
}
void Window::Clean() { std::cout << "Game cleaned" << std::endl; }
bool Window::isRunning() { return isRunning_; }

void Window::Update() {
  fb_.clear(0);
  /* Application Processing */
  world_.Tick();

  /* 2.3 - Geometry Processing */
  // view transform model and camera
  // compute positions of vertices
  std::vector<glm::vec2> screen_space_cordinates{};
  std::vector<glm::vec4> points = world_.PerpsectiveProject(5);
  for (const auto &p : points) {
    screen_space_cordinates.push_back(
        glm::vec2{// x-cordinate:
                  ((p.x / p.w) + 1) * (width_ / 2),
                  // y-cordinate
                  ((p.y / p.w) + 1) * (height_ / 2)

        });
  }

  /* 2.3.1 --- Vertex Shading */
  // shading is done here
  
  /* 2.3.2 Optinal vetex processing */
  // {none} 

  /* --- Projection */

  /* --- Clipping */
  /* --- Screen mapping */

  /* Raterization */
  rasterizer_.Rasterize(screen_space_cordinates, fb_);

  /* Pixel processing */
  /*
  for (const auto& p : screen_space_cordinates) {
    fb_.putPixel((int)p.x, (int)p.y, {255, 0, 0, 255});
  }
  */

  fb_.UpdateTexture();
}
} // namespace sdlraycaster
