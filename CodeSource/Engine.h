/**
 *\file Engine.h
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 12:23
 */

#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>

const int SCREEN_HEIGHT = 960;
const int SCREEN_LENGHT = 640;

class Engine
{
public:

  static Engine*
  GetInstance ()
  {
    s_Intance = (s_Intance != nullptr) ? s_Intance : new Engine ();
    return s_Intance;
  }

  bool Init ();
  bool Clean ();
  void Quit ();

  void Update ();
  void Render ();
  void Events ();

  inline bool
  IsRunning ()
  {
    return m_IsRunning;
  }

  inline SDL_Renderer*
  GetRenderer ()
  {
    return m_Renderer;
  }

private:

  Engine () { }
  bool m_IsRunning;

  SDL_Window* m_Window;
  SDL_Renderer* m_Renderer;

  static Engine*s_Intance;
};




#endif /* ENGINE_H */

