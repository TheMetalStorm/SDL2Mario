//
// Created by arapo on 11.12.2022.
//

#include <iostream>
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
