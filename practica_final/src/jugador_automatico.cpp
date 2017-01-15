#include "jugador_automatico.h"
#include <vector>

void GeneraHijos(nodo<Tablero>* n) {

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


int eligeColumna (int metrica){
  int columnaelegida;
  vector<int> puntacion;
  nodo<Tablero> señalado;
  int max = 0;
  int nhijos = contarhijos(arbol.raiz());

  señalado = hijomasizquierda(arbol.raiz());

  puntuacion.push_back(metrica(señalado));

  while(int i = 1; i < nhijos; i++){
    señalado = arbol.hermanoderecha(señalado);
    puntuacion.push_back(metrica(señalado));
  }

  for(int i = 1; i <= nhijos; i++){
    if (puntuacion[i-1] > max){
      max = puntuacion[i-1];
      columnaelegida = i;
    }
  }

  return columnaelegida;
}


int metrica (int n){




}




