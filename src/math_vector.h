#include <vector>

class MathVector {
  public:
    MathVector(std::vector<float> t_coordinates);
    MathVector(int t_dimensions);
    float get_coordinate(int t_coordinate_num) const;
    std::vector<float> get_std_vector() const;
    short get_dimensionality() const;
    float abs();
    float sqrabs();
    MathVector norm();
    MathVector operator+(const MathVector& t_operand);
    MathVector operator-(const MathVector& t_operand);
    MathVector operator/(const float& t_operand);
    MathVector operator*(const float& t_operand);
    MathVector operator+=(const MathVector& t_operand);
  private:
    std::vector<float> m_coordinates;
};
