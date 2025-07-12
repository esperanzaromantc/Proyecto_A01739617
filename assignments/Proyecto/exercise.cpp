#include "Personaje.hpp"
#include "Auror.hpp"
#include "Elfo.hpp"
#include "Mortifago.hpp"
#include <iostream>
using namespace std;

int main() {
    Auror harry(150, 20, 5, 80, 85);
    Elfo dobby(120, 15, 3, 40, 60, true);
    Mortifago lucius(130, 25, 4, 75, true);

    cout << "==================================" << endl;
    cout << "Inicio" << endl;
    cout << "Harry Potter:" << endl;
    harry.imprimir();
    cout << "\nDobby:" << endl;
    dobby.imprimir();
    cout << "\nLucius Malfoy:" << endl;
    lucius.imprimir();
    
    cout << "==================================" << endl;
    cout << "\nPelea1: Harry vs Lucius" << endl;
    harry.atacar(lucius);
    lucius.atacar(harry);
    cout << "\nDespues del intercambio:" << endl;
    cout << "Harry:" << endl;
    harry.imprimir();
    cout << "\nLucius:" << endl;
    lucius.imprimir();
    
    cout << "==================================" << endl;
    cout << "\nPelea 2: Dobby vs Lucius" << endl;
    dobby.atacar(lucius);
    lucius.atacar(dobby);
    cout << "\nDespues del intercambio:" << endl;
    cout << "Dobby:" << endl;
    dobby.imprimir();
    cout << "\nLucius:" << endl;
    lucius.imprimir();
    cout << "==================================" << endl;
    
    return 0;
}

