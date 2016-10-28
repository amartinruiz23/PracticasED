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

	for (i=0; i<eventos.size()-1 ; i++) {
		min = i ;
		for (j=i+1 ; j < eventos.size() ; j++)
			if (eventos[j].getanio() < min)
				min = j ;
		intercambia(eventos[i], eventos[min]);
	}
}

cronologia::cronologia(){} // Al tener solo un vector la clase, esta función es necesaria???

cronologia::cronologia(const cronologia& c){
  eventos = c.geteventos();
}

cronologia::~cronologia(){} //Igual que con constructor vacío

cronologia& cronologia::subcronologia(int anio_inicio, int anio_final=2017){
  cronologia devolver;
  for (int i = 0, i < eventos.size(), i++){
    if (eventos[i].getanio() >= anio_inicio && eventos[i].getanio() <= anio_final)
      devolver.aniadirevento(eventos[i]);
  }
  return devolver;
}

cronologia& cronologia::operator+(const cronologia& c){ //lolxd
  vector<int> noaniadir;
  for (int i = 0, i < c.eventos.size(), i++){
    for (int j = 0; j < eventos.size(), j++){
      if ( c.eventos[i] == eventos[j]{
        eventos[i] = c.eventos[i] + eventos[j];
        noaniadir.push_back(i);
      }
    }
	}
  ordenar();
  return *this;
}

void cronologia::eliminarevento (int anio){
    for (int i = 0, i < eventos.size(), i++){
      if (eventos[i].getanio() == anio)
        eventos.erase(i);
      
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
		for (int j = 0 ; j < eventos[i].sucesos.size() ; j++) {
			if (s == eventos[i].sucesos[j])
				devolver.eventos.push_back(eventos[i]);
		}
	}
	return devolver ;
}

vector<evento> cronologia::geteventos(){
  return eventos;
}
