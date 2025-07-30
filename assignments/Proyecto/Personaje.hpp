
#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP
#include <iostream>
#include <string>
using namespace std;

class Personaje {
private:
    int vida;
    int salud;
    int ataque;
    int nivel;
    string nombre;

public:
    Personaje();
    Personaje(int v, int a, int n, const string &nom = "");
    
    int getVida();
    int getSalud();
    int getAtaque();
    int getNivel();
    string getNombre();

    void setVida(int v);
    void setSalud(int s);
    void setAtaque(int a);
    void setNivel(int n);
    void setNombre(const string &nom);

    int porcentajeSalud();
    void imprimeBarra();
    virtual void recibeAtaque(int ptosAtaque);
    virtual void atacar(Personaje &objetivo);
    virtual void imprimir();
    virtual bool estaVivo() = 0;
    friend std::ostream& operator<<(std::ostream& os, const Personaje& p);
};

#endif
