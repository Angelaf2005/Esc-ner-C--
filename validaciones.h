#ifndef VALIDACIONES
#define VALIDACIONES
#include <string>
#include <vector>
using namespace std;

struct objetivo {
    string ip; /// Aquí se añadiran los campos de los rangos o listas de puertos.
};

struct puerto {
    int puerto;
    std::string estado;
};


objetivo* obtener_datos();

#endif
