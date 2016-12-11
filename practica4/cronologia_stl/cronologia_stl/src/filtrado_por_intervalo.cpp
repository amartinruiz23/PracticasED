#include <iostream>
#include "cronologia.h"
using namespace std ;

int main (int argc, char* argv[]){

	if (argc > 5 || argc < 4) {
		cout << "Fallo en los parámetros. Recuerde ./filtrado_por_invervalo nombre_fichero_entrada limite_inferior limite_superior nombre_fichero_salida[opcional]" << endl ;
		return 0 ;
	}

	else {
		if (argc >= 4) {
			ifstream fin(argv[1]);
			if (!fin) {
				cout << "Error al abrir el archivo "<<argv[1]<<endl;
				return 0 ;
			}
			else {
				Cronologia c ;
				fin >> c ;
				
				int inferior = argv[2] ;
				int superior = argv[3] ;

				Cronologia filtrada (c.filtrado_por_invervalo(inferior,superior));

				if (argc == 5) {
					ofstream fout(argv[5]);

					if (!fout) {
						cout << "Error con el fichero de salida" << endl;
						cout << filtrada ;
					}
					else 
						fout << filtrada ;
				}
				else 
					cout << filtrada ;
			}
		}
	}

} 
