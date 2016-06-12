#pragma once

#include <SDL2/SDL.h>
#include "math_vector.h"

class GraphicalReflection {
  public:
    GraphicalReflection(SDL_Renderer* t_renderer);
    virtual void draw(MathVector t_coordinates) = 0;
  protected:
    SDL_Renderer* m_renderer_pointer;
};
