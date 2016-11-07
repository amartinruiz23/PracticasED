/**
  * @file cronologia.h
  * @brief Fichero cabecera del TDA cronología
  *
  */


#ifndef _CRONOLOGIA_H_
#define _CRONOLOGIA_H_

#include "evento.h"

	/**
  *  @brief T.D.A. cronologia
  *
  * Una instancia @e c del tipo de datos abstracto @c cronología es un objeto
  * compuesto por un vector de sucesos 
	* 
  * Un ejemplo de su uso:
  * @include pruebacronologia.cpp
  *
  * @author Álvaro López Jiménez y Antonio Martín Ruíz
  * @date Octubre 2016
  */

class cronologia {

	/**
  * @page repConjunto Rep del TDA Cronologia
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es que la cronología debe estar ordenada
  */

	std::vector<evento> eventos ;

	/**
	* @brief ordena la cronología por fechas de los eventos
	*/
	void ordenar();

	/**
	* @brief intercambia la posición de dos eventos del vector de eventos
	*/
	void intercambia(evento& e1, evento& e2);

	public:

		/**
		* @brief devuelve una cronología entre dos fechas
		* @param anio_inicio año a partir del cual empieza la subcronología
		* @param anio_final último año de la subcronología, por defecto, hasta hoy
		* @return cronología "recortada"
		*/
		cronologia subcronologia(int anio_inicio, int anio_final=2017);

		/**
		* @brief mezcla dos cronologías
		* @param c cronología a ser mezclada
		* @return puntero a la cronología mezclada para poder concatenar mezclas
		*/

		cronologia operator+(const cronologia& c);

		/**
		* @brief elimina un evento de la cronología
		* @param anio , año del evento que queremos borrar
		*/
		void eliminarevento (int anio);

		/**
		* @brief añade un evento a la cronología
		* @param e , evento a añadir
		*/
		void aniadirevento (evento& e);

		/**
		* @brief busca un evento en la cronología
		* @param anio , fecha del evento a buscar
		* @return evento buscado
		*/
		evento buscaevento (int anio) ;

		/**
		* @brief busca un evento en la cronología
		* @param s , suceso a buscar
		* @return cronologia con los eventos que contienen el string
		*/
		cronologia buscaevento (const std::string& s);

		/**
		* @brief Devuelve el vector de eventos
		* @return vector de eventos
		*/
		vector<evento> geteventos ();

		/**
		* @brief Devuelve el vector con los sucesos del año indicado
		* @param anio , año de los sucesos que se buscan
		* @return Sucesos del año indicado que hay en la cronología
		*/
		vector<string> GetEventos(int anio);

		/**
		* @brief Sobrecarga de operador>> para cronologías
		* @param s, flujo
		* @param c, cronología a leer
		* @return flujo para poder concatenar lecturas
		*/
		friend istream& operator>>(istream& s, cronologia& c);

		/**
		* @brief Sobrecarga de operador<< para cronologías
		* @param s,flujo
		* @param c, cronología a escribir
		* @return flujo para poder concatenar escrituras
		*/
		friend ostream& operator<<(ostream& s, const cronologia& c);


};




#endif
