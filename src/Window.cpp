#include "include/Window.h"

#include <iostream>
#include <string>

void Window::updateSprite() {
    this->texture.loadFromImage(this->set.image);
    this->sprite.setTexture(this->texture);
}

void Window::mainloop() {
    sf::Clock deltaClock;
    double frametime;

    while (this->window->isOpen()) {
        sf::Event event;
        frametime = 0;

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->window->close();
            }
        }

        while (frametime < 0.1 && !this->set.finished) {
            this->set.solveNextRow();
            frametime += deltaClock.restart().asSeconds();
        }

        this->updateSprite();

        this->window->clear();

        this->window->draw(this->sprite);

        this->window->display();

        if (this->set.finished) {
            this->set.saveImage(this->zoomIndx);
            std::cout << "Das " << this->zoomIndx << ". Bild wurde gespeichert" << std::endl;
            this->zoomIndx++;
            set = Set(width, height, this->centerX, this->centerY, this->maxIterations, this->zoomIndx, this->zoom);
            std::string windowTitle = "Mandelbrot - " + std::to_string(this->zoomIndx);
            this->window->setTitle(windowTitle);
        }
    }
}