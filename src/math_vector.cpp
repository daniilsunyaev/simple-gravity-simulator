#include <iostream>
#include <stdexcept>
#include <cmath>
#include "math_vector.h"

MathVector::MathVector(std::vector<float> t_coordinates) :
  m_coordinates(t_coordinates) {};

MathVector::MathVector(std::size_t t_dimensions) :
  m_coordinates(t_dimensions, 0) {};

std::size_t MathVector::size() const {
  return m_coordinates.size();
}

float MathVector::get_abs() const {
  return sqrt(get_sqrabs());
}

float MathVector::get_sqrabs() const {
  float result = 0;
  for(std::size_t i = 0; i < m_coordinates.size(); i++) {
    float component = m_coordinates.at(i);
    result += component * component;
  }
  return result;
}

MathVector MathVector::get_norm() const {
  return *this / get_abs();
}

MathVector MathVector::operator+(const MathVector& t_operand) const {
  if(m_coordinates.size() != t_operand.size()) {
    throw std::out_of_range("Dimensionality mismatch!");
  }
  decltype(m_coordinates) new_vector;

  for(std::size_t i = 0; i < m_coordinates.size(); i++) {
    new_vector.push_back(m_coordinates.at(i) + t_operand[i]);
  }
  return MathVector(new_vector);
}

MathVector MathVector::operator-(const MathVector& t_operand) const {
  if(m_coordinates.size() != t_operand.size()) {
    throw std::out_of_range("Dimensionality mismatch!");
  }
  decltype(m_coordinates) new_vector;

  for(std::size_t i = 0; i < m_coordinates.size(); i++) {
    new_vector.push_back(m_coordinates.at(i) - t_operand[i]);
  }
  return MathVector(new_vector);
}

MathVector MathVector::operator/(const float& t_operand) const {
  decltype(m_coordinates) new_vector;

  for(std::size_t i = 0; i < m_coordinates.size(); i++) {
    new_vector.push_back(m_coordinates.at(i) / t_operand);
  }
  return MathVector(new_vector);
}

MathVector MathVector::operator*(const float& t_operand) const {
  decltype(m_coordinates) new_vector;

  for(std::size_t i = 0; i < m_coordinates.size(); i++) {
    new_vector.push_back(m_coordinates.at(i) * t_operand);
  }
  return MathVector(new_vector);
}

MathVector MathVector::operator+=(const MathVector& t_operand) {
  if(m_coordinates.size() != t_operand.size()) {
    throw std::out_of_range("Dimensionality mismatch!");
  }

  for(std::size_t i = 0; i < m_coordinates.size(); i++) {
    m_coordinates.at(i) += t_operand[i];
  }
  return *this;
}

float MathVector::operator[](std::size_t t_dimension) const {
  return m_coordinates.at(t_dimension);
}
