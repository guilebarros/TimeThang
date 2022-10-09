#pragma once

inline float tt_linear_interp(float v0, float v1, float t)
{
    // algoritmo de interpolacao linear (wikipedia)
    return (1 - t) * v0 + t * v1;
    
}
