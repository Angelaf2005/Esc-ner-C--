#include <iostream>
#include "art.h"
#include "validaciones.h"
#include "escaneo.h"

// Prueba
int main()
{

    objetivo* Dir_escaneo;
    visualizacion_inicio();
    Dir_escaneo = obtener_datos();

    int startPort = 1;
    int endPort = 100;
	// 0 - Rango  1 - Lista  2 - Top ports  3 - Todos
    cout << "Escaneando " << Dir_escaneo->ip << " desde el puerto " << startPort << " hasta " << endPort << "...\n";
    scan(Dir_escaneo->ip, 1, startPort, endPort, {10,12,15,20,25,53,80,110,143,443,445,993,995,1723,3306,3389,5900,8080});
    cout << "Escaneo terminado." << endl;

    delete Dir_escaneo;
    return 0;


}