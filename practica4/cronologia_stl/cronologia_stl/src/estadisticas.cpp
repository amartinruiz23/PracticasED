#include <iostream>
#include <fstream>
#include "cronologia.h"
using namespace std;

int main (int argc, char* argv[]){

	if (argc > 2 || argc == 1) {
		cout << "Fallo en los parámetros. Recuerde ./estadisticas nombre_fichero_entrada" << endl;
		return 0 ;
	}
	else {
		ifstream f(argv[1]);
		if (!f) {
			cout << "Error al abrir el fichero "<< argv[1] << endl ;
			return 0 ;
		}
		else {
			Cronologia c ;
			f >> c ;
			int total_anios=0 ;
			int total_sucesos=0 ;
			int maximo=0 ;
			double promedio=0 ;

			c.estadisticas(total_anios,total_sucesos,maximo,promedio);
			cout << "Total de años para los que ha sucedido algún evento: " << total_anios << endl ;
			cout << "Total de sucesos de la cronología: " << total_sucesos << endl ;
			cout << "Máximo de eventos en un año: " << maximo << endl;
			cout << "Promedio de eventos por año: " << promedio << endl;
		}
	}
}
