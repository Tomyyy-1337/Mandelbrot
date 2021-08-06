#include <iostream>
#include <vector>

#include "src/include/Window.h"

#include <SFML/Graphics.hpp>

int main() {

    Window window(2560, 1440);

    window.mainloop();

    return 0;
}