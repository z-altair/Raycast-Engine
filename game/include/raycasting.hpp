#pragma once
#include <vector>
#include "utils.hpp"

#include "raycaster.hpp"


class RenderRayCaster{
    public:
    RenderRayCaster(/*Later I will pass an engine instance*/);
    RayResult Cast(vector2f star_pos, vector2f direction, float max_distance);
    
    private: 
    // Later this will be received from the engine instance, for now I will initialize a map inside raycasting
    std::vector<int> map;
    // I may want multiple maps, one for walls, other for doors, other for floor textures or ceiling's

    std::function<bool(vector2i)> hit_callback;
    bool IsHit(vector2i pos);
};