#ifndef _EVENTO__
#define _EVENTO__
#include <string>

class evento{
  int anio;
  string *sucesos;

  public:

  evento();

  evento(const evento& e);

  ~evento();

  &evento operator=();

  int getanio(const evento& e);

  *string getsucesos(const evento& e); 

};

#endif
