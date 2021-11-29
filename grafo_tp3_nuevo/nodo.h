#ifndef NODO_H
#define NODO_H

#include "vertice.h"

class Nodo
{
private:
    Vertice* vertice;
    Nodo* adyacente_derecho; 
    Nodo* adyacente_izquierdo; 
    Nodo* adyacente_abajo;     
    Nodo* adyacente_arriba;

public:
    //pre:
    //post: Inicializa el nodo con el vertice y sus vertices adyacentes.
    Nodo(Vertice* vertice);

    //pre:
    //post: Inicializa el nodo adyacente derecho.
    void asignar_derecho(Nodo* vertice_derecho);

    //pre:
    //post: Inicializa el nodo adyacente izquierdo.
    void asignar_izquierdo(Nodo* vertice_izquierdo);
    
    //pre:
    //post: Inicializa el nodo adyacente superior.
    void asignar_arriba(Nodo* vertice_arriba);

    //pre:
    //post: Inicializa el nodo adyacente inferior.
    void asignar_abajo(Nodo* vertice_abajo);

    //pre:
    //post: Elimina el vertice.
    ~Nodo();
};

#endif // NODO_H