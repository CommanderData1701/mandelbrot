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
    this->scroll_sensitivity = config["scroll_sensitivity"].asFloat();

    this->mapper.init(style);
    this->zoom = .5;

    center.set(.0, .0);
    re_width = 2.; im_width=2.;
    double aspect_ratio = 1.*width/height;
    re_width *= aspect_ratio;
    im_width /= aspect_ratio;

    max_iter = 500;
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

    if((this->buttons & SDL_BUTTON_LMASK) != 0) {
        int dx = mouse_x - width/2;
        int dy = mouse_y - height/2;

        double re = center.Re() + 1.*dx/width*re_width;
        double im = center.Im() + 1.*dy/height*im_width;

        Complex new_center(re, im);
        this->center = new_center;

        im_width *= zoom;
        re_width *= zoom;

        zoom = .5;
        has_changed = true;
    }

    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;


        case SDL_MOUSEWHEEL:
            if (event.wheel.y > 0) {
                zoom -= scroll_sensitivity/100.;
            } else if (event.wheel.y < 0) {
                zoom += scroll_sensitivity/100.;
            }
    }

}


bool Client::running() {
    return isRunning;
}


void Client::update() {
    this->buttons = SDL_GetMouseState(&mouse_x, &mouse_y);

    if(this->has_changed) {
        this->mandelbrot.update(center, re_width, im_width, max_iter, max_val);
    }

    this->has_changed = false;
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

    this->focus.w = width * zoom;
    this->focus.h = height * zoom;
    this->focus.x = mouse_x - this->focus.w/2;
    this->focus.y = mouse_y - this->focus.h/2;

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(this->renderer, &this->focus);

    SDL_RenderPresent(this->renderer);
}


void Client::close() {
    std::cout << "Quitting SDL2..." << '\n';
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);

    SDL_Quit();
    std::cout << "Successfully quit SDL2!" << '\n';
}

