
#ifndef personaje_hpp
#define personaje_hpp
#include <iostream>

class Personaje {
private:
    int vida;
    int salud;
    int ataque;
    int nivel;

public:
    Personaje();
    Personaje(int v, int a, int n);
    
    int getVida();
    int getSalud();
    int getAtaque();
    int getNivel();

    void setVida(int v);
    void setSalud(int s);
    void setAtaque(int a);
    void setNivel(int n);

    int porcentajeSalud();
    void imprimeBarra();
    virtual void recibeAtaque(int ptosAtaque);
    virtual void atacar(Personaje &objetivo);
    virtual void imprimir();
    virtual bool estaVivo() = 0;
    friend std::ostream& operator<<(std::ostream& os, const Personaje& p);
};

#endif