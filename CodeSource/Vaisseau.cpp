/**
 *\file Vaisseau.cpp
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 16:10
 */

#include "Vaisseau.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Input.h"


Vaisseau::Vaisseau (Properties* p_props) : Character (p_props)
{
  m_rigidBody = new RigidBody ();
  m_rigidBody->SetGravity (2);
  m_animation = new Animation ();
  m_animation->SetProps (m_TextureID, 1, 6, 100);
}


void
Vaisseau::Draw ()
{
  m_animation->Draw (m_Transform->m_X, m_Transform->m_Y, m_Width, m_Height);
}


void
Vaisseau::Update (float p_deltaTime)
{

  m_animation->SetProps ("player", 1, 6, 100);
  m_rigidBody->unSetForce ();
  m_rigidBody->ApplyForceY (-10);

  if (Input::GetInstance ()->GetKeyDown (SDL_SCANCODE_W))
    {
      m_rigidBody->ApplyForceY (-20);
      m_animation->SetProps ("player_run", 1, 6, 100);
    }

  if (Input::GetInstance ()->GetKeyDown (SDL_SCANCODE_S))
    {
      m_rigidBody->ApplyForceY (20);
      m_animation->SetProps ("player", 1, 6, 100);
    }

  if (Input::GetInstance ()->GetKeyDown (SDL_SCANCODE_D))
    {
      m_rigidBody->ApplyForceX (10);
      m_animation->SetProps ("player_run", 1, 6, 100);
    }

  if (Input::GetInstance ()->GetKeyDown (SDL_SCANCODE_A))
    {
      m_rigidBody->ApplyForceX (-10);
      m_rigidBody->ApplyForceX (-5);
      m_animation->SetProps ("player_run", 1, 6, 100);
    }

  m_rigidBody->Update (0.2);

  m_Transform->TranslateX (m_rigidBody->Position ().m_X);
  m_Transform->TranslateY (m_rigidBody->Position ().m_Y);

  m_animation->Update ();
}


void
Vaisseau::Clean ()
{
  TextureManager::GetInstance ()->Clean ();
}
