#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

bool init_graphics(SDL_Window** window, SDL_Renderer** renderer, std::string* error);
bool sdl_init(std::string* error);
bool init_window(SDL_Window** window, std::string* error);
bool create_renderer(SDL_Window* window, SDL_Renderer** renderer, std::string* error);
bool sdl_image_init(std::string* error);
void close(SDL_Window* t_window, SDL_Renderer* t_renderer);
