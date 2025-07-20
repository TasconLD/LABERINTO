/*  Proyecto: Agentes Inteligentes en un Laberinto
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Elbert Leandro Moreno Castillo -
                 Daniel Escobar Escobar - 2437924
                 Jesus Giovanny Mora -
    Fecha: Mayo 2025 */


#include <iostream>
#include "Controlador.h"

using namespace std;


int main() {
    try {
        // controlador del juego MVC
        Controlador controladorJuego;


        controladorJuego.ejecutarJuego();

    }
    catch(const exception& e) {
        // Manejo básico de errores con const
        cout << "Error durante la ejecución del juego: " << e.what() << endl;
        return 1;
    }
    catch(...) {
        // Manejo de errores inesperados
        cout << "Error inesperado durante la ejecución del juego." << endl;
        return 1;
    }

    return 0;
}
