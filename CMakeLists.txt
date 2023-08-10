cmake_minimum_required(VERSION 3.12)

# Specify the paths to g++ and gcc compilers
set(CMAKE_CXX_COMPILER "${CMAKE_CURRENT_SOURCE_DIR}/compiler/bin/g++.exe")
set(CMAKE_C_COMPILER "${CMAKE_CURRENT_SOURCE_DIR}/compiler/bin/gcc.exe")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# executable will be creted in /bin directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Set project name
project(MyGame)

# Set the source files for project
file(GLOB SOURCES "src/*.cpp")

# Create the target for executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories for target
target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib"
)

# Link against SDL2 libraries
target_link_libraries(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/bin/SDL2.dll")

# cmake . -G "MinGW Makefiles" -S . -B ./build
# cmake --build ./build
# bin/MyGame