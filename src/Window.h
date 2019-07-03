#include "SDL.h"

namespace sdlraycaster {
class Window {
 private:
  bool isRunning_ = false;
  SDL_Window *window_ = nullptr;
  SDL_Renderer *renderer_ = nullptr;

 public:
  Window();
  ~Window();
  void Init();
  void HandleEvents();
  void Render();
  void Clean();
  bool isRunning();
  void Update();
};

}  // namespace sdlraycaster
