#include "cronologia.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


int main (int argc, char* argv[]) {

	if (argc > 4)
		cout << "demasiados argumentos. Recuerde ./filtrado_por_clave nombre_fichero_entrada palabra_clave[opcional] nombre_fichero_salida[opcional]" << endl ;

	else {
		if (argc >= 2) {

			ifstream f1 (argv[1]);
			if (!f1){
				cout << "No puedo abrir el fichero "<<argv[1]<<endl;
				return 0 ;
			}

			Cronologia c, resultado;
			f1 >> c ;

			string clave ;

			if (argc>=3) {
				clave = argv[2] ;

				resultado = c.filtrado_por_clave(clave);

				if (argc == 4) {
					ofstream f2(argv[3]) ;
					if (f2) {
						f2 << resultado ;
						return 1 ;
						}
				}
				else {
					cout << resultado ;
				}
			}
			else {
				cout << "Introduzca la clave: " ;
				cin >>clave;
				resultado = c.filtrado_por_clave(clave);
				cout << resultado ;
			}
		}
		else {
			cout << "Argumentos insuficientes. Recuerde ./filtrado_por_clave nombre_fichero_entrada palabra_clave[opcional] nombre_fichero_salida[opcional]" << endl ;
			return 0 ;
		}

	}

}
