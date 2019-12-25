#include <iostream>
#include "window.h"

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