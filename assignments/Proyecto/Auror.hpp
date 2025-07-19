#ifndef AUROR_HPP
#define AUROR_HPP

#include "Personaje.hpp"

class Auror : public Personaje {
private:
    int poderPatronus;
    int resistenciaOscura;

public:
    Auror();
    Auror(int v, int a, int n, int pp, int ro);
    
    int getPoderPatronus();
    int getResistenciaOscura();
    
    void setPoderPatronus(int pp);
    void setResistenciaOscura(int ro);
    
    void imprimir() override;
    void atacar(Personaje &objetivo) override;
    void recibeAtaque(int ptosAtaque) override;
    bool estaVivo() override;
};

#endif