//
// Created by arapo on 11.12.2022.
//

#include <iostream>
#include <cmath>
#include "Utils.h"

SDL_Texture *Utils::getTexture(SDL_Renderer *renderer, const char *filePath) {
    SDL_Surface* spriteSurface = SDL_LoadBMP(filePath);
    if (!spriteSurface) {

        std::cout << SDL_GetBasePath() << "ERROR: Could not create spriteSurface: " << SDL_GetError()<< std::endl;
        exit(1);
    }


    // Create the texture from the sprite surface
    SDL_Texture* spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteSurface);
    SDL_FreeSurface(spriteSurface);


    return spriteTexture;
}

int Utils::sgn(float x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

bool Utils::cmpf(float A, float B, float epsilon) {
    return (fabs(A - B) < epsilon);
}

float Utils::clip(float n, float lower, float upper) {
    return std::max(lower, std::min(n, upper));

}
