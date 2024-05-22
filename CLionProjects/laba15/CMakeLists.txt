cmake_minimum_required(VERSION 3.28)
project(laba15 C)

set(CMAKE_C_STANDARD 11)

add_executable(laba15 main.c
        libs/algorithms/array/array.c
        libs/algorithms/array/array.c
        libs/algorithms/array/unordered_array_set.c
        libs/data_structures/matrix/matrix.c
        libs/data_structures/matrix/matrix.h
        libs/data_structures/matrix/matrix.h
        libs/data_structures/matrix/test.matrix.c
        libs/data_structures/matrix/test.matrix.c.h)
