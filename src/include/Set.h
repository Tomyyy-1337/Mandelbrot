#pragma once

#include "Pixel.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Set {

private:

    // Enthält alle Punkte des Sets
    std::vector<std::vector<Pixel>> Points;

    // Maximale anzahl an schleifendurchläufen bevor ein Punkt dem Set zugeordnet wird
    unsigned int maxIterations;

    // Auflösung des Sets 
    unsigned int resX, resY;

    int currentRow;

    //Färft den Pixel in image an der Position x,y anhand der r,b,g Werte der Pixel aus Points
    void colorPixel(unsigned int x, unsigned int y);

    // erstellt einen Pixel, die Farbe wird noch nicht berechnet
    void createPixel(double, double, double);

    // Potenzfunktin mit Laufzeit O(log(n))
    double pow(double base, int exponent);

public:

    bool finished;

    // Erstellt ein Bild für die Vorschau und den Output
    sf::Image image;

    // Berechnet die Farbe aller Pixel
    void solveAllPixel();

    void solveNextRow();

    // Speichert image im output Ordner
    void saveImage(int indx = -1);

    // Gibte die Iterations des Sets in der Konsole aus
    void print();

    Set() {

    }

    Set(unsigned int resX, unsigned int resY, double centerX, double centerY, int maxIterations, int zoomindx, double zoom) {
        image.create(resX, resY, sf::Color(0, 0, 0));
        for (int i = 0; i < resX; i++) {
            std::vector<Pixel> v1;
            v1.reserve(resY);
            Points.push_back(v1);
        }
        this->resX = resX;
        this->resY = resY;
        this->maxIterations = maxIterations;
        double currentZoom = 0.5 * this->pow(zoom, zoomindx);
        createPixel(currentZoom, centerX, centerY);
        this->currentRow = 0;
        this->finished = false;
    }

};