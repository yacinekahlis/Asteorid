/**
 *\file Engine.cpp
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 12:28
 */

#include "Engine.h"
#include <iostream>
#include <SDL_image.h>
#include "TextureManager.h"
#include "Vaisseau.h"
#include "Input.h"

Engine* Engine::s_Intance = nullptr;
Vaisseau* player = nullptr;


bool
Engine::Init ()
{
  if (SDL_Init (SDL_INIT_EVERYTHING) != 0)
    {
      SDL_Log ("Failed to initialize SDL...");
      return false;
    }

  m_Window = SDL_CreateWindow ("Asteroid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_LENGHT, 0);

  if (m_Window == nullptr)
    {
      SDL_Log ("Failed to create the window...");
      return false;
    }

  m_Renderer = SDL_CreateRenderer (m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (m_Renderer == nullptr)
    {
      SDL_Log ("Failed to create the Renderer...");
      return false;
    }

  TextureManager::GetInstance ()->Load ("player", "V.png");
  TextureManager::GetInstance ()->Load ("player_run", "AVF.png");
  player = new Vaisseau (new Properties ("player_run", 480, 310, 32, 32));

  m_IsRunning = true;
  return m_IsRunning;
}


bool
Engine::Clean ()
{
  TextureManager::GetInstance ()->Clean ();
  SDL_DestroyRenderer (m_Renderer);
  SDL_DestroyWindow (m_Window);
  IMG_Quit ();
  SDL_Quit ();

}


void
Engine::Quit ()
{
  m_IsRunning = false;
}


void
Engine::Update ()
{
  player->Update (0);
}


void
Engine::Render ()
{
  SDL_SetRenderDrawColor (m_Renderer, 124, 218, 254, 255);
  SDL_RenderClear (m_Renderer);

  player->Draw ();
  SDL_RenderPresent (m_Renderer);
}


void
Engine::Events ()
{
  Input::GetInstance ()->Listen ();
}
