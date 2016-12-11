#include "cronologia.h"


typedef typename map<int, EventoHistorico>::iterator itc;
typedef typename map<int, EventoHistorico>::const_iterator constitc;

Cronologia::Cronologia(Cronologia& c1, Cronologia& c2) {
	map<int, EventoHistorico>::iterator it1 = c1.begin() ;
	map<int, EventoHistorico>::iterator it2 = c2.begin() ;

	while (it1 != c1.end() && it2 != c2.end()) {
		cout << "a" << endl;
		while (it1->first < it2->first && it1 != c1.end()) { cout << "b" << endl;
			eventos.insert(*it1);
			it1++ ;
		}

		while (it1->first > it2->first && it2 != c2.end()) { cout << "c" << endl;
			eventos.insert(*it2);
			it2++ ;
		}

		while (it1->first == it2-> first && it1 != c1.end() && it2 != c2.end()) { cout << "d" << endl;
			eventos.insert(make_pair(it1->first, EventoHistorico(it1->second , it2->second)));
			it1++;
			it2++;
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


EventoHistorico Cronologia::getEvento(int anio) {

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

	Cronologia c;

	Cronologia::itc it1 = eventos.lower_bound(comienzo);
	Cronologia::itc it2 = eventos.lower_bound(fin);

	while(it1 != it2){
			c.inserta(it1->second);
			it1++;
	}

return c;

}

void Cronologia::estadisticas (int& total_anios, int& total_acont, int& max_acont, double& media_acont) { // ¿Cabecera??

	Cronologia::itc it1 = eventos.begin();
	EventoHistorico::it it2 ;


	total_anios = 0 ;

	while (it1 != eventos.end()){
		it1++ ;
		total_anios++;
	}


	it1 = eventos.begin() ;

	while (it1 != eventos.end()) {
		it2 = it1->second.begin() ; // ¿Se puede hacer?
		while (it2 != it1->second.end()){
			it2++ ;
			total_acont++ ;
		}
		it1++;
	}


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
