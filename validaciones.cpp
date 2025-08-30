#include <iostream>
#include "validaciones.h"
#include <string>
#include <regex>


bool validar_ip(){
    /// Aquí planeaba usar regex para validar, solo hay que ver qué onda con la excepción de errores
    return true;
}


objetivo* obtener_datos(){
    objetivo* Dir_escaneo = new objetivo;

    std::cout << "Ingresa direccion IP objetivo para el escaneo: " << std::endl;
    std::cin >> Dir_escaneo->ip;
    /// esta función reserva un espacio para el struct que contiene la dirección IP que se asignará al struct

    return Dir_escaneo;
}

