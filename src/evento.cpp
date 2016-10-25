#include <iostream>
#include <vector>
#include <string>

// DUDA -> sintaxis -> std::const vector<string>& s ???????????????

evento::evento(){
	anio = 0;
}

evento::evento(int a, std::const vector<string>& s){
	anio = a ;
	sucesos = s ;
}


evento::evento(const evento& e){
	anio = e.getanio();
	sucesos = e.getsucesos();
}

evento::~evento(){
	anio = 0;
	~sucesos; // ??? Sobra ???
}

&evento evento::operator=(const evento& e){
	if (*this != e) {	
		anio = e.getanio();
		sucesos = e.getsucesos();		
	}

	return *this; 
}	

bool evento::operator==(const evento& e){
	if (anio == e.getanio() && sucesos == e.getsucesos())
		return true ;
	else
		return false ;
}

bool evento::operator>(const evento& e){
	if (anio > e.getanio())
		return true ;
	else 
		return false ;
}

bool evento::operator<(const evento& e){
	if (anio < e.getanio())
		return true ;
	else
		return false ;
}

int evento::getanio(const evento& e){
	return anio;
}

const vector& evento::getsucesos(const evento& e){ 
	return sucesos;
}

vector& evento::getsucesos(const evento& e){ 
	return sucesos;
}

const string& evento::getsuceso(const evento& e, int n){
	return sucesos.at(n); //at devuelve una referencia al elemento en la posición indicada del vector. Lanza excepción si fuera de rango.
}

string& evento::getsuceso(const evento& e, int n){
	return sucesos.at(n); //at devuelve una referencia al elemento en la posición indicada del vector. Lanza excepción si fuera de rango.
}

void evento::insertasuceso(const string s, int p){ 
	sucesos.insert(p-1, s);
}

void evento::eliminasuceso(int n){
	suceso.erase(n-1);

bool evento::eliminasuceso(const string& s) {
	for (int i = 0 ; i < vector.size() ; i++) {
		if (sucesos[i] == s)
			sucesos.erase(i) ;
			return true ;
	}

	return false ;
}

std::istream& operator>>(std::istream& s , evento& e) {
	if (s) {
		s >> e.anio ;
		
		int i = 0 ;					// ??????????????????
		while (
		s >> e.sucesos ;
	}

	return s ;
}

std::ostream& operator<<(std::ostream& s , const evento& e) {
	s << e.anio ;
	s << '\t' ;
	s << e.sucesos ; // ?????????

	return s ;
}
