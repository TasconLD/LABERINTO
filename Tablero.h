/*  Proyecto: Agentes Inteligentes en un Laberinto
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Elbert Leandro Moreno Castillo -
                 Daniel Escobar Escobar -
                 Jesus Giovanny Mora -
    Fecha: Mayo 2025 */

#ifndef TABLERO_H
#define TABLERO_H

using namespace std;


class Tablero {
private:
    static const int TAMANIO = 10;
    int matriz[TAMANIO][TAMANIO];

public:
    // Constructor
    Tablero();

    // Destructor
    ~Tablero();


    void generarLaberintoAleatorio();
    bool esPosicionValida(int fila, int columna) const;
    int obtenerValor(int fila, int columna) const;
    void establecerValor(int fila, int columna, int valor);
    int obtenerTamanio() const;


    void obtenerPosicionInicialAleatoria(int& fila, int& columna);


    bool esLaSalida(int fila, int columna) const;
};

#endif // TABLERO_H
