#include "massive_body.h"

constexpr float MassiveBody::GRAVITY_CONST;

MassiveBody::MassiveBody(MathVector t_position, float t_mass) :
  m_mass(t_mass), m_position(t_position),
  m_acceleration(t_position.get_dimensionality()),
  m_velocity(t_position.get_dimensionality()) {};

void MassiveBody::add_external_force(MathVector t_force) {
  m_forces.push(t_force);
}

void MassiveBody::set_attractor(MassiveBody *t_attractor_p) {
  m_attractors.push_back(t_attractor_p);
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

MathVector MassiveBody::calculate_acceleration() {
  MathVector resulting_forse(m_position.get_dimensionality());
  std::list<MassiveBody*>::iterator iter;

  for(iter = m_attractors.begin(); iter != m_attractors.end(); iter++) {
    MathVector attractor_position = (*iter)->m_position;
    float attractor_mass = (*iter)->m_mass;

    resulting_forse += (attractor_position - m_position).norm() * 
      GRAVITY_CONST * m_mass * attractor_mass /
      (attractor_position - m_position).sqrabs();
  }

  // while(!m_forces.empty()) {
  //   resulting_forse += m_forces.top();
  //   m_forces.pop();
  // }

  m_acceleration = resulting_forse / m_mass;
  return m_acceleration;
}
