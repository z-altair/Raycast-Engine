#pragma once
#include "utils.hpp"
#include <cmath>
#include <functional>

struct RayResult{
    bool hit_blocked = false;
    int side = -1;
    vector2i hit_pos = {-1, -1};
    float distance = 0.0f;
};

namespace RayCasting{
    RayResult Cast(vector2f start_pos, vector2f direction, const std::function<bool(vector2i)> RayHits, float max_distance);
};