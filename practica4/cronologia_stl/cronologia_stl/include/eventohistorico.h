/**
*		TDA EventoHistorico
*
*		Antonio Martín Ruíz y Álvaro López Jiménez
*/

#ifndef _EventoHistorico_H_
#define _EventoHistorico_H_

#include <string>
#include <utility>
#include <set>
#include <iostream>
using namespace std;

/**
* TDA EventoHistorico
*
* @brief TDA contenedor de un par de elementos, un entero y un set de strings donde guardar un evento formado por una fecha y un conjunto de sucesos
*/
class EventoHistorico{
  pair<int, set<string> > evento;

public:
	/**
	* @brief Constructor por defecto
	*/
	EventoHistorico() = default;

	/**
	* @brief Destructor del TDA EventoHistorico
	*/
	~EventoHistorico() = default;

	/**
	* @brief Constructor copia del TDA EventoHistorico
	* @param h evento a copiar
	*/
	EventoHistorico(const EventoHistorico& h);

	/**
	* @brief Constructor del TDA EventoHistorico
	* @param p par de elementos formado por un entero (fecha) y un set de strings (conjunto de sucesos)
	*/
	EventoHistorico(const pair<int, set<string> >& p);

  /**
  * @brief Construcor de mezcla del TDA EventoHistorico
  * @pre El año de ambos eventos debe ser el mismo, de otra manera no tiene sentido mezclarlos.
  * @param e1 primer evento histórico
  * @param e2 segundo evento histórico
  */
  EventoHistorico(const EventoHistorico& e1,const  EventoHistorico& e2);

	/**
	* Definición de los iteradores sobre el TDA EventoHistorico
	*/
  typedef typename set<string>::iterator it;
  typedef typename set<string>::const_iterator constit;

	/**
	* @brief Comienzo o primer elemento del TDA EventoHistorico
	* @return iterator
	*/
  it begin();

	/**
	* @brief Final o ultimo elemento del TDA EventoHistorico
	* @return iterator
	*/
	it end();

	/**
	* @brief Comienzo o primer elemento del TDA EventoHistorico
	* @return const iterator
	*/
	constit begin() const;

	/**
	* @brief Final o ultimo elemento del TDA EventoHistorico
	* @return const iterator
	*/
	constit end() const;

	/**
	* @brief Consulta del año del evento
	* @return año del evento
	*/
  int getanio();

	/**
	* @brief Establece el año del evento
	* @param a año del evento
	*/
	void setanio(int a);

	/**
	* @brief Consulta de los sucesos del evento
	* @return set<string> con los sucesos
	*/
	set<string> getsucesos();

	/**
	* @brief Añade o establece un suceso al evento
	* @param s string con el suceso
	*/
  void insertasuceso(string s);

	/**
	* @brief Busca si un suceso esta en el evento
	* @param s suceso a comprobar si esta
	* @return suceso pasado como parámetro o un string con "No esta"
	*/
	string buscasuceso (string& s);

	/**
	* @brief Sobrecarga de operador de salida del TDA EventoHistorico
	* @param os flujo de salida
	* @param e Evento
	* @return flujo para poder concatenar salidas
	*/
  friend ostream& operator<<(ostream& os, EventoHistorico& e);

	/**
	* @brief Sobrecarga de operador de entrada del TDA EventoHistorico
	* @param is flujo de entrada
	* @param e evento
	* @return flujo para poder concatenar entradas
	*/
  friend istream& operator>>(istream& is, EventoHistorico& e);
};

#include "../src/eventohistorico.cpp"

#endif
