/**
  * @file pila_max.h
  * @brief Fichero cabecera del TDA Pila_max
  */


#include <iostream>
using namespace std;

template <class T>

struct Par {
		T dato ;
		T max ;
};

template <class T>

ostream& operator<<(ostream& s, const Par<T>& p){
	s <<"[" << p.dato << " " << p.max << "]";
	return s ;
}

#define CUAL_COMPILA 2
#if CUAL_COMPILA==1
#include "pila_max_vd.h"
#elif CUAL_COMPILA==2
#include "pila_max_lista.h"
#else
#include "pila_max_cola.h"
#endif
