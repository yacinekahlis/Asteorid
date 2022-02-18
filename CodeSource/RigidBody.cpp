/**
 *\file RigidBody.cpp
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 19:40
 */

#include "RigidBody.h"
#include "Vector2D.h"


RigidBody::RigidBody () : m_mass (UNI_MASS), m_gravity (GRAVITY) { }


void
RigidBody::SetMass (float p_mass)
{
  m_mass = p_mass;
}


void
RigidBody::SetGravity (float p_gravity)
{
  m_gravity = p_gravity;
}


void
RigidBody::ApplyForce (const Vector2D& p_f)
{
  m_vForce = p_f;
}


void
RigidBody::ApplyForceX (float p_fx)
{
  m_vForce.m_X = p_fx;
}


void
RigidBody::ApplyForceY (float p_fy)
{
  m_vForce.m_Y = p_fy;
}


void
RigidBody::unSetForce ()
{
  m_vForce = Vector2D (0, 0);
}


void
RigidBody::ApplyFriction (const Vector2D& p_fr)
{
  m_vFriction = p_fr;
}


void
RigidBody::unSetFriction ()
{
  m_vFriction = Vector2D (0, 0);
}


void
RigidBody::Update (float p_deltaTime)
{
  m_vAcceleration.m_X = (m_vForce.m_X) / m_mass;
  m_vAcceleration.m_Y = m_gravity + (m_vForce.m_Y) / m_mass;
  m_vVelocity = m_vAcceleration*p_deltaTime;
  m_vPosition = m_vVelocity*p_deltaTime;
}


float
RigidBody::GetMass ()
{
  return m_mass;
}


Vector2D
RigidBody::Position ()
{
  return m_vPosition;
}


Vector2D
RigidBody::Velocity ()
{
  return m_vVelocity;
}


Vector2D
RigidBody::Acceleration ()
{
  return m_vAcceleration;
}
