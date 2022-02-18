/**
 *\file Character.h
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 16:04
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObject.h"
#include <string>

class Character : public GameObject
{
public:

  Character (Properties* p_props) : GameObject (p_props) { }

  virtual void Draw () = 0;
  virtual void Update (float p_deltaTime) = 0;
  virtual void Clean () = 0;

protected:
  std::string m_name;

};

#endif /* CHARACTER_H */

