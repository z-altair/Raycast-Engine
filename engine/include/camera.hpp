#pragma once 
#include "utils.hpp"
#include <cmath>

class EngineCamera
{
private:
    vector2f position;
    float angle = 0;
    
public:
    vector2f forward = {0, 1};
    vector2f right = {1, 0};

    //EngineCamera();
    void Update();
    void Rotate(float d_a);
    void SetPosition(vector2f new_pos);
    vector2f GetPosition();
    void MoveForward(float velocity);
    void MoveRight(float velocity);
};
