cmake_minimum_required(VERSION 3.9)
project(snake_vol2)

set(CMAKE_CXX_STANDARD 11)

add_executable(snake_vol2
        dane.c
        dane.h
        main.c
        menu.c
        menu.h
        rysuj.c
        rysuj.h
        silnik_gry.c
        silnik_gry.h)
