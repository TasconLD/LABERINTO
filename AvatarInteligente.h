#ifndef AVATAR_INTELIGENTE_H
#define AVATAR_INTELIGENTE_H

#include "Avatar.h"

class AvatarInteligente : public Avatar {
public:
    AvatarInteligente(int filaInicial, int columnaInicial);
    virtual void generarMovimiento(int& nuevaFila, int& nuevaColumna) const override;
};

#endif
