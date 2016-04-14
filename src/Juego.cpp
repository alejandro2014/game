/*
 * Juego.cpp
 *
 *  Created on: 22 Nov 2009
 *      Author: alejandro
 */

#include "Juego.h"

Juego::Juego(Ventana *vent) {
	this->ventana = vent;
	this->surface = ventana->getSurface();
	angAlfa = 0.0, angBeta = 0.0;
	acabar = false;


	dcel = new Dcel("../terreno1.bmp");
	//dcel = new Dcel();
	camara = new Camara(dcel->getCentroX(),dcel->getCentroY(),
						0.0, 15.0, 20.0, 17.0);
}

Juego::~Juego() {
	// TODO Auto-generated destructor stub
}

void Juego::bucleJuego() {
	while (!acabar) {
		procesarEventos(surface);
		procesarTeclado();

		camara->actualizarCamara();

		if(!acabar) ventana->dibujarEscena(camara->getAlfa(), camara->getBeta(),
										   camara->getDistancia(), dcel);

		this->espera();
	}
}

void Juego::procesarEventos(SDL_Surface *screen) {
	while (SDL_PollEvent(&evento)) {
		switch(evento.type) {
			case SDL_VIDEORESIZE:
				screen = SDL_SetVideoMode(evento.resize.w, evento.resize.h, 16,
                                    SDL_OPENGL|SDL_RESIZABLE);
				if (screen) {
					ventana->reshape(screen->w, screen->h);
				} else {
					/* Uh oh, we couldn't set the new video mode?? */
				}
				break;

			case SDL_QUIT:
				acabar = 1;
				break;
		}
	}
}

void Juego::procesarTeclado() {
	Uint8 *keys = SDL_GetKeyState(NULL);

	//TODO poner referencias en vez de punteros
    if (keys[SDLK_ESCAPE]) acabar = true;
    if (keys[SDLK_UP]) camara->girarAlfa(5.0);
    if (keys[SDLK_DOWN]) camara->girarAlfa(-5.0);
    if (keys[SDLK_LEFT]) camara->girarBeta(5.0);
    if (keys[SDLK_RIGHT]) camara->girarBeta(-5.0);
    if (keys[SDLK_q]) camara->ajustarDistancia(-2.0);
    if (keys[SDLK_a]) camara->ajustarDistancia(2.0);
    //if (keys[SDLK_w]) dcel->incActual();
}

void Juego::espera(void) {
	usleep(100000); // Hay que hacerlo por medio de un timer en lugar de esto
}
