/*
 * Ventana.cpp
 *
 *  Created on: 22 Nov 2009
 *      Author: alejandro
 */

#include "Ventana.h"
//#define FRAMERATE

Ventana::Ventana() {
	//done = 0;

	SDL_Init(SDL_INIT_VIDEO);

	screen = SDL_SetVideoMode(800, 600, 16, SDL_OPENGL|SDL_RESIZABLE);
	if (!screen) {
		fprintf(stderr, "No se puede inicializar el modo de vídeo: %s\n", SDL_GetError());
	    SDL_Quit();
	    exit(2);
	}
	SDL_WM_SetCaption("Prueba de opengl", "gears");

	reshape(screen->w, screen->h);
	glClearColor(0.5,0.5,0.5,0.0);

	//Como estamos fuera eliminamos las caras de dentro
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
    glCullFace(GL_BACK);

    //Muestra sólo los polígonos que se pueden ver
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

Ventana::~Ventana() {

}

//
void Ventana::reshape(int width, int height) {
	GLfloat h = (GLfloat) height / (GLfloat) width;

	glViewport(0, 0, (GLint) width, (GLint) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -h, h, 5.0, 450.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -40.0);
}

void Ventana::dibujarEscena(GLfloat angAlfa, GLfloat angBeta, GLfloat distancia, Dcel *dcel) {
#ifdef FRAMERATE
	gettimeofday(&tiempo0,NULL);
#endif
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -distancia);
	glRotatef(angAlfa - 90,1.0,0.0,0.0);
	glRotatef(angBeta,0.0,0.0,1.0);
	glTranslatef(-(dcel->puntoMedioX), -(dcel->puntoMedioY), 0.0);

	//dibujarEjes();
	//dcel->dibujarCaras(0.0,0.0,0.0);
	dcel->dibujarAristas(0.0,0.0,0.0);

	glPopMatrix();

	SDL_GL_SwapBuffers();

#ifdef FRAMERATE
	gettimeofday(&tiempo1,NULL);
	frameRate = 1000000.0;
	frameRate /= ((tiempo1.tv_sec * 1000000 + tiempo1.tv_usec) -
				  (tiempo0.tv_sec * 1000000 + tiempo0.tv_usec));
	cout << frameRate << endl;
#endif
}

void Ventana::dibujarEjes() {
	glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(1.0,0.0,0.0);

		glColor3f(0.0,1.0,0.0);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,1.0,0.0);

		glColor3f(0.0,0.0,1.0);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,0.0,1.0);
	glEnd();
}
