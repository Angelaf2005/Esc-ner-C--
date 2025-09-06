#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>
#include <vector>

//using namespace std; //puede contaminar los namespaces globales (no usar en .h)

class excepciones {
    std::string mensaje_error;
public:
    excepciones(std::string men = "Error desconocido") : mensaje_error(men) {}
    std::string what() const { return mensaje_error; }
};

struct objetivo {
    std::string ip; /// Aquí se añadiran los campos de los rangos o listas de puertos.
    int modo;
    int puerto_inicial = 0;
    int puerto_final = 0;
    std::vector<int> puertos = {};
    std::string filename;
};

struct puerto {
    int puerto;
    int modo;
};


objetivo* obtener_datos();
bool validar_ip(std::string &ip);
void validar_rango_puertos();
bool validar_lista();
std::vector<int> ingresar_lista_puertos();


#endif
