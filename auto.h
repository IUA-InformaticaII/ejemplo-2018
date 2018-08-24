//
// Created by martin on 23/08/18.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#ifndef AUTO_AUTO_H
#define AUTO_AUTO_H

/**
 * Estructura con los datos comunes de un auto
 */
typedef struct {
    int x;
    int y;
    int velx;
    int vely;
    unsigned tipo;
    int nivel;
} tAuto;

/*
 * Función dedicada a dibujar un auto con la textura particular
 */
void dibujar(tAuto au, SDL_Texture *mTexture, SDL_Renderer *gRenderer);

/*
 * Función dedicada a realizar los movimientos de un auto
 */
void mover(tAuto *au);

/*
 * Función dedicada a reaccionar ante presiones de teclas
 */
void reaccionar(tAuto *au, SDL_Event *e);

#endif //AUTO_AUTO_H
