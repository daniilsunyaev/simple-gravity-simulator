#include "init_graphics.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;

bool init_graphics(SDL_Window** t_window, SDL_Renderer** t_renderer, std::string* t_error) {
  if (sdl_init(t_error) &&
      init_window(t_window, t_error) &&
      create_renderer(*t_window, t_renderer, t_error) &&
      sdl_image_init(t_error)) {
    return true;
  }
  return false;
}

void close(SDL_Window* t_window, SDL_Renderer* t_renderer) {
  SDL_DestroyRenderer(t_renderer);
  SDL_DestroyWindow(t_window);
  IMG_Quit();
  SDL_Quit();
}

bool sdl_init(std::string* t_error) {
  if(SDL_Init(SDL_INIT_VIDEO) < 0 ) {
    t_error -> assign("Unable to initialize SDL: ");
    t_error -> append(SDL_GetError());
    return false;
  }
  return true;
}

bool init_window(SDL_Window** t_window, std::string* t_error) {
  *t_window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if(*t_window == NULL) {
    t_error -> assign("Window could not be created! SDL_Error ");
    t_error -> append(SDL_GetError());
    return false;
  }
  return true;
}

bool create_renderer(SDL_Window* t_window, SDL_Renderer** t_renderer, std::string* t_error) {
  *t_renderer = SDL_CreateRenderer(t_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(*t_renderer == NULL) {
    t_error -> assign("Renderer could not be created! SDL Error: ");
    t_error -> append(SDL_GetError());
    return false;
  }
  return true;
}

bool sdl_image_init(std::string* t_error) {
  int imgFlags = IMG_INIT_PNG;

  if (!(IMG_Init(imgFlags) & imgFlags)) {
    t_error -> assign("Sdl image could not initialized ");
    t_error -> append(IMG_GetError());
    return false; 
  }
  return true;
}
