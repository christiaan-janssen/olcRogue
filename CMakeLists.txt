cmake_minimum_required(VERSION 3.5)
project(olcRogue)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-lX11 -lGL -lpthread -lpng -lstdc++fs")

include_directories(vendor/*/include)
link_libraries(X11 GL pthread png)

add_executable(olcRogue main.cpp components.cpp components.h systems.cpp systems.h)