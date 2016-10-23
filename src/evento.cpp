#include <iostream>

// DUDA -> sintaxis -> std::const vector<string>& s ???????????????

evento::evento(){
	anio = 0;
}

evento::evento(int a, std::const vector<string>& s){
	anio = a ;
	sucesos = s ;
}


evento::evento(std::const evento<string>& e){
	anio = e.getanio();
	sucesos = e.getsucesos();
}

evento::~evento(){
	anio = 0;
	~sucesos; // ??? Sobra ???
}

&evento evento::operator=(std::evento<string>& e){
	anio = e.getanio();
	sucesos = e.getsucesos();
	return *this; 
}

bool operator==(std::const evento<string>& e){
	if (anio == e.getanio() && sucesos == e.getsucesos())
		return true ;
	else
		return false ;
}

bool operator>(std::const evento<string>& e){
	if (anio > e.getanio())
		return true ;
	else 
		return false ;
}

bool operator<(std::const evento<string>& e){
	if (anio < e.getanio())
		return true ;
	else
		return false ;
}

int evento::getanio(std::const evento<string>& e){
	return anio;
}

const vector& evento::getsucesos(std::const evento<string>& e){ // TIPO DE DATO DEVUELTO
	return sucesos;
}

string evento::getsuceso(std::const evento<string>& e, int n){
	return sucesos.at(n); //at devuelve una referencia al elemento en la posición indicada del vector. Lanza excepción si fuera de rango.
}

void evento::insertasuceso(string s, int p){ // string const ???????
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

std::istream& operator>>(std::istream& s , std::evento<string>& e) {
	if (s) {
		s >> e.anio ;
		s >> e.sucesos ;
	}

	return s ;
}

std::ostream& operator<<(std::ostream& s , std::const evento<string>& e) {
	s << e.anio ;
	s << '\t' ;
	s << e.sucesos ;

	return s ;
}