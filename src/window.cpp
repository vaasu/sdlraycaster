#include "window.h"
#include <iostream>
#include "map.h"
#include "utils.h"

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
  // manipulate framebuffer here,
  fb_.DrawVLineDown({300, 0}, height_, {0, 0, 0});
  // fb_.putPixel(200, 303, Rgb{255, 0,
  // fb_.putPixel(200, 303, Rgba{255, 0, 0, 0});
  fb_.UpdateTexture();
}
// void Window::DrawTopView(SDL_Renderer *r) {
// int topViewWidth = width_ / 2;
// int topViewHeight = height_;
// int currentBlock = 0;  // goes from 0 -> 16**16-1

// for (auto x : sdlraycaster::map) {
// }
// }
}  // namespace sdlraycaster