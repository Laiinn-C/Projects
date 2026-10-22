#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
using namespace std;

#define WIN_SIZE_W 1080
#define WIN_SIZE_H 720


int main(){
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        cout << "sdl_init fallo\nERROR: " << SDL_GetError();
        return 1;
    }

    if(!(IMG_Init(IMG_INIT_PNG) && IMG_INIT_PNG)){
        cerr << "img_init fallor\n ERROR: " << IMG_GetError();
        SDL_Quit();
        return 1;

    }

    SDL_Window* ventana = SDL_CreateWindow("Terraria", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_SIZE_W, WIN_SIZE_H, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_PRESENTVSYNC);
    
    SDL_Texture* fondo = IMG_LoadTexture(renderer, "texturas/cielo.png");
    SDL_Texture* personaje = IMG_LoadTexture(renderer, "texturas/personaje.png");
    
    //JUEGO (Me voy a matar)
    float x_pos = WIN_SIZE_W/2;
    float y_pos = WIN_SIZE_H/2;
    const float velocidad = 300.0f;

    Uint32 tiempo_anterior = SDL_GetTicks();
    bool run = true;
    SDL_Event eventodemierda;
    while(run){
        Uint32 tiempo_ahora = SDL_GetTicks();
        float dt = (tiempo_ahora - tiempo_anterior) / 1000.0f;
        tiempo_anterior = tiempo_ahora;
        while(SDL_PollEvent(&eventodemierda)){
            if(eventodemierda.type == SDL_QUIT){
                run = false;   
            }
        }
        const Uint8* teclado = SDL_GetKeyboardState(nullptr);
        if(teclado[SDL_SCANCODE_D]) x_pos += velocidad * dt;
        if(teclado[SDL_SCANCODE_A]) x_pos -= velocidad * dt;
        if(teclado[SDL_SCANCODE_W]) y_pos -= velocidad * dt;
        if(teclado[SDL_SCANCODE_S]) y_pos += velocidad * dt;


        SDL_SetRenderDrawColor(renderer, 30, 30, 40, 255);
        SDL_RenderClear(renderer);

        SDL_Rect destino = {0, 0, 1080, 720};
        SDL_RenderCopy(renderer, fondo, nullptr, &destino);

        SDL_Rect destino_personaje = {x_pos, y_pos, 64,64};
        SDL_RenderCopy(renderer, personaje, nullptr, &destino_personaje);
        
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(fondo);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    IMG_Quit();
    SDL_Quit();
    return 0;
    
}