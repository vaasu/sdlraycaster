#include <iostream>
#include "SDL.h"
#include "Window.h"

int main(int argc, char* argv[]) {
  sdlraycaster::Window win{};
  win.Init();
  while (win.isRunning()) {
    win.HandleEvents();
    win.Update();
    win.Render();
  }
  win.Clean();

  return 0;
}