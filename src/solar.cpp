#include <iostream>
#include <algorithm>
#include "massive_body.h"
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
  std::list<MassiveBody*> moving_objects;

  MathVector sun_position({400, 300});
  MathVector earth_position({200, 300});
  MathVector moon_position({205, 300});
  MathVector mars_position({105, 300});
  MathVector earth_velocity({0, 2});
  MathVector sun_velocity({0, 0.0});
  MathVector moon_velocity({0, 2.5});
  MathVector mars_velocity({0, 1.5});

  MassiveBody sun(1000.0F, sun_position, sun_velocity);
  MassiveBody earth(1, earth_position, earth_velocity);
  MassiveBody mars(1, mars_position, mars_velocity);
  MassiveBody moon(0.1, moon_position, moon_velocity);

  sun.add_attractor(&earth);
  moving_objects.push_back(&sun);

  earth.add_attractor(&sun);
  earth.add_attractor(&mars);
  moving_objects.push_back(&earth);

  moon.add_attractor(&sun);
  moon.add_attractor(&earth);
  moving_objects.push_back(&moon);

  mars.add_attractor(&sun);
  mars.add_attractor(&earth);
  moving_objects.push_back(&mars);

  bool loop = true;
  SDL_Event event;

  while(loop) {
    while(SDL_PollEvent(&event) != 0) {
      if(event.type == SDL_QUIT) { loop = false; }
    }

    for_each(moving_objects.begin(), moving_objects.end(), move_objects);

    SDL_SetRenderDrawColor( t_renderer, 0, 0, 0, 0);
    SDL_RenderClear(t_renderer);

    SDL_SetRenderDrawColor( t_renderer, 0xFF, 0xFF, 0, 0xFF );
    SDL_RenderDrawPoint(t_renderer, sun.get_position(0), sun.get_position(1));

    SDL_SetRenderDrawColor( t_renderer, 0x1F, 0x1F, 0xFF, 0xFF );
    SDL_RenderDrawPoint(t_renderer, earth.get_position(0), earth.get_position(1));

    SDL_SetRenderDrawColor( t_renderer, 0xBB, 0xBB, 0xBB, 0xFF );
    SDL_RenderDrawPoint(t_renderer, moon.get_position(0), moon.get_position(1));

    SDL_SetRenderDrawColor( t_renderer, 0xFF, 0xBB, 0x10, 0xFF );
    SDL_RenderDrawPoint(t_renderer, mars.get_position(0), mars.get_position(1));

    SDL_RenderPresent(t_renderer);
  }
}

void move_objects(MassiveBody* t_body) {
  t_body->set_position(t_body->get_position() + t_body->get_velocity());
  t_body->set_velocity(t_body->get_velocity() + t_body->calculate_acceleration());
}
