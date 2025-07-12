#include "Elfo.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Elfo::Elfo() : Personaje() {
    poderElf = 30;
    magiaCurativa = 40;
    esLibre = true;
}

Elfo::Elfo(int v, int a, int n, int pe, int mc, bool el) : Personaje(v, a, n) {
    poderElf = pe;
    magiaCurativa = mc;
    esLibre = el;
}

int Elfo::getPoderElf() {
    return poderElf;
}

int Elfo::getMagiaCurativa() {
    return magiaCurativa;
}

bool Elfo::getEsLibre() {
    return esLibre;
}

void Elfo::setPoderElf(int pe) {
    poderElf = pe;
}

void Elfo::setMagiaCurativa(int mc) {
    magiaCurativa = mc;
}

void Elfo::setEsLibre(bool el) {
    esLibre = el;
}

void Elfo::imprimir() {
    Personaje::imprimir();
    cout << "Poder elfico: " << poderElf << endl;
    cout << "Magia curativa: " << magiaCurativa << endl;
    cout << "Es un elfo libre: " << (esLibre ? "Si" : "No") << endl;
}

void Elfo::atacar(Personaje &objetivo) {
    int danio;
    if (objetivo.getNivel() > getNivel()) {
        danio = rand() % (getAtaque() / 2) + 1;
    } else {
        danio = (getAtaque() / 2) + rand() % (getAtaque() / 2 + 1);
    }
    
    danio += danio * poderElf / 100;
    
    objetivo.recibeAtaque(danio);
}

void Elfo::recibeAtaque(int ptosAtaque) {
    int danio = ptosAtaque;
    
    if (esLibre) {
        danio = ptosAtaque * 0.85;
    }
    
    setSalud(getSalud() - danio);
    
    if (magiaCurativa >= 50) {
        int curacion = getVida() * 0.1;
        setSalud(getSalud() + curacion);
        if (getSalud() > getVida()) {
            setSalud(getVida());
        }
    }
    
    if (getSalud() < 0) setSalud(0);
}