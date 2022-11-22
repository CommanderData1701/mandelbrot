//
// Created by linus on 04.11.22.
//

#include <iostream>
#include "../include/Mandelbrot.h"


Mandelbrot::Mandelbrot() {

}


void Mandelbrot::init(int height, int width) {
    this->height = height;
    this->width = width;

    for(int y=0; y<height; y++) {
        std::vector<int> row;
        for(int x=0; x<width; x++) {
            row.push_back(0);
        }
        this->values.push_back(row);
    }

}


void Mandelbrot::update(Complex center, double re_width, double im_width, int max_iter, double max_val) {
    std::cout << "Processing...\n";
    this->center = center;
    this->re_width = re_width;
    this->im_width = im_width;
    this->max_iter = max_iter;
    this->max_val = max_val;

    double current_im = center.Im() - im_width/2.;
    double re_step = re_width/width;
    double im_step = im_width/height;


    for(int y=0; y<height; y++) {
        double current_re = center.Re() - re_width/2.;
        for(int x=0; x<width; x++) {
            Complex z(current_re, current_im);
            int val = value(z);
            values[y][x] = val;
            current_re += re_step;
        }
        current_im += im_step;
    }

    std::cout << "Done!\n";

}


std::vector<std::vector<int> > Mandelbrot::compute() {
    return values;
}


int Mandelbrot::value(Complex z) {
    int res = 0;
    Complex iter(0., 0.);

    while(iter.abs() <= max_val && res != max_iter) {
        res++;
        iter = iter*iter + z;

        if(res > max_iter/4 && z.abs()<10) {
            res = max_iter;
            break;
        }
    }

    if(res == max_iter) {
        res = 0;
    }
    return res;
}
