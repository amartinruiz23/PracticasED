#include "../include/eventohistorico.h"

typedef typename set<string>::iterator it;
typedef typename set<string>::const_iterator constit;

EventoHistorico::EventoHistorico(const EventoHistorico& h){
  evento.first = h.evento.first;
  evento.second = h.evento.second;
}
EventoHistorico::EventoHistorico(const pair<int, set<string> > &p){
  evento.first = p.first;
  evento.second = p.second;
}

EventoHistorico::EventoHistorico( EventoHistorico& e1, EventoHistorico& e2){
  set<string>::iterator it;

  evento.first = e1.evento.first;

  for(it = e1.begin(); it!= e1.end(); ++it){
    insertasuceso(*it);
  }

  for(it = e2.begin(); it!= e2.end(); ++it){
    insertasuceso(*it);
  }
}

it EventoHistorico::begin(){
  return (evento.second.begin());
}

it EventoHistorico::end(){
  return (evento.second.end());
}

constit EventoHistorico::begin() const{
  return(evento.second.begin());
}

constit EventoHistorico::end() const{
  return(evento.second.end());
}

int EventoHistorico::getanio(){
  return evento.first;
}

void EventoHistorico::setanio(int a){
  evento.first = a;
}

set<string> EventoHistorico::getsucesos(){
  return evento.second;
}

void EventoHistorico::insertasuceso(string s){
  evento.second.insert(s);
}

string EventoHistorico::buscasuceso (string& s) {
	set<string>::iterator it;

	for (it=evento.second.begin(); it!=evento.second.end(); ++it){
		if (s == *it)
			return *it;
	}

	s = "No está" ;

	return s ;
}

ostream& operator<<(ostream& os, EventoHistorico& e){
	set<string>::iterator it;
	os<<e.evento.first;

	for (it=e.evento.second.begin(); it!=e.evento.second.end(); ++it){
			os <<'#'<< *it;
	}

	return os;
}

istream& operator>>(istream& is, EventoHistorico& e){
  if (is) {
    is >> e.evento.first;

    bool primero = false ;
    string c ;

    while(is.peek() != '\n' && !is.eof()) {
      if (is.peek() == '#' && primero) {
        is.ignore();
        e.evento.second.insert(c);
        c = '\0' ;
      }
      else {
        if (is.peek() != '#'){
          c.push_back(is.get());
          primero = true ;
        }
        else
          is.ignore();
      }
    }

    e.evento.second.insert(c);

  }
  return is ;

}
