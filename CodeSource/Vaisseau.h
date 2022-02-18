/**
 *\file Vaisseau.h
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 16:07
 */

#ifndef VAISSEAU_H
#define VAISSEAU_H

#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"

class Vaisseau : public Character
{
public:

  Vaisseau (Properties* p_props);
  virtual void Draw ();
  virtual void Update (float p_deltaTime);
  virtual void Clean ();

private:
  RigidBody* m_rigidBody;
  Animation* m_animation;
};

#endif /* VAISSEAU_H */

