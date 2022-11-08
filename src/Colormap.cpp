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

        R.push_back(config["R"][std::to_string(percent)].asInt());
        G.push_back(config["G"][std::to_string(percent)].asInt());
        B.push_back(config["B"][std::to_string(percent)].asInt());
    }
}


std::array<int, 3> Colormap::plot(int val, int max) {
    std::array<int, 3> res;
    float percent = 1.*val/max;

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
