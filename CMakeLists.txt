cmake_minimum_required(VERSION 3.23)
project(Mandelbrot)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mandelbrot main.cpp src/Client.cpp include/Client.h src/Complex.cpp include/Complex.h src/Mandelbrot.cpp include/Mandelbrot.h src/Colormap.cpp include/Colormap.h)
target_link_libraries(Mandelbrot SDL2main SDL2 jsoncpp)
