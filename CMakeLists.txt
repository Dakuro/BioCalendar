cmake_minimum_required(VERSION 3.26)
project(BioCalendar C)

set(CMAKE_C_STANDARD 11)

add_executable(BioCalendar
        source/main.c
        header/functions.h
        source/conversions.c
        source/calendar.c
        source/biorhythm.c)
