#ifndef _PILA_MAX_LISTA_H_
#define _PILA_MAX_LISTA_H_

template <class T>

class Pila_max {

	struct Par {
		T dato ;
		T max ;
	};

	struct Celda{
		Par pareja ;
		Celda * sig ;
	};

	Celda * topedepila ;

	public:
		/**
		* @brief Constructor vacío de Pila_max_lista
		*/
		Pila_max();

		/**
		* @brief Constructor copia de Pila_max_lista
		* @param p , pila a copiar
		*/
		Pila_max(const Pila_max& p);

		/**
		* @brief Destructor de Pila_max_lista
		*/
		~Pila_max();

		/**
		* @brief Operador de asignación de Pila_max_lista
		* @param p , pila a ser asignada
		* @return referencia a pila para poder concatenar asignaciones
		*/
		Pila_max& operator= (const Pila_max& p);

		/**
		* @brief Consulta si la lista está vacía
		* @return 1 si lo está, 0 si no
		*/
		bool vacia() const ;

		/**
		* @brief Coloca un elemento en el tope de la pila
		* @param e , elemento a ser apilado
		*/
		void poner (T e);
		/**
		* @brief Quita el elemento tope de la pila
		*/
		void quitar();

		/**
		* @brief Consulta el tope de la pila
		* @return ///////////////////////////////
		*/
		Par tope() const ; ////////////////////////////////////

};

#include "pila_max_lista.cpp"

#endif
