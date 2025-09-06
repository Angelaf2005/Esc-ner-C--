#include <iostream>
#include "../include/art.h"
#include "../include/validaciones.h"
#include "../include/escaneo.h"

using namespace std;

// Prueba
int main() {
    objetivo* Dir_escaneo;
    visualizacion_inicio();
    Dir_escaneo = obtener_datos();

	// 0 - Rango  1 - Lista  2 - Top ports  3 - Todos
    switch (Dir_escaneo->modo) {
		case 0: // Rango
		    cout << " desde el puerto " << Dir_escaneo->puerto_inicial
		        << " hasta " << Dir_escaneo->puerto_final;
		    break;
		case 1: // Lista
		    cout << " en los puertos: ";
		    for (size_t i = 0; i < Dir_escaneo->puertos.size(); ++i) {
		        cout << Dir_escaneo->puertos[i];
		        if (i < Dir_escaneo->puertos.size() - 1)
		            cout << ",";
		    }
		    break;
		case 2: // Puertos top
		    cout << " en puertos comunes: 20,21,22,23,25,53,67,68,80,110,143,443,3306,3389,5900,8080";
		    break;
		case 3: // Todos
		    cout << " en todos los puertos";
		    break;
		}
		
	cout << "..." << endl;
	scan(Dir_escaneo->ip, Dir_escaneo->modo, Dir_escaneo->puerto_inicial, Dir_escaneo->puerto_final, Dir_escaneo->puertos, Dir_escaneo->filename);
    cout << "Escaneo terminado." << endl;

    delete Dir_escaneo;
    return 0;
}
