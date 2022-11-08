#include <iostream>
#include "include/Client.h"
#include <time.h>
#include <iomanip>
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
