//
// Created by arapo on 10.12.2022.
//

#include <iostream>
#include "Mario.h"

//playerPhysics Guide i am (loosely) following
//https://web.archive.org/web/20130807122227/http://i276.photobucket.com/albums/kk21/jdaster64/smb_playerphysics.png
//SMB dissasembly
//https://gist.github.com/1wErt3r/4048722#file-smbdis-asm

void Mario::update(const Uint8 *keyStates) {
    int dir;
    bool isSkidding;
    pressingLeft = false;
    pressingRight = false;


    if (keyStates[SDL_SCANCODE_A]) {
        pressingLeft = true;
        dir = -1;
    }
    if (keyStates[SDL_SCANCODE_D]) {
        pressingRight = true;
        dir = 1;
    }
    isRunning = keyStates[SDL_SCANCODE_LCTRL];

    if(position.y == 400){
        isGrounded = true;
    }
    else
        isGrounded = false;

    //TODO: when releasing run button, continue run for 10 frames then slow to walk speed instantly
    //TODO: jumping

    groundMovement(dir, isSkidding);
    std::cout << isGrounded << std::endl;
    //airMovement(dir);

}

void Mario::groundMovement(int dir, bool isSkidding) {
    if (pressingRight) {
        isSkidding = false;
        if (Utils::sgn(vel.x) == -1 && abs(vel.x) > skidTurnaroundSpeed) {
            isSkidding = true;
        }

        else{
            if (vel.x < minWalkSpeed) {
                vel.x = minWalkSpeed;
            }

            //accelerate
            if(isRunning) vel.x += walkAcceleration * (float) dir;
            else
                vel.x += walkAcceleration * (float) dir;

            //limit vel to current max
            if(isRunning){
                if (vel.x > maxRunSpeed) {
                    vel.x = maxRunSpeed;
                }
            }
            else{
                if (vel.x > maxWalkSpeed) {
                    if(Utils::cmpf(abs(vel.x), maxWalkSpeed, 0.05)){
                        vel.x = maxWalkSpeed;
                    }
                    else{
                        vel.x -= releaseDecel * (float) dir;
                    }
                }
            }

        }

    } else if (pressingLeft) {
        isSkidding = false;
        if (Utils::sgn(vel.x) == 1 && abs(vel.x) > skidTurnaroundSpeed) {
            isSkidding = true;
        }
        else {
            if (vel.x > -minWalkSpeed) {
                vel.x = -minWalkSpeed;
            }

            if(isRunning)
                vel.x += runningAcceleration * (float) dir;
            else
                vel.x += walkAcceleration * (float) dir;

            if(isRunning){
                if (vel.x < -maxRunSpeed) {
                    vel.x = -maxRunSpeed;
                }
            }
            else{
                if (vel.x < -maxWalkSpeed) {
                    if(Utils::cmpf(abs(vel.x), maxWalkSpeed, 0.05)){
                        vel.x = -maxWalkSpeed;
                    }
                    else{
                        vel.x -= releaseDecel * (float) dir;
                    }
                }
            }
        }
    } else {
        if (abs(vel.x) >= minWalkSpeed) vel.x += releaseDecel * Utils::sgn(-vel.x);
        else vel.x = 0;
    }

    if (isSkidding){
        vel.x += skiddingDecel * Utils::sgn(-vel.x);
    }

    position.x += vel.x;
}

void Mario::airMovement(int dir) {

    if(isGrounded){
        float startJumpXVel = vel.x;
    }
    else{
        horizontalAirMovement();
    }



}

void Mario::horizontalAirMovement() const {//TODO: On press jump



}

void Mario::render(SDL_Renderer *renderer) {

    spriteRect.x = (int) position.x;
    spriteRect.y = (int) position.y;
    SDL_RenderCopy(renderer, sprite, nullptr, &spriteRect);
}

void Mario::init(SDL_Renderer *renderer) {
    sprite = Utils::getTexture(renderer, R"(C:\Users\arapo\CLionProjects\SDL2Mario\src\art\mario.bmp)");

    SDL_QueryTexture(sprite, nullptr, nullptr, &spriteWidth, &spriteHeight);

    spriteRect.x = (int) position.x;
    spriteRect.y = (int) position.y;
    spriteRect.w = spriteWidth;
    spriteRect.h = spriteHeight;

}



