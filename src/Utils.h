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

};


#endif //SDLEXPLORATION_UTILS_H
