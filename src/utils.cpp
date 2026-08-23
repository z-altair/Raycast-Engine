#include "utils.hpp"

int Index(int i, int j, int cols, int rows) { 
    if (i < 0 || j < 0 || i > cols - 1 || j > rows - 1){
        return -1;
    }
    return j * cols + i; 
}

float MapValue(float x, float in_min, float in_max, float out_min, float out_max)
{
    return out_min + (x - in_min) * (out_max - out_min) / (in_max - in_min);
}
