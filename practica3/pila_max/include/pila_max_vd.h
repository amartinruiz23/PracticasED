/**
  * @file pila_max_vd.h
  * @brief Fichero cabecera del TDA Pila_max versión vector dinámico
  *
  */


#ifndef _PILA_MAX_VD_H_
#define _PILA_MAX_VD_H_

template <class T>

class Pila_max {

	Par<T> *datos ;
	int reservados ;
	int nelem ;

	/**
	* @brief cambia el tamaño del vector
	* @param n nuevo tamaño del vector
	*/
	void reserve (int n);

	public:

		/**
		* @brief Constructor vacío de pila_max_vd
		*/
		Pila_max<T> () ;


		/**
		* @brief Constructor copia de pila_max_vd
		* @param p pila_max_vd a copiar
		*/
		Pila_max<T> (const Pila_max<T>& p);


		/**
		* @brief Destructor de pila_max_vd
		*/
		~Pila_max<T> () ;


		/**
		* @brief Operador de asignación
		* @param p pila_max_vd a ser asignada
		* @return pila_max_vd& referencia a la pila asignada para poder concatenar esta operación
		*/
		Pila_max<T>& operator=(const Pila_max<T>& p);


		/**
		* @brief Comprueba si una pila_max_vd esta vacía
		* @return bool , 1 si está vacía , 0 si no lo está
		*/
		bool vacia() const { return nelem==0 ; }


		/**
		* @brief Pone un elemento en el tope de la pila_max_vd
		* @param e, elemento (par) a ser añadido
		*/
		void poner (T e) ;


		/**
		* @brief Saca un elemento de la pila_max_vd
		*/
		void quitar() ;


		/**
		* @brief Consulta el elemento situado en el tope de la pila_max_vd
		* @return Par , dato situado en el tope de la pila y el máximo de la pila
		*/
		Par<T> tope() const ;

};

#include "pila_max_vd.cpp"

#endif
