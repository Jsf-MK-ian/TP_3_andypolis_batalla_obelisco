#include ".\idea_menu\menu_nueva_partida.h"
#include ".\idea_menu\menu.h"
#include ".\juego\juego.h"

int main() {
    
    srand((unsigned)time(NULL)); // Semilla para generar números aleatorios.
        
    Juego *juego = new Juego();
    
    Jugador *jug_1 = new Jugador();
    Jugador *jug_2 = new Jugador();

    juego -> crear_juego(jug_1, jug_2);

    ifstream archivo;

    bool mapa_bien_cargado = false;
    bool diccionario_edificios_bien_cargado = true;
    bool inventario_bien_cargado = true;
    
    
    if (juego -> es_archivo_legible(archivo, ARCHIVO_MAPA) ){
        //mapa->cargar_mapa(archivo,ARCHIVO_MAPA)
        mapa_bien_cargado = true;
    }
    
    cout << "mitad archivos";
    
    // if (juego -> es_archivo_legible(archivo, ARCHIVO_EDIFICIOS) ){
    //     //registro_edificios->cargar_edificios(archivo, jug_1, jug_2);
    //     bool diccionario_edificios_bien_cargado = true;
    // }

    // if (juego -> es_archivo_legible(archivo, ARCHIVO_MATERIALES) ){
    //     //registro_edificios->cargar_edificios(archivo, jug_1, jug_2);
    //     bool inventario_bien_cargado = true;
    // }
    cout << "cargo archivos";
    bool nueva_partida = false;
  
    nueva_partida = !( juego -> es_archivo_legible(archivo, ARCHIVO_UBICACIONES) );
    
    if (mapa_bien_cargado && diccionario_edificios_bien_cargado && inventario_bien_cargado) {
        
        bool alguien_gano = false;
        bool sin_energia = false;
        bool quiere_salir = false;
        bool quiere_terminar_turno = false;
        
        if (nueva_partida ){
            int ingreso;
            menu_nueva_partida();
            cout<<"Desea ser jugador 1 o 2 ? (ingrese 1 o 2)"<<endl;
            cin >> ingreso;
            jug_1 -> pedir_coordenadas();
            jug_2 -> pedir_coordenadas();

        }else{
            juego -> cargar_ubicaciones(archivo, jug_1, jug_2);
        }

        Jugador* jug_turno;
        Jugador* jug_secundario;        

        jug_turno = jug_1;
        //jug_secundario = jug_2;
        while (!alguien_gano && !quiere_salir){
        
            if ( !jug_turno->es_su_turno() ){ // turnos impares puese si el resto es 0 == false
                jug_turno = jug_1;
                jug_secundario = jug_2;
            }
            else{ //turnos pares
                jug_turno = jug_2;
                jug_secundario = jug_1;
            } 
        
            while( !alguien_gano && !sin_energia && !quiere_terminar_turno && !quiere_salir ){
                cout <<"en turno";
                //menu_principal(Jugador* jug_turno, Jugador *jug_secundario);
                sin_energia = jug_turno -> obtener_energia();
                alguien_gano = jug_turno ->gano();
                quiere_salir = jug_turno -> quiere_salir_del_juego();
                quiere_terminar_turno = jug_turno -> es_su_turno();
                int opc;
                cout<<"dese salir del juego?";
                menu_principal(jug_turno, jug_secundario);
            }
        }
    }else{
        cout<<"No se pudieron abrir uno o varios archivos ";
    
    }  
    delete juego;
    delete jug_1;
    delete jug_2;

    return 0;
}
