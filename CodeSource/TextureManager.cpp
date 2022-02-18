/*
 * File:   TextureManager.cpp
 * Author: Yacine Kahlis
 *
 * Created on 16 décembre 2021, 13:44
 */

#include "TextureManager.h"
#include "Engine.h"
#include <SDL_image.h>
#include <cstring>
#include <string>
#include <iterator>

TextureManager* TextureManager::s_Instance = nullptr;


bool
TextureManager::Load (const std::string& p_id, const std::string& p_fileName)
{
  SDL_Surface* surface = IMG_Load (p_fileName.c_str ());
  if (surface == nullptr)
    {
      SDL_Log ("Failed to load texture...");
      return false;
    }

  SDL_Texture* texture = SDL_CreateTextureFromSurface (Engine::GetInstance ()->GetRenderer (), surface);
  if (texture == nullptr)
    {
      SDL_Log ("Failed to create texture from surface...");
      return false;
    }

  m_TextureMap[p_id] = texture;
  return true;
}


void
TextureManager::Drop (const std::string& p_id)
{
  SDL_DestroyTexture (m_TextureMap[p_id]);
  m_TextureMap.erase (p_id);
}


void
TextureManager::Clean ()
{
  std::map<std::string, SDL_Texture*>::iterator it;
  for (it = m_TextureMap.begin (); it != m_TextureMap.end (); it++)
    SDL_DestroyTexture (it->second);

  m_TextureMap.clear ();
  SDL_Log ("Texture map cleaned...");
}


void
TextureManager::Draw (const std::string& p_id, int p_x, int p_y, int p_width, int p_height, SDL_RendererFlip p_flip)
{
  SDL_Rect srcRect = {0, 0, p_width, p_height};
  SDL_Rect dstRect = {p_x, p_y, p_width, p_height};
  SDL_RenderCopyEx (Engine::GetInstance ()->GetRenderer (), m_TextureMap[p_id], &srcRect, &dstRect, 0, nullptr, p_flip);
}


void
TextureManager::DrawFrame (const std::string& p_id, int p_x, int p_y, int p_width, int p_height, int p_row, int p_frame, SDL_RendererFlip p_flip)
{
  SDL_Rect srcRect = {p_width*p_frame, p_height * (p_row - 1), p_width, p_height};
  SDL_Rect dstRect = {p_x, p_y, p_width, p_height};
  SDL_RenderCopyEx (Engine::GetInstance ()->GetRenderer (), m_TextureMap[p_id], &srcRect, &dstRect, 0, nullptr, p_flip);
}
