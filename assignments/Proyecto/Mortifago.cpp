#include "Mortifago.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Mortifago::Mortifago() : Personaje() {
    nivelOscuridad = 60;
    marcaTenebrosa = true;
}

Mortifago::Mortifago(int v, int a, int n, int no, bool mt) : Personaje(v, a, n) {
    nivelOscuridad = no;
    marcaTenebrosa = mt;
}

int Mortifago::getNivelOscuridad() {
    return nivelOscuridad;
}

bool Mortifago::getMarcaTenebrosa() {
    return marcaTenebrosa;
}

void Mortifago::setNivelOscuridad(int no) {
    nivelOscuridad = no;
}

void Mortifago::setMarcaTenebrosa(bool mt) {
    marcaTenebrosa = mt;
}

void Mortifago::imprimir() {
    Personaje::imprimir();
    cout << "Nivel de oscuridad: " << nivelOscuridad << endl;
    cout << "Tiene marca tenebrosa: " << (marcaTenebrosa ? "Si" : "No") << endl;
}

void Mortifago::atacar(Personaje &objetivo) {
    int danio;
    if (objetivo.getNivel() > getNivel()) {
        danio = rand() % (getAtaque() / 2) + 1;
    } else {
        danio = (getAtaque() / 2) + rand() % (getAtaque() / 2 + 1);
    }
    
    if (nivelOscuridad >= 70) {
        int probabilidad = rand() % 100;
        if (probabilidad < 30) {
            danio *= 2;
        }
    }
    
    objetivo.recibeAtaque(danio);
}

void Mortifago::recibeAtaque(int ptosAtaque) {
    setSalud(getSalud() - ptosAtaque);
    if (getSalud() < 0) setSalud(0);
}