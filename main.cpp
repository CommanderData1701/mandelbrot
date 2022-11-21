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

    // Mandelbrot mandelbrot;
    // int width = 11520, height = 6480;
    // mandelbrot.init(height, width);

    // Complex center(0., 0.);

    // mandelbrot.update(center, 7., 7., 10000, 10000.);

    // std::vector<std::vector<int> > res = mandelbrot.compute();

    // std::ofstream file("../values.txt");


    // for(auto row: res) {
    //     for (int x = 0; x < width; ++x) {
    //         int val = row[x];
    //         file << val;

    //         if(x != width - 1) {
    //             file << ',';
    //         }
    //     }
    //     file << '\n';
    // }

    // file.close();

    return 0;
}
