#pragma once
#include <SDL2/SDL.h>
#include "graphical_reflection.h"
#include "math_vector.h"

class PixelReflection : protected GraphicalReflection {
  public:
    PixelReflection(SDL_Renderer* t_renderer, SDL_Color t_color);
    void draw(MathVector t_coordinates);
  private:
    SDL_Color m_color;
};
