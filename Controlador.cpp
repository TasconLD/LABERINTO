/*  Proyecto: Agentes Inteligentes en un Laberinto
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Elbert Leandro Moreno Castillo -
                 Daniel Escobar Escobar - 2437924
                 Jesus Giovanny Mora -
    Fecha: Mayo 2025 */


#include "Controlador.h"
#include <iostream>

using namespace std;

Controlador::Controlador() :
    tablero(new Tablero()),
    avatar(nullptr),
    vista(nullptr),
    juegoTerminado(false) {


    int filaInicial, columnaInicial;
    tablero->obtenerPosicionInicialAleatoria(filaInicial, columnaInicial);

    //const_cast para asignar
    const_cast<Avatar*&>(avatar) = new Avatar(filaInicial, columnaInicial);

    // Crear la vista pasando referencias al modelo
    const_cast<Vista*&>(vista) = new Vista(tablero, avatar);
}


Controlador::~Controlador() {
    delete tablero;
    delete avatar;
    delete vista;
}

void Controlador::ejecutarJuego() {

    inicializarJuego();

    // Bucle
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
    vista->mostrarMensajeBienvenida();
    vista->mostrarInstrucciones();


    cin.get();

    cout << "\nIniciando simulacion..." << endl;
    cout << "Posicion inicial del agente: [" << avatar->obtenerFila()
         << "][" << avatar->obtenerColumna() << "]" << endl;
    cout << "Presiona Enter para comenzar...";
    cin.get();
}


void Controlador::procesarMovimiento() {
    bool movimientoExitoso = false;
    int intentos = 0;
    const int MAX_INTENTOS = 50; // Evita bucles infinitos

    // Intentar realizar un movimiento válido
    while(!movimientoExitoso && intentos < MAX_INTENTOS) {
        movimientoExitoso = intentarMovimiento();
        intentos++;
    }


    if(!movimientoExitoso) {
        cout << "\nEl agente esta atrapado! Generando un nuevo laberinto..." << endl;
        tablero->generarLaberintoAleatorio();


        int nuevaFila, nuevaColumna;
        tablero->obtenerPosicionInicialAleatoria(nuevaFila, nuevaColumna);
        avatar->reiniciar(nuevaFila, nuevaColumna);

        vista->pausar();
    }
}


void Controlador::verificarEstadoJuego() {
    if(tablero->esLaSalida(avatar->obtenerFila(), avatar->obtenerColumna())) {
        juegoTerminado = true;
    }
}


void Controlador::finalizarJuego() {

    vista->mostrarEstadoCompleto();


    vista->mostrarMensajeVictoria();

    cout << "\nPresiona Enter para salir...";
    cin.get();
}


bool Controlador::intentarMovimiento() {
    int nuevaFila, nuevaColumna;


    avatar->generarMovimientoAleatorio(nuevaFila, nuevaColumna);


    if(tablero->esPosicionValida(nuevaFila, nuevaColumna)) {

        avatar->mover(nuevaFila, nuevaColumna);
        return true;
    }

    return false;
}


void Controlador::mostrarProgreso() {
    vista->mostrarEstadoCompleto();


    if(avatar->obtenerMovimientos() % 10 == 0 && avatar->obtenerMovimientos() > 0) {
        cout << "\n>>> El agente continua buscando la salida..." << endl;
    }
}
