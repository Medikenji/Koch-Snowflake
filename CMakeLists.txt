cmake_minimum_required(VERSION 3.12)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Set the project name
project(KochSnowflake)

# Add the raylib library
add_subdirectory(raylib-5.5)

# Add the sources
file(GLOB GAME_SOURCES "sources/*.cpp")

# Add the main executable
set(EXECUTABLE_NAME Koch-Snowflake)

add_executable(${EXECUTABLE_NAME} ${GAME_SOURCES})

# Link the raylib library
target_link_libraries(${EXECUTABLE_NAME} PRIVATE raylib)