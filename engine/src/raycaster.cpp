#include "raycaster.hpp"

RayResult RayCasting::Cast(vector2f start_pos, vector2f direction, const std::function<bool(vector2i)> RayHits, float max_distance){

    // Ray unitary length and normalization
    float dir_length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (dir_length == 0.0f) {
        return RayResult{};
    }
    direction = direction / dir_length;

    // Position on the map
    vector2i current_tile = {(int)start_pos.x, (int)start_pos.y};

    // Current real distance traversed
    float distance = 0.0f;

    // Distance from the current position to the next x/y side
    float current_dist_x;
    float current_dist_y;

    // Distance from an x/y side to the next x/y side
    float dist_x = (direction.x == 0) ? 1e30 : std::abs(1/direction.x);
    float dist_y = (direction.y == 0) ? 1e30 : std::abs(1/direction.y);

    // Direction to step into (either +1 or -1)
    int step_x;
    int step_y;

    // Calculate the step direction and distance to the next wall
    if (direction.x < 0){
        step_x = -1;
        current_dist_x = (start_pos.x - current_tile.x) * dist_x;
    } else {
        step_x = 1;
        current_dist_x = (current_tile.x + 1 - start_pos.x) * dist_x;
    }

    // If the ray hit something
    bool hit = false;
    // 0 left, 1 up, 2 right, 3 down
    int side = -1; 

    if (direction.y < 0){
        step_y = -1;
        current_dist_y = (start_pos.y - current_tile.y) * dist_y;
    } else {
        step_y = 1;
        current_dist_y = (current_tile.y + 1 - start_pos.y) * dist_y;
    }

    // DDA Algorithim
    while (!hit){

        if (current_dist_x < current_dist_y){
            distance = current_dist_x;
            current_tile.x += step_x;
            current_dist_x += dist_x;
            side = 0;
        }else{
            distance = current_dist_y;
            current_tile.y += step_y;
            current_dist_y += dist_y;
            side = 1;
        }

        // Return if distance is greater than the maximum
        if (distance > max_distance){
            return RayResult{};
        }

        // Check if hit
        hit = RayHits(current_tile);
    }

    if (side == 0) {
        side = (step_x < 0) ? 2 : 0;
        distance = (current_tile.x - start_pos.x + (1 - step_x) * 0.5f) / direction.x;
    } else {
        side = (step_y < 0) ? 3 : 1;
        distance = (current_tile.y - start_pos.y + (1 - step_y) * 0.5f) / direction.y;
    }

    return RayResult{hit, side, current_tile, distance};

}