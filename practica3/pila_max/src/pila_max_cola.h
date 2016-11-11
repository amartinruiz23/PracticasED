#include "cola.h"

#ifndef _PILA_MAX_VD_H_
#define _PILA_MAX_VD_H_

template <class T>

class Pila_max {

  Cola<Par<T> > cola;

public:

  /**
  * @brief Constructor vacío de pila_max_cola
  */
  Pila_max () ;

  /**
  * @brief Constructor copia de pila_max_cola
  * @param p pila_max_vd a copiar
  */
  Pila_max (const Pila_max& p);

  /**
  * @brief Destructor de pila_max_cola
  */
  ~Pila_max () ;

  /**
  * @brief Operador de asignación
  * @param p pila_max_cola a ser asignada
  * @return pila_max_cola& referencia a la pila asignada para poder concatenar esta operación
  */
  Pila_max& operator=(const Pila_max& p);

  /**
  * @brief Comprueba si una pila_max_cola esta vacía
	* @return bool , 1 si está vacía , 0 si no lo está
	*/
	bool vacia() const { return cola.num_elementos()==0 ; }

	/**
	* @brief Pone un elemento en el tope de la pila_max_cola
	* @param e, elemento a ser añadido
	*/
	void poner (T e) ;

	/**
	* @brief Saca un elemento de la pila_max_cola
	*/
	void quitar() ;

	/**
	* @brief Consulta el elemento situado en el tope de la pila_max_cola
	* @return T , elemento
	*/
	Par<T> tope() const ;

};

#include "pila_max_cola.cpp"

#endif
