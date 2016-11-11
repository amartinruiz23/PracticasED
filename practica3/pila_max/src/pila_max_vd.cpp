#include <cassert>

template <class T>
void Pila_max<T>::reserve(int n) {

	if (reservados < n) {
		Par *p ;
		p = new Par [n] ;
		reservados = n ;
		for (int i = 0 ; i < nelem ; i++) 
			p[i] = datos[i] ;

		delete[] datos ;

		datos = p ;	
	}
}

template <class T>
Pila_max<T>::Pila_max() {
	reservados = 1 ;
	datos = new Par [reservados] ;
	nelem = 0 ;
}

template <class T>
Pila_max<T>::Pila_max(const Pila_max&<T> p) {
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
Pila_max<T>& Pila_max<T>::operator=(const Pila_max<T>& p) {
	if (this != &p) {
		if (p.reservados != reservados) {
			reserve(p.reservados);
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
		reserve(2*reservados);
	datos[nelem].dato = e ;
	if (nelem != 0) {
		for (int i = 0 ; i < nelem ; i++) {
			if(datos[nelem-1].max <= e)
				datos[nelem].max = e ;
			else 
				datos[nelem].max = datos[nelem-1].max ;
		}
	}
	else 
		datos[nelem].max = e ;
	nelem++ ;
}

template <class T>
void Pila_max<T>::quitar() {
	assert(nelem>0);
	nelem-- ;
	if (nelem<reservados/4)
		reserve(reservados/2); //////////////////////////
}

template <class T>
Par<T> Pila_max<T>::tope() const {
	assert(nelem>0);
	return datos[nelem-1];
}

