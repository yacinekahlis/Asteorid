/**
 *\file Input.cpp
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 21:06
 */

#include "Input.h"
#include "Engine.h"


Input* Input::s_Intance = nullptr;


Input::Input ()
{
  m_keyStates = SDL_GetKeyboardState (nullptr);
}


void
Input::Listen ()
{
  SDL_Event event;

  while (SDL_PollEvent (&event))
    {
      switch (event.type)
        {
          case SDL_QUIT:
            Engine::GetInstance ()->Quit ();
            break;

          case SDL_KEYDOWN:
            KeyDown ();
            break;

          case SDL_KEYUP:
            KeyUp ();
            break;
        }
    }
}


bool
Input::GetKeyDown (SDL_Scancode p_key)
{
  if (m_keyStates[p_key] == 1)
    {
      return true;
    }
  return false;
}


void
Input::KeyDown ()
{
  m_keyStates = SDL_GetKeyboardState (nullptr);
}


void
Input::KeyUp ()
{
  m_keyStates = SDL_GetKeyboardState (nullptr);
}