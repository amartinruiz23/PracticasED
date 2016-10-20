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

  vector getsucesos(const evento& e);

  string getsuceso(const evento& e, int n);

  void aniadesuceso(string s);

  void eliminasuceso(int n);

};

#endif
