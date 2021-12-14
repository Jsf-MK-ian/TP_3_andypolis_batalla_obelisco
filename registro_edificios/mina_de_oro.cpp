#include "mina_de_oro.h"

Mina_de_oro::Mina_de_oro(int piedra, int madera, int metal, int maximo,  int fila, int columna) : 
Edificio(piedra, madera, metal, maximo, fila, columna){
    this->nombre = "mina de oro";
    this->diminutivo = "G";
    this->brinda = 50;
    this->vida_actual = 2;
    this->vida_maxima = 2;
    this->fila = fila;
    this->columna = columna;
}

void Mina_de_oro::mostrar_mensaje(){
    cout << " Soy una " << nombre << " brindo " << brinda << " andycoins" << endl;
}

string Mina_de_oro::obtener_material_brindado(){
    return "andycoins";
}