#include <cassert>

template <class T>
Pila_max<T>::resize(int n) {


}

template <class T>
Pila_max<T>::Pila_max() {
	datos = 0 ;
	reservados = 0 ;
	nelem = 0 ;
}

template <class T>
Pila_max<T>::Pila_max(const Pila_max& p) {
	datos = new Par [p.reservados] ;
	reservados = p.reservados ;
	nelem = p.nelem ;

	for (int i = 0 ; i < nelem ; i++) {
		datos[i].dato = p.datos[i].dato ;
		datos[i].max = p.datos[i].max ;
	}

}

template <class T>
Pila_max<T>::~Pila_max() {
	delete[] datos ;
}

template <class T>
Pila_max<T>& Pila_max<T>::operator=(const Pila_max& p) {
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

template <class T>
void Pila_max<T>::poner(T e) {
	if (nelem==reservados)
		resize(2*reservados);
	datos[nelem].dato = e ;
	for (int i = 0 ; i < nelem ; i++) {
		if(datos[i].max >= e)
			datos[nelem].max = datos[i].max ;
	}
	nelem++ ;
}

template <class T>
void Pila_max<T>::quitar() {
	assert(nelem>0);
	nelem-- ;
	if (nelem<reservados/4)
		resize(reservados/2);
}

template <class T>
T Pila_max<T>::tope() const {
	assert(nelem>0);
	return datos[nelem-1].dato;
}

template <class T>
T Pila_max<T>::max() const {
	assert(nelem>0);
	return datos[nelem-1].max;
}

