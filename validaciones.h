#ifndef VALIDACIONES
#define VALIDACIONES

struct objetivo {
    std::string ip; /// Aquí se añadiran los campos de los rangos o listas de puertos.
};

struct puerto {
    int puerto;
    std::string estado;
};


objetivo* obtener_datos();

#endif
