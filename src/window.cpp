#include "window.h"
#include <iostream>
#include "map.h"
#include "utils.h"
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
  std::vector<glm::vec4> points = world_.PerpsectiveProject(5);
  for (auto const x : points) {
    std::cout << glm::to_string(x) << std::endl;
  }
  // fb_.putPixel((int)sample_point.x, (int)sample_point.y, {255, 0, 0, 255});

  // manipulate framebuffer here,

  // fb_.DrawVLineDown({300, 0}, height_, {0, 0, 255});

  fb_.UpdateTexture();
}
}  // namespace sdlraycaster