#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

#include "helpers.h"
#include "auto.h"


//The window renderer
SDL_Renderer *gRenderer = NULL;


int main(int argc, char *args[]) {
    SDL_Window *gWindow = nullptr;
    SDL_Event e;                    // Manejador de Eventos (teclas)
    SDL_Texture *imgAuto;           // Textura del auto

    // Inicio y creo la ventana con iniciar()
    if (!iniciar(&gWindow, &gRenderer))
        return 1;

    // Cargo las imagenes para el juego
    if (!cargarTexturas(&imgAuto, "../auto.bmp", gRenderer))
        return 2;

    // Bandera para saber si hay que salir del juego
    bool salir = false;

    // Inicializo el auto del jugador
    tAuto player = {200, 200, 0, 0, 1, 1};

    // Loop principal del juego
    while (!salir) {
        // Analizo Eventos de teclas
        while (SDL_PollEvent(&e) != 0) {
            // Si el usuario quiere salir (cierra la ventana)
            if (e.type == SDL_QUIT)
                salir = true;

            // Veo que hace el player
            reaccionar(&player, &e);
        }

        // Muevo el Auto
        mover(&player);

        // Limpio la pantalla
        limpiar_pantalla(gRenderer);

        // Dibujo Objtos
        dibujar(player, imgAuto, gRenderer);

        // Actualizo la pantalla
        SDL_RenderPresent(gRenderer);
    }

    // Libero recursos de memoria
    close(gWindow, gRenderer);
    return 0;
}
