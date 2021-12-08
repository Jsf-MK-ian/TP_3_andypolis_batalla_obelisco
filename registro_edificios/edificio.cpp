#include "edificio.h"

Edificio::Edificio() {
    this-> nombre = "edificio";
    this-> diminutivo = "";
    this-> cantidad_piedra = 0;
    this-> cantidad_madera = 0;
    this-> cantidad_metal = 0;
    this-> brinda = 0;
    this-> maximo_construir = 0;
    this->vida_actual =0;
    this->vida_maxima =0;
    this->fila=0;
    this->columna=0;
}

Edificio::Edificio(int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_construir, int fila, int columna) {
    this-> nombre = "";
    this-> diminutivo = "Ed";
    this-> cantidad_piedra = cantidad_piedra;
    this-> cantidad_madera = cantidad_madera;
    this-> cantidad_metal = cantidad_metal;
    this-> brinda = 0;
    this-> maximo_construir = maximo_construir;
    this->vida_actual =0;
    this->vida_maxima =0;
} 

string Edificio::obtener_nombre(){
    return nombre;
}

string Edificio::obtener_diminutivo(){
    return diminutivo;
}

int Edificio::obtener_cantidad_piedra(){
    return cantidad_piedra;
}

int Edificio::obtener_cantidad_madera(){
    return cantidad_madera;
}

int Edificio::obtener_cantidad_metal(){
    return cantidad_metal;
}

int Edificio::obtener_cantidad_brindada(){
    return brinda;
}

int Edificio::obtener_maximo_construir(){
    return maximo_construir;
}

int Edificio::obtener_mitad_madera(){
    return cantidad_madera/2;
}

int Edificio::obtener_mitad_piedra(){
    return cantidad_piedra/2;
}

int Edificio::obtener_mitad_metal(){
    return cantidad_metal/2;
}

int Edificio::obtener_vida_actual(){
    return vida_actual;
}

void Edificio:: daniar(){
    vida_actual--;
}

bool Edificio:: edificio_en_pie() {
    return (vida_actual > 0);
}

void Edificio::reparar() {
    if (vida_actual == vida_maxima) {
        cout << "El edificio no requiere reparacion" << endl;
    }
    else {
        vida_actual++;
        cout << "Se reparo el edificio "<< nombre <<" correctamente";
    }
}

void Edificio::mostrar_toda_informacion() {

    cout << "Se requieren los siguientes materiales para construir un/a '" << nombre << "': ";
    cout << "-" << cantidad_piedra << " unidades de piedra." << endl;
    cout << "-" << cantidad_madera << " unidades de madera." << endl;
    cout << "-" << cantidad_metal << " unidades de metal." << endl;
    cout << endl;
    
    if (diminutivo != "O") {
        cout << "-Produce " << brinda << " de " << obtener_material_brindado() << " cuando se recolecta." << endl;
    }
    
    cout << "-Construidos: " << "???" << "/";
    cout << obtener_maximo_construir() << "." << endl;
    cout << endl;
}

void Edificio::asignar_fila(int fila) {
    this -> fila = fila;
}

void Edificio::asignar_columna(int columna) {
    this -> columna = columna;
}

int Edificio::obtener_fila() {
    return fila;
}

int Edificio::obtener_columna() {
    return columna;
}

void Edificio:: modificar_cantidades_edificio(Edificio*edificio){
    if ( edificio->obtener_nombre() != "O"){
        int cantidad_suma_resta_madera;
        int cantidad_suma_resta_piedra;
        int cantidad_suma_resta_metal;
        cout << "Cantidad de madera a sumar o restar (incluir signo): ";
        cin >> cantidad_suma_resta_madera;
        edificio->cantidad_madera = edificio->cantidad_madera + cantidad_suma_resta_madera;
        cout << "Cantidad de madera a sumar o restar (incluir signo): ";
        cin >> cantidad_suma_resta_piedra;
        edificio->cantidad_piedra = edificio->cantidad_piedra + cantidad_suma_resta_piedra;
        cout << "Cantidad de madera a sumar o restar (incluir signo): ";
        cin >> cantidad_suma_resta_metal;
        edificio->cantidad_metal = edificio->cantidad_metal + cantidad_suma_resta_metal;
    }
    else{
        cout<< "Obelisco no es un edificio modificable." << endl;
    }
}

Edificio::~Edificio() {}