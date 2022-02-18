/**
 *\file RigidBody.h
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 19:40
 */

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Vector2D.h"

const float UNI_MASS = 1.0;
const float GRAVITY = 9.8;

class RigidBody
{
public:
  RigidBody ();

  void SetMass (float p_mass);
  float GetMass ();
  Vector2D Position ();
  Vector2D Velocity ();
  Vector2D Acceleration ();

  void SetGravity (float p_gravity);

  void ApplyForce (const Vector2D& p_f);
  void ApplyForceX (float p_fx);
  void ApplyForceY (float p_fy);
  void unSetForce ();

  void ApplyFriction (const Vector2D& p_fr);
  void unSetFriction ();

  void Update (float p_deltaTime);

private:
  float m_mass;
  float m_gravity;

  Vector2D m_vForce;
  Vector2D m_vFriction;

  Vector2D m_vPosition;
  Vector2D m_vVelocity;
  Vector2D m_vAcceleration;
};


#endif /* RIGIDBODY_H */

