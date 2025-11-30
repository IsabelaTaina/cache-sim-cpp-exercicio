#include <iostream>
#include "MemoriaPrincipal.h"
#include "Cache.h"
#include "Processador.h"
using namespace std;

int main() {
    MemoriaPrincipal *ram = new MemoriaPrincipal("RAM", 100);

    Cache *l2 = new Cache("L2", 10, 4, 32, 64, 1, ram);
    Cache *l1 = new Cache("L1", 2, 2, 32, 64, 0, l2);

    Processador cpu;
    cpu.configurar(0, 1024, 5000, 1, l1);

    cpu.executar();

    cout << "===== RESULTADOS =====\n";
    cout << "Ciclos totais: " << cpu.getCiclos() << "\n\n";

    l1->printStats();
    cout << "\n";
    l2->printStats();
    cout << "\n";
    ram->printStats();

    delete l1;
    delete l2;
    delete ram;

    return 0;
}
