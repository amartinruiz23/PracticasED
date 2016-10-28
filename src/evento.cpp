#include <iostream>
#include <vector>
#include <string>
#include "evento.h"
using namespace std;

evento::evento(){
	anio = 0;
}

evento::evento(int a, const vector<string>& s){
	anio = a ;
	sucesos = s ;
}


evento::evento(const evento& e){
	anio = e.anio;
	sucesos = e.sucesos;
}

evento::~evento(){
	anio = 0;
}

evento& evento::operator=(const evento& e){
	if (this != &e) {
		anio = e.anio;
		sucesos = e.sucesos;
	}

	return *this;
}

bool evento::operator==(const evento& e){
	if (anio == e.anio && sucesos == e.sucesos)
		return true ;
	else
		return false ;
}

bool evento::operator>(const evento& e){
	if (anio > e.anio)
		return true ;
	else
		return false ;
}

bool evento::operator<(const evento& e){
	if (anio < e.anio)
		return true ;
	else
		return false ;
}

int evento::getanio(){
	return anio;
}

string& evento::getsuceso(int n){
	return sucesos.at(n); //at devuelve una referencia al elemento en la posición indicada del vector. Lanza excepción si fuera de rango.
}

void evento::insertasuceso(string s){
	sucesos.push_back(s);
}

void evento::eliminasuceso(int n){
	sucesos.erase(sucesos.begin()+n);
}

bool evento::eliminasuceso(const string& s) {
	for (int i = 0 ; i < sucesos.size() ; i++) {
		if (sucesos[i] == s)
			sucesos.erase(sucesos.begin()+i) ;
			return true ;
	}

	return false ;
}

evento& evento::operator+(const evento& e){
	for (int i=0; i < e.sucesos.size(); i++){
		sucesos.push_back(e.sucesos[i]);
	}
	return *this;
}

istream& operator>>(istream& s , evento& e) {
	if (s) {
		s >> e.anio ;

		bool primero = false ;
		string c ;

		while(s.peek() != '\n') {
			if (s.peek() == '#' && primero) {
				s.ignore();
				e.sucesos.push_back(c);
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

		e.sucesos.push_back(c);


	return s ;
	}
}

ostream& operator<<(ostream& s , const evento& e) {
	s << e.anio ;
	for (int i = 0 ; i < e.sucesos.size() ; i++)
		s << '#' << e.sucesos[i];

	return s ;
}
