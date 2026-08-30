#pragma once
#include <raylib.h>

class GameState{
    public:
    virtual void Enter() = 0;
    virtual void Exit() = 0;
    virtual void HandleEvent() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
};

class App{
    public:
    App();
    ~App();
    GameState GetState();
    void PushState();
    GameState PopState();
};