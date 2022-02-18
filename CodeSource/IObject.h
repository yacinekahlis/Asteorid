/**
 *\file IObject.h
 * \brief
 * \author Yacine Kahlis
 *\date 16 décembre 2021, 15:40
 */

#ifndef IOBJECT_H
#define IOBJECT_H

class IObject
{
public:
  virtual void Draw () = 0;
  virtual void Update (float p_deltaTime) = 0;
  virtual void Clean () = 0;

};

#endif /* IOBJECT_H */

