#pragma once
#include "engine.hpp"

class Scene{
    public:
    Scene(Engine *eng);
    void Update();
    void Draw();
};