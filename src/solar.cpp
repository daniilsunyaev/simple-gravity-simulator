#include <iostream>
#include <algorithm>
#include "massive_body.h"
#include "init_graphics.h"

void run_loop(SDL_Renderer *t_renderer);
void move_objects(MassiveBody *t_body);

int main() {
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
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

void run_loop(SDL_Renderer *t_renderer) {
  std::list<MassiveBody*> moving_objects;

  MathVector sp({400, 300});
  MathVector ep({200, 300});
  MathVector mp({205, 300});
  MathVector marsp({105, 300});
  MathVector ev({0, 2});
  MathVector sv({0, 0.0});
  MathVector mv({0, 2.5});
  MathVector marsv({0, 1.5});

  MassiveBody sun(sp, 1000.0F);
  MassiveBody earth(ep, 1);
  MassiveBody mars(marsp, 1);
  MassiveBody moon(mp, 0.1);

  sun.set_attractor(&earth);
  moving_objects.push_back(&sun);
  sun.set_velocity(sv);

  earth.set_attractor(&sun);
  earth.set_attractor(&mars);
  moving_objects.push_back(&earth);
  earth.set_velocity(ev);

  moon.set_attractor(&sun);
  moon.set_attractor(&earth);
  moving_objects.push_back(&moon);
  moon.set_velocity(mv);

  mars.set_attractor(&sun);
  mars.set_attractor(&earth);
  moving_objects.push_back(&mars);
  mars.set_velocity(marsv);

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
    SDL_RenderDrawPoint(t_renderer, sun.get_position().get_coordinate(0), sun.get_position().get_coordinate(1));

    SDL_SetRenderDrawColor( t_renderer, 0x1F, 0x1F, 0xFF, 0xFF );
    SDL_RenderDrawPoint(t_renderer, earth.get_position().get_coordinate(0), earth.get_position().get_coordinate(1));

    SDL_SetRenderDrawColor( t_renderer, 0xBB, 0xBB, 0xBB, 0xFF );
    SDL_RenderDrawPoint(t_renderer, moon.get_position().get_coordinate(0), moon.get_position().get_coordinate(1));

    SDL_SetRenderDrawColor( t_renderer, 0xFF, 0xBB, 0x10, 0xFF );
    SDL_RenderDrawPoint(t_renderer, mars.get_position().get_coordinate(0), mars.get_position().get_coordinate(1));

    SDL_RenderPresent(t_renderer);
  }
}

void move_objects(MassiveBody *t_body) {
  t_body->set_position(t_body->get_position() + t_body->get_velocity());
  t_body->set_velocity(t_body->get_velocity() + t_body->calculate_acceleration());
}
