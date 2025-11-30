#include "Processador.h"
#include <cstdlib>
#include <ctime>

Processador::Processador() {
    tipo = 0;
    buffer = 256;
    acessos = 1000;
    stride = 1;
    primeiro = NULL;
    ciclos = 0;
}

void Processador::configurar(int t, int b, int a, int s, NivelMemoria *p) {
    tipo = t;
    buffer = b;
    acessos = a;
    stride = s;
    primeiro = p;
    ciclos = 0;
}

int Processador::getCiclos() {
    return ciclos;
}

void Processador::executar() {
    srand((unsigned int) time(NULL));
    int atual = 0;

    for (int i = 0; i < acessos; i++) {
        int end;
        if (tipo == 0) {
            end = atual % buffer;
            atual += stride;
        } else {
            end = rand() % buffer;
        }

        bool esc = (rand() % 2 == 1);

        ciclos += primeiro->access(end, esc);
    }
}
