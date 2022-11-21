//
// Created by linus on 05.11.22.
//

#include "../include/Colormap.h"


Colormap::Colormap() {

}


void Colormap::init(std::string style) {
    std::ifstream file("../styles/" + style + ".json");
    Json::Value config;
    Json::Reader reader;

    reader.parse(file, config);
    file.close();

    for(int i=0; i<100; i++) {
        float percent = i/100.;

        std::ostringstream dummy;
        if(i%10 != 0) {
            dummy.precision(2);
        }else{
            dummy.precision(1);
        }

        dummy << std::fixed << percent;
        std::string index = dummy.str();

        R.push_back(config["R"][index].asInt());
        G.push_back(config["G"][index].asInt());
        B.push_back(config["B"][index].asInt());
    }
}


std::array<int, 3> Colormap::plot(int val, int max) {
    std::array<int, 3> res;
    float percent = 1.*log(val + 1)/log(max + 1);

    int index;

    if(percent == 1) {
        index = 99;
    }else{
        index = percent * 100;
    }

    res[0] = R[index];
    res[1] = G[index];
    res[2] = B[index];

    return res;
}


std::array<int, 3> Colormap::Black_White(int val, int max) {
    float factor = 1. * val/max;

    std::array<int, 3> res;

    res[0] = factor*255;
    res[1] = factor*255;
    res[2] = factor*255;

    return res;
}
