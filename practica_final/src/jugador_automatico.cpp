#include "jugador_automatico.h"
#include <vector>


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

}


int metrica (int n){




}
