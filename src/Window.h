#include "SDL.h"

namespace sdlraycaster {
class Window {
 private:
  bool isRunning_ = false;
  SDL_Window *window_ = nullptr;
  SDL_Renderer *renderer_ = nullptr;

  int width_ = 0;
  int height_ = 0;

 public:
  Window();
  ~Window();
  void Init(int w, int h);
  void HandleEvents();
  void Render();
  void Clean();
  bool isRunning();
  void Update();
  void DrawTopView(SDL_Renderer *r);
};

}  // namespace sdlraycaster
