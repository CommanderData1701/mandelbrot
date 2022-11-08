//
// Created by linus on 04.11.22.
//

#include "../include/Complex.h"


Complex::Complex() {
    this->re = .0;
    this->im = .0;
}


Complex::Complex(double re, double im) {
    this->re = re;
    this->im = im;
}


void Complex::set(double re, double im) {
    this->re = re;
    this->im = im;
}


double Complex::abs() {
    return sqrt(re*re + im*im);
}


Complex Complex::operator+(const Complex &other) {
    Complex res;
    res.re = this->re + other.re;
    res.im = this->im + other.im;

    return res;
}


Complex Complex::operator*(const Complex &other) {
    Complex res;
    res.re = this->re * other.re - this->im * other.im;
    res.im = this->re * other.im + this->im * other.re;

    return res;
}


Complex Complex::operator=(const Complex &other) {
    this->re = other.re;
    this->im = other.im;

    return *this;
}


Complex Complex::operator+=(const Complex &other) {
    *this = *this + other;

    return *this;
}


double Complex::Re() {
    return re;
}


double Complex::Im() {
    return im;
}
