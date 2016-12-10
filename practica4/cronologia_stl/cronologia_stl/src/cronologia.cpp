#include <utility>
using namespace std; 

/*
	casos:
		1 -> fecha evento de c1 < fecha evento de c2
		2 -> fecha evento de c2 < fecha evento de c1
		3 -> fecha evento de c1 = fecha evento de c2
*/

Cronologia::Cronologia(const Cronologia& c1, const Cronologia& c2) {
	Cronologia::iterator it1 = c1.begin() ;
	Cronologia::iterator it2 = c2.begin() ;

	while (it1 != c1.end() && it2 != c2.end() {

		while (it1->first < it2->first && it1 != c1.end() {
			eventos.insert(*it1);
			it1++ ;
		}

		while (it1->first > it2->first && it2 != c2.end()) {
			eventos.insert(*it2);
			it2++ ;
		}

		while (it1->first == it2-> first && it1 != c1.end() && it2 != c2.end()) {
			eventos.insert(make_pair(it1->first, EventoHistorico(make_pair(it1->first, 
		// No acabada -> Problema: hay que insertar un evento, que está formado por una pareja (llave,evento) es decir (fecha,evento). Pero el evento es una pareja (fecha, sucesos) y sucesos es un set<string> formado por los sucesos del evento de c1 y de c2 (es decir hay que concatenarlos)

		}

	}
}	

it Cronologia::begin() {
	return eventos.begin() ;
}

it Cronologia::end() {
	return eventos.end() ;
}

constit Cronologia::begin() {
	return eventos.begin() ;
}

constit Cronologia::end() {
	return eventos.end() ;
}

// Prec: el año debe estar
EventoHistorico& Cronologia::GetEventos(int anio) { // ?? Devuelve evento o sucesos?

	Cronologia::iterator it = eventos.begin() ;

	while ( it->first != anio && it != eventos.end() ) {
		it++ ;

	return *it ;

}	
	

void Cronologia::inserta(const EventoHistorico& e) {
}

	
