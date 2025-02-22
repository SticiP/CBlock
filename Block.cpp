//
// Created by PAVEL on 2/22/2025.
//

#include "Block.hpp"

Block::Block(float x, float y, float z, float size) : x(x), y(y), z(z), size(size) {
    initGeometry();
}

Block::~Block() {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
}

void Block::initGeometry() {
    float halfSize = size / 2.0f;
    GLfloat vertices[] = {
        -halfSize, -halfSize,  halfSize,  // 0
         halfSize, -halfSize,  halfSize,  // 1
         halfSize,  halfSize,  halfSize,  // 2
        -halfSize,  halfSize,  halfSize,  // 3
        -halfSize, -halfSize, -halfSize,  // 4
         halfSize, -halfSize, -halfSize,  // 5
         halfSize,  halfSize, -halfSize,  // 6
        -halfSize,  halfSize, -halfSize   // 7
    };

    GLubyte indices[] = {
        0, 1, 2,  0, 2, 3,  // Fața din față
        1, 5, 6,  1, 6, 2,  // Fața dreapta
        5, 4, 7,  5, 7, 6,  // Fața din spate
        4, 0, 3,  4, 3, 7,  // Fața stânga
        3, 2, 6,  3, 6, 7,  // Fața de sus
        4, 5, 1,  4, 1, 0   // Fața de jos
    };

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Block::render() {
    glBindVertexArray(vao);
    glColor3f(0.5f, 0.5f, 0.5f); // Gri
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, 0);
    glBindVertexArray(0);
}