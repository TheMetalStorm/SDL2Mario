//
// Created by arapo on 11.12.2022.
//
#ifndef SDLEXPLORATION_UTILS_H
#define SDLEXPLORATION_UTILS_H

#include "SDL2/SDL.h"

struct Vector2
{
    float x;
    float y;
};

class Utils {
public:
    static SDL_Texture *getTexture(SDL_Renderer *renderer, const char *filePath);
    static int sgn(float x);
    static bool cmpf(float A, float B, float epsilon = 0.005f);
    static float clip(float n, float lower, float upper);
};


#endif //SDLEXPLORATION_UTILS_H
