cmake_minimum_required(VERSION 3.10)
project(CBlock)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

set(GLFW_LIBRARY "C:/MinGW/glfw-3.4/build/src/libglfw3.a")
set(GLFW_INCLUDE_DIR "C:/MinGW/glfw-3.4/include")
set(GLEW_LIBRARY "C:/MinGW/glew-2.2.0/lib/Release/x64/glew32s.lib")
set(GLEW_INCLUDE_DIR "C:/MinGW/glew-2.2.0/include")

if(NOT EXISTS ${GLFW_LIBRARY})
    message(FATAL_ERROR "GLFW library not found at ${GLFW_LIBRARY}")
endif()
if(NOT EXISTS ${GLEW_LIBRARY})
    message(FATAL_ERROR "GLEW library not found at ${GLEW_LIBRARY}")
endif()

add_executable(
        CBlock
        main.cpp
        Block.cpp
        Block.hpp
        Light.cpp
        Light.hpp
)

target_include_directories(CBlock PRIVATE ${GLFW_INCLUDE_DIR} ${GLEW_INCLUDE_DIR})

target_link_libraries(CBlock PRIVATE ${GLFW_LIBRARY} ${GLEW_LIBRARY} OpenGL::GL gdi32 user32)