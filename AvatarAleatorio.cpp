#include "AvatarAleatorio.h"
#include <cstdlib>

AvatarAleatorio::AvatarAleatorio(int filaInicial, int columnaInicial)
    : Avatar(filaInicial, columnaInicial) {}

void AvatarAleatorio::generarMovimiento(int& nuevaFila, int& nuevaColumna) const {
    int direcciones[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int direccion = rand() % 4;

    nuevaFila = filaActual + direcciones[direccion][0];
    nuevaColumna = columnaActual + direcciones[direccion][1];
}
