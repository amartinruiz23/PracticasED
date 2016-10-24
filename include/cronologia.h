#ifndef _CRONOLOGIA_H_
#define _CRONOLOGIA_H_

#include "evento.h"

class cronologia {

	std::vector<evento> eventos ; // ????????????

	/**
	* @brief ordena la cronología por fechas de los eventos
	*/
	void ordenar();

	public:

		/**
		* @brief Constructor por defecto
		*/
		cronologia();

		/**
		* @brief Constructor copia
		* @param c cronologia a copiar
		*/
		cronologia(const cronologia& c);

		/**
		* @brief Destructor
		*/
		~cronologia();

		/**
		* @brief devuelve una cronología entre dos fechas
		* @param anio_inicio año a partir del cual empieza la subcronología
		* @param anio_final último año de la subcronología, por defecto, hasta hoy
		* @return cronología "recortada"
		*/
		cronologia subcronologia(int anio_inicio, int anio_final=2017);


		cronologia& operator+(const cronologia& c); // operator+ o funcion mezcla ??????????????????

		/**
		* @brief elimina un evento de la cronología
		* @param anio , año del evento que queremos borrar
		* @return si la operación ha tenido éxito
		*/
		bool eliminarevento (int anio);

		/**
		* @brief añade un evento a la cronología
		* @param e , evento a añadir
		* @return si la operación ha tenido éxito
		*/
		bool aniadirevento (evento& e);

		/**
		* @brief busca un evento en la cronología
		* @param anio , fecha del evento a buscar
		* @return evento buscado
		*/
		evento buscaevento (int anio) ;

		/**
		* @brief busca un evento en la cronología
		* @param s , suceso a buscar
		* @return evento buscado
		*/
		vector buscaevento (const string& s);

		/**
		* @brief Devuelve el vector de eventos
		* @return vector de eventos
		*/
		vector geteventos ();


};




#endif
