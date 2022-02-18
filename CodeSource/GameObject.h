/**
 *\file GameObject.h
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 15:44
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "IObject.h"
#include "Transform.h"
#include <string>
#include <SDL.h>

struct Properties
{
public:

  Properties (const std::string& p_textureID, int p_x, int p_y, int p_width, int p_height, SDL_RendererFlip p_flip = SDL_FLIP_NONE)
  {
    m_x = p_x;
    m_y = p_y;
    m_Flip = p_flip;
    m_Height = p_height;
    m_Width = p_width;
    m_TextureID = p_textureID;
  }

public:
  float m_x, m_y;
  int m_Width, m_Height;
  std::string m_TextureID;
  SDL_RendererFlip m_Flip;

};

class GameObject : public IObject
{
public:
  GameObject (Properties* p_props);

  virtual void Draw () = 0;
  virtual void Update (float p_deltaTime) = 0;
  virtual void Clean () = 0;

protected:
  Transform* m_Transform;
  int m_Width, m_Height;
  std::string m_TextureID;
  SDL_RendererFlip m_Flip;
};

#endif /* GAMEOBJECT_H */

