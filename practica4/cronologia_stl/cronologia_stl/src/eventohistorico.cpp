
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
