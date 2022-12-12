//
// Created by arapo on 10.12.2022.
//

#ifndef SDLEXPLORATION_MARIO_H
#define SDLEXPLORATION_MARIO_H

#include "SDL2/SDL.h"
#include "Utils.h"



//values should be fine
const float pixelLength= 0x01000;

//Walking
const float walkAcceleration = 0x00098/pixelLength;
const float minWalkSpeed =0x00130/pixelLength;
const float maxWalkSpeed = 0x01900/pixelLength;

//Running
const float runningAcceleration = 0x000E4/pixelLength;
const float maxRunSpeed = 0x02900/pixelLength;

//decel
const float releaseDecel = 0x000D0 / pixelLength;
const float skiddingDecel = 0x001A0 / pixelLength;


const float skidTurnaroundSpeed = 0x00900 / pixelLength;



class Mario {


public:
    Mario() = default;

    ~ Mario(){
        SDL_DestroyTexture(sprite);
    }

    void init(SDL_Renderer* renderer);
    void update(const Uint8 *string);
    void render(SDL_Renderer* renderer);
    void setVel(Vector2 newVel) {
        this->vel = newVel;
    }

    void setPos(Vector2 newPos) {
        this->position= newPos;
    }

private:

    bool pressingRight = false;
    bool pressingLeft = false;
    bool isRunning = false;

    Vector2 vel{};
    Vector2 position {0, 400};

    SDL_Texture *sprite{};

    int spriteWidth = 0, spriteHeight = 0;

    SDL_Rect spriteRect{};

};


#endif //SDLEXPLORATION_MARIO_H
