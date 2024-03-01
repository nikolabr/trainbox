#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

#include <SDL_error.h>
#include <SDL_surface.h>
#include <SDL_error.h>
#include <SDL.h>

static const int WINDOW_WIDTH = 960;
static const int WINDOW_HEIGHT = 960;

int main() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "Failed to initialize the SDL2 library" << std::endl;
    return -1;
  }

  SDL_Window *window =
      SDL_CreateWindow("Transport sim", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

  if (!window) {
    std::cerr << "Failed to create window" << SDL_GetError() << std::endl;
    return -1;
  }

  SDL_Surface *window_surface = SDL_GetWindowSurface(window);

  SDL_UpdateWindowSurface(window);

  SDL_Event e;
  bool quit = false;
  while (quit == false) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        quit = true;
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
}
