#include <iostream>

#include "window.h"
#ifdef USE_GLM_MATH
#include <glm/ext.hpp>
#include <glm/glm.hpp>

#else
// todo write the math  library
#error "glm required"
#include "matrix.h"
#endif

int main(int argc, char* argv[]) {
  sdlraycaster::Window win{640, 480};
  while (win.isRunning()) {
    win.HandleEvents();
    win.Update();
    win.Render();
  }
  win.Clean();
  return 0;
}