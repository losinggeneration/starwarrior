project(starwarrior)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(SDL REQUIRED)
find_package(SDL_gfx REQUIRED)

add_subdirectory(src)
