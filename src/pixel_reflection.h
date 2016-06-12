#pragma once

#include <SDL2/SDL.h>
#include "graphical_reflection.h"
#include "math_vector.h"

class PixelReflection : public GraphicalReflection {
  public:
    PixelReflection(SDL_Renderer* t_renderer, Uint8 t_red, Uint8 t_green, Uint8 blue);
    void draw(MathVector t_coordinates);
  private:
    Uint8 m_red, m_green, m_blue;
};
