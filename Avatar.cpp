/*  Proyecto: Agentes Inteligentes en un Laberinto
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Elbert Leandro Moreno Castillo - 2436884
                 Daniel Escobar Escobar - 2437924
                 Jesus Giovanny Mora - 2439620
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

void Avatar::generarMovimientoAleatorio(int& nuevaFila, int& nuevaColumna) const {
    // Array de direcciones posibles: arriba, abajo, izquierda, derecha
    int direcciones[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Seleccionar una dirección aleatoria
    int direccionElegida = rand() % 4;

    // Calcular nueva posición basada en la dirección elegida
    nuevaFila = filaActual + direcciones[direccionElegida][0];
    nuevaColumna = columnaActual + direcciones[direccionElegida][1];
}

void Avatar::mover(int nuevaFila, int nuevaColumna) {
    filaActual = nuevaFila;
    columnaActual = nuevaColumna;
    incrementarMovimientos();
}

void Avatar::reiniciar(int filaInicial, int columnaInicial) {
    filaActual = filaInicial;
    columnaActual = columnaInicial;
    movimientos = 0;
}
