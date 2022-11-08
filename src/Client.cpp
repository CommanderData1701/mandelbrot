//
// Created by linus on 04.11.22.
//

#include "../include/Client.h"


Client::Client() {
    std::ifstream file("../config.json");
    Json::Value config;
    Json::Reader reader;

    reader.parse(file, config);
    file.close();

    this->has_changed = true;

    std::string style = config["style"].asString();

    this->height = config["height"].asInt();
    this->width = config["width"].asInt();
    this->mouse_sensitivity = config["mouse_sensitivity"].asFloat();
    this->scroll_sensitivity = config["scroll_sensitivity"].asFloat();

    this->mapper.init(style);

    center.set(.0, .0);
    re_width = 2.; im_width=2.;
    double aspect_ratio = 1.*width/height;
    re_width *= aspect_ratio;
    im_width /= aspect_ratio;

    max_iter = 1000;
    max_val = 1000.;

    mandelbrot.init(height, width);

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL2 initialized..." << '\n';
        this->window = SDL_CreateWindow("Explore the Mandelbrot set!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, SDL_WINDOW_SHOWN);
        this->renderer = SDL_CreateRenderer(window, -1, 0);

        isRunning = true;
    }else {
        std::cout << "SDL2 initialization failed..." << '\n';

        isRunning = false;
    }

}


void Client::handleEvents() {
    SDL_Event event;

    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;

    }
}


bool Client::running() {
    return isRunning;
}


void Client::update() {
    if(this->has_changed) {
        mandelbrot.update(center, re_width, im_width, max_iter, max_val);
    }

    has_changed = false;
}


void Client::render() {
    SDL_RenderClear(renderer);

    std::vector<std::vector<int> > image = mandelbrot.compute();

    for(int y=0; y<height; y++) {
        for(int x=0; x<width; x++) {
            int val = image[y][x];

            std::array<int, 3> colors = mapper.plot(val, max_iter);
            SDL_SetRenderDrawColor(renderer, colors[0], colors[1], colors[2], 255);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }

    SDL_RenderPresent(renderer);
}


void Client::close() {
    std::cout << "Quitting SDL2..." << '\n';
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();
    std::cout << "Successfully quit SDL2!" << '\n';
}

