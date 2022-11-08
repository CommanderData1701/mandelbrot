//
// Created by linus on 04.11.22.
//

#ifndef MANDELBROT_CLIENT_H
#define MANDELBROT_CLIENT_H
#include "SDL2/SDL.h"
#include "Complex.h"
#include "Mandelbrot.h"
#include "Colormap.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>


class Client {
public:
    Client();
    Client(int width, int height);

    void handleEvents();
    void update();
    void render();
    void close();

    bool running();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    int width, height;
    float mouse_sensitivity, scroll_sensitivity;

    float re_width, im_width;
    Complex center;
    Mandelbrot mandelbrot;
    bool isRunning;
    int max_iter;
    float max_val;
    bool has_changed;

    Colormap mapper;

};


#endif //MANDELBROT_CLIENT_H
