cmake_minimum_required(VERSION 3.17)
project(Thread C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(Thread main.c VerketteteListeTest.c VerketteteListe.h VerketteteListe.c Thread.c Thread.h Config.h utils.h utils.c Warteschlange.c Warteschlange.h)