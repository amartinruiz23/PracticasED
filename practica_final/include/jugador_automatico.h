#ifndef __CONECTA_4_
#define __CONECTA_4_

#include "ArbolGeneral.h"
#include "tablero.h"

class conecta4{

  ArbolGeneral<Tablero> arbol;
  const int PROFUNDIDAD;

  void GeneraHijos(nodo<Tablero>* n);
	/**
	Idea:
		- Generar <N_columnas> hijos
	*/

  int evalua1 (nodo<Tablero>* t) ;
  int evalua2 (nodo<Tablero>* t) ;
  int evalua3 (nodo<Tablero>* t) ;

public:

	/**
	* @brief Constructor de conecta4
	*/
  conecta4(Tablero t);
	/**
	Idea:
		- AsignaRaiz(t);
		- GeneraHijos (t)
		- Etiquetamos los primeros <
		- recorre arbol
			- si nodo_actual != padre		// para cada hijo de la raíz
			- si profundidad_actual < PROFUNDIDAD
				- GeneraHijos (nodo_actual)
	*/



	~conecta4();

  conecta4(ArbolGeneral<Tablero> a);

	/**
	* @brief : Función que dado un tablero elige la columna más optima (para ganar la partida)
	* @param t tablero
	* @return valor que indica la columna en la que se introducirá la ficha
	*/
	int eligeColumna (int metrica) ;
	/**
	Idea:
		- Recorre el arbol (no se que recorrido) tal que cada hoja se evalue y se lo devuelva al padre
		- Esto se repite mientras el padre != raiz
		- Cuando padre == raiz tendremos <N_columnas> evaluaciones, escogemos el de mayor valor
	*/


	int metrica (nodo<Tablero> t);
	/**
	Idea:
		- si m == 1 -> evalua1
		- si m == 2 -> evalua2

	la función métrica se llama en eligecolumna
	*/

};
