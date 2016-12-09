
EventoHistorico(EventoHistorico &h){
  evento.first = h.evento.first;
  evento.second = h.evento.second;
}
EventoHistorico(pair<int, set<string> > &p){
  evento.first = p.first;
  evento.second = p.second;
}

it begin(){
  return (evento.second.begin());
}

it end(){
  return (evento.second.end());
}

constit begin() const{
  return(evento.second.cbegin());
}

constit end() const{
  return(evento.second.cend());
}

int getanio(){
  return evento.first;
}

void setanio(int a){
  evento.first = a;
}

set<string> getsucesos(){
  return evento.first;
}

void insertasuceso(&string s){
  evento.second.insert(s);
}

ostream &operator <<(ostream& os, EventoHistorico& e){
	set<string>::iterator it;
	os<<e.evento.first;

	for (it=e.evento.second.begin(); it!=e.evento.second.end(); ++it){
			os <<'#'<< *it;
	}

	return os;
}

istream &operator >>(istream& is, EventoHIstorico& e){
  if (is) {
    is >> e.evento.first;

    bool primero = false ;
    string c ;

    while(is.peek() != '\n' && !is.eof()) {
      if (s.peek() == '#' && primero) {
        s.ignore();
        e.evento.second.insert(c);
        c = '\0' ; // ?????
      }
      else {
        if (s.peek() != '#'){
          c.push_back(s.get());
          primero = true ;
        }
        else
          s.ignore();
      }
    }

    e.evento.second.insert(c);

  }
  return is ;
}
