# Set the project name
project(osrs-mousekey-cli)

# Set the CMake version
cmake_minimum_required(VERSION 3.0)

# Create globs for the headers and source to catch all the files.
file(GLOB header_files "src/*.h" "src/*.hpp")
file(GLOB src_files "src/*.c" "src/*.cpp")

ADD_EXECUTABLE(osrs-mousekey-cli ${header_files} ${src_files})

# Set the C++ version
set (CMAKE_CXX_STANDARD 11)
# Set the project for VS to use.
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT "osrs-mousekey-cli")