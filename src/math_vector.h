#include <vector>

struct MathVector {
  MathVector(std::vector<float> t_coordinates);
  MathVector(std::size_t t_dimensions);
  //std::vector<float> get_std_vector() const;
  std::size_t size() const;
  //short get_dimensionality() const;
  float get_abs() const;
  float get_sqrabs() const;
  MathVector get_norm() const;
  MathVector operator+(const MathVector& t_operand) const;
  MathVector operator-(const MathVector& t_operand) const;
  MathVector operator/(const float& t_operand) const;
  MathVector operator*(const float& t_operand) const;
  MathVector operator+=(const MathVector& t_operand);
  float operator[](std::size_t t_dimension) const;

  std::vector<float> m_coordinates;
};
