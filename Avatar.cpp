/*  Proyecto: Agentes Inteligentes en un Laberinto
    Curso: Fundamentos de Programaci�n Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Elbert Leandro Moreno Castillo -
                 Daniel Escobar Escobar -
                 Jesus Giovanny Mora -
    Fecha: Mayo 2025 */


#include "Avatar.h"

Avatar::Avatar(int filaInicial, int columnaInicial)
    : filaActual(filaInicial), columnaActual(columnaInicial), movimientos(0) {}

Avatar::~Avatar() {}

int Avatar::obtenerFila() const { return filaActual; }
int Avatar::obtenerColumna() const { return columnaActual; }
int Avatar::obtenerMovimientos() const { return movimientos; }

void Avatar::establecerPosicion(int nuevaFila, int nuevaColumna) {
    filaActual = nuevaFila;
    columnaActual = nuevaColumna;
}

void Avatar::incrementarMovimientos() {
    movimientos++;
}

void Avatar::reiniciar(int filaInicial, int columnaInicial) {
    filaActual = filaInicial;
    columnaActual = columnaInicial;
    movimientos = 0;
}
