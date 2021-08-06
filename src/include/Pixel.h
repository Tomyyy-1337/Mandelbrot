#pragma once

#include "Complex.h"

class Pixel {

private:

    // Position des Pixels als Komplexe Zahl
    Complex complex;

public:

    // RGB Farben des pixels
    unsigned int r, g, b;

    // Anzahl der relevanten Durchl�ufe (0 Teil des Sets)
    int iterations;

    // Berechnet die Anzahl der Durchl�ufe
    void calculateIterations(int);

    // TODO
    void calculateColor(int);

    Pixel(double re, double im) {
        iterations = 0;
        complex = Complex(re, im);
    }
};