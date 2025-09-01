#ifndef VALIDACIONES
#define VALIDACIONES
#include <string>
#include <vector>
using namespace std;

class excepciones {
    string mensaje_error;
    public:
    excepciones(string men = "Error desconocido") : mensaje_error(men) {}
    string what() const { return mensaje_error; }
};

struct objetivo {
    string ip; /// Aquí se añadiran los campos de los rangos o listas de puertos.
    int modo;
    int puerto_inicial = 0;
    int puerto_final = 0;
    vector<int> puertos = {};
};

struct puerto {
    int puerto;
    int modo;
};


objetivo* obtener_datos();
bool validar_ip(string &ip);
void validar_rango_puertos();
bool validar_lista();
std::vector<int> ingresar_lista_puertos();


#endif
