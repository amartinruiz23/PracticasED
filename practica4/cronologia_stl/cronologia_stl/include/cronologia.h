/**
* 	TDA Cronologia
*
*		Antonio Martín Ruíz y Álvaro López Jiménez
*/

#ifndef _Cronologia_H_
#define _Cronologia_H_

#include <map>
#include <string>
#include <iostream>
#include "eventohistorico.h"
using namespace std;

/**
* TDA Cronologia
*
* @brief TDA contenedor de un conjunto de eventos históricos formado por un map donde la llave es la fecha del evento y el elemento a almacenar es el propio evento.
*
* Invariante de representación: la cronología debe estar ordenada
*/

class Cronologia{

  map<int, EventoHistorico> eventos;

public:

	/**
	* @brief Constructor vacío del TDA Cronología
	*/
  Cronologia() = default;

	/**
	* @brief Destructor del TDA Cronología
	*/
  ~Cronologia () = default;

	/**
	* @brief Constructor del TDA Cronología a partir de dos cronologías
	* @param c1, primera cronología
	* @param c2, segunda cronología
	*/
  Cronologia(const Cronologia& c1, const Cronologia& c2);

	/**
	* Definición de los iteradores sobre el TDA Cronología
	*/
  typedef typename map<int, EventoHistorico>::iterator it;
  typedef typename map<int, EventoHistorico>::const_iterator constit;

	/**
	* @brief Indica el comienzo o primer elemento de la cronología
	* @return iterador "apuntando" al comienzo de la cronología
	*/
  it begin();

	/**
	* @brief Indica el final o último elemento de la cronología
	* @return iterador "apuntando" al final de la cronología
	*/
	it end();

	/**
	* @brief Indica el comienzo o primer elemento de la cronología
	* @return iterador constante "apuntando" al comienzo de la cronología
	*/
  constit cbegin() const;

	/**
	* @brief Indica el final o último elemento de la cronología
	* @return iterador constante "apuntando" al final de la cronología
	*/
  constit cend() const;

	/**
	* @brief Devuelve el evento dado una "key" o una fecha
	* @param anio, fecha del evento, en este caso, una key del map
	* @return evento ocurrido en esa fecha
	*/
  EventoHistorico& getEvento(int anio);

	/**
	* @brief Inserta un evento en la cronología
	* @param e, evento a insertar
	*/
  void inserta(const EventoHistorico& e);

	/**
	* @brief Sobrecarga del operador de salida para el TDA Cronologia
	* @param os, flujo de salida
	* @param c, cronologia a ser mostrada
	* @return ostream&, flujo de salida para poder concatenar salidas
	*/
  friend ostream& operator<<(ostream& os, Cronologia& c);

	/**
	* @brief Sobrecarga del operador de entrada para el TDA Cronologia
	* @param is, flujo de entrada
	* @param c, cronología a ser leída
	* @return istream&, flujo de entrada para poder concatenar entradas
	*/
  friend istream& operator>>(istream& is, Cronologia& c);

	/**
	* @brief Dada dos cronologías crea una resultante de mezlar las dos. Esta función podría estar fuera de la clase
	* @param c1, primera cronología
	* @param c2, segunda cronología
	* @return cronologia resultante
	*/
	Cronologia& une_cronologias (Cronologia& c1, Cronologia&c2);

	/**
	* @brief Crea una subcronología a partir de los eventos que contengan la palabra clave
	* @param palabraclave, palabra que selecciona los eventos
	* @return Cronologia resultante
	*/
 	//Cronologia& filtrado_por_clave (const string& palabraclave);

	/**
	* @brief Crea una subcronología a partir de dos fechas
	* @param comienzo, fecha inicial de la subcronología
	* @param fin, fecha final de la subcronología
	* @return cronología resultante
	*/
	Cronologia& filtrado_por_intervalo (int comienzo, int fin);

	/**
	* @brief Construye unas estadísticas sobre la cronología, en concreto, el número de años que aparecen, el número de sucesos que aparecen, el máximo de sucesos en un año y la media de sucesos por años
	* @param total_anios, número total de años que aparecen en la cronología
	* @param total_acont, número total de sucesos que aparecen en la cronología
	* @param max_acont, número máximo de sucesos que aparece en un año
	* @param media_acont, media del número de sucesos por año
	*/
	void estadisticas(int& total_anios, int& total_acont, int& max_acont, double& media_acont);

};

/*
      >[TO DO]<
      > Implementar funciones en los distintos cpps (no olvidar incluir el .h)
      > Makefike
      > Doxygen (hecho salvo que se implemente alguna función adicional)
*/
#endif
