//
// Created by martin on 24/08/18.
//

#include <SDL2/SDL.h>
#include <string>
#ifndef AUTO_BALA_H
#define AUTO_BALA_H


typedef struct tBala {
    int x;
    int y;
    int velY;
    int nivel;
    bool dibujar;
};

void dibujarB(tBala bal, SDL_Texture *mTexture, SDL_Renderer *gRenderer);

void moverB(tBala *bal);


#endif //AUTO_BALA_H
