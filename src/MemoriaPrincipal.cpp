#include "MemoriaPrincipal.h"
#include <iostream>
using namespace std;

MemoriaPrincipal::MemoriaPrincipal(string n, int l) {
    nome = n;
    latencia = l;
    leituras = 0;
    escritas = 0;
}

int MemoriaPrincipal::access(int endereco, bool escrita) {
    if (escrita) escritas++;
    else leituras++;
    return latencia;
}

void MemoriaPrincipal::printStats() {
    cout << "=== " << nome << " ===\n";
    cout << "Latencia: " << latencia << "\n";
    cout << "Leituras: " << leituras << "\n";
    cout << "Escritas: " << escritas << "\n";
}
