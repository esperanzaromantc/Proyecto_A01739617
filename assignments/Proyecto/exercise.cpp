#include "Personaje.hpp"
#include "Auror.hpp"
#include "Elfo.hpp"
#include "Mortifago.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void cargarEjercito(Personaje* ejercito[], int &tam, const char* nombreArchivo);
void imprimirEjercito(Personaje* ejercito[], int tam, const string &nombreEjercito);
void batalla(Personaje* ejercito1[], int &tam1, Personaje* ejercito2[], int &tam2);
void liberarEjercito(Personaje* ejercito[], int tam);

int main() {
    srand(time(NULL));

    const int MAX = 20;
    Personaje* ejercitoDumbledore[MAX];
    Personaje* ejercitoVoldemort[MAX];
    int tamD = 0, tamV = 0;

    try {
        cargarEjercito(ejercitoDumbledore, tamD, "EjercitoDumbledore.txt");
        cargarEjercito(ejercitoVoldemort, tamV, "EjercitoVoldemort.txt");
    } catch (const char* e) {
        cout << "Error: " << e << endl;
        return 1;
    }

    imprimirEjercito(ejercitoDumbledore, tamD, "Ejercito de Dumbledore");
    imprimirEjercito(ejercitoVoldemort, tamV, "Ejercito de Voldemort");

    batalla(ejercitoDumbledore, tamD, ejercitoVoldemort, tamV);

    liberarEjercito(ejercitoDumbledore, tamD);
    liberarEjercito(ejercitoVoldemort, tamV);

    return 0;
}

void cargarEjercito(Personaje* ejercito[], int &tam, const char* nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw "No se pudo abrir el archivo";
    }

    string tipo, nombre;
    int vida, ataque, nivel;

    while (!archivo.eof() && tam < 20) {
        archivo >> tipo;
        if (archivo.eof()) break;

        if (tipo == "Auror") {
            int poderPatronus, resistenciaOscura;
            archivo >> nombre >> vida >> ataque >> nivel >> poderPatronus >> resistenciaOscura;
            ejercito[tam++] = new Auror(vida, ataque, nivel, poderPatronus, resistenciaOscura, nombre);

        } else if (tipo == "Elfo") {
            int poderElf, magiaCurativa, esLibreInt;
            archivo >> nombre >> vida >> ataque >> nivel >> poderElf >> magiaCurativa >> esLibreInt;
            bool esLibre = (esLibreInt == 1);
            ejercito[tam++] = new Elfo(vida, ataque, nivel, poderElf, magiaCurativa, esLibre, nombre);

        } else if (tipo == "Mortifago") {
            int nivelOscuridad, marcaTenebrosaInt;
            archivo >> nombre >> vida >> ataque >> nivel >> nivelOscuridad >> marcaTenebrosaInt;
            bool marcaTenebrosa = (marcaTenebrosaInt == 1);
            ejercito[tam++] = new Mortifago(vida, ataque, nivel, nivelOscuridad, marcaTenebrosa, nombre);

        } else {
            cout << "Tipo desconocido: " << tipo << "no es valido" << endl;
            string linea;
            getline(archivo, linea); 
        }
    }
    archivo.close();
}

void imprimirEjercito(Personaje* ejercito[], int tam, const string &nombreEjercito) {
    cout << "\n ESTADISTICAS PRE BATALLA " << endl; 
    cout << "\n---------" << nombreEjercito << "---------" << endl;
    for (int i = 0; i < tam; i++) {
        cout << "\nCombatiente " << i + 1 << ":" << endl;
        ejercito[i]->imprimir();
    }
}

void batalla(Personaje* ejercito1[], int &tam1, Personaje* ejercito2[], int &tam2) {
    string bajasDumbledore[100];
    int totalBajasDumbledore = 0;
    string bajasVoldemort[100];
    int totalBajasVoldemort = 0;


    cout << "\n---------Batalla de Hogwarts comenzando---------\n" << endl;

    int ronda = 1;
    int i1 = 0, i2 = 0;

    while (tam1 > 0 && tam2 > 0) {
        cout << ejercito1[i1]->getNombre() << " (Ejercito Dumbledore) ataca a " << ejercito2[i2]->getNombre() << " (Ejercito Voldemort)" << endl;
        ejercito1[i1]->atacar(*ejercito2[i2]);
        if (!ejercito2[i2]->estaVivo()) {
            cout << ejercito2[i2]->getNombre() << " ha muerto." << endl;
            bajasVoldemort[totalBajasVoldemort] = ejercito2[i2]->getNombre();
            totalBajasVoldemort++;
            delete ejercito2[i2];
            ejercito2[i2] = ejercito2[tam2 - 1];
            tam2--;

            if (i2 >= tam2) i2 = 0;
        } else {
            i2 = (i2 + 1) % tam2;
        }

        if (tam2 == 0) break;

        cout << ejercito2[i2]->getNombre() << " (Ejercito Voldemort) ataca a " << ejercito1[i1]->getNombre() << " (Ejercito Dumbledore)" << endl;
        ejercito2[i2]->atacar(*ejercito1[i1]);
        if (!ejercito1[i1]->estaVivo()) {
            cout << ejercito1[i1]->getNombre() << " ha muerto." << endl;
            bajasDumbledore[totalBajasDumbledore] = ejercito1[i1]->getNombre();
            totalBajasDumbledore++;
            delete ejercito1[i1];
            ejercito1[i1] = ejercito1[tam1 - 1];
            tam1--;

            if (i1 >= tam1) i1 = 0;
        } else {
            i1 = (i1 + 1) % tam1;
        }

        cout << endl;
        ronda++;
    }

    cout << "\n---------La batalla de Hogwarts ha finalizado ---------" << endl;
    if (tam1 > 0) {
        cout << "El ejercito de dumbledore gana con " << tam1 << " aurores y elfos vivos" << endl;
        imprimirEjercito(ejercito1, tam1, "Ejercito de Dumbledore");
    } else if (tam2 > 0) {
        cout << "El Ejercito de Voldemort gana con " << tam2 << " mortifagos vivos" << endl;
        imprimirEjercito(ejercito2, tam2, "Ejercito de Voldemort");
    } else {
        cout << "Ambos ejercitos han sido aniquilados" << endl;
    }
    cout << "\n---------Bajas de la batalla---------" << endl;

    cout << "\nEjercito de Dumbledore" << endl;
    for (int i = 0; i < totalBajasDumbledore; i++) {
        cout << "~ " << bajasDumbledore[i] << endl;
    }

    cout << "\nEjercito de voldemort" << endl;
    for (int i = 0; i < totalBajasVoldemort; i++) {
        cout << "~ " << bajasVoldemort[i] << endl;
    }

    for (int i = 0; i < tam1; i++) {
    if (ejercito1[i]->getSalud() < 30) {
        cout << "\n" << ejercito1[i]->getNombre() << " necesita ayuda urgente su salud es de " << ejercito1[i]->getSalud() << "" << endl;
    }
    }

}

void liberarEjercito(Personaje* ejercito[], int tam) {
    for (int i = 0; i < tam; i++) {
        delete ejercito[i];
    }
}
