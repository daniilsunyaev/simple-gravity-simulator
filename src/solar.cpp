#include <iostream>
#include "massive_body.h"
#include "massive_body_controller.h"
#include "pixel_reflection.h"
#include "init_graphics.h"

void run_loop(SDL_Renderer* t_renderer);
void move_objects(MassiveBody* t_body);

int main() {
  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;
  std::string error = "";

  if(init_graphics(&window, &renderer, &error)) {
    run_loop(renderer);
    close(window, renderer);
  } else {
    std::cout << "Failed to initialize graphics:" << std::endl;
    std::cout << error << std::endl;
  }

  return 0;
}

void run_loop(SDL_Renderer* t_renderer) {
  std::list<MassiveBodyController*> world;

  MassiveBody sun(3.3e3, {400, 300}, {0, 0});
  PixelReflection sun_image(t_renderer, 0xFF, 0xFF, 0);

  MassiveBody earth(1e0, {200, 300}, {0, 3.5});
  PixelReflection earth_image(t_renderer, 0x1F, 0x1F, 0xFF);

  MassiveBody moon(1e-2, {206, 300}, {0, 3.9});
  PixelReflection moon_image(t_renderer, 0xBB, 0xBB, 0xBB);

  MassiveBody mars(1e-1, {105, 300}, {0, 3.5});
  PixelReflection mars_image(t_renderer, 0xFF, 0xBB, 0x10);

  MassiveBodyController sun_controller(sun, {&earth, &mars}, sun_image);
  MassiveBodyController earth_controller(earth, {&sun, &mars, &moon}, earth_image);
  MassiveBodyController moon_controller(moon, {&sun, &earth, &mars}, moon_image);
  MassiveBodyController mars_controller(mars, {&sun, &earth}, mars_image);

  world.push_back(&sun_controller);
  world.push_back(&earth_controller);
  world.push_back(&moon_controller);
  world.push_back(&mars_controller);

  bool loop = true;
  SDL_Event event;

  while(loop) {
    while(SDL_PollEvent(&event) != 0) {
      if(event.type == SDL_QUIT) { loop = false; }
    }

    SDL_SetRenderDrawColor( t_renderer, 0, 0, 0, 0);
    SDL_RenderClear(t_renderer);

    for(const auto& controller : world) {
      controller->move_body();
      controller->draw_body();
    }

    SDL_RenderPresent(t_renderer);
  }
}
