/**
 *\file Input.h
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 21:06
 */

#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

class Input
{
public:

  static Input*
  GetInstance ()
  {
    s_Intance = (s_Intance != nullptr) ? s_Intance : new Input ();
    return s_Intance;
  }
  void Listen ();
  bool GetKeyDown (SDL_Scancode p_key);


private:
  Input ();
  void KeyDown ();
  void KeyUp ();
  static Input* s_Intance;
  const Uint8* m_keyStates;

};

#endif /* INPUT_H */

