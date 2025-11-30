#ifndef CACHE_H
#define CACHE_H

#include <string>
#include <vector>
#include "NivelMemoria.h"
using namespace std;

struct Linha {
    int tag;
    bool valido;
    bool sujo;
    int uso;
    Linha();
};

class Cache : public NivelMemoria {
private:
    string nome;
    int latencia;
    int associatividade;
    int conjuntos;
    int tamanhoLinha;
    int politica;
    NivelMemoria *proximo;
    vector< vector<Linha> > linhas;
    int leituras;
    int escritas;
    int hits;
    int misses;
    int tempo;

public:
    Cache(string n, int lat, int assoc, int conj, int linha, int pol, NivelMemoria *prox);
    int access(int endereco, bool escrita);
    int encontrar(int c, int t);
    int escolherLRU(int c);
    void printStats();
};

#endif
