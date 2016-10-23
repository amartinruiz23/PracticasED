#ifndef _EVENTO_H_
#define _EVENTO_H_
#include <string>
#include <vector>
#include <iostream>

class evento{
  int anio;
  std::vector<string> sucesos; // ???????????

  public:

	/** 
	* @brief Constructor por defecto de eventos
	* 
	*/
  evento();

	/**
	* @brief Constructor de eventos
	* @param a año del suceso
	* @param s suceso a crear
	*/
	evento(int a, std::const vector<string>& s);

	/**
	* @brief Constructor copia de eventos
	* @param e evento a copiar
	*/
  evento(std::const evento<string>& e);

	/**
	* @brief Destructor de eventos
	*/
  ~evento();

	/**
	* @brief Operador de asignación de eventos
	* @param e evento a asignar
	* @return referencia al evento asignado
	*/ 
  evento& operator=(std::const evento<string>& e);

	/**
	* @brief Comprueba si dos eventos son iguales
	* @param e evento a comparar
	* @return 1 indica si son iguales, 0 si no lo son
	*/ 
	bool operator==(std::const evento<string>& e);

	/**
	* @brief Comprueba si un evento es más reciente que otro
	* @param e evento a comparar
	* @return 1 indica que es más reciente, 0 si no lo es
	*/
	bool operator>(std::const evento<string>& e);

	/**
	* @brief Comprueba si un evento es menos reciente que otro
	* @param e evento a comparar
	* @return 1 indica que es menos reciente, 0 si no lo es
	*/
	bool operator<(std::const evento<string>& e);

	/** 
	* @brief Consulta del año de un evento
	* @param e evento a consultar
	* @return año del evento // especificamos tipo devuelto ?????????
	*/
  int getanio(std::const evento<string>& e);

	/** 
	* @brief Consulta de los sucesos de un evento
	* @param e evento a consultar
	* @return conjunto de sucesos del evento
	*/
 
  const vector& getsucesos(std::const evento<string>& e); // ?

	/** 
	* @brief Consulta de un suceso de un evento
	* @param e evento a consultar
	* @param n posicion del suceso a consultar en el vector
	* @pre n debe ser mayor o igual a 1
	* @return suceso consultado
	*/
  string getsuceso(std::const evento<string>& e, int n);

	/**
	* @brief Inserta un suceso
	* @param s suceso a insertar
	* @param p posicion del vector en la que se quiere insertar el suceso, si no se indica nada, será en la primera posición
	* @pre p tiene que ser mayor o igual a 1 en caso de que se quiera indicar la posición
	* @return // ???????????????????????????
	*/
  void insertasuceso(string s, int p=-1);

	/**
	* @brief Elimina un suceso de un evento
	* @param n posición del suceso en el vector a eliminar
	* @pre n tiene que ser mayor o igual a 1
	* @return // ?????????????????????????
	*/
	void eliminasuceso(int n);
	/**
	* @brief Elimina un suceso de un evento
	* @param s suceso a eliminar
	* @return si ha eliminado dicho suceso
	*/ 
	bool eliminasuceso(const string& s);

	/**
	* @brief Operador para leer desde un flujo de entrada un evento 
	* @param f flujo de entrada
	* @param e evento a modificar o ser leído
	* @return referencia a flujo para poder encadenar lecturas	
	*/	
	friend std::istream& operator>>(std::istream& f , sd::evento<string>& e); 

	/**
	* @brief Operador para escribir en un flujo de salida un evento
	* @param f flujo de salida
	* @param e evento a imprimir o ser escrito
	* @return referencia a flujo para poder encadenar escrituras
	*/
	friend std::ostream& operator<<(std::ostream& f , std::const evento<string>& e); 
	
};

#endif
