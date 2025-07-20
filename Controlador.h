/*  Proyecto: Agentes Inteligentes en un Laberinto
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Elbert Leandro Moreno Castillo -
                 Daniel Escobar Escobar - 2437924
                 Jesus Giovanny Mora -
    Fecha: Mayo 2025 */

#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Tablero.h"
#include "Avatar.h"
#include "AvatarAleatorio.h"
#include "Vista.h"

using namespace std;
//Esta clase dirige el juego y se encarga de unir modelo y avatar con vista
class Controlador {
private:
    // declaracion de punteros, tablero, personaje y la interfaz, tambien permite polimorfismo (se inicializan en .cpp)
    Tablero* const tablero;    // Puntero const al tablero del juego
    Avatar* const avatar;      // Puntero const al avatar del juego
    Vista* const vista;        // Puntero const a la vista del juego
//metodos publicos, constructor y destructor 
public:
    Controlador();
    ~Controlador();
//metodos funcionales
    void ejecutarJuego();    //ciclo principal del juefo
    void inicializarJuego();    //muestra mensaje inicial
    void procesarMovimiento();    //intenta mover el persojae
    void verificarEstadoJuego();    //verifica si ya llegó a la meta
    void finalizarJuego();        //muestra el mensaje final
    bool intentarMovimiento();    //prueba si el movimiento es valido
    void mostrarProgreso();    //muestra el tablero y el estado actual
};

#endif

