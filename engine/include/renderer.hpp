#pragma once
#include "camera.hpp"

class Renderer{
    private:
    int width;
    int height;

    public:
    void SetResolution(int width, int height);
    void Draw(const EngineCamera &cam);
};