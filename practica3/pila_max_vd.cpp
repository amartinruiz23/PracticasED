template <class T>
Pila_max::Pila_max() {
	datos = 0 ;
	reservados = 0 ;
	nelem = 0 ;
}

template <class T>
Pila_max::Pila_max(const Pila_max& p) {
	datos = new Par [p.reservados] ;
	reservados = p.reservados ;
	nelem = p.nelem ;

	for (int i = 0 ; i < nelem ; i++) {
		datos[i].dato = p.datos[i].dato ;
		datos[i].max = p.datos[i].max ;
	}

}

template <class T>
Pila_max::~Pila_max() {
	delete[] datos ;
}

template <class T>
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

template <class T>
void Pila_max::poner(Par e) {
	if (nelem==reservados)
		resize(2*reservados);
	datos[nelem] = e ;
	for (int i = 0 ; i < nelem ; i++) {
		if(datos[i].max > e.max)
			datos[nelem].max = datos[i].max ;
	}
	nelem++ ;
}

template <class T>
void Pila_max::quitar() {
	assert(nelem>0);
	nelem-- ;
	if (nelem<reservados/4)
		resize(reservados/2);
}

template <class T>
Par Pila_max::tope() const {
	assert(nelem>0);
	return datos[nelem-1];
}
