// if SDL include not found -> i put the SDL (lib,...) into C:\\msys64\\mingw64

#include <iostream>
#include "SDL2/SDL.h"
#include "Mario.h"

const int WIDTH = 800, HEIGHT = 600;
const int FPS = 60;
const int frameDelay = 1000/FPS;
Uint32 frameStart;
int frameTime;


void cleanupSDL(SDL_Window *window, SDL_Renderer *renderer);

void limitFPS();

SDL_Renderer *getRenderer(SDL_Window *window);

SDL_Window *getWindow();

int main (int argc, char *argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = getWindow();
    SDL_Renderer *renderer = getRenderer(window);

    Mario mario = Mario();

    mario.init(renderer);



    SDL_Event windowEvent;
    const Uint8* keyStates = SDL_GetKeyboardState(nullptr);
    while(true){

        frameStart = SDL_GetTicks();

        if(SDL_PollEvent(&windowEvent)){
            if(SDL_QUIT == windowEvent.type){
                break;
            }
        }

        mario.update(keyStates);

        // Clear the screen
        SDL_RenderClear(renderer);
        //render Player
        mario.render(renderer);
        // Update the screen
        SDL_RenderPresent(renderer);

        limitFPS();
    }

    // Clean up
    cleanupSDL(window, renderer);

    return EXIT_SUCCESS;
}

SDL_Window *getWindow() {
    SDL_Window *window = SDL_CreateWindow("SDL2Mario", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    if(nullptr == window){
        std::cout << "ERROR: Could not create window: " << SDL_GetError()<< std::endl;
        exit(1);
    }
    return window;
}

SDL_Renderer *getRenderer(SDL_Window *window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    if(nullptr == renderer){
        std::cout << "ERROR: Could not create renderer: " << SDL_GetError()<< std::endl;
        exit(1);
    }
    return renderer;
}

//limit FPS to 60 (edit global var FPS to change)
void limitFPS() {
    frameTime = SDL_GetTicks() - frameStart;

    if(frameDelay>frameTime){
        SDL_Delay(frameDelay-frameTime);
    }
}

void cleanupSDL(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit( );
}



