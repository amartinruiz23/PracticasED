#ifndef __CONECTA_4_
#define __CONECTA_4_

#include "ArbolGeneral.h"
#include "tablero.h"

/**
   @brief T.D.A. conecta4

   \b Definición:
   Una instancia \e c del tipo de dato abstracto conecta4 se se puede construir como

   - Un árbol que contiene un elemento destacado, el nodo raíz, indispensable para
	 crear el árbol, y dos valores, \e PROFUNDIDAD cuyo valor será decidido por los
	 autores, y \e metrica valor suministrado por el usuario que indicará en cierta
   medida el grado de dificultad.

	 En definitiva un objeto del tipo de dato abstracto conecta4 es el conjunto de
   todos los movimientos posibles del jugador automático, que son almacenados en
	 una estructura de tipo ArbolGeneral

   Para poder usar el tipo de dato conecta4 se debe incluir el fichero

   <tt>\#include conecta4.h</tt>

   El espacio requerido para el almacenamiento es O(n), donde n es el número de
   nodos del árbol.

   @authors Álvaro López Jiménez y Antonio Martín Ruíz.
   @date Enero de 2017
*/


class conecta4{

  ArbolGeneral<Tablero> arbol;
  const int PROFUNDIDAD;
	int metrica ;

	/**
	* @brief Dado un nodo genera todos los posibles movimientos (todos los tableros resultantes)
	* del jugador automático
	* @param n nodo padre de los futuros tableros a crear
	*/
  void GeneraHijos(nodo<Tablero>* n);

	/**
	* @brief Función que evalua la idoneidad o no de un tablero de cara a los intereses
	* del jugador automático de cara a ganar la partida.
	* @param t Tablero a evaluar
	* @return entero con la puntuación obtenida
	*/
  int evalua1 (nodo<Tablero>* t) ;
  int evalua2 (nodo<Tablero>* t) ;
  int evalua3 (nodo<Tablero>* t) ;

public:

	/**
	* @brief Constructor de conecta4, construye todo el árbol de posibles jugadas del
	* jugador automático hasta una cierta profundidad dada por PROFUNDIDAD
	* @param t Tablero actual de la partida que será el nodo raíz del árbol
	* @param met, métrica que decidirá qué función evaluará los nodos del árbol
	*/
  conecta4(Tablero t, int met=0);

	/**
	* @brief Destructor de conecta4, libera los recursos ocupados por el árbol
	*/
	~conecta4() = default ;


	int eligeColumna () ;


	int metrica (nodo<Tablero>* t);

  pair<int, int> maximo(vector<double<int,int> > v);
  pair<int, int> minimo(vector<double<int,int> > v);

};






/*

FUNCIÓN RECURSIVA

CASO GENERAL: GENERA HIJOS DEL NODO Y LOS VALORA. RECIBE LAS VALORACIONES DE LOS HIJOS, SELECCIONA EL MEJOR, Y DEVUELVE LA VALORACIÓN Y EL HIJO QUE ELIGE.

CASO BASE: VALORA EL NODO Y DEVUELVE -1 (NO TIENE HIJOS) Y SU VALORACIÓN. ESTE CASO SE DA CUANDO SE ESTÉ A LA PROFUNDIDAD MÁXIMA DEL ÁRBOL.

*/
#endif
