/*  Proyecto: Agentes Inteligentes en un Laberinto
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Elbert Leandro Moreno Castillo -
                 Daniel Escobar Escobar - 2437924
                 Jesus Giovanny Mora -
    Fecha: Mayo 2025 */


#ifndef VISTA_H
#define VISTA_H

#include "Tablero.h"
#include "Avatar.h"

using namespace std;


class Vista {
private:
    // Punteros const a los objetos del modelo (relación de agregación)
    // Los punteros no pueden cambiar, pero los objetos sí pueden ser modificados
    Tablero* const tablero;
    Avatar* const avatar;

public:
    // Constructor: recibe punteros const al modelo
    Vista(Tablero* const ptrTablero, Avatar* const ptrAvatar);


    ~Vista();


    void mostrarTablero() const;
    void mostrarEstadisticas() const;
    void mostrarMensajeBienvenida() const;
    void mostrarMensajeVictoria() const;
    void mostrarInstrucciones() const;
    void limpiarPantalla() const;
    void pausar() const;


    void mostrarEstadoCompleto() const;
};

#endif // VISTA_H
