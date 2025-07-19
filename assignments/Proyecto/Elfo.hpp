#ifndef ELFO_HPP
#define ELFO_HPP

#include "Personaje.hpp"

class Elfo : public Personaje {
private:
    int poderElf;
    int magiaCurativa;
    bool esLibre;

public:
    Elfo();
    Elfo(int v, int a, int n, int pe, int mc, bool el);
    
    int getPoderElf();
    int getMagiaCurativa();
    bool getEsLibre();
    
    void setPoderElf(int pe);
    void setMagiaCurativa(int mc);
    void setEsLibre(bool el);
    
    void imprimir() override;
    void atacar(Personaje &objetivo) override;
    void recibeAtaque(int ptosAtaque) override;
    bool estaVivo() override;
};

#endif