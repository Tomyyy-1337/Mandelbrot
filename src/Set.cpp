#include "include/Set.h"

void Set::print() {
    for (int y = 0; y < this->resY; y++) {
        for (int x = 0; x < this->resX; x++) {
            std::cout << this->Points[x][y].iterations % 10 << " ";
        }
        std::cout << "\n";
    }
}

void Set::colorPixel(unsigned int x, unsigned int y) {
    Pixel* pxl = &this->Points[x][y];
    this->image.setPixel(x, y, sf::Color(pxl->r, pxl->g, pxl->b));
}

void Set::saveImage(int indx) {
    std::string filePath = "output/Mandelbrot_";
    if (indx == -1) {
        filePath += "temp.png";
    }
    else {
        filePath += std::to_string(indx) + ".png";
    }
    this->image.saveToFile(filePath);
}

void Set::createPixel(double zoom, double centerX, double centerY) {
    // Distanz zwischen Pixeln
    double stepSize = 4 / (this->resX * zoom);
    double xPos = centerX - (stepSize * (this->resX / 2));
    double yStart = centerY + (stepSize * (this->resY / 2));
    double yPos = yStart;

    for (int x = 0; x < this->resX; x++) {
        for (int y = 0; y < this->resY; y++) {
            this->Points[x].push_back(Pixel(xPos, yPos));
            yPos -= stepSize;
        }
        yPos = yStart;
        xPos += stepSize;
    }
}

void Set::solveAllPixel() {
    for (int x = 0; x < this->resX; x++) {
        for (int y = 0; y < this->resY; y++) {
            this->Points[x][y].calculateIterations(this->maxIterations);
            this->Points[x][y].calculateColor(this->maxIterations);
            this->colorPixel(x, y);

        }
    }
}

void Set::solveNextRow() {
    for (int y = 0; y < this->resY; y++) {
        this->Points[this->currentRow][y].calculateIterations(this->maxIterations);
        this->Points[this->currentRow][y].calculateColor(this->maxIterations);
        this->colorPixel(this->currentRow, y);
    }
    this->currentRow += 1;
    if (this->currentRow >= this->resX) {
        this->finished = true;
    }
}

double Set::myPow(double base, int exponent) {
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    double tmp = myPow(base, exponent / 2);
    if (exponent % 2 == 0) return tmp * tmp;
    return base * tmp * tmp;
}