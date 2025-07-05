//GEnera la implementación de la clase base Personaje

#include "Personaje.hpp"
#include <iostream>
using namespace std;

Personaje::Personaje() {
    vida = 100;
    salud = vida;
    ataque = 10;
    nivel = 1;
}

Personaje::Personaje(int v, int a, int n) {
    vida = v;
    salud = vida;
    ataque = a;
    nivel = n;
}

int Personaje::getVida() {
    return vida;
}

void Personaje::setVida(int v) {
    vida = v;
}

int Personaje::getSalud() {
    return salud;
}

void Personaje::setSalud(int s) {
    salud = s;
}

int Personaje::getAtaque() {
    return ataque;
}

void Personaje::setAtaque(int a) {
    ataque = a;
}

int Personaje::getNivel() {
    return nivel;
}

void Personaje::setNivel(int n) {
    nivel = n;
}

int Personaje::porcentajeSalud() {
    return (salud * 100) / vida;
}

void Personaje::imprimeBarra() {
    int porcentaje = porcentajeSalud();
    int cantidad = porcentaje / 5;

    cout << "Salud [%";  

    for (int i = 0; i < cantidad; i++) {
        cout << "#";  
    }
    for (int i = cantidad; i < 20; i++) {
        cout << "-";
    }
    cout << "] " << porcentaje << "%" << endl;  
}

void Personaje::recibeAtaque(int ptosAtaque) {
    salud -= ptosAtaque;
    if (salud < 0) salud = 0;
}

void Personaje::atacar(Personaje &objetivo) {
    int danio;
    if (objetivo.getNivel() > nivel) {
        danio = rand() % (ataque / 2) + 1;
    } else {
        danio = (ataque / 2) + rand() % (ataque / 2+1);
    }
    objetivo.recibeAtaque(danio);
}

void Personaje::imprimir() {
    cout << "Vida: " << vida << endl;
    cout << "Salud actual: " << salud << endl;
    cout << "Ataque: " << ataque << endl;
    cout << "Nivel: " << nivel << endl;
    imprimeBarra();
}
