#include <cassert>

template <class T>
Pila_max<T>::Pila_max() : topedepila (0) {}

template <class T>
Pila_max<T>::Pila_max(const Pila_max& p) {

		if (p.topedepila == 0)
			topedepila=0 ;
		else {
			topedepila = new Celda ;
			topedepila -> pareja = p.topedepila -> pareja ;
			Celda * origen = p.topedepila ;
			Celda * destino = topedepila ;
			while(origen->sig != 0) {
				destino->sig = new Celda ;
				origen = origen -> sig ;
				destino = destino -> sig ;
				destino -> pareja = origen -> pareja ;
			}

			destino -> sig = 0 ;
		}
}

template <class T>
Pila_max<T>::~Pila_max<T>() {
	Celda * aux;
	while(topedepila!=0) {
		aux = topedepila ;
		topedepila = topedepila -> sig ;
		delete aux ;
	}
}

template <class T>
Pila_max<T>& Pila_max<T>::operator=(const Pila_max& p) {

	if (this != *p) {
			Pila_max paux(p) ;
			Celda * aux ;
			aux = this->topedepila ;
			this->topedepila = paux.topedepila ;
			paux.topedepila = aux ;
	}

	return *this ;
}


template <class T>
void Pila_max<T>::poner(T e) {
	Celda * aux = new Celda ;
	aux -> pareja.dato = e ;
	aux -> sig = topedepila ;
	topedepila = aux ;

	if (topedepila->sig != 0) {
		if (topedepila->pareja.dato >= topedepila->sig->pareja.max )
			topedepila->pareja.max = topedepila->pareja.dato ;
		else
			topedepila->pareja.max = topedepila->sig->pareja.max ;
	}
	else
		topedepila->pareja.max = topedepila->pareja.dato ;

}


template <class T>
void Pila_max<T>::quitar() {
	assert(topedepila != 0);
	Celda * aux = topedepila ;
	topedepila = topedepila -> sig ;
	delete aux ;
}


template <class T>
Par<T> Pila_max<T>::tope() { /////////////////////
	assert(topedepila!=0);
	return topedepila -> pareja ;
}
