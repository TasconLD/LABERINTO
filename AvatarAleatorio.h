#ifndef AVATAR_ALEATORIO_H
#define AVATAR_ALEATORIO_H

#include "Avatar.h"

class AvatarAleatorio : public Avatar {
public:
    AvatarAleatorio(int filaInicial, int columnaInicial);
    virtual void generarMovimiento(int& nuevaFila, int& nuevaColumna) const override;
};

#endif
