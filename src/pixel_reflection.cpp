#include <SDL2/SDL.h>
#include "pixel_reflection.h"

PixelReflection::PixelReflection(SDL_Renderer* t_renderer, SDL_Color t_color) :
  GraphicalReflection(t_renderer), m_color(t_color) {}

void PixelReflection::draw(MathVector t_coordinates) {
  SDL_SetRenderDrawColor(m_renderer_pointer, m_color.r, m_color.g, m_color.b, m_color.a);
  SDL_RenderDrawPoint(m_renderer_pointer, t_coordinates[0], t_coordinates[1]);
}
