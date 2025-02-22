//
// Created by PAVEL on 2/22/2025.
//

#ifndef LIGHT_HPP
#define LIGHT_HPP



class Light {
public:
    Light(float x, float y, float z); // Poziție
    void apply(); // Aplică lumina în OpenGL

private:
    float x, y, z; // Direcția luminii
};



#endif //LIGHT_HPP
