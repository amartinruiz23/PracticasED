#include "jugador_automatico.h"
#include <iostream>
using namespace std;

int conecta4::evalua1 (ArbolGeneral<Tablero>::nodo* t) {

		if (t->etiqueta.quienGana() == 2)
			return 1 ;
		else {
			if (t->etiqueta.quienGana() == 1){
					return -5+(nivel(t)) ;
		}
			else
				return 0 ;
		}
}

int conecta4::evalua2 (ArbolGeneral<Tablero>::nodo* t) {

	ArbolGeneral<Tablero>::nodo* aux = t;
	int puntuacion = 0;
//	int hermanosderecha =0;
//	int diferencia = 0;

	if (t->etiqueta.quienGana() == 2)
	  puntuacion += 20-(nivel(t)) ;
	if (t->etiqueta.quienGana() == 1)
	  puntuacion += -20+(nivel(t)) ;

/*	while(aux->drcha != NULL){
  	hermanosderecha++;
  	aux = aux->drcha;
	}*/
/*	cout <<"hermanosderecha:"<< hermanosderecha << endl;

  diferencia = (hermanosderecha - (t->etiqueta.GetColumnas() / 2));
	if (diferencia < 0){
		diferencia = (-1)*diferencia;
	}

	if (t->etiqueta.GetTurno() == 1)
  	puntuacion += diferencia;
	if (t->etiqueta.GetTurno() == 2)
	  puntuacion -= diferencia;

		cout << "PUNTUACIÓN: "<<puntuacion <<"DIFERENCIA:" <<diferencia<< endl;
*/
	return puntuacion;
}

int conecta4::metrica (ArbolGeneral<Tablero>::nodo* t){

	if (metricaelegida == 1)

		return evalua1(t);

	if (metricaelegida == 2)

		return evalua2(t);

}

int conecta4::jugada(Tablero t, int met) {

	metricaelegida = met ;
	arbol.AsignaRaiz(t);

	int columna =	((recursiva (arbol.raiz())).first) ;

	return columna ;
}


pair<int,int> conecta4::recursiva (ArbolGeneral<Tablero>::nodo* n) {

	// cout << n->etiqueta ;

	if ( (nivel(n) < PROFUNDIDAD) && (metrica(n) == 0) ) {										// CASO GENERAL

		int i = 0;
		vector<pair<int, int> > puntuaciones ;

		for ( i = 0 ; i < n->etiqueta.GetColumnas() ; i++) {										// Para cada columna del tablero

			if (n->etiqueta.hayHueco(i) != -1) {																	// Si hay hueco
				cout << "1" << endl ;

				Tablero t = n->etiqueta ;																						// Copia el tablero
				t.colocarFicha(i);																									// Le insertas la ficha en la columna
				t.cambiarTurno();

																																						// Le insertas el tablero al nodo como hijo a la izqda
				cout << "2" << endl ;
				ArbolGeneral<Tablero> a(t);
				arbol.insertar_hijomasizquierda(n, a);
				puntuaciones.push_back(make_pair(i,(recursiva(n->izqda)).second));	// LLAMO A RECURSIVA Y METO EN EL VECTOR EL PAR <Nº_NODO,PUNTUACION>

			}
		}
																																						// Devuelve o el máximo o el mínimo de las
		if ( (nivel(n) % 2) == 1 ) 																							// posibles jugadas dependiendo de si el movimiento
			return minimo(puntuaciones);																					// es del jugador automático o del adversario

		else
			return maximo(puntuaciones);

	}

	else																																			// CASO NODO HOJA
		return casohoja(n);

}


pair<int, int> conecta4::maximo(vector<pair<int,int> > v){
	int maximo = 0;
	int apasar = 0;

	for (unsigned int i = 0; i < v.size(); i++){
		if(v[i].second >= maximo){
			maximo = v[i].second;
			apasar = i;
		}
	}

	return v[apasar];
}

pair<int, int> conecta4::minimo(vector<pair<int,int> > v){
	int minimo = 0;
	int apasar = 0;

	for (unsigned int i = 0; i < v.size(); i++){
		if(v[i].second <= minimo){
			minimo = v[i].second;
			apasar = i;
		}
	}

	return v[apasar];
}

int conecta4::nivel (ArbolGeneral<Tablero>::nodo* n) {

	int i = 0;

	while (n != arbol.raiz()) {
		n = arbol.padre(n) ;
		i++ ;
	}

	return i ;

}


pair <int,int> conecta4::casohoja (ArbolGeneral<Tablero>::nodo* n) {

	int puntuacion = metrica (n) ;
	return make_pair(-1,puntuacion);

}
