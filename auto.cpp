#include "auto.h"

//Constantes de valores fijos
const int ANCHO_IMG = 53;
const int ALTO_IMG = 113;
const int MAX_VEL_X = 10;
const int MAX_VEL_Y = 5;


void dibujar(tAuto au, SDL_Texture *mTexture, SDL_Renderer *gRenderer) {
    // Dimensiones del rectángulo a dibujar
    SDL_Rect rect = {au.x, au.y, ANCHO_IMG, ALTO_IMG};

    // Dibujo la textura en el Renderer.
    SDL_RenderCopyEx(gRenderer, mTexture, nullptr, &rect, 0, nullptr, SDL_FLIP_NONE);
}

void mover(tAuto *au) {

    au->x += au->velx; // Muevo el auto horizontalmente

    au->y += au->vely; // Muevo el auto Verticalmente

    // Si me pasé lo vuelvo
    if ((au->x < 0) || (au->x + ANCHO_IMG > 640))
        au->x -= au->velx;

    //Si me pasé lo vuelvo
    if ((au->y < 0) || (au->y + ALTO_IMG > 480))
        au->y -= au->vely;
}


void reaccionar(tAuto *au, SDL_Event *e) {

    // Veo que pasa con las teclas
    // Si hay una tecla apretada
    if (e->type == SDL_KEYDOWN && e->key.repeat == 0) {
        //Ajusto la Velocidad según la tecla
        switch (e->key.keysym.sym) {
            case SDLK_UP:
                au->vely -= MAX_VEL_Y;
                break;
            case SDLK_DOWN:
                au->vely += MAX_VEL_Y;
                break;
            case SDLK_LEFT:
                au->velx -= MAX_VEL_X;
                break;
            case SDLK_RIGHT:
                au->velx += MAX_VEL_X;
                break;
            default:break;
        }
    }
        // Si suelto una tecla
    else if (e->type == SDL_KEYUP && e->key.repeat == 0) {
        // Ajusto la Velocidad según la tecla
        switch (e->key.keysym.sym) {
            case SDLK_UP:
                au->vely += MAX_VEL_Y;
                break;
            case SDLK_DOWN:
                au->vely -= MAX_VEL_Y;
                break;
            case SDLK_LEFT:
                au->velx += MAX_VEL_X;
                break;
            case SDLK_RIGHT:
                au->velx -= MAX_VEL_X;
                break;
            default:break;
        }
    }
}