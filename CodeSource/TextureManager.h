/*
 * File:   TextureManager.h
 * Author: Yacine Kahlis
 *
 * Created on 16 décembre 2021, 13:44
 */

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <map>
#include <SDL.h>

class TextureManager
{
public:

  static TextureManager*
  GetInstance ()
  {
    s_Instance = (s_Instance != nullptr) ? s_Instance : new TextureManager ();
    return s_Instance;
  }

  bool Load (const std::string& p_id, const std::string& p_fileName);
  void Drop (const std::string& p_id);
  void Clean ();

  void
  Draw (const std::string& p_id, int p_x, int p_y, int p_width, int p_height, SDL_RendererFlip p_flip = SDL_FLIP_NONE);

  void
  DrawFrame (const std::string& p_id, int p_x, int p_y, int p_width, int p_height, int p_row, int p_frame, SDL_RendererFlip p_flip = SDL_FLIP_NONE);

private:
  std::map<std::string, SDL_Texture*> m_TextureMap;

  TextureManager () { }
  static TextureManager* s_Instance;

};

#endif /* TEXTUREMANAGER_H */

