//
// Created by arapo on 10.12.2022.
//

#include "Mario.h"

void Mario::update(const Uint8 *keyStates) {

    if (keyStates[SDL_SCANCODE_A]) {
        pos.x  -= 22;
    }
    else if (keyStates[SDL_SCANCODE_D]) {
        pos.x += 22;
    }

}

void Mario::render(SDL_Renderer* renderer) {

    spriteRect.x = (int)pos.x;
    spriteRect.y = (int)pos.y;
    SDL_RenderCopy(renderer, sprite, nullptr, &spriteRect);
}

void Mario::init(SDL_Renderer* renderer) {
    sprite = Utils::getTexture(renderer, R"(C:\Users\arapo\CLionProjects\SDL2Mario\src\art\mario.bmp)");

    SDL_QueryTexture(sprite, nullptr, nullptr, &spriteWidth, &spriteHeight);

    spriteRect.x = (int)pos.x;
    spriteRect.y = (int)pos.y;
    spriteRect.w = spriteWidth;
    spriteRect.h = spriteHeight;

}

