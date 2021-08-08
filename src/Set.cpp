#include "include/Set.h"

void Set::print() {
    for (int y = 0; y < resY; y++) {
        for (int x = 0; x < resX; x++) {
            std::cout << Points[x][y].iterations % 10 << " ";
        }
        std::cout << "\n";
    }
}

void Set::colorPixel(unsigned int x, unsigned int y) {
    Pixel& pxl = Points[x][y];
    image.setPixel(x, y, sf::Color(pxl.r, pxl.g, pxl.b));
}

void Set::saveImage(int indx) {
    std::string filePath = "output/Mandelbrot_";
    if (indx == -1) 
    {
        filePath += "temp.png";
    }
    else 
    {
        filePath += std::to_string(indx) + ".png";
    }
    image.saveToFile(filePath);
}

void Set::createPixel(double zoom, double centerX, double centerY) {
    // Distanz zwischen Pixeln
    double stepSize = 4 / (resX * zoom);
    double xPos = centerX - (stepSize * (resX / 2));
    double yStart = centerY + (stepSize * (resY / 2));
    double yPos = yStart;

    for (int x = 0; x < resX; x++) 
    {
        for (int y = 0; y < resY; y++) 
        {
            Points[x].push_back(Pixel(xPos, yPos));
            yPos -= stepSize;
        }
        yPos = yStart;
        xPos += stepSize;
    }
}

void Set::solveAllPixel() {
    for (int x = 0; x < resX; x++) 
    {
        for (int y = 0; y < resY; y++) 
        {
            Points[x][y].calculateIterations(maxIterations);
            Points[x][y].calculateColor(maxIterations);
            colorPixel(x, y);
        }
    }
}

void Set::solveNextRow() {
    for (int y = 0; y < resY; y++) {
        Points[currentRow][y].calculateIterations(maxIterations);
        Points[currentRow][y].calculateColor(maxIterations);
        colorPixel(currentRow, y);
    }
    currentRow += 1;
    if (currentRow >= resX) {
        finished = true;
    }
}

double Set::pow(double base, int exponent) {
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    double tmp = pow(base, exponent / 2);
    if (exponent % 2 == 0) return tmp * tmp;
    return base * tmp * tmp;
}