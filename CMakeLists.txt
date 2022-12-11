cmake_minimum_required(VERSION 3.22)
project(SDL2Mario)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
add_executable(SDL2Mario src/main.cpp src/mario.cpp src/mario.h src/Utils.cpp src/Utils.h)

target_link_libraries(SDL2Mario ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -mwindows)