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
			if (t->etiqueta.quienGana() == 1) // CAMBIAR
				return -1 ;
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

	if (arbol.altura(n) < PROFUNDIDAD) {				// CASO GENERAL

		int contador = 0 ;
		int i ;
		vector<pair<int, int> > puntuaciones ;

		cout << "1" << endl;

		for ( i = 0 ; i < n->etiqueta.GetColumnas() ; i++) {			// Para cada columna del tablero
			cout << "Creo el tablero de columna " << i << endl;
			if (n->etiqueta.hayHueco(i) != -1) {		// Si esa columna no está llena

				Tablero t = n->etiqueta ;				cout << "trololo" <<endl;	// Copia el tablero
				t.colocarFicha(i);							cout << "wololo" <<endl;	// Le insertas la ficha en la columna

				if (contador == 0) {			// Le insertas el tablero al nodo como hijo a la izqda
					n->izqda->etiqueta = t ; cout << "AQUÍ SE PRODUCE LA VIOLACIÓN DE SEGMENTO" <<endl; //HAY QUE INSERTAR EL HIJO
					contador++ ;
					puntuaciones.push_back(make_pair(i,(recursiva(n->izqda)).second));		cout << "lirilo" <<endl;// LLAMO A RECURSIVA Y METO EN EL VECTOR EL PAR <Nº_NODO,PUNTUACION>
				}

				else {														// Le insertas el tablero al nodo como hijo a la derecha
					ArbolGeneral<Tablero> a(t);
					arbol.insertar_hermanoderecha(n , a ); // CAMBIAR
					puntuaciones.push_back(make_pair(i,(recursiva(a.raiz()).second)));	// LLAMO A RECURSIVA Y METO EN EL VECTOR EL PAR <Nº_NODO, PUNTUACION>
				}

				if ( (arbol.altura(n) % 2) == 0 )

					return minimo(puntuaciones);

				else

					return maximo(puntuaciones);

			}
		}
	}

	else {				// CASO NODO HOJA
		int puntuacion = metrica (n) ;
		return make_pair(-1,puntuacion);
	}

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
