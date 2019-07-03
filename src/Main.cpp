#include <iostream>
#include "SDL.h"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "SDL failed to initialize" << std::endl;
        return 2;
    }
    SDL_Window *window = SDL_CreateWindow(
        "raytracer",
        0,0,640,480,SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,0);
    Uint8 h = 255;
    SDL_SetRenderDrawColor(renderer,0,255,255,255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
    SDL_Delay(3000);


    return 0;
}