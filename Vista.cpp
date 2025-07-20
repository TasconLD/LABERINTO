/*  Proyecto: Agentes Inteligentes en un Laberinto
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Elbert Leandro Moreno Castillo -
                 Daniel Escobar Escobar - 2437924
                 Jesus Giovanny Mora -
    Fecha: Mayo 2025 */

#include "Vista.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Vista::Vista(Tablero* const ptrTablero, Avatar* const ptrAvatar, bool detallado)
    : tablero(ptrTablero), avatar(ptrAvatar), modoDetallado(detallado) {}

Vista::Vista(Tablero* const ptrTablero, Avatar* const ptrAvatar)
    : tablero(ptrTablero), avatar(ptrAvatar) {
    // Inicialización en lista de inicialización para punteros const
}

void Vista::mostrarInicio() const {
    cout << "===============================" << endl;
    cout << "  BIENVENIDO AL LABERINTO" << endl;
    cout << "===============================" << endl;
    cout << "Objetivo: llegar a la salida en [9][9] sin caer en precipicios." << endl;
    cout << "Leyenda: 😃=Avatar, 🚪=Salida, ⬜=Camino, ⬛=Precipicio" << endl << endl;
}

void Vista::mostrarEstado() const {
    limpiarPantalla();
    mostrarTablero();

    if (modoDetallado || avatar->obtenerMovimientos() % 10 == 0) {
        cout << "\nMovimientos: " << avatar->obtenerMovimientos() << endl;
        cout << "Posicion: [" << avatar->obtenerFila() << "][" << avatar->obtenerColumna() << "]" << endl;
    }
}

void Vista::mostrarTablero() const {
    cout << "\n=== LABERINTO ===" << endl;
    cout << "Leyenda: 😃=Avatar, 🚪=Salida, ⬜=Camino, ⬛=Precipicio" << endl;
    cout << "   ";

    // Mostrar números de columna superior
    for(int j = 0; j < tablero->obtenerTamanio(); j++) {
        cout << " " << j << " ";
    }
    cout << endl;

    for(int i = 0; i < tablero->obtenerTamanio(); i++) {
        cout << i << "  "; // Número de fila

        for(int j = 0; j < tablero->obtenerTamanio(); j++) {
            // Verificar si el avatar está en esta posición
            if(avatar->obtenerFila() == i && avatar->obtenerColumna() == j) {
                cout << "[A]"; // Mostrar avatar
            }
            // Verificar si es la posición de salida
            else if(i == 9 && j == 9) {
                cout << "[S]";
            }
            else if (tablero->obtenerValor(i, j) == 1) {
                cout << "⬜";
            }
            else {
                cout << "⬛";
            }
        }
        cout << "  " << i << endl;
    }

    // Mostrar números de columna en la parte inferior
    cout << "   ";
    for(int j = 0; j < tablero->obtenerTamanio(); j++) {
        cout << " " << j << " ";
    }
    cout << endl;
}

void Vista::mostrarMensajeVictoria() const {
    cout << "\n************************************************" << endl;
    cout << "           ¡¡¡ MISION COMPLETADA !!!" << endl;
    cout << "************************************************" << endl;
    cout << "El soldado ha encontrado la salida del laberinto!" << endl;
    cout << "Movimientos totales: " << avatar->obtenerMovimientos() << endl;
    cout << "************************************************" << endl;
}

void Vista::mostrarEstadoCompleto() const {
    limpiarPantalla();
    mostrarTablero();
    cout << "\nMovimientos: " << avatar->obtenerMovimientos() << endl;
    cout << "Posicion: [" << avatar->obtenerFila() << "][" << avatar->obtenerColumna() << "]" << endl;
}

void Vista::pausar() const {
    #ifdef _WIN32
        system("pause");
    #else
        system("sleep 1");
    #endif
}

void Vista::limpiarPantalla() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
