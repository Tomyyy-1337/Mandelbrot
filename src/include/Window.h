#pragma once

#include "Set.h"

#include <SFML/Graphics.hpp>
#include <vector>

class Window {

private:

    int width, height;

    sf::RenderWindow* window;

    Set set;

    // Breite der Einstellungen im Fenster
    const int CONTROLS_WIDTH = 200;

    sf::Texture texture;

    sf::Sprite sprite;

    int zoomIndx = 18;

    double zoom = 2;

    double centerX = //-1.141673804921333917694299572171880522108633990003187337459764329577153037086780055411646585650298338610512006529379321040191599132908755479812986846536;
      0.36024044343761436323612524444954530848260780795858575048837581474019534605;
    // -1.99977406013629035931268075596025004757104162338563840071485085742910123359;
    double centerY = //0.281479342516091034246762286304792454844871560215549510213109824062942736231379351772886714646455545033969837498914378008943763965768510640909245404395;
     -0.64131306106480317486037501517930206657949495228230525955617754306444857417;
    // -0.00000000329004032147943505349697867592668059678529465058784100883260469278; 

    unsigned int maxIterations = 3000;

    void updateSprite();

public:

    void mainloop();


    Window(int width, int height) {
        this->width = width;
        this->height = height;
        set = Set(width, height, this->centerX, this->centerY, this->maxIterations, this->zoomIndx, this->zoom);
        this->window = new sf::RenderWindow(sf::VideoMode(width, height), "Mandelbrot");
    }

};