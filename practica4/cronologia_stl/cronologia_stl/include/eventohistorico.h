#ifndef _EventoHistorico_H_
#define _EventoHistorico_H_

#include <string>
#include <pair>
#include <set>

using namespace std;

class EventoHistorico{
  pair<int, set<string>> evento;

public:

  typedef typename set<string>::iterator iterator;
  typedef typename set<string>::const_iterator const_iterator;

  iterator begin();
  iterator end();
  const interator begin() const;
  const interator end() const;
  iterator& operator ++();
  iterator& operator --();
  iterator& operator *();

  int getanio();
  void setanio(int a);
  set<string> getsucesos();
  void insertasuceso(&string s);

};

#endif
