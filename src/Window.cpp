#include "Window.h"
#include <iostream>
#include "Map.h"
#include "Utils.h"

namespace sdlraycaster {

Window::Window() {}
Window::~Window() {}

void Window::Init(int w, int h) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "SDL failed to initialize" << std::endl;
  } else {
    window_ = SDL_CreateWindow("raytracer", 0, 0, w, h, SDL_WINDOW_SHOWN);
    renderer_ = SDL_CreateRenderer(window_, -1, 0);
    fb_ = new Framebuffer(w, h);
    if (renderer_) {
      isRunning_ = true;
      framebuffer_texture_ =
          SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_ABGR8888,
                            SDL_TEXTUREACCESS_STREAMING, w, h);
      SDL_UpdateTexture(framebuffer_texture_, NULL,
                        reinterpret_cast<void *>(fb_->img.data()), w * 4);

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
  SDL_SetRenderDrawColor(renderer_, 0, 255, 255, 255);
  SDL_RenderClear(renderer_);
  // draw the framebuffer texture:

  SDL_RenderCopy(renderer_, framebuffer_texture_, NULL, NULL);
  SDL_RenderPresent(renderer_);
}
void Window::Clean() {
  SDL_DestroyWindow(window_);
  SDL_DestroyRenderer(renderer_);
  SDL_Quit();
  std::cout << "Game cleaned" << std::endl;
}
bool Window::isRunning() { return isRunning_; }
void Window::Update() {
  // memset(fb_->img.data(), 255, 640 * 480 * sizeof(uint32_t));
  static uint8_t c = 2;
  fb_->img.assign(640 * 480, pack_color(255, 0, 0));
  SDL_UpdateTexture(framebuffer_texture_, NULL,
                    reinterpret_cast<void *>(fb_->img.data()), width_ * 4);

  c = c * 3;
}
void Window::DrawTopView(SDL_Renderer *r) {
  // int topViewWidth = width_ / 2;
  // int topViewHeight = height_;
  // int currentBlock = 0;  // goes from 0 -> 16**16-1

  // for (auto x : sdlraycaster::map) {
  // }
}
}  // namespace sdlraycaster