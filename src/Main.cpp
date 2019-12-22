#include <iostream>
#include "SDL.h"
#include "Window.h"

int main(int argc, char* argv[]) {
  sdlraycaster::Window* win = new sdlraycaster::Window();
  win->Init(640, 480);
  while (win->isRunning()) {
    win->HandleEvents();
    win->Update();
    win->Render();
  }
  win->Clean();

  return 0;
}