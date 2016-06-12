#include <initializer_list>
#include "massive_body.h"
#include "massive_body_controller.h"
#include "graphical_reflection.h"

MassiveBodyController::MassiveBodyController(MassiveBody& t_body,
    std::initializer_list<MassiveBody*> t_attractors,
    GraphicalReflection& t_reflection) :
  m_reflection(t_reflection), m_body(t_body), m_attractors(t_attractors) {}

void MassiveBodyController::add_attractor(MassiveBody* t_attractor_pointer) {
  m_attractors.push_back(t_attractor_pointer);
}

void MassiveBodyController::move_body() {
  m_body.set_position(m_body.get_position() + m_body.get_velocity());
  m_body.set_velocity(m_body.get_velocity() + m_body.calculate_acceleration(m_attractors));
}

void MassiveBodyController::draw_body() {
  m_reflection.draw(m_body.get_position());
}
