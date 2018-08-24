//
// Created by martin on 23/08/18.
//

#include "helpers.h"


bool cargarTexturas(SDL_Texture **mTexture, std::string path, SDL_Renderer *gRenderer) {
    // Puntero a la imagen que carguemos
    SDL_Texture *newTexture = nullptr;

    // Cargar imagen en la ruta
    SDL_Surface *loadedSurface = SDL_LoadBMP(path.c_str());
    if (loadedSurface == nullptr) {
        printf("No se pudo cargar la imagen %s! SDL_image Error: %s\n", path.c_str(), SDL_GetError());
    } else {
        // Setear el Color key (color transparente)
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0));

        // Crear textura de la surface
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == nullptr) {
            printf("No se pudo cargar la textura de %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        } else {
            // Muestro tamaño de la textura
            printf("W: %d, H:%d\n", loadedSurface->w, loadedSurface->h);
        }

        // Libero memoria de la textura
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    *mTexture = newTexture;
    return mTexture != nullptr;
}


void close(SDL_Window *gWindow, SDL_Renderer *gRenderer) {

    // Destruyo la ventana
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);

    //Finalizo el SDL
    SDL_Quit();
}


bool iniciar(SDL_Window **gWindow, SDL_Renderer **gRenderer) {

    // Arranco SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    // Pongo el filtro de texturas a lineal
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf("Warning: Linear texture filtering not enabled!");
    }

    // Creo una ventana
    *gWindow = SDL_CreateWindow("Auto - Info II", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,
                                SDL_WINDOW_SHOWN);

    if (*gWindow == nullptr) {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    // Creo un renderer en la ventana donde dibujar posteriormente
    *gRenderer = SDL_CreateRenderer(*gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (*gRenderer == nullptr) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    // Inicio el renderer en color blanco
    SDL_SetRenderDrawColor(*gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Inicializo el cargador de imagenes

    return true;
}


void limpiar_pantalla(SDL_Renderer *gRenderer) {
    // Pinto toda la pantalla de un color gris oscuro
    SDL_SetRenderDrawColor(gRenderer, 0x99, 0x99, 0x99, 0xFF);
    SDL_RenderClear(gRenderer);
}