#include "cronologia.h"

/*
	casos:
		1 -> fecha evento de c1 < fecha evento de c2
		2 -> fecha evento de c2 < fecha evento de c1
		3 -> fecha evento de c1 = fecha evento de c2
*/

typedef typename map<int, EventoHistorico>::iterator itc;
typedef typename map<int, EventoHistorico>::const_iterator constitc;

Cronologia::Cronologia(Cronologia& c1, Cronologia& c2) {
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
			eventos.insert(make_pair(it1->first, EventoHistorico(it1->second , it2->second)));
		}
	}
}

itc Cronologia::begin() {
	return eventos.begin() ;
}

itc Cronologia::end() {
	return eventos.end() ;
}

constitc Cronologia::cbegin() const{
	return eventos.begin() ;
}

constitc Cronologia::cend() const{
	return eventos.end() ;
}

// Prec: el año debe estar
EventoHistorico Cronologia::getEvento(int anio) { // ?? Devuelve evento o sucesos?

	Cronologia::itc it = eventos.begin() ;

	while ( it->first != anio && it != eventos.end() )
		it++ ;

	return it->second ;

}


void Cronologia::inserta(EventoHistorico& e) {
	eventos.insert(make_pair(e.getanio(),e));
}

Cronologia Cronologia::une_cronologias (Cronologia& c1, Cronologia& c2) {

	Cronologia unida (c1,c2);

	return unida ;
}


Cronologia Cronologia::filtrado_por_clave (const string& palabraclave) {

	Cronologia c;
	Cronologia::itc it = begin();
	EventoHistorico::it it2 ;

	while (it != end()) {
		it2 = it->second.begin();
		while(it2 != it->second.end()){
			if ((it2->find(palabraclave)) != (it2->npos)){
				c.inserta(it->second);
				cout << *it2;
			 }
			it2++;
		}
		it++;
	}

	return c ;

}


Cronologia Cronologia::filtrado_por_intervalo (int comienzo, int fin) {

	Cronologia c ;
	Cronologia::itc it = eventos.begin() ;

	while (it->first != comienzo)
		it++ ;

	while (it->first != fin)
		c.inserta(it->second);

	return c ;

}

void Cronologia::estadisticas (int& total_anios, int& total_acont, int& max_acont, double& media_acont) { // ¿Cabecera??

	Cronologia::itc it1 = eventos.begin();
	EventoHistorico::it it2 ;

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

	media_acont = total_acont / total_anios ;

}


ostream& operator<<(ostream& os, Cronologia& c) {
	Cronologia::constitc it;
	EventoHistorico::constit it_ev;

   for (it=c.cbegin(); it!=c.cend();++it){
       os<<(*it).first<<"#";          //año esta en el key del map
       for (it_ev=(*it).second.begin(); it_ev!=(*it).second.end();++it_ev)
       	os<<(*it_ev)<<"#";
   }

	return os ;
}

istream& operator>>(istream& is, Cronologia& c) {

	if (is) {
		EventoHistorico e ;
		while(is.peek() != '\0' && !is.eof()){
			EventoHistorico e;
			is >> e;
			c.inserta(e);
		}
	}
	return is ;
}
