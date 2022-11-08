//
// Created by linus on 04.11.22.
//

#ifndef MANDELBROT_MANDELBROT_H
#define MANDELBROT_MANDELBROT_H


#include <vector>
#include "Complex.h"

class Mandelbrot {
public:
    Mandelbrot();

    void init(int height, int width);
    void update(Complex center, double re_width, double im_width, int max_iter, double max_val);

    std::vector< std::vector<int> > compute();

private:
    int width, height;
    double re_width, im_width;
    int max_iter;
    double max_val;
    Complex center;

    int value(Complex z);

    std::vector< std::vector<int>> values;
};

#endif //MANDELBROT_MANDELBROT_H
