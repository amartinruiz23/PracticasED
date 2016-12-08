
EventoHistorico(EventoHistorico &h){
  evento.first = h.evento.first;
  evento.second = h.evento.second;
}
EventoHistorico(pair<int, set<string> > &p){
  evento.first = p.firts;
  evento.second = p.second;
}

iterator begin(){
  iterator it;
  it = evento.second.begin();
  return it;
}

iterator end(){
  iteratir it;
  it = evento.second.end();
  return it;
}

const interator begin() const{
  iterator it;
  it = evento.second.begin();
  return it;
}

const interator end() const{
  iteratir it;
  it = evento.second.end();
  return it;
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
