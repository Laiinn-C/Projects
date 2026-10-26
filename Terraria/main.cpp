#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

using namespace std;

struct player{
    int vida = 0;
    
};

int main(){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG);
    SDL_Window* ventana = SDL_CreateWindow("Terraria", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1366, 720, 0);
    SDL_CreateRenderer(ventana, -1, 0);

    SDL_Event event;
    bool run;
    while(run){
        
    }



}

