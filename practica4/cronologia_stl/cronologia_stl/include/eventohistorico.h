#ifndef _EventoHistorico_H_
#define _EventoHistorico_H_

#include <string>
#include <utility>
#include <set>
#include <iostream>

using namespace std;

class EventoHistorico{
  pair<int, set<string> > evento;

public:
  EventoHistorico() = default;
  ~EventoHistorico() = default;
  EventoHistorico(const EventoHistorico& h);
  EventoHistorico(const pair<int, set<string> >& p);
  
  typedef typename set<string>::iterator it;
  typedef typename set<string>::const_iterator constit;

  it begin();
  it end();
  constit begin() const;
  constit end() const;

  int getanio();
  void setanio(int a);
  set<string> getsucesos();
  void insertasuceso(string& s);

  friend ostream& operator<<(ostream& os, EventoHistorico& e);
  friend istream& operator>>(istream& is, EventoHistorico& e);
};

#include "../src/eventohistorico.cpp"

#endif
