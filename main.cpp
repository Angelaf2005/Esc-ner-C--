#include <iostream>
#include "art.h"
#include "validaciones.h"
#include "escaneo.h"

using namespace std;

// Prueba
int main() {
    objetivo* Dir_escaneo;
    visualizacion_inicio();
    Dir_escaneo = obtener_datos();

	// 0 - Rango  1 - Lista  2 - Top ports  3 - Todos
    cout << "Escaneando " << Dir_escaneo->ip << " desde el puerto " << Dir_escaneo->puerto_inicial << " hasta " << Dir_escaneo->puerto_final << "...\n";
    scan(Dir_escaneo->ip, Dir_escaneo->modo, Dir_escaneo->puerto_inicial, Dir_escaneo->puerto_final, Dir_escaneo->puertos);
    cout << "Escaneo terminado." << endl;

    delete Dir_escaneo;
    return 0;
}