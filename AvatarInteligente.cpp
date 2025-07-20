#include "AvatarInteligente.h"

AvatarInteligente::AvatarInteligente(int filaInicial, int columnaInicial)
    : Avatar(filaInicial, columnaInicial) {}

void AvatarInteligente::generarMovimiento(int& nuevaFila, int& nuevaColumna) const {
    // Por defecto intenta moverse hacia la derecha
    if (columnaActual < 9) {
        nuevaFila = filaActual;
        nuevaColumna = columnaActual + 1;
    }
    // Si no puede a la derecha, intenta hacia abajo
    else if (filaActual < 9) {
        nuevaFila = filaActual + 1;
        nuevaColumna = columnaActual;
    }
    // Si está en el borde, no se mueve
    else {
        nuevaFila = filaActual;
        nuevaColumna = columnaActual;
    }
}
