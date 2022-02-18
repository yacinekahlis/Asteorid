/**
 *\file Transform.cpp
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 15:28
 */

#include "Transform.h"
#include "Vector2D.h"
#include <iostream>

using namespace std;


Transform::Transform (float p_x, float p_y) : m_X (p_x), m_Y (p_y) { }


void
Transform::TranslateX (float p_x)
{
  m_X += p_x;
}


void
Transform::TranslateY (float p_y)
{
  m_Y += p_y;
}


void
Transform::Translate (const Vector2D& p_v)
{
  m_X += p_v.m_X;
  m_Y += p_v.m_Y;
}


void
Transform::Log (const std::string& p_msg)
{
  cout << p_msg << "(X, Y) = (" << m_X << ", " << m_Y << ")" << endl;
}