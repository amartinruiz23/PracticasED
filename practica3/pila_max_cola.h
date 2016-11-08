#include "cola.h"

#ifndef _PILA_MAX_VD_H_
#define _PILA_MAX_VD_H_

template <class T>

class Pila_max {

  struct Par{
    T dato;
    T max;
  };

  Cola<Par> cola;

public:

  /**
  * @brief Constructor vacío de pila_max_vd
  */
  Pila_max () ;

  /**
  * @brief Constructor copia de pila_max_vd
  * @param p pila_max_vd a copiar
  */
  Pila_max (const Pila_max& p);

  /**
  * @brief Destructor de pila_max_vd
  */
  ~Pila_max () ;

  /**
  * @brief Operador de asignación
  * @param p pila_max_vd a ser asignada
  * @return pila_max_vd& referencia a la pila asignada para poder concatenar esta operación
  */
  Pila_max& operator=(const Pila_max& p);

  /**
  * @brief Comprueba si una pila_max_vd esta vacía
	* @return bool , 1 si está vacía , 0 si no lo está
	*/
	bool vacia() const { return nelem==0 ; }

	/**
	* @brief Pone un elemento en el tope de la pila_max_vd
	* @param e, elemento a ser añadido
	*/
	void poner (T e) ;

	/**
	* @brief Saca un elemento de la pila_max_vd
	*/
	void quitar() ;

	/**
	* @brief Consulta el elemento situado en el tope de la pila_max_vd
	* @return T , elemento
	*/
	T tope() const ;
