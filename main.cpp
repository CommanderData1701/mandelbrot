#include <iostream>
#include "include/Client.h"
#include "include/Mandelbrot.h"
#include "include/Complex.h"
#include "include/Colormap.h"

int main() {
    Client client;

    while(client.running()) {
        client.handleEvents();
        client.update();
        client.render();
    }

    client.close();

    return 0;
}
