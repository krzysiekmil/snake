cmake_minimum_required(VERSION 3.9)
project(snake_vol2)

set(CMAKE_CXX_STANDARD 11)

add_executable(snake_vol2 main.c
        dane.c
        dane.h
        menu.c
        menu.h
        rysuj.c
        rysuj.h
        silnik_gry.h
        silnik_gry.c
        )
