/**
 *\file GameObject.cpp
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 15:44
 */

#include "GameObject.h"


GameObject::GameObject (Properties* p_props) : m_TextureID (p_props->m_TextureID), m_Width (p_props->m_Width), m_Height (p_props->m_Height), m_Flip (p_props->m_Flip)
{
  m_Transform = new Transform (p_props->m_x, p_props->m_y);
}