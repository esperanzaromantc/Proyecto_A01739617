#include "Personaje.hpp"
#include "Auror.hpp"
#include "Elfo.hpp"
#include "Mortifago.hpp"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

int main() {
    // Crear vector de apuntadores a Personaje
    vector<Personaje*> combatientes;
    
    // Crear objetos dinámicamente
    combatientes.push_back(new Auror(150, 20, 5, 80, 85));
    combatientes.push_back(new Elfo(120, 15, 3, 40, 60, true));
    combatientes.push_back(new Mortifago(130, 25, 4, 75, true));
    
    // Imprimir información inicial usando polimorfismo
    cout << "=== MUNDO MAGICO ===" << endl;
    for (size_t i = 0; i < combatientes.size(); ++i) {
        cout << "\nCombatiente " << i+1 << ":" << endl;
        combatientes[i]->imprimir();
    }
    
    // Probar polimorfismo en ataques
    cout << "\n=== INICIO ===" << endl;
    for (size_t i = 0; i < combatientes.size(); ++i) {
        size_t objetivo = (i + 1) % combatientes.size();
        cout << "\nEl " << i+1 << " ataca a el  " << objetivo+1 << endl;
        
        combatientes[i]->atacar(*combatientes[objetivo]);
        
        cout << "Estado despues de la pelea:" << endl;
        combatientes[objetivo]->imprimir();
    }
    
    // Probar la sobrecarga del operador <<
    cout << "\n=== Resumen de la batalla ===" << endl;
    for (size_t i = 0; i < combatientes.size(); ++i) {
        cout << "Combatiente " << i+1 << ": " << *combatientes[i] << endl;
    }
    
    // Liberar memoria
    for (auto* combatiente : combatientes) {
        delete combatiente;
    }
    
    return 0;
}