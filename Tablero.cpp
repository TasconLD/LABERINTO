/*  Proyecto: Agentes Inteligentes en un Laberinto
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Elbert Leandro Moreno Castillo -
                 Daniel Escobar Escobar - 2437924
                 Jesus Giovanny Mora -
    Fecha: Mayo 2025 */


#include "Tablero.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


Tablero::Tablero() {

    srand(time(0));


    generarLaberintoAleatorio();


    matriz[9][9] = 1;
}


Tablero::~Tablero() {

}


void Tablero::generarLaberintoAleatorio() {
    for(int i = 0; i < TAMANIO; i++) {
        for(int j = 0; j < TAMANIO; j++) {
            // Generar número aleatorio entre 0 y 1
            // 70% probabilidad de encontrar un camino (1), y un 30% un precipicio (0)
            matriz[i][j] = (rand() % 100 < 70) ? 1 : 0;
        }
    }


    matriz[9][9] = 1;

    // Crear un camino que si llegue a la salida
    // Asegurar que haya caminos alrededor de la salida para que sea accesible
    matriz[8][9] = 1;  // Arriba de la salida
    matriz[9][8] = 1;  // Izquierda de la salida

    // Crear un camino desde una esquina hacia la salida
    // Camino horizontal en la última fila
    for(int j = 7; j <= 9; j++) {
        matriz[9][j] = 1;
    }

    // Camino vertical hacia la salida
    for(int i = 7; i <= 9; i++) {
        matriz[i][9] = 1;
    }

    // Asegurar algunos caminos
    matriz[7][8] = 1;
    matriz[8][8] = 1;
    matriz[8][7] = 1;
    matriz[7][9] = 1;
}


bool Tablero::esPosicionValida(int fila, int columna) const {

    if(fila < 0 || fila >= TAMANIO || columna < 0 || columna >= TAMANIO) {
        return false;
    }


    return matriz[fila][columna] == 1;
}


int Tablero::obtenerValor(int fila, int columna) const {
    if(fila >= 0 && fila < TAMANIO && columna >= 0 && columna < TAMANIO) {
        return matriz[fila][columna];
    }
    return -1;
}

void Tablero::establecerValor(int fila, int columna, int valor) {
    if(fila >= 0 && fila < TAMANIO && columna >= 0 && columna < TAMANIO) {
        matriz[fila][columna] = valor;
    }
}


int Tablero::obtenerTamanio() const {
    return TAMANIO;
}


void Tablero::obtenerPosicionInicialAleatoria(int& fila, int& columna) {
    do {
        fila = rand() % TAMANIO;
        columna = rand() % TAMANIO;
    } while(!esPosicionValida(fila, columna)); // Repetir hasta encontrar una posición que sea válida
}


bool Tablero::esLaSalida(int fila, int columna) const {
    return (fila == 9 && columna == 9);
}
