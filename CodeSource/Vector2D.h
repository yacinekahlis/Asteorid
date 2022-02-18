/**
 *\file Vector2D.h
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 14:56
 */

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <string>

class Vector2D
{
public:
  Vector2D (float p_x = 0, float p_y = 0);

  float X ();
  float Y ();

  Vector2D operator+ (const Vector2D& p_v) const;

  Vector2D operator- (const Vector2D& p_v) const;

  Vector2D operator* (float p_scalar) const;

  void Log (const std::string& p_msg = "");

  float m_X;
  float m_Y;
};

#endif /* VECTOR2D_H */

