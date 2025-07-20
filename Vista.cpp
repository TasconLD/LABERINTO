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


Vista::Vista(Tablero* const ptrTablero, Avatar* const ptrAvatar) : tablero(ptrTablero), avatar(ptrAvatar) {
    // Inicialización en lista de inicialización para punteros const
}


Vista::~Vista() {

}


void Vista::mostrarTablero() const {
    cout << "\n=== LABERINTO ===" << endl;
    cout << "Leyenda: [A]=Avatar, [S]=Salida, [1]=Camino, [0]=Precipicio" << endl;
    cout << "   ";

    // Mostrar números de columna sUperior
    for(int j = 0; j < tablero->obtenerTamanio(); j++) {
        cout << " " << j << " ";
    }
    cout << endl;

    // Mostrar cada fila del tablero
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
            // Mostrar el contenido normal del tablero
            else if(tablero->obtenerValor(i, j) == 1) {
                cout << "[1]";
            }
            else {
                cout << "[0]";
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


void Vista::mostrarEstadisticas() const {
    cout << "\n=== ESTADISTICAS ===" << endl;
    cout << "Posicion actual: [" << avatar->obtenerFila() << "][" << avatar->obtenerColumna() << "]" << endl;
    cout << "Movimientos realizados: " << avatar->obtenerMovimientos() << endl;
    cout << "Objetivo: Llegar a la salida [9][9]" << endl;
}


void Vista::mostrarMensajeBienvenida() const {
    cout << "================================================" << endl;
    cout << "    SIMULADOR DE AGENTE EN LABERINTO" << endl;
    cout << "================================================" << endl;
    cout << "Un soldado debe encontrar la salida del laberinto" << endl;
    cout << "sin caer en los precipicios!" << endl;
    cout << "================================================" << endl;
}


void Vista::mostrarMensajeVictoria() const {
    cout << "\n************************************************" << endl;
    cout << "           ¡¡¡ MISION COMPLETADA !!!" << endl;
    cout << "************************************************" << endl;
    cout << "El soldado ha encontrado la salida del laberinto!" << endl;
    cout << "Movimientos totales: " << avatar->obtenerMovimientos() << endl;
    cout << "************************************************" << endl;
}


void Vista::mostrarInstrucciones() const {
    cout << "\n=== INSTRUCCIONES ===" << endl;
    cout << "- El agente [A] se mueve automaticamente" << endl;
    cout << "- Debe evitar los precipicios [0]" << endl;
    cout << "- Solo puede moverse por caminos [1]" << endl;
    cout << "- El objetivo es llegar a la salida [S] en [9][9]" << endl;
    cout << "- Presiona Enter para continuar..." << endl;
}


void Vista::limpiarPantalla() const {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear"); // Linux/Mac
    #endif
}


void Vista::pausar() const {
    #ifdef _WIN32
        system("timeout /t 1 >nul"); // Windows
    #else
        system("sleep 1"); // Linux/Mac
    #endif
}

void Vista::mostrarEstadoCompleto() const {
    limpiarPantalla();
    mostrarTablero();
    mostrarEstadisticas();
}
