#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

#include "helpers.h"
#include "auto.h"
#include "bala.h"

#define BALAS 10000


//The window renderer
SDL_Renderer *gRenderer = NULL;


int main(int argc, char *args[]) {
    SDL_Window *gWindow = nullptr;
    SDL_Event e;                    // Manejador de Eventos (teclas)
    SDL_Texture *imgAuto;           // Textura del auto
    SDL_Texture *imgBala;           // Textura del auto

    // Inicio y creo la ventana con iniciar()
    if (!iniciar(&gWindow, &gRenderer))
        return 1;

    // Cargo las imagenes para el juego
    if (!cargarTexturas(&imgAuto, "../auto.bmp", gRenderer))
        return 2;

    if (!cargarTexturas(&imgBala, "../bala.bmp", gRenderer))
        return 2;

    // Bandera para saber si hay que salir del juego
    bool salir = false;

    // Inicializo el auto del jugador
    tAuto player = {200, 200, 0, 0, 1, 1};
    tBala b[BALAS];
    int iB = 0;
    for (int i = 0; i < BALAS; i++) {
        b[i] = {320, 400, 1, 1, false};
    }

    // Loop principal del juego
    while (!salir) {
        // Analizo Eventos de teclas
        while (SDL_PollEvent(&e) != 0) {
            // Si el usuario quiere salir (cierra la ventana)
            if (e.type == SDL_QUIT)
                salir = true;

            // Veo que hace el player
            reaccionar(&player, &e);

            if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
                //Ajusto la Velocidad según la tecla
                if (e.key.keysym.sym == SDLK_SPACE) {
                    b[iB].x = player.x + 53 / 2 - 7 / 2;
                    b[iB].y = player.y;
                    b[iB].dibujar = true;
                    iB++;
                    if (iB >= BALAS) {
                        iB = 0;
                    }
                }
            }
        }

        // Muevo el Auto
        mover(&player);
        for (int i = 0; i < BALAS; i++)
            moverB(&b[i]);

        // Limpio la pantalla
        limpiar_pantalla(gRenderer);

        // Dibujo Objtos
        dibujar(player, imgAuto, gRenderer);
        for (int i = 0; i < BALAS; i++)
            dibujarB(b[i], imgBala, gRenderer);

        // Actualizo la pantalla
        SDL_RenderPresent(gRenderer);
    }

    // Libero recursos de memoria
    close(gWindow, gRenderer);
    return 0;
}
