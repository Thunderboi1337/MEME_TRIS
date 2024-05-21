cmake_minimum_required(VERSION 3.14)
project(MEMETRIS)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Set default build type if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

# Dependencies
include(FetchContent)

set(RAYLIB_VERSION 4.5.0)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
)
set(RAYLIB_BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

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
target_link_libraries(main gamelib blocklib blockslib positionlib colorslib gridlib raylib)

# Apply strict compile flags only to the main executable
target_compile_options(main PRIVATE ${STRICT_COMPILE_FLAGS})

# Copy resource files to the build directory
add_custom_command(
    TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/memes $<TARGET_FILE_DIR:main>/memes
)



# Make sure Raylib is built before linking
add_dependencies(main raylib)
