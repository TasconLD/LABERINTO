/*  Proyecto: Agentes Inteligentes en un Laberinto
    Curso: Fundamentos de Programaci�n Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Elbert Leandro Moreno Castillo -
                 Daniel Escobar Escobar -
                 Jesus Giovanny Mora -
    Fecha: Mayo 2025 */


#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Tablero.h"
#include "Avatar.h"
#include "AvatarAleatorio.h"
#include "Vista.h"

using namespace std;

class Controlador {
private:
    Tablero* tablero;
    Avatar* avatar;
    Vista* vista;
    bool juegoTerminado;

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

#endif
