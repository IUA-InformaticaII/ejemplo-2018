//
// Created by martin on 23/08/18.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#ifndef AUTO_HELPERS_H
#define AUTO_HELPERS_H


bool cargarTexturas(SDL_Texture **mTexture, std::string path, SDL_Renderer *gRenderer);

void close(SDL_Window *gWindow, SDL_Renderer *gRenderer);

bool iniciar(SDL_Window **gWindow, SDL_Renderer **gRenderer);

void limpiar_pantalla(SDL_Renderer *gRenderer);

#endif //AUTO_HELPERS_H
