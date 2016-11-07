/**
  * @file evento.h
  * @brief Fichero cabecera del TDA evento (histórico)
  *
  */


#ifndef _EVENTO_H_
#define _EVENTO_H_

#include <string>
#include <vector>
#include <iostream>
using namespace std;

	/**
  *  @brief T.D.A. evento
  *
  * Una instancia @e c del tipo de datos abstracto @c evento es un objeto
  * compuesto por un valor entero que representa la fecha del evento y un 
  * vector de string que representan los sucesos que tuvieron lugar ese
  * año
  * 
  * @author Álvaro López Jiménez , Antonio Martín Ruíz
  * @date Octubre 2016
  */
class evento{


	/**
  * @page repConjunto Rep del TDA evento
  */


  int anio;
  vector<string> sucesos;

  public:

	/**
	* @brief Constructor por defecto de eventos
	*/
  evento();

	/**
	* @brief Constructor de eventos
	* @param a año del suceso
	* @param s suceso a crear
	*/
	evento(int a, const vector<string>& s);

	/**
	* @brief Constructor copia de eventos
	* @param e evento a copiar
	*/
  evento(const evento& e);

	/**
	* @brief Destructor de eventos
	*/
  ~evento();

	/**
	* @brief Operador de asignación de eventos
	* @param e evento a asignar
	* @return referencia al evento asignado
	*/
  evento& operator=(const evento& e);

	/**
	* @brief Comprueba si dos eventos son iguales
	* @param e evento a comparar
	* @return 1 indica si son iguales, 0 si no lo son
	*/
	bool operator==(const evento& e);

	/**
	* @brief Comprueba si un evento es más reciente que otro
	* @param e evento a comparar
	* @return 1 indica que es más reciente, 0 si no lo es
	*/
	bool operator>(const evento& e);

	/**
	* @brief Comprueba si un evento es menos reciente que otro
	* @param e evento a comparar
	* @return 1 indica que es menos reciente, 0 si no lo es
	*/
	bool operator<(const evento& e);

	/**
	* @brief Consulta del año de un evento
	* @return año del evento
	*/
  int getanio();

	/**
	* @brief Consulta de un suceso de un evento
	* @param n posicion del suceso a consultar en el vector
	* @pre n debe ser mayor o igual a 1
	* @return suceso consultado
	*/
  string& getsuceso(int n);

	/**
	* @brief Inserta un suceso
	* @param s suceso a insertar
	*/
  void insertasuceso(string s);

	/**
	* @brief Elimina un suceso de un evento
	* @param n posición del suceso en el vector a eliminar
	* @pre n tiene que ser mayor o igual a 1
	*/
	void eliminasuceso(int n);

	/**
	* @brief Elimina un suceso de un evento
	* @param s suceso a eliminar
	* @return si ha eliminado dicho suceso
	*/
	bool eliminasuceso(const string& s);

  /**
  * @brief Devuelve cuantos sucesos hay en un evento
  * @return Número de sucesos del evento
  */

  int CuantosSucesos();

  /**
  * @brief Operador para sumar eventos.
  * @param e evento a sumar
	* @pre el año del evento tiene que coincidir
  * @return un evento como suma del evento y e
  */
  evento& operator+(const evento& e);

	/**
	* @brief Operador para leer desde un flujo de entrada un evento
	* @param f flujo de entrada
	* @param e evento a modificar o ser leído
	* @return referencia a flujo para poder encadenar lecturas
	*/
	friend istream& operator>>(istream& f , evento& e);

	/**
	* @brief Operador para escribir en un flujo de salida un evento
	* @param f flujo de salida
	* @param e evento a imprimir o ser escrito
	* @return referencia a flujo para poder encadenar escrituras
	*/
	friend ostream& operator<<(ostream& f , const evento& e);

};

#endif
