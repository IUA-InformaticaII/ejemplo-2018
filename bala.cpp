//
// Created by martin on 24/08/18.
//

#include "bala.h"


void moverB(tBala *bal) {

    bal->y = bal->y - bal->velY;
    if (bal->y < -16) {
        bal->y = bal->y + bal->velY;
        bal->dibujar = false;
    }
}


void dibujarB(tBala bal, SDL_Texture *mTexture, SDL_Renderer *gRenderer) {
    // Dimensiones del rectángulo a dibujar
    SDL_Rect rect = {bal.x, bal.y, 7, 16};

    // Dibujo la textura en el Renderer.
    if(bal.dibujar)
        SDL_RenderCopyEx(gRenderer, mTexture, nullptr, &rect, 0, nullptr, SDL_FLIP_NONE);
}
