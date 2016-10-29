#include "cronologia.h"
#include "evento.h"
#include <string>
#include <vector>
using namespace std;

void cronologia::intercambia (evento& e1 , evento& e2) {
	evento aux = e1 ;
	e1 = e2 ;
	e2 = aux ;
}

void cronologia::ordenar(){
	int i , j , min ;

	for (i=0; i< eventos.size()-1 ; i++) {
		min = i ;
		for (j=i+1 ; j < eventos.size() ; j++)
			if (eventos[j].getanio() < min)
				min = j ;
		intercambia(eventos[i], eventos[min]);
	}
}

cronologia cronologia::subcronologia(int anio_inicio, int anio_final){
  cronologia devolver;
  for (int i = 0; i < eventos.size(); i++){
    if (eventos[i].getanio() >= anio_inicio && eventos[i].getanio() <= anio_final)
      devolver.aniadirevento(eventos[i]);
  }
  return devolver;
}

cronologia& cronologia::operator+(const cronologia& c){
	cronologia nueva;
	for (int i = 0; i < c.eventos.size(); i++){
		nueva.eventos.push_back(c.eventos[i]);
	}
	for (int i = 0; i < eventos.size(); i++){
		nueva.eventos.push_back(eventos[i]);
	}

	nueva.ordenar();

	int i = 0;
	while(i+1 < nueva.eventos.size()){
		if (nueva.eventos[i] == nueva.eventos[i+1]){
			nueva.eventos[i] = nueva.eventos[i]+nueva.eventos[i+1];
			i--;
		}
		i++;
	}
  return nueva;
}

vector<string> cronologia::GetEventos(int anio){
	vector<string> devolver;
	for (int i = 0; i < eventos.size(); i++){
		if(eventos[i].getanio() == anio){
			for (int j = 0; j < eventos[i].CuantosSucesos(); j++){
				devolver.push_back(eventos[i].getsuceso(j));
			}
		}
	}
}

void cronologia::eliminarevento (int anio){
    for (int i = 0; i < eventos.size(); i++){
      if (eventos[i].getanio() == anio)
        eventos.erase(eventos.begin()+i);

    }
}

void cronologia::aniadirevento (evento& e){
	eventos.push_back(e);
}

evento& cronologia::buscaevento (int anio){
  evento vacio;
  for (int i = 0; i < eventos.size(); i++){
    if(eventos[i].getanio() == anio)
      return eventos[i];
  }
  return vacio;
}

cronologia& cronologia::buscaevento (const string& s){
	cronologia devolver ;

	for (int i = 0 ; i < eventos.size() ; i++) {
		for (int j = 0 ; j < eventos[i].CuantosSucesos() ; j++) {
			if (s == eventos[i].getsuceso(j))
				devolver.eventos.push_back(eventos[i]);
		}
	}
	return devolver ;
}

vector<evento> cronologia::geteventos(){
  return eventos;
}

istream& operator>>(istream& s, cronologia& c) {
	if (s) {
		for (int i = 0 ; i < c.eventos.size() ; i++)
			s >> c.eventos[i];
	}
	return s ;
}

ostream& operator<<(ostream& s, const cronologia& c){
	for (int i = 0 ; i < c.eventos.size() ; i++)
		s << c.eventos[i];

	return s ;
}
