/**
 *\file Animation.cpp
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 17:50
 */
#include "Animation.h"
#include "TextureManager.h"


Animation::Animation () { }


void
Animation::Update ()
{
  m_spriteFrame = (SDL_GetTicks () / m_animSpeed) % m_frameCount;
}


void
Animation::Draw (float p_x, float p_y, int p_spriteWidth, int p_spiteHeight)
{
  TextureManager::GetInstance ()->DrawFrame (m_textureID, p_x, p_y, p_spriteWidth, p_spiteHeight, m_spriteRow, m_spriteFrame, m_flip);
}


void
Animation::SetProps (const std::string& p_textureID, int p_spriteRow, int p_frameCount, int p_animSpeed, SDL_RendererFlip p_flip )
{
  m_textureID = p_textureID;
  m_spriteRow = p_spriteRow;
  m_frameCount = p_frameCount;
  m_animSpeed = p_animSpeed;
  m_flip = p_flip;
}