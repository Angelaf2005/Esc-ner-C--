#ifndef VALIDACIONES
#define VALIDACIONES

struct objetivo {
    std::string ip;
};

struct puerto {
    int puerto;
    std::string estado;
};


objetivo* obtener_datos();

#endif
