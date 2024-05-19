cmake_minimum_required(VERSION 3.10)
project(TCPCommunication)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the -pedantic-errors flag to the CMAKE_C_FLAGS
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic-errors -lraylib")

# Create libraries
add_library(blocklib lib/blocks/block.cpp)
add_library(blockslib lib/blocks/blocks.cpp)
add_library(positionlib lib/blocks/position.cpp)
add_library(colorslib lib/colors/colors.cpp)
add_library(gridlib lib/grid/grid.cpp)
add_library(gamelib lib/game/game.cpp)

# Include directories for the libraries
target_include_directories(blocklib PUBLIC 
    "${PROJECT_SOURCE_DIR}/lib/blocks"
    "${PROJECT_SOURCE_DIR}/lib/colors" 
    "${PROJECT_SOURCE_DIR}/lib/grid"
    "${PROJECT_SOURCE_DIR}/lib/game")

target_include_directories(blockslib PUBLIC 
    "${PROJECT_SOURCE_DIR}/lib/blocks"
    "${PROJECT_SOURCE_DIR}/lib/colors" 
    "${PROJECT_SOURCE_DIR}/lib/grid"
    "${PROJECT_SOURCE_DIR}/lib/game")

target_include_directories(positionlib PUBLIC 
    "${PROJECT_SOURCE_DIR}/lib/blocks"
    "${PROJECT_SOURCE_DIR}/lib/colors" 
    "${PROJECT_SOURCE_DIR}/lib/grid"
    "${PROJECT_SOURCE_DIR}/lib/game")

target_include_directories(gridlib PUBLIC 
    "${PROJECT_SOURCE_DIR}/lib/grid"
    "${PROJECT_SOURCE_DIR}/lib/blocks"
    "${PROJECT_SOURCE_DIR}/lib/colors")

target_include_directories(gamelib PUBLIC 
    "${PROJECT_SOURCE_DIR}/lib/game"
    "${PROJECT_SOURCE_DIR}/lib/blocks"
    "${PROJECT_SOURCE_DIR}/lib/colors"
    "${PROJECT_SOURCE_DIR}/lib/grid")

# Link libraries to each other
target_link_libraries(blocklib PUBLIC gridlib colorslib)
target_link_libraries(blockslib PUBLIC blocklib)
target_link_libraries(positionlib PUBLIC blocklib)
target_link_libraries(gridlib PUBLIC colorslib)
target_link_libraries(gamelib PUBLIC blocklib blockslib positionlib colorslib gridlib)

# Create the executable
add_executable(main src/main.cpp)

# Include directories for the main executable
target_include_directories(main PUBLIC 
    "${PROJECT_SOURCE_DIR}/lib/blocks"
    "${PROJECT_SOURCE_DIR}/lib/colors"
    "${PROJECT_SOURCE_DIR}/lib/grid"
    "${PROJECT_SOURCE_DIR}/lib/game")

# Link libraries to the main executable
target_link_libraries(main gamelib blocklib blockslib positionlib colorslib gridlib)
