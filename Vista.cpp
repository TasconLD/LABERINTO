/*  Proyecto: Agentes Inteligentes en un Laberinto
    Curso: Fundamentos de Programaci�n Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Elbert Leandro Moreno Castillo -
                 Daniel Escobar Escobar -
                 Jesus Giovanny Mora -
    Fecha: Mayo 2025 */

#include "Vista.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Vista::Vista(Tablero* const ptrTablero, Avatar* const ptrAvatar, bool detallado)
    : tablero(ptrTablero), avatar(ptrAvatar), modoDetallado(detallado) {}

Vista::~Vista() {}

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

    for(int j = 0; j < tablero->obtenerTamanio(); j++) {
        cout << " " << j << " ";
    }
    cout << endl;

    for(int i = 0; i < tablero->obtenerTamanio(); i++) {
        cout << i << "  ";
        for(int j = 0; j < tablero->obtenerTamanio(); j++) {
            if (avatar->obtenerFila() == i && avatar->obtenerColumna() == j) {
                cout << "😃";
            }
            else if (tablero->esLaSalida(i, j)) {
                cout << "🚪";
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

    cout << "   ";
    for(int j = 0; j < tablero->obtenerTamanio(); j++) {
        cout << " " << j << " ";
    }
    cout << endl;
}

void Vista::mostrarMensajeVictoria() const {
    cout << "\n=================================" << endl;
    cout << "    ¡¡ FELICIDADES !!" << endl;
    cout << "    Has llegado a la salida" << endl;
    cout << "    Movimientos: " << avatar->obtenerMovimientos() << endl;
    cout << "=================================" << endl;
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
