#include <SDL2/SDL.h>
#include "pixel_reflection.h"

PixelReflection::PixelReflection(SDL_Renderer* t_renderer,
    Uint8 t_red, Uint8 t_green, Uint8 t_blue) :
  GraphicalReflection(t_renderer), m_red(t_red), m_green(t_green), m_blue(t_blue) {}

void PixelReflection::draw(MathVector t_coordinates) {
  SDL_SetRenderDrawColor(m_renderer_pointer, m_red, m_green, m_blue, 255);
  SDL_RenderDrawPoint(m_renderer_pointer, t_coordinates[0], t_coordinates[1]);
}
