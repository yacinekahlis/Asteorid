/**
 *\file Animation.h
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 17:50
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include <SDL.h>

class Animation
{
public:
  Animation ();

  void Update ();
  void Draw (float p_x, float p_y, int p_spriteWidth, int p_spiteHeight);
  void SetProps (const std::string& p_textureID, int p_sprietRow, int p_frameCount, int p_animSpeed, SDL_RendererFlip p_flip = SDL_FLIP_NONE);

private:
  int m_spriteRow, m_spriteFrame;
  int m_animSpeed, m_frameCount;
  std::string m_textureID;
  SDL_RendererFlip m_flip;
};

#endif /* ANIMATION_H */

