#include "include/Complex.h"

double Complex::absoluteValue() {
    return imaginary * imaginary + real * real;
}

void Complex::square() {
    double re = real * real - imaginary * imaginary;
    imaginary = real * imaginary + real * imaginary;
    real = re;
}

void Complex::add(Complex c) {
    real += c.real;
    imaginary += c.imaginary;
}