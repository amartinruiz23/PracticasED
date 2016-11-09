#include <cassert>

class template <T>
Pila_max<T>::Pila_max() : tope (0) {}

class template <T>
Pila_max<T>::Pila_max(const Pila& p) {

		if (p.tope == 0)
			tope=0 ;
		else {
			tope = new Celda ;
			tope -> pareja = p.tope -> pareja ;
			Celda * origen = p.tope ;
			Celda * destino = tope ;
			while(origen->sig != 0) {
				destino->sig = new Celda ;
				origen = origen -> sig ;
				destino = destino -> sig ;
				destino -> pareja = origen -> pareja ;
			}

			destino -> sig = 0 ;
		}
}

class template <T>
Pila_max<T>::~Pila_max() {
	Celda * aux;
	while(tope!=0) {
		aux = tope ;
		tope = tope -> sig ;
		delete aux ;
	}
}

class template <T>
Pila_max& Pila_max<T>::operator=(const Pila_max& p) {

	if (this != *p) {
			Pila_max paux(p) ;
			Celda * aux ;
			aux = this->tope ;
			this->tope = paux.tope ;
			paux.tope = aux ;
	}
	
	return *this ;
}


class template <T>
void Pila_max<T>::poner(T e) {
	Celda * aux = new Celda ;
	aux -> pareja.dato = c ;
	aux -> sig = tope ;
	tope = aux ;

	if (tope->sig != 0) {
		if (tope->pareja.dato >= tope->sig->pareja.max )
			tope->pareja.max = tope->pareja.dato ;
		else 
			tope->pareja.max = tope->sig->pareja.max ;
	}
	else
		tope->pareja.max = tope->pareja.dato ;
		
} 


class template <T>
void Pila_max<T>::quitar() {
	assert(tope != 0);
	Celda * aux = tope ;
	tope = tope -> sig ;
	delete aux ;
}


class template <T>
Par Pila_max<T>::tope() { /////////////////////
	assert(tope!=0);
	return tope -> pareja ;
}


