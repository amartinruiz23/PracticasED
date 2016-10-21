evento::evento(){
	anio = 0;
}

evento::evento(int a, const vector& s){
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

&evento evento::operator=(evento& e){
	anio = e.getanio();
	sucesos = e.getsucesos();
	return *this; 
}

bool operator==(const evento& e){
}
bool operator>(const evento& e){
}
bool operator<(const evento& e){
}


int evento::getanio(const evento& e){
	return anio;
}

const vector& evento::getsucesos(const evento& e){ // TIPO DE DATO DEVUELTO
	return sucesos;
}

string evento::getsuceso(const evento& e, int n){
	return sucesos.at(n); //at devuelve una referencia al elemento en la posición indicada del vector. Lanza excepción si fuera de rango.
}

void evento::insertasuceso(string s, int p){
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

