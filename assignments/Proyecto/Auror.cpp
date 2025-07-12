#include "Auror.hpp"
#include "Personaje.hpp"
#include "Mortifago.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Auror::Auror() : Personaje() {
    poderPatronus = 50;
    resistenciaOscura = 50;
}

Auror::Auror(int v, int a, int n, int pp, int ro) : Personaje(v, a, n) {
    poderPatronus = pp;
    resistenciaOscura = ro;
}

int Auror::getPoderPatronus() {
    return poderPatronus;
}

int Auror::getResistenciaOscura() {
    return resistenciaOscura;
}

void Auror::setPoderPatronus(int pp) {
    poderPatronus = pp;
}

void Auror::setResistenciaOscura(int ro) {
    resistenciaOscura = ro;
}

void Auror::imprimir() {
    Personaje::imprimir();
    cout << "Poder del patronus: " << poderPatronus << endl;
    cout << "Resistencia a la magia oscura: " << resistenciaOscura << endl;
}

void Auror::atacar(Personaje &objetivo) {
    int danio;
    if (objetivo.getNivel() > getNivel()) {
        danio = rand() % (getAtaque() / 2) + 1;
    } else {
        danio = (getAtaque() / 2) + rand() % (getAtaque() / 2 + 1);
    }
    
    if (typeid(objetivo) == typeid(Mortifago)) {
        danio += danio * poderPatronus / 100;
    }
    
    objetivo.recibeAtaque(danio);
}

void Auror::recibeAtaque(int ptosAtaque) {
    int danio = ptosAtaque;
    
    if (resistenciaOscura >= 90) {
        danio = ptosAtaque / 2;
    } else if (resistenciaOscura >= 70) {
        danio = ptosAtaque * 0.75;
    }
    
    setSalud(getSalud() - danio);
    if (getSalud() < 0) setSalud(0);
}