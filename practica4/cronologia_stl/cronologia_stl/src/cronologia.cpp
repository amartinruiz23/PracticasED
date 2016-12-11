#include <utility>
#include "cronologia.h"
using namespace std;

/*
	casos:
		1 -> fecha evento de c1 < fecha evento de c2
		2 -> fecha evento de c2 < fecha evento de c1
		3 -> fecha evento de c1 = fecha evento de c2
*/

typedef typename map<int, EventoHistorico>::iterator itc;
typedef typename map<int, EventoHistorico>::const_iterator constitc;

Cronologia::Cronologia(const Cronologia& c1, const Cronologia& c2) {
	map<int, EventoHistorico>::iterator it1 = c1.begin() ;
	map<int, EventoHistorico>::iterator it2 = c2.begin() ;

	while (it1 != c1.end() && it2 != c2.end()) {

		while (it1->first < it2->first && it1 != c1.end()) {
			eventos.insert(*it1);
			it1++ ;
		}

		while (it1->first > it2->first && it2 != c2.end()) {
			eventos.insert(*it2);
			it2++ ;
		}

		while (it1->first == it2-> first && it1 != c1.end() && it2 != c2.end()) {
			eventos.insert(EventoHistorico(*it1 , *it2));
		// No acabada -> Problema: hay que insertar un evento, que está formado por una pareja (llave,evento) es decir (fecha,evento). Pero el evento es una pareja (fecha, sucesos) y sucesos es un set<string> formado por los sucesos del evento de c1 y de c2 (es decir hay que concatenarlos)

		}
	}
}

itc Cronologia::begin() {
	return eventos.begin() ;
}

itc Cronologia::end() {
	return eventos.end() ;
}

constitc Cronologia::cbegin() {
	return eventos.begin() ;
}

constitc Cronologia::cend() {
	return eventos.end() ;
}

// Prec: el año debe estar
EventoHistorico& Cronologia::getEvento(int anio) { // ?? Devuelve evento o sucesos?

	Cronologia::iterator it = eventos.begin() ;

	while ( it->first != anio && it != eventos.end() ) {
		it++ ;

	return it->second ;

}


void Cronologia::inserta(const EventoHistorico& e) {
	eventos.insert(make_pair(e.first,e));
}

Cronologia& Cronologia::une_cronologias (Cronologia& c1, Cronologia& c2) {

	Cronologia unida (c1,c2);

	return unida ;
}

/*Cronologia& Cronologia::filtrado_por_clave (const string& palabraclave) {

	Cronologia c ;
	Cronologia::iterator it = eventos.begin();

	while (it != eventos.end()) {

		// ¿Cómo comparo un string de tamaño una palabra (palabraclave) con un string que puede ser una frase?

	EventoHistorico::iterator it2 ;

		if (it->second.second

}*/

Cronologia& Cronologia::filtrado_por_intervalo (int comienzo, int final) {

	Cronologia c ;
	Cronologia::iterator it = eventos.begin() ;

	while (it->first != comienzo)
		it++ ;

	while (it->first != final)
		c.inserta(it->second);

	return c ;

}

void Cronologia::estadisticas (int& total_anios, int& total_acont, int& max_acont, double& media_acont) { // ¿Cabecera??

	Cronologia::iterator it1 = eventos.begin();
	EventoHistorico::iterator it2 ;

	// total_anios

	total_anios = 0 ;

	while (it1 != eventos.end()){
		it1++ ;
		total_anios++;
	}

	// total_acont

	it1 = eventos.begin() ;

	while (it1 != eventos.end()) {
		it2 = it1->second.begin() ; // ¿Se puede hacer?
		while (it2 != it1->second.end()){
			it2++ ;
			total_acont++ ;
		}
		it1++;
	}

	// max_acont

	it1 = eventos.begin() ;
	int contador_aux = 0 ;
	int contador_aux2 = 0 ;

	while (it1 != eventos.end()) {
		it2 = it1->second.begin() ; // ¿Se puede hacer?
		while (it2 != it1->second.end()){
			it2++ ;
			total_acont++ ;
			contador_aux2++ ;
			if (contador_aux == 0)
				max_acont = total_acont ;
			}

		contador_aux++ ;

		if (contador_aux2 > max_acont)
			max_acont = contador_aux2 ;

		contador_aux2 = 0 ;
		it1++;

	}

	// med_acont

	med_acont = total_acont / total_anios ;

}


ostream& operator<<(ostream& os, Cronologia& c) {
	Cronologia::const_iterator it;
   for (it=c.begin(); it!=c.end();++it){
       os<<(*it).first<<"#";          //año esta en el key del map
       EventoHistorico::const_iterator it_ev;
       for (it_ev=(*it).second.begin(); it_ev!=(*it).second.end();++it_ev)
       	os<<(*it_ev)<<"#";
   }

	return os ;
}

istream& operator>>(istream& is, Cronologia& c) {

	if (is) {

		int key ;
		EventoHistorico e ;

		while(is.peek() != '\0' && !is.eof()){
			is >> key ;
			evento e;
			is >> e;
			c.inserta(make_pair(key,e));
		}
	}
	return s ;
}
