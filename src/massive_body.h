#pragma once

#include <list>
#include <stack>
#include "math_vector.h"

class MassiveBody {
  public:
    MassiveBody(float t_mass, MathVector t_position);
    MassiveBody(float t_mass, MathVector t_position, MathVector t_velocity);
    MassiveBody(float t_mass, std::initializer_list<float> t_position);
    MassiveBody(float t_mass,
        std::initializer_list<float> t_position,
        std::initializer_list<float> t_velocity);
    void add_external_force(MathVector t_force);
    MathVector calculate_acceleration(std::list<MassiveBody*>& t_attractors);
    void set_position(MathVector t_position);
    void set_velocity(MathVector t_velocity);
    MathVector get_velocity();
    MathVector get_position();
    float get_position(std::size_t);
  protected:
    float m_mass;
    MathVector m_position;
  private:
    static constexpr float GRAVITY_CONST = 1;
    std::stack<MathVector> m_forces;
    MathVector m_acceleration;
    MathVector m_velocity;
};
