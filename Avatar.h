/*  Proyecto: Agentes Inteligentes en un Laberinto
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Elbert Leandro Moreno Castillo - 2436884
                 Daniel Escobar Escobar - 2437924
                 Jesus Giovanny Mora - 2439620
    Fecha: Mayo 2025 */


#ifndef AVATAR_H
#define AVATAR_H

using namespace std;

class Avatar {
protected:
    int filaActual;
    int columnaActual;
    int movimientos;

public:
    Avatar(int filaInicial, int columnaInicial);
    virtual ~Avatar();

    int obtenerFila() const;
    int obtenerColumna() const;
    int obtenerMovimientos() const;

    void establecerPosicion(int nuevaFila, int nuevaColumna);
    void incrementarMovimientos();
    void reiniciar(int filaInicial, int columnaInicial);

    // Método virtual puro
    virtual void generarMovimiento(int& nuevaFila, int& nuevaColumna) const = 0;
};

#endif
