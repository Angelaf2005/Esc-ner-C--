#include <iostream>
#include "validaciones.h"
#include <string>
#include <regex>
#include <limits>

bool validar_ip(std::string& ip){
    std::regex ipv4(R"(^((25[0-5]|(2[0-4][0-9])|(1[0-9][0-9])|([1-9]?[0-9]))\.){3}(25[0-5]|(2[0-4][0-9])|(1[0-9][0-9])|([1-9]?[0-9]))$)");
    if(!regex_match(ip,ipv4)){
       throw excepciones("Se ingresó una dirección IP no válida");
    } else {
        return true;
    }
    ;
}


objetivo* obtener_datos(){
    objetivo* Dir_escaneo = new objetivo;
    std::string ip;
    std::cin.exceptions(std::ios::failbit | std::ios::failure);
    while (true)
    {   try{
        std::cout << "Ingresa direccion IP objetivo para el escaneo: " << std::endl;
        std::cin >> ip;
        validar_ip(ip);
        break;} catch (const std::ios_base::failure& e){
            std::cin.clear();
            std::cin.ignore(numeric_limits<int>::max(), '\n');
            std::cout << "La entrada es inválida.";
        } catch(const excepciones& e){
                std::cout << "Error: " << e.what() << std::endl;
        }
    } 
    Dir_escaneo->ip = ip;
    return Dir_escaneo;
    /// esta función reserva un espacio para el struct que contiene la dirección IP que se asignará al struct
}

