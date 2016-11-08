#include "pila_max_vd.h"

Pila_max::Pila_max() {
	datos = 0 ;
	reservados = 0 ;
	nelem = 0 ;
}

Pila_max::Pila_max(const Pila_max& p) {
	datos = new Par [p.reservados] ;
	reservados = p.reservados ;
	nelem = p.nelem ;

	for (int i = 0 ; i < nelem ; i++) {
		datos[i].dato = p.datos[i].dato ;
		datos[i].max = p.datos[i].max ;
	}

}

Pila_max::~Pila_max() {
	delete[] datos ;
}

Pila_max& Pila_max::operator=(const Pila_max& p) {
	if (this != &p) {
		if (p.reservados != reservados) {
			resize(p.reservados);
			reservados = p.reservados ;
		}

		nelem = p.nelem ;
		for (int i = 0 ; i < nelem ; i++) {
			datos[i].dato = p.datos[i].dato ;
			datos[i].max = p.datos[i].max ;
		}
		return *this ;
		
	}
}

void Pila_max::poner(T e) {
	if (nelem==reservados)
		resize(2*reservados);
	datos[nelem] = e ;
	nelem++ ;
}

void Pila_max::quitar() {
	assert(nelem>0);
	nelem-- ;
	if (nelem<reservados/4)
		resize(reservados/2);
}

Par Pila_max::tope() const {
	assert(nelem>0);
	return datos[nelem-1];
}
