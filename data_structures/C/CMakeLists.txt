cmake_minimum_required(VERSION 3.6)
project(Algorithms_in_C
        LANGUAGES C)

# Set compilation standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED YES)


file(GLOB SOURCES)

add_executable(data_structures/C ${SOURCE_FILES} ${SOURCES} dicitionary/dict.h)