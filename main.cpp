#include <iostream>
#include "art.h"
#include "validaciones.h"

// Prueba
int main()
{

    objetivo* Dir_escaneo;
    visualizacion_inicio();
    Dir_escaneo = obtener_datos();

    int startPort = 1;
    int endPort = 500;

    cout << "Escaneando " << Dir_escaneo->ip << " desde el puerto " << startPort << " hasta " << endPort << "...\n";
    scan(Dir_escaneo->ip, startPort, endPort);
    cout << "Escaneo terminado." << endl;


    return 0;


}