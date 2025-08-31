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
class excepciones {
    string mensaje_error;
    public:
    excepciones(string men = "Error desconocido") : mensaje_error(men) {}
    string what() { return mensaje_error; }
}

objetivo* obtener_datos();
validar_ip(string &ip)

#endif
