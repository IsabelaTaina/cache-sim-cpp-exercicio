#ifndef MEMORIAPRINCIPAL_H
#define MEMORIAPRINCIPAL_H

#include <string>
#include "NivelMemoria.h"
using namespace std;

class MemoriaPrincipal : public NivelMemoria {
private:
    int latencia;
    int leituras;
    int escritas;
    string nome;

public:
    MemoriaPrincipal(string n, int l);
    int access(int endereco, bool escrita);
    void printStats();
};

#endif
