#ifndef NIVELMEMORIA_H
#define NIVELMEMORIA_H

class NivelMemoria {
public:
    virtual int access(int endereco, bool escrita) = 0;
    virtual void printStats() = 0;
    virtual ~NivelMemoria() {}
};

#endif
