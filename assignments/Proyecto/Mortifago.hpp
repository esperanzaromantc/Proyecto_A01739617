#ifndef MORTIFAGO_HPP
#define MORTIFAGO_HPP

#include "Personaje.hpp"

class Mortifago : public Personaje {
private:
    int nivelOscuridad;
    bool marcaTenebrosa;

public:
    Mortifago();
    Mortifago(int v, int a, int n, int no, bool mt);
    
    int getNivelOscuridad();
    bool getMarcaTenebrosa();
    
    void setNivelOscuridad(int no);
    void setMarcaTenebrosa(bool mt);
    
    void imprimir();
    void atacar(Personaje &objetivo);
    void recibeAtaque(int ptosAtaque);
};

#endif