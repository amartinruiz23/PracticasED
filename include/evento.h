#ifndef _EVENTO__
#define _EVENTO__
#include <string>

class evento{
  int anio;
  string *sucesos;

  public:

  evento();

  evento(evento e);

  ~evento();

  &evento operator=();

  int getanio(evento e);

  *string getsucesos(evento e); 

};
