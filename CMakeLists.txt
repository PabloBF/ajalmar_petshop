cmake_minimum_required(VERSION 3.23)
project(petshop C)

set(CMAKE_C_STANDARD 23)

add_executable(petshop main.c pessoa.h pessoa.c pet.c pet.h)
