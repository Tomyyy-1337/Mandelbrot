#pragma once

class Complex {

private:

    // Realteil der Zahl
    double real;

    // Imagin�rteil der Zahl 
    double imaginary;

public:

    // Gibt das Quadrat des Betrags zur�ck
    double absoluteValue();

    // Quadriert die Zahl
    void square();

    // f�gt der zahl c hinzu
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