#ifndef MORTIFAGO_HPP
#define MORTIFAGO_HPP

#include "Personaje.hpp"

class Mortifago : public Personaje {
private:
    int nivelOscuridad;
    bool marcaTenebrosa;

public:
    Mortifago();
    Mortifago(int v, int a, int n, int no, bool mt, const string &nom);
    
    int getNivelOscuridad();
    bool getMarcaTenebrosa();
    
    void setNivelOscuridad(int no);
    void setMarcaTenebrosa(bool mt);
    
    void imprimir() override;
    void atacar(Personaje &objetivo) override;
    void recibeAtaque(int ptosAtaque) override;
    bool estaVivo() override;
};

#endif