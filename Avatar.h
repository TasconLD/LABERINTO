/*  Proyecto: Agentes Inteligentes en un Laberinto
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Elbert Leandro Moreno Castillo -
                 Daniel Escobar Escobar -
                 Jesus Giovanny Mora -
    Fecha: Mayo 2025 */


#ifndef AVATAR_H
#define AVATAR_H

using namespace std;


class Avatar {
public:
    int filaActual;
    int columnaActual;
    int movimientos;

    Avatar(int filaInicial, int columnaInicial);

    // Destructor
    ~Avatar();

    // Métodos para obtener la posición actual
    int obtenerFila() const;
    int obtenerColumna() const;
    int obtenerMovimientos() const;

    // Métodos para establecer nueva posición
    void establecerPosicion(int nuevaFila, int nuevaColumna);

    /
    void incrementarMovimientos();


    void generarMovimientoAleatorio(int& nuevaFila, int& nuevaColumna) const;


    void mover(int nuevaFila, int nuevaColumna);


    void reiniciar(int filaInicial, int columnaInicial);
};

#endif // AVATAR_H
