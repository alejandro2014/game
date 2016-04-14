/*
 * Camara.h
 *
 *  Created on: 12 Jun 2010
 *      Author: alejandro
 */

#ifndef CAMARA_H_
#define CAMARA_H_

#include "Objeto.h"

class Camara {
private:
	float x,y,z;
	float px, py, pz;
	float alfa, beta;
	float distancia;
	Objeto *referencia;
public:
	Camara();
	Camara(float coordx, float coordy, float coordz,
	               int angalfa, int angbeta, float distanc);
	//Camara(obj_generico *refer, int angalfa, int angbeta, float distanc);

	void ajustarDistancia(float incremento){distancia += incremento;}
	void girarAngulos(float anguloA, float anguloB);
	void actualizarCamara(void);
	//void fijarCamara(obj_generico *objetivo) {referencia = objetivo;}

	void girarAlfa(float valor) {this->girarAngulos(valor,0.0);}
	void girarBeta(float valor) {this->girarAngulos(0.0,valor);}

	float getAlfa() {return alfa;}
	float getBeta() {return beta;}
	float getDistancia() {return distancia;}

	~Camara();
};

#endif /* CAMARA_H_ */
