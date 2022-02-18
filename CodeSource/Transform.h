/**
 *\file Transform.h
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 15:28
 */

#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "Vector2D.h"

class Transform
{
public:

  float m_X, m_Y;

  Transform (float p_x = 0, float p_y = 0);

  void TranslateX (float p_x);
  void TranslateY (float p_y);
  void Translate (const Vector2D& p_v);

  void Log (const std::string& p_msg = "");

};

#endif /* TRANSFORM_H */

