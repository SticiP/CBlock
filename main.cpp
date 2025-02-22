#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Block.hpp"
#include "Light.hpp"

int main() {
    if (!glfwInit()) {
        std::cerr << "Eroare la inițializarea GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(200, 200, "CBlock", nullptr, nullptr);
    if (!window) {
        std::cerr << "Eroare la crearea ferestrei" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Inițializează GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Eroare la inițializarea GLEW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    Block block(0.0f, 0.0f, 0.0f, 1.0f);
    Light light(1.0f, 1.0f, 1.0f);

    float angle = 0.0f;
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -5.0f);
        glRotatef(angle, 0.0f, 1.0f, 0.0f);

        light.apply();
        block.render();

        glfwSwapBuffers(window);
        glfwPollEvents();

        angle += 0.01f;
    }

    glfwTerminate();
    return 0;
}