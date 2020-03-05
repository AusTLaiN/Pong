cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Pong)

include_directories(include)
include_directories(include/BotStrategies)
include_directories(include/UI)
file(GLOB_RECURSE SRC src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# Add SDL


find_package(SDL2 REQUIRED)
find_package(SDL2_TTF REQUIRED)

message("SDL2 FOUND = " ${SDL2_FOUND})
message("SDL2_TTF FOUND = " ${SDL2_TTF_FOUND})

message("SDL2_INCLUDE = " ${SDL2_INCLUDE_DIR})
message("SDL2_TTF_INCLUDE = " ${SDL2_TTF_INCLUDE_DIRS})

message("SDL2_LIB = " ${SDL2_LIBRARY})
message("SDL2_TTF_LIB = " ${SDL2_TTF_LIBRARIES})

#include_directories(${SDL2_INCLUDE_DIR})
#include_directories(${SDL2_TTF_INCLUDE_DIRS})
include_directories(third-party/SDL/include/SDL2)
include_directories(third-party/SDL2-ttf-2.0.15/include/SDL2)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${SDL2_TTF_LIBRARIES})




