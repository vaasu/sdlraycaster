#include "Window.h"
#include <iostream>
#include "Map.h"

namespace sdlraycaster {

Window::Window() {}
Window::~Window() {}

void Window::Init(int w, int h) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "SDL failed to initialize" << std::endl;
  } else {
    window_ = SDL_CreateWindow("raytracer", 0, 0, w, h, SDL_WINDOW_SHOWN);
    renderer_ = SDL_CreateRenderer(window_, -1, 0);
    if (renderer_) {
      isRunning_ = true;
      SDL_SetRenderDrawColor(renderer_, 0, 255, 255, 255);
      std::cout << "renderer created" << std::endl;
    } else {
      isRunning_ = false;
    }
  }
}
void Window::HandleEvents() {
  SDL_Event ev;
  SDL_PollEvent(&ev);
  switch (ev.type) {
    case SDL_QUIT:
      isRunning_ = false;
      break;
    default:
      break;
  }
}
void Window::Render() {
  SDL_RenderClear(renderer_);
  // DrawTopView(renderer_);
  SDL_SetRenderDrawColor(renderer_, 0, 255, 255, 255);

  SDL_RenderPresent(renderer_);
}
void Window::Clean() {
  SDL_DestroyWindow(window_);
  SDL_DestroyRenderer(renderer_);
  SDL_Quit();
  std::cout << "Game cleaned" << std::endl;
}
bool Window::isRunning() { return isRunning_; }
void Window::Update() {}
void Window::DrawTopView(SDL_Renderer *r) {
  // int topViewWidth = width_ / 2;
  // int topViewHeight = height_;
  // int currentBlock = 0;  // goes from 0 -> 16**16-1

  // for (auto x : sdlraycaster::map) {
  // }
}
}  // namespace sdlraycaster