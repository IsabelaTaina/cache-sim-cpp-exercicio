#include "Cache.h"
#include <iostream>
using namespace std;

Linha::Linha() {
    tag = -1;
    valido = false;
    sujo = false;
    uso = 0;
}

Cache::Cache(string n, int lat, int assoc, int conj, int linha, int pol, NivelMemoria *prox) {
    nome = n;
    latencia = lat;
    associatividade = assoc;
    conjuntos = conj;
    tamanhoLinha = linha;
    politica = pol;
    proximo = prox;

    linhas.resize(conjuntos, vector<Linha>(associatividade));
    leituras = 0;
    escritas = 0;
    hits = 0;
    misses = 0;
    tempo = 0;
}

int Cache::encontrar(int c, int t) {
    for (int i = 0; i < associatividade; i++) {
        if (linhas[c][i].valido && linhas[c][i].tag == t) return i;
    }
    return -1;
}

int Cache::escolherLRU(int c) {
    int menor = linhas[c][0].uso;
    int idx = 0;
    for (int i = 1; i < associatividade; i++) {
        if (!linhas[c][i].valido) return i;
        if (linhas[c][i].uso < menor) {
            menor = linhas[c][i].uso;
            idx = i;
        }
    }
    return idx;
}

int Cache::access(int endereco, bool escrita) {
    tempo++;

    int bloco = endereco / tamanhoLinha;
    int c = bloco % conjuntos;
    int tag = bloco / conjuntos;

    if (escrita) escritas++;
    else leituras++;

    int pos = encontrar(c, tag);

    if (pos != -1) {
        hits++;
        linhas[c][pos].uso = tempo;

        if (escrita && politica == 1)
            linhas[c][pos].sujo = true;

        if (escrita && politica == 0)
            return latencia + proximo->access(endereco, true);

        return latencia;
    }

    misses++;

    int latProx = proximo->access(endereco, false);

    int vit = escolherLRU(c);

    if (linhas[c][vit].valido && linhas[c][vit].sujo && politica == 1) {
        int endAnt = linhas[c][vit].tag * conjuntos * tamanhoLinha;
        proximo->access(endAnt, true);
    }

    linhas[c][vit].valido = true;
    linhas[c][vit].tag = tag;
    linhas[c][vit].sujo = false;
    linhas[c][vit].uso = tempo;

    if (escrita && politica == 0) {
        int w = proximo->access(endereco, true);
        return latencia + latProx + w;
    }

    if (escrita && politica == 1)
        linhas[c][vit].sujo = true;

    return latencia + latProx;
}

void Cache::printStats() {
    cout << "=== " << nome << " ===\n";
    cout << "Latencia: " << latencia << "\n";
    cout << "Leituras: " << leituras << "\n";
    cout << "Escritas: " << escritas << "\n";
    cout << "Hits: " << hits << "\n";
    cout << "Misses: " << misses << "\n";
}
