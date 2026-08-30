#pragma once
#include "app.hpp"
#include "player.hpp"
#include "scene.hpp"
#include "level_map.hpp"
#include "raycasting.hpp"

class Engine{
    public:
    private:
    App app;
    int num_level = 0;
    Player player;
    Scene scene;
    LevelMap level_map;
    RenderRayCaster render_ray_caster;
};