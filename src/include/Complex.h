#pragma once

class Complex {

private:

    // Realteil der Zahl
    double real;

    // Imaginärteil der Zahl 
    double imaginary;

public:

    // Gibt das Quadrat des Betrags zurück
    double absoluteValue();

    // Quadriert die Zahl
    void square();

    // fügt der zahl c hinzu
    void add(Complex);

    Complex() {
        this->real = 0;
        this->imaginary = 0;
    }

    Complex(double real, double imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }
};