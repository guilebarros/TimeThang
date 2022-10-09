#pragma once

const int maxBufferSize = 192000;
const static double TTPI = 3.14159265359;
const static double TT2PI = 6.28318530718;

inline float tt_linear_interp(float v0, float v1, float t)
{
    // algoritmo de interpolacao linear (wikipedia)
    return (1 - t) * v0 + t * v1;
    
}
