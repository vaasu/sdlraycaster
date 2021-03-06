#include <SFML/Graphics.hpp>

#include "framebuffer.h"
#include "rasterizer/rasterizer.h"
#include "world.h"

namespace sdlraycaster {

class Window {
 public:
  Window(int w, int h)
      : width_{w},
        height_{h},
        window_{sf::VideoMode(w, h), "SFML works!"},
        fb_{w, h},
        isRunning_{true} {
    window_.setFramerateLimit(60);
  };
  ~Window() = default;
  void HandleEvents();
  void Render();
  void Clean();
  bool isRunning();
  void Update();

 private:
  bool isRunning_ = false;
  sf::RenderWindow window_;
  Framebuffer fb_;
  World world_;
  Rasterizer rasterizer_{};

  int width_ = 0;
  int height_ = 0;
};

}  // namespace sdlraycaster
