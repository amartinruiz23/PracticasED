#ifndef __CONECTA_4_
#define __CONECTA_4_

#include "ArbolGeneral.h"
#include "tablero.h"

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
	
};
