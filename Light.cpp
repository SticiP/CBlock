//
// Created by PAVEL on 2/22/2025.
//

#include "Light.hpp"
#include <GLFW/glfw3.h>

Light::Light(float x, float y, float z) : x(x), y(y), z(z) {}

void Light::apply() {
    // Lumină direcțională simplă
    GLfloat lightPos[] = {x, y, z, 0.0f}; // w = 0 pentru direcțională
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_COLOR_MATERIAL); // Pentru a folosi culorile vertex-urilor
}