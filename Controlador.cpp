/*  Proyecto: Agentes Inteligentes en un Laberinto

    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Elbert Leandro Moreno Castillo -
                 Daniel Escobar Escobar - 2437924
                 Jesus Giovanny Mora -
    Fecha: Mayo 2025 */

//encabezado y dependencias 
#include "Controlador.h"
#include "AvatarInteligente.h"
#include <iostream>

using namespace std;
//constructor, crea el tablero, inicializa el avatar y vista, y pone el juego como no terminado
Controlador::Controlador() :
    tablero(new Tablero()),
    avatar(nullptr),
    vista(nullptr),
    juegoTerminado(false) {
    //este fragmento es el de la posición inicial aleatoria del avatar donde evita que haga respawn en un precipicio 
    int filaInicial, columnaInicial;
    do {
        tablero->obtenerPosicionInicialAleatoria(filaInicial, columnaInicial);
    } while (tablero->obtenerValor(filaInicial, columnaInicial) == 0); // Evita precipicio
    //crea el avatar usando la clase AvatarInteligente que hereda de Avatar, y se crea la vista pasandole el tableto y el avatar 
    avatar = new AvatarInteligente(filaInicial, columnaInicial);
    vista = new Vista(tablero, avatar);
}
//metodo destructor que libera memoria que fue reservada con new en el constructor
Controlador::~Controlador() {
    delete tablero;
    delete avatar;
    delete vista;
}

void Controlador::ejecutarJuego() {
    inicializarJuego();

    while(!juegoTerminado) {
        mostrarProgreso();
        procesarMovimiento();
        verificarEstadoJuego();
        vista->pausar();
    }

    finalizarJuego();
}

void Controlador::inicializarJuego() {
    vista->limpiarPantalla();
    cout << "Bienvenido al juego del laberinto!" << endl;
    cout << "Presiona Enter para comenzar..." << endl;
    cin.get();
}

void Controlador::procesarMovimiento() {
    bool movimientoExitoso = false;
    int intentos = 0;
    const int MAX_INTENTOS = 50;

    while(!movimientoExitoso && intentos < MAX_INTENTOS) {
        movimientoExitoso = intentarMovimiento();
        intentos++;
    }

    if(!movimientoExitoso) {
        cout << "Agente atrapado! Reiniciando laberinto..." << endl;
        tablero->generarLaberintoAleatorio();

        int nuevaFila, nuevaColumna;
        do {
            tablero->obtenerPosicionInicialAleatoria(nuevaFila, nuevaColumna);
        } while (tablero->obtenerValor(nuevaFila, nuevaColumna) == 0); // Evita precipicio

        avatar->reiniciar(nuevaFila, nuevaColumna);
    }
}

void Controlador::verificarEstadoJuego() {
    if (tablero->esLaSalida(avatar->obtenerFila(), avatar->obtenerColumna())) {
        juegoTerminado = true;
    }
}

void Controlador::finalizarJuego() {
    vista->mostrarEstadoCompleto();
    cout << "¡Felicidades, llegaste a la salida!" << endl;
    cout << "Movimientos realizados: " << avatar->obtenerMovimientos() << endl;
}

bool Controlador::intentarMovimiento() {
    int nuevaFila, nuevaColumna;
    avatar->generarMovimiento(nuevaFila, nuevaColumna);

    if (tablero->esPosicionValida(nuevaFila, nuevaColumna)) {
        avatar->establecerPosicion(nuevaFila, nuevaColumna);
        avatar->incrementarMovimientos();
        return true;
    }
    return false;
}

void Controlador::mostrarProgreso() {
    vista->mostrarEstadoCompleto();
}
