/**
  * @file prueba_pila.cpp
  * @brief Programa para probar funciones
  *
  */


#include "pila_max_vd.h"
#include <iostream>
using namespace std;

int main () {

	Pila_max<int> mip ;

	cout << "¿Vacia?" << mip.vacia() << endl ;

	mip.poner(1);
	mip.poner(2);
	mip.poner(3);

	cout << "¿Vacia?" << mip.vacia() << endl ;

	cout << "Elemento tope" << mip.tope() << endl ;

	mip.quitar();
	
	cout << "Elemento tope" << mip.tope() << endl ;

	Pila_max<int> mip2 = mip ;

	cout << "Elemento tope" << mip2.tope() << endl ;

}
