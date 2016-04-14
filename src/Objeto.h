/*
 * Objeto.h
 *
 *  Created on: 12 Jun 2010
 *      Author: alejandro
 */

#ifndef OBJETO_H_
#define OBJETO_H_

#include "cabecera.h"

class Objeto {
private:
	GLfloat cx, cy, cz;
public:
	Objeto();
	~Objeto();

	GLfloat getX() {return cx;}
	GLfloat getY() {return cy;}
	GLfloat getZ() {return cz;}
};

#endif /* OBJETO_H_ */
