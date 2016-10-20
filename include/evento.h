#ifndef _EVENTO__
#define _EVENTO__
#include <string>
#include <vector>
#include <iostream>

class evento{
  int anio;
  vector<string> sucesos;

  public:

  evento();

  evento(const evento& e);

  ~evento();

  &evento operator=();

  int getanio(const evento& e);

  string getsucesos(const evento& e);

  string getsuceso(const evemto& e, int n);

};

#endif
