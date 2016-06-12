#include <initializer_list>
#include "massive_body.h"
#include "graphical_reflection.h"

class MassiveBodyController {
  public:
    MassiveBodyController(MassiveBody& t_body,
        std::initializer_list<MassiveBody*> t_attractors,
        GraphicalReflection& t_reflection);
    void add_attractor(MassiveBody* t_attractor);
    void move_body();
    void draw_body();
  private:
    GraphicalReflection& m_reflection;
    MassiveBody& m_body;
    std::list<MassiveBody*> m_attractors;
};
