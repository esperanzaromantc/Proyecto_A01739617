// Crear el archivo header de la clase Personaje, no olvides las guardas o el pragma.
#ifndef personaje_hpp
#define personaje_hpp

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
    void recibeAtaque(int ptosAtaque);
    void atacar (Personaje &objetivo);
    void imprimir();

};

#endif