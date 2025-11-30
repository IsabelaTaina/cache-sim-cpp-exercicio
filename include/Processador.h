#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include "NivelMemoria.h"

class Processador {
private:
    int tipo;
    int buffer;
    int acessos;
    int stride;
    NivelMemoria *primeiro;
    int ciclos;

public:
    Processador();
    void configurar(int t, int b, int a, int s, NivelMemoria *p);
    void executar();
    int getCiclos();
};

#endif
