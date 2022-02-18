/**
 *\file Vector2D.cpp
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 15:04
 */

#include "Vector2D.h"
#include <iostream>

using namespace std;


Vector2D::Vector2D (float p_x, float p_y) : m_X (p_x), m_Y (p_y) { }


void
Vector2D::Log (const std::string& p_msg)
{
  cout << p_msg << "(X, Y) = (" << m_X << ", " << m_Y << ")" << endl;
}


Vector2D Vector2D::operator+ (const Vector2D& p_v) const
{
  return Vector2D (m_X + p_v.m_X, m_Y + p_v.m_Y);
}


Vector2D Vector2D::operator- (const Vector2D& p_v) const
{
  return Vector2D (m_X - p_v.m_X, m_Y - p_v.m_Y);
}


Vector2D Vector2D::operator* (float p_scalar) const
{
  return Vector2D (m_X*p_scalar, m_Y * p_scalar);
}