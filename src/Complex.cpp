#include "include/Complex.h"

double Complex::absoluteValue() {
    return this->imaginary * this->imaginary + this->real * this->real;
}

void Complex::square() {
    double re = this->real * this->real - this->imaginary * this->imaginary;
    this->imaginary = this->real * this->imaginary + this->real * this->imaginary;
    this->real = re;
}

void Complex::add(Complex c) {
    this->real += c.real;
    this->imaginary += c.imaginary;
}