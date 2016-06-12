#pragma once
#include <SDL2/SDL.h>

class GraphicalReflection {
  public:
    GraphicalReflection(SDL_Renderer* t_renderer);
  protected:
    SDL_Renderer* m_renderer_pointer;
};
