#include <iostream>
#include "validaciones.h"
#include <string>
#include <string.h>
#include <regex>
#include <limits>
#include <vector>
#include <exception>
#include <sstream>

bool validar_ip(std::string& ip){
    std::regex ipv4(R"(^((25[0-5]|(2[0-4][0-9])|(1[0-9][0-9])|([1-9]?[0-9]))\.){3}(25[0-5]|(2[0-4][0-9])|(1[0-9][0-9])|([1-9]?[0-9]))$)");
    if(!regex_match(ip,ipv4)){
       throw excepciones("Se ingreso una direccion IP no valida");
    } else {
        return true;
    }
}

void validar_rango_puertos(objetivo& Dir){
    std::cin.exceptions(std::ios::failbit | std::ios::badbit);
    int puerto_inicial;
    int puerto_final;
    while (true)
    {
        try {
            std::cout << "Ingresa puerto inicial (1 - 65535): " << std::endl;
            std::cin >> puerto_inicial;
            if(puerto_inicial>= 1 and puerto_inicial <= 65535){
                std::cout << "Ingresa puerto final (" << puerto_inicial << " - 65535)" << std::endl;
                std::cin >> puerto_final;
                if(puerto_final >= puerto_inicial && puerto_final <= 65535){
                    Dir.puerto_inicial = puerto_inicial;
                    Dir.puerto_final = puerto_final;
                    return;
                } else{
                    std::cout << "Puerto no valido, ingrese de nuevo" << std::endl;
                    continue;
                }
            } else{
                std::cout << "Puerto no valido, ingrese de nuevo" << std::endl;
                continue;
            }
        } catch(const std::ios_base::failure& e) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error al ingresar puertos, vuelva a ingresar" << std::endl;
        }
        
    }
    
}

bool validar_lista(std::string& lista_puertos){
    std::regex puertos(R"(^([1-9]|[1-9]\d{1,3}|[1-5]\d{4}|6[0-4]\d{3}|65[0-4]\d{2}|655[0-2]\d|6553[0-5])(,([1-9]|[1-9]\d{1,3}|[1-5]\d{4}|6[0-4]\d{3}|65[0-4]\d{2}|655[0-2]\d|6553[0-5]))*$)");
    if(!regex_match(lista_puertos,puertos)){
        throw excepciones("No se ingresó una lista de puertos valida");
    } else {
        return true;
    }
}



std::vector<int> ingresar_lista_puertos (){
    std::string lista_puertos;
    std::string token;
    std::vector<int> puertos;


    while (true)
    {
        try
        {
            std::cout << "Ingresa tu lista de puertos(ex: 80,443,53): ";
            std::cin >> lista_puertos;
            validar_lista(lista_puertos);
            std::stringstream ss(lista_puertos);
            while (std::getline(ss, token, ',')) {
                int puerto = std::stoi(token);
                if (puerto >= 1 && puerto <= 65535) {
                    puertos.push_back(puerto);
                }
            }
            return puertos;
        } catch(const std::ios_base::failure& e) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ocurrió un error, ingrese de nuevo: " << std::endl;
        } catch(const excepciones& e){
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}











objetivo* obtener_datos(){
    objetivo* Dir_escaneo = new objetivo;
    std::string ip;
    int opcion;
    std::cin.exceptions(std::ios::failbit | std::ios::badbit);
    while (true)
    {   try{
        std::cout << "Ingresa direccion IP objetivo para el escaneo: " << std::endl;
        std::cin >> ip;
        validar_ip(ip);
        break;} catch (const std::ios_base::failure& e){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "La entrada es inválida.";
        } catch(const excepciones& e){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    while (true)
    {
        try{
            std::cout << R"( 
Elegir tipo de escaneo:
0) Rango de puertos
1) Lista de puertos
2) Escaneo de puertos comunes
3) Todos los puertos
            )" << std::endl;
            std::cin >> opcion;
            if(opcion >= 0 && opcion <= 3){
                Dir_escaneo->modo = opcion;
                break;
            }  else {
                std::cout << "Se ingreso una opcion no valida, vuelve a ingresar" << std::endl;
            }

        } catch(const std::ios_base::failure& e){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "La entrada es inválida, vuelve a ingresar";
        }
    }

    bool flag = true;
    while (flag) {
        try {
            switch (opcion) {
                case 0:
                    validar_rango_puertos(*Dir_escaneo);
                    flag = false;
                    break;
                case 1:
                    Dir_escaneo->puertos = ingresar_lista_puertos();
                    flag = false;
                    break;
                default:
                    flag = false;
                    break;
            }
        } catch(const std::exception& e) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error, intente de nuevo"<< std::endl;
        }
    }

    Dir_escaneo->ip = ip;
    return Dir_escaneo;
    /// esta función reserva un espacio para el struct que contiene la dirección IP que se asignará al struct
}

// int main(){
//     objetivo* Dir_escaneo;
//     Dir_escaneo = obtener_datos();
//     std::cout << Dir_escaneo->ip << std::endl;
//     std::cout << Dir_escaneo->modo << std::endl;
//     std::cout << Dir_escaneo->puerto_inicial << std::endl;
//     std::cout << Dir_escaneo->puerto_final << std::endl;
//     std::cout << "[";
//     for (size_t i = 0; i < Dir_escaneo->puertos.size(); ++i) {
//         std::cout << Dir_escaneo->puertos[i];
//         if (i < Dir_escaneo->puertos.size() - 1) std::cout << ",";
//     }
//     std::cout << "]" << std::endl;



//     return 0;
// }