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

class Vista {
private:

    // Punteros const a los objetos del modelo (relación de agregación)
    // Los punteros no pueden cambiar, pero los objetos sí pueden ser modificados

    Tablero* const tablero;
    Avatar* const avatar;
    bool modoDetallado;  // Nuevo: para decidir nivel de detalle en impresión

public:
    Vista(Tablero* const ptrTablero, Avatar* const ptrAvatar, bool detallado = true);
    ~Vista();
    void mostrarEstadoCompleto() const;  //  este muestra tablero + posición y movimientos
    void mostrarTablero() const;         // este muestra tablero con estilo gráfico


    void mostrarInicio() const;
    void mostrarEstado() const;
    void mostrarMensajeVictoria() const;
    void pausar() const;
    void limpiarPantalla() const;
};

#endif
