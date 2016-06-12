#include "massive_body.h"

constexpr float MassiveBody::GRAVITY_CONST;

MassiveBody::MassiveBody(float t_mass, MathVector t_position) :
  m_mass(t_mass), m_position(t_position),
  m_acceleration(t_position.size()),
  m_velocity(t_position.size()) {}

MassiveBody::MassiveBody(float t_mass, MathVector t_position, MathVector t_velocity) :
  m_mass(t_mass), m_position(t_position),
  m_acceleration(t_position.size()),
  m_velocity(t_velocity) {}

MassiveBody::MassiveBody(float t_mass, std::initializer_list<float> t_position) :
  m_mass(t_mass), m_position(t_position),
  m_acceleration(t_position.size()),
  m_velocity(t_position.size()) {}

MassiveBody::MassiveBody(
    float t_mass,
    std::initializer_list<float> t_position,
    std::initializer_list<float> t_velocity
    ) :
  m_mass(t_mass), m_position(t_position),
  m_acceleration(t_position.size()),
  m_velocity(t_velocity) {}

void MassiveBody::add_external_force(MathVector t_force) {
  m_forces.push(t_force);
}

void MassiveBody::add_attractor(MassiveBody* t_attractor_pointer) {
  m_attractors.push_back(t_attractor_pointer);
}

void MassiveBody::set_position(MathVector t_position) {
  m_position = t_position;
}

void MassiveBody::set_velocity(MathVector t_velocity) {
  m_velocity = t_velocity;
}

MathVector MassiveBody::get_velocity() {
  return m_velocity;
}

MathVector MassiveBody::get_position() {
  return m_position;
}

float MassiveBody::get_position(std::size_t t_dimension) {
  return m_position[t_dimension];
}

MathVector MassiveBody::calculate_acceleration() {
  MathVector resulting_forse(m_position.size());

  for(const auto& attractor : m_attractors) {
    MathVector attractor_position = attractor->m_position;
    float attractor_mass = attractor->m_mass;

    resulting_forse += (attractor_position - m_position).get_norm() *
      GRAVITY_CONST * m_mass * attractor_mass /
      (attractor_position - m_position).get_sqrabs();
  }

  while(!m_forces.empty()) {
    resulting_forse += m_forces.top();
    m_forces.pop();
  }

  m_acceleration = resulting_forse / m_mass;
  return m_acceleration;
}
