#ifndef _EventoHistorico_H_
#define _EventoHistorico_H_

#include <string>
#include <pair>
#include <set>

using namespace std;

class EventoHistorico{
  pair<int, set<string> > evento;

public:
  EventoHistorico() = default;
  ~EventoHistorico() = default;
  EventoHistorico(EventoHistorico &h);
  EventoHistorico(pair<int, set<string> > &p);
  typedef typename set<string>::iterator it;
  typedef typename set<string>::const_iterator constit;

  it begin();
  it end();
  constit begin() const;
  constit end() const;

  int getanio();
  void setanio(int a);
  set<string> getsucesos();
  void insertasuceso(&string s);

};

#include "../src/eventohistorico.cpp"

#endif
