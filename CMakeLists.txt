cmake_minimum_required(VERSION 3.10)
project(My3DEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# specify FLTK paths (adjust the paths as needed)
set(FLTK_DIR "C:/Users/arman/OneDrive/Documents/fltk-1.3.9-source.tar/fltk-1.3.9")
set(FLTK_INCLUDE_DIR "C:/Users/arman/OneDrive/Documents/sltk-1.3.9-source.tar/fltk-1.3.9/include")
set(FLTK_LIBRARIES "C:/Users/arman/OneDrive/Documents/fltk-1.3.9-source.tar/fltk-1.3.9/lib")
set(FLTK_FLUID_EXECUTABLE "C:/Users/arman/OneDrive/Documents/fltk-1.3.9-source.tar/fltk-1.3.9/bin/fluid.exe")

find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})

# Your project executable
add_executable(My3DEngine src/main.cpp src/renderer.cpp src/shader.cpp)

# Link FLTK libraries
target_link_libraries(My3DEngine ${FLTK_LIBRARIES})

