#include <iostream>
#include <stdexcept>
#include <cmath>
#include "math_vector.h"

MathVector::MathVector(std::vector<float> t_coordinates) :
  m_coordinates(t_coordinates) {};

MathVector::MathVector(int t_dimensions) :
  m_coordinates(t_dimensions, 0) {};

float MathVector::get_coordinate(int t_coordinate_num) const {
  return m_coordinates.at(t_coordinate_num);
}

std::vector<float> MathVector::get_std_vector() const {
  return m_coordinates;
}

short MathVector::get_dimensionality() const {
  return m_coordinates.size();
}

float MathVector::abs() {
  return sqrt(sqrabs());
}

float MathVector::sqrabs() {
  float result = 0;
  for(int i = 0; i < m_coordinates.size(); i++) {
    float component = m_coordinates.at(i);
    result += component * component;
  }
  return result;
}

MathVector MathVector::norm() {
  return *this / abs();
}

MathVector MathVector::operator+(const MathVector& t_operand) {
  if(m_coordinates.size() != t_operand.get_dimensionality()) {
    throw std::out_of_range("Dimensionality mismatch!");
  }
  decltype(m_coordinates) new_vector;

  for(int i = 0; i < m_coordinates.size(); i++) {
    new_vector.push_back(m_coordinates.at(i) + t_operand.get_coordinate(i));
  }
  return MathVector(new_vector);
}

MathVector MathVector::operator-(const MathVector& t_operand) {
  if(m_coordinates.size() != t_operand.get_dimensionality()) {
    throw std::out_of_range("Dimensionality mismatch!");
  }
  decltype(m_coordinates) new_vector;

  for(int i = 0; i < m_coordinates.size(); i++) {
    new_vector.push_back(m_coordinates.at(i) - t_operand.get_coordinate(i));
  }
  return MathVector(new_vector);
}

MathVector MathVector::operator/(const float& t_operand) {
  decltype(m_coordinates) new_vector;

  for(int i = 0; i < m_coordinates.size(); i++) {
    new_vector.push_back(m_coordinates.at(i) / t_operand);
  }
  return MathVector(new_vector);
}

MathVector MathVector::operator*(const float& t_operand) {
  decltype(m_coordinates) new_vector;

  for(int i = 0; i < m_coordinates.size(); i++) {
    new_vector.push_back(m_coordinates.at(i) * t_operand);
  }
  return MathVector(new_vector);
}

MathVector MathVector::operator+=(const MathVector& t_operand) {
  if(m_coordinates.size() != t_operand.get_dimensionality()) {
    throw std::out_of_range("Dimensionality mismatch!");
  }

  for(int i = 0; i < m_coordinates.size(); i++) {
    m_coordinates.at(i) += t_operand.get_coordinate(i);
  }
  return *this;
}
