#include <list>
#include <stack>
#include "math_vector.h"

class MassiveBody {
  public:
    MassiveBody(MathVector t_position, float t_mass);
    void add_external_force(MathVector t_force);
    void set_attractor(MassiveBody *t_attractor);
    MathVector calculate_acceleration();
    void set_position(MathVector t_position);
    void set_velocity(MathVector t_velocity);
    MathVector get_velocity();
    MathVector get_position();
  protected:
    float m_mass;
    MathVector m_position;
  private:
    static constexpr float GRAVITY_CONST = 1;
    std::list<MassiveBody*> m_attractors;
    float m_get_gravity_force();
    std::stack<MathVector> m_forces;
    MathVector m_acceleration;
    MathVector m_velocity;
};
