#include "jugador_automatico.h"
#include <iostream>
using namespace std;

/*void conecta4::GeneraHijos(nodo<Tablero>* n) {

	int contador = 0 ;


	for (int i = 0 ; i < n.etiqueta.columnas ; i++) {	// Para cada columna del tablero

		if (n.etiqueta.hayHueco(i) != -1) {		// Si esa columna no está llena

			Tablero t = n.etiqueta ;					// Copia el tablero
			t.colocarFicha(i);								// Le insertas la ficha en la columna

			if (contador == 0) {							// Le insertas el tablero al nodo como hijo a la izqda
				n.izqda = t ;
				contador++ ;
			}

			else {														// Le insertas el tablero al nodo como hijo a la derecha
				ArbolGeneral<Tablero> a(t);
				arbol.insertar_hermanoderecha(n , a );
			}

		}
	}
}

conecta4::conecta4(Tablero t, int met=0) {

	metrica = met ;
	arbol.AsignaRaiz(t);								// Asigna la raiz
	preorder_iterator(arbol.raiz()) it;

	int n_hijos = contar_Hijos(arbol.raiz());

	//int i = 0 ;
	//while ( i < n_hijos ) {		// Para los hijos del nodo raiz

		while (arbol.altura(*it) < PROFUNDIDAD) { // Recorre el arbol hasta el nivel profundidad
			GeneraHijos(*it);
			it++;
		}

		//while (arbol.altura(*it) >= PROFUNDIDAD)
			//it++;

		//if (arbol.altura(*it) == 1)
			//i++;
	//}

}*/

int conecta4::evalua1 (ArbolGeneral<Tablero>::nodo* t) { // CAMBIAR

		if (t->etiqueta.quienGana() == 2) //CAMBIAR
			return 1 ;
		else {
			if (t->etiqueta.quienGana() == 1){ // CAMBIAR
					return -5+(nivel(t)) ;
		}
			else
				return 0 ;
		}
}

int conecta4::evalua2 (ArbolGeneral<Tablero>::nodo* t) { // CAMBIAR

		if (t->etiqueta.quienGana() == 2) // CAMBIAR
			return 1 ;
		else {
			if (t->etiqueta.quienGana() == 1) // CAMBIAR
				return -1 ;
			else
				return 0 ;
		}
}

/*int conecta4::eligeColumna (){

  int columnaelegida;
  vector<int> puntacion;
  nodo<Tablero> senialado;
  int max = 0;
  int nhijos = contarhijos(arbol.raiz());

  senialado = hijomasizquierda(arbol.raiz());

  puntuacion.push_back(metrica(senialado));		// Se añade al vector la evaluación de todo el subárbol

  while(int i = 1; i < nhijos; i++){
    senialado = arbol.hermanoderecha(senialado);
    puntuacion.push_back(metrica(senialado));
  }

  for(int i = 0; i < nhijos; i++){
    if (puntuacion[i] > max){
      max = puntuacion[i];
      columnaelegida = i;
    }
  }

  return columnaelegida;
}*/


int conecta4::metrica (ArbolGeneral<Tablero>::nodo* t){	// CAMBIAR CABECERA

	if (metricaelegida == 1)

		return evalua1(t);

	if (metricaelegida == 2)

		return evalua2(t);


}

int conecta4::jugada(Tablero t, int met) {

	metricaelegida = met ;
	arbol.AsignaRaiz(t);

	int columna =	((recursiva (arbol.raiz())).first) ; // CAMBIAR

	return columna ;
}


pair<int,int> conecta4::recursiva (ArbolGeneral<Tablero>::nodo* n) { // CAMBIAR

	// cout << "Voy a imprimir el tablero raiz " << endl ;
	// cout << n->etiqueta ;

	if ( (nivel(n) < PROFUNDIDAD) && (metrica(n) == 0) ) {				// CASO GENERAL

		//int contador = 0 ;
		int i = 0;
		vector<pair<int, int> > puntuaciones ;

		for ( i = 0 ; i < n->etiqueta.GetColumnas() ; i++) {			// Para cada columna del tablero

			if (n->etiqueta.hayHueco(i) != -1) {
				cout << "1" << endl ;

				Tablero t = n->etiqueta ;					// Copia el tablero
				t.colocarFicha(i);							// Le insertas la ficha en la columna
				t.cambiarTurno();

				//contador = 0 ;

				//if (contador == 0) {			// Le insertas el tablero al nodo como hijo a la izqda
					cout << "2" << endl ;
					ArbolGeneral<Tablero> a(t);
					arbol.insertar_hijomasizquierda(n, a);
			//		contador++ ;
					puntuaciones.push_back(make_pair(i,(recursiva(n->izqda)).second));	// LLAMO A RECURSIVA Y METO EN EL VECTOR EL PAR <Nº_NODO,PUNTUACION>
				//}

			//	else {														// Le insertas el tablero al nodo como hijo a la derecha
			//		cout << "3" << endl ;
			//		ArbolGeneral<Tablero> a(t);
			//		arbol.insertar_hermanoderecha(n , a ); // CAMBIAR
			//		puntuaciones.push_back(make_pair(i,(recursiva(a.raiz()).second)));	// LLAMO A RECURSIVA Y METO EN EL VECTOR EL PAR <Nº_NODO, PUNTUACION>
			//	}
			}
		}

		if ( (nivel(n) % 2) == 1 ) {
			cout << "4" << endl ;
			// cout << "minimo = " << minimo(puntuaciones).first << endl;
			return minimo(puntuaciones);
		}

		else {
			cout << "5" << endl ;
			// cout << "maximo = " << maximo(puntuaciones).first << endl ;
			return maximo(puntuaciones);
		}

	}

	else				// CASO NODO HOJA
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

	cout << "6" << endl ;
	int puntuacion = metrica (n) ;
	// cout << "Puntuacion = " << puntuacion  << endl ;
	return make_pair(-1,puntuacion);

}
