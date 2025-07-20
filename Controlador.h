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
#include "Vista.h"

using namespace std;


class Controlador {
private:
    // Composición: el controlador contiene estos objetos
    Tablero* const tablero;    // Puntero const al tablero del juego
    Avatar* const avatar;      // Puntero const al avatar del juego
    Vista* const vista;        // Puntero const a la vista del juego

    bool juegoTerminado; //
public:

    Controlador();

    ~Controlador();


    void ejecutarJuego();


    void inicializarJuego();
    void procesarMovimiento();
    void verificarEstadoJuego();
    void finalizarJuego();


    bool intentarMovimiento();
    void mostrarProgreso();
};

#endif // CONTROLADOR_H
