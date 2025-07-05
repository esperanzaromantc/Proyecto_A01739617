#include "Personaje.hpp"
#include <iostream>
using namespace std;

int main() 
{
  Personaje p1;
  Personaje p2(150,20,3);
  cout << "Personaje 1:" << endl;
  p1.imprimir();
  cout << "Personaje 2:" << endl;
  p2.imprimir();

  p1.atacar(p2);
  p2.atacar(p1);

  cout << "Despues del ataque:" << endl;
  cout << "Personaje 1:" << endl;
  p1.imprimir();
  cout << "Personaje 2:" << endl;
  p2.imprimir();
  
  return 0;

}
