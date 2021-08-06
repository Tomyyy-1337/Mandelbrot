#include "include/Pixel.h"

void Pixel::calculateIterations(int maxIterations) {
    Complex z(0, 0);
    for (int i = 1; i <= maxIterations; i++) {
        z.square();
        z.add(this->complex);
        if (z.absoluteValue() >= 4) {
            this->iterations = i;
            return;
        }
    }
    this->iterations = 0;
}

void Pixel::calculateColor(int maxIterations) {
    // Schwarz weiß:
    // this->r = this->iterations * 2 % 256;
    // this->g = this->iterations * 2 % 256;
    // this->b = this->iterations * 2 % 256;

    if (this->iterations == 0) {
        this->r = 0;
        this->g = 0;
        this->b = 0;
    }
    else {
        int stepsize = 16;
        int stepcolors = 256 / stepsize;
        int relevant = this->iterations % (stepcolors * 6);

        switch (relevant / stepcolors) {
        case 0: //Türkis zu Blau
            relevant = relevant % stepcolors;
            this->r = 0;
            this->g = 255 - relevant * stepsize;
            this->b = 255;
            break;
        case 1: // Blau zu Lila
            relevant = relevant % stepcolors;
            this->r = relevant * stepsize;
            this->g = 0;
            this->b = 255;
            break;
        case 2: // Lila zu Rot
            relevant = relevant % stepcolors;
            this->r = 255;
            this->g = 0;
            this->b = 255 - relevant * stepsize;
            break;
        case 3: //Rot zu Gelb
            relevant = relevant % stepcolors;
            this->r = 255;
            this->g = relevant * stepsize;
            this->b = 0;
            break;
        case 4: // Gelb zu Grün
            relevant = relevant % stepcolors;
            this->r = 255 - relevant * stepsize;
            this->g = 255;
            this->b = 0;
            break;
        case 5: // Grün zu Türkis
            relevant = relevant % stepcolors;
            this->r = 0;
            this->g = 255;
            this->b = relevant * stepsize;
            break;
        default:
            this->r = 255;
            this->g = 255;
            this->b = 255;
        }
    }
}

