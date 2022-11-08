//
// Created by linus on 05.11.22.
//

#ifndef MANDELBROT_COLORMAP_H
#define MANDELBROT_COLORMAP_H


#include <string>
#include <vector>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <fstream>
#include <sstream>

class Colormap {
public:
    Colormap();

    void init(std::string style);

    std::array<int, 3> plot(int val, int max);

    std::array<int, 3> Black_White(int val, int max);

private:
    std::vector<int> R;
    std::vector<int> G;
    std::vector<int> B;

};


#endif //MANDELBROT_COLORMAP_H
