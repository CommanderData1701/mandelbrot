//
// Created by linus on 04.11.22.
//

#ifndef MANDELBROT_COMPLEX_H
#define MANDELBROT_COMPLEX_H
#include <math.h>


class Complex {
public:
    Complex();
    Complex(double re, double im);

    void set(double re, double im);

    double abs();

    Complex operator+(const Complex& other);
    Complex operator*(const Complex& other);
    Complex operator=(const Complex& other);
    Complex operator+=(const Complex& other);

    double Re();
    double Im();

private:
    double re, im;

};


#endif //MANDELBROT_COMPLEX_H
