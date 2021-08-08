#include "include/Window.h"

#include <iostream>
#include <string>

void Window::updateSprite() 
{
    texture.loadFromImage(set.image);
    sprite.setTexture(texture);
}

void Window::mainloop() 
{
    sf::Clock deltaClock;
    double frametime;

    while (window->isOpen()) 
    {
        sf::Event event;
        frametime = 0;

        while (window->pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window->close();
            }
        }

        while (frametime < 0.12 && !set.finished) 
        {
            set.solveNextRow();
            frametime += deltaClock.restart().asSeconds();
        }

        updateSprite();

        window->clear();

        window->draw(sprite);

        window->display();

        if (set.finished) 
        {
            set.saveImage(zoomIndx);
            std::cout << "Das " << zoomIndx << ". Bild wurde gespeichert" << std::endl;
            zoomIndx++;
            set = Set(width, height, centerX, centerY, maxIterations, zoomIndx, zoom);
            std::string windowTitle = "Mandelbrot - " + std::to_string(zoomIndx);
            window->setTitle(windowTitle);
        }
    }
}