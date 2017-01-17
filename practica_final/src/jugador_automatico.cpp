#include "jugador_automatico.h"
#include <vector>

void conecta4::GeneraHijos(nodo<Tablero>* n) {

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

}

int conecta4::evalua1 (nodo<Tablero>* t) {

		if (t.etiqueta.quienGana() == 2) 
			return 1 ;
		else {
			if (t.etiqueta.quienGana() == 1) 
				return -1 ;
			else 
				return 0 ;
		}
}

int conecta4::eligeColumna (){

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
}


int conecta4::metrica (nodo<Tablero>* t){

	// tenemos que recorrer el sub-arbol que cuelga de t

	

	if (metrica == 1) 

		evalua1(t);

	if (metrica == 2)

		evalua2(t);


}


/**

int conecta4 (Tablero t) {

	arbol.AsignaRaiz(t);
	
	int columna =	(recursiva (arbol.raiz())).first ;
 
	return columna ;
}


pair<int,int> recursiva (nodo <Tablero> n) {

	if (altura(n) < PROFUNDIDAD) {				// CASO GENERAL
		
		int contador = 0 ;
		int i ;
		vector<pair<int, int> > puntuaciones ;	

		for ( i = 0 ; i < n.etiqueta.GetColumnas() ; i++) {			// Para cada columna del tablero

			if (n.etiqueta.hayHueco(i) != -1) {		// Si esa columna no está llena

				Tablero t = n.etiqueta ;					// Copia el tablero
				t.colocarFicha(i);								// Le insertas la ficha en la columna

				if (contador == 0) {							// Le insertas el tablero al nodo como hijo a la izqda
					n.izqda = t ;
					contador++ ;
					puntuaciones.push_back(makepair(i,recursiva(n.izqda).second));		// LLAMO A RECURSIVA Y METO EN EL VECTOR EL PAR <Nº_NODO,PUNTUACION>
				}

				else {														// Le insertas el tablero al nodo como hijo a la derecha
					ArbolGeneral<Tablero> a(t);
					arbol.insertar_hermanoderecha(n , a );
					puntuaciones.push_back(makepair(i,recursiva(a.raiz().second));	// LLAMO A RECURSIVA Y METO EN EL VECTOR EL PAR <Nº_NODO, PUNTUACION>
				}

				if ( (altura(n) % 2) == 0 ) 

					return minimo(puntuaciones);

				else 

					return maximo(puntuaciones);
			
			}			
		}
	}

	else {				// CASO NODO HOJA
		int puntuacion = metrica (n) ;
		return makepair(-1,puntuacion);
	}
		
}				

*/


funciones aux -> calcula max de un vector <pair<int, int> >
							-> calcula min de un vector <pair<int, int> >
