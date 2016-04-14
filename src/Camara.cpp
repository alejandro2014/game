/*
 * Camara.cpp
 *
 *  Created on: 12 Jun 2010
 *      Author: alejandro
 */

#include "Camara.h"

//Constructores de la cámara
Camara::Camara() {

}

Camara::Camara(float coordx, float coordy, float coordz,
               int angalfa, int angbeta, float distanc) {
	x = coordx; y = coordy; z = coordz;
	alfa = angalfa; beta = angbeta;
	distancia = distanc;
	referencia = NULL;
}

//Camara(obj_generico *refer, int angalfa, int angbeta, float distanc);

/** Gira los ángulos de la cámara teniendo en cuenta las restricciones espaciales **/
void Camara::girarAngulos(float angulo_a, float angulo_b) {
	if((alfa < 90 && alfa > 0) || (alfa == 0 && angulo_a > 0) || (alfa == 90 && angulo_a < 0))
		alfa += angulo_a;
	if(beta == -360 || beta == 360) beta = 0;
	beta += angulo_b;
}

/*
 * Método encargado de ajustar la posición de la cámara
 */
void Camara::actualizarCamara(void) {
	/* Se traslada y rota según los valores deseados. El resultado
	después de estas tres sentencias es la camara alejada y girada
	correctamente, pero sin apuntar a donde se desea */
	glTranslatef(0.0,0.0,-distancia);
	glRotatef(-(GLfloat)beta,1.0,0.0,0.0);
	glRotatef((GLfloat)alfa,0.0,0.0,1.0);

	//Se sitúa enfocando a la referencia
	if(referencia) {
		x = referencia->getX();
	    y = referencia->getY();
	    z = referencia->getZ();
	}

	glTranslatef(-x,-y,-z);
}

Camara::~Camara() {
	// TODO Auto-generated destructor stub
}

