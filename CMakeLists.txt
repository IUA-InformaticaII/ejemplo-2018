cmake_minimum_required(VERSION 3.12)
project(auto)

set(CMAKE_CXX_STANDARD 14)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
#PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} )#${SDL2IMAGE_INCLUDE_DIRS})

add_executable(auto main.cpp helpers.cpp helpers.h auto.cpp auto.h)

target_link_libraries(auto ${SDL2_LIBRARIES} )# ${SDL2IMAGE_LIBRARIES})