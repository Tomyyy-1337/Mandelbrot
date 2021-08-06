#include "include/Pixel.h"

void Pixel::calculateIterations(int maxIterations) {
    Complex z(0, 0);
    for (int i = 1; i <= maxIterations; i++) {
        z.square();
        z.add(complex);
        if (z.absoluteValue() >= 4) {
            iterations = i;
            return;
        }
    }
    iterations = 0;
}

void Pixel::calculateColor(int maxIterations) {
    // Schwarz weiß:
    // this->r = this->iterations * 2 % 256;
    // this->g = this->iterations * 2 % 256;
    // this->b = this->iterations * 2 % 256;

    if (iterations == 0) {
        r = 0;
        g = 0;
        b = 0;
    }
    else {
        int stepsize = 6;

        int stepcolors = 256 / stepsize;
        int relevant = iterations % (stepcolors * 6);

        switch (relevant / stepcolors) {
        case 0: //Türkis zu Blau
            relevant = relevant % stepcolors;
            r = 0;
            g = 255 - relevant * stepsize;
            b = 255;
            break;
        case 1: // Blau zu Lila
            relevant = relevant % stepcolors;
            r = relevant * stepsize;
            g = 0;
            b = 255;
            break;
        case 2: // Lila zu Rot
            relevant = relevant % stepcolors;
            r = 255;
            g = 0;
            b = 255 - relevant * stepsize;
            break;
        case 3: //Rot zu Gelb
            relevant = relevant % stepcolors;
            r = 255;
            g = relevant * stepsize;
            b = 0;
            break;
        case 4: // Gelb zu Grün
            relevant = relevant % stepcolors;
            r = 255 - relevant * stepsize;
            g = 255;
            b = 0;
            break;
        case 5: // Grün zu Türkis
            relevant = relevant % stepcolors;
            r = 0;
            g = 255;
            b = relevant * stepsize;
            break;
        default:
            r = 255;
            g = 255;
            b = 255;
        }
    }
}

