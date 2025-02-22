//
// Created by PAVEL on 2/22/2025.
//

#ifndef BLOCK_HPP
#define BLOCK_HPP

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Block {
public:
    Block(float x, float y, float z, float size); // Poziție și mărime
    ~Block();
    void render(); // Desenează cubul

private:
    float x, y, z; // Poziția
    float size;    // Lungimea laturii
    GLuint vao, vbo, ebo; // Vertex Array Object și Vertex Buffer Object Adaugă EBO pentru indici
    void initGeometry(); // Inițializează vertex-urile cubului
};



#endif //BLOCK_HPP
