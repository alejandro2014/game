/*
 * Dcel.h
 *
 *  Created on: 22 Nov 2009
 *      Author: alejandro
 */

#ifndef DCEL_H_
#define DCEL_H_
#include <fstream>
#include <iostream>
#include <new>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "cabecera.h"
using namespace std;

class Dcel {
private:
	VERTICE *lista_v;
	ARISTA *lista_a;
	CARA *lista_c;
	int actual;
	int num_v, num_a, num_c;
	unsigned int ancho, alto; //Atributos cuando es un mapa de alturas
	bool dibujado;
	VERTICE *vertActual1, *vertActual2, *vertActual3, *vertActual4;

	unsigned int cont1, cont2; //Contadores utilizados en el dibujado de la imagen
	int dspFila;

public:
	float puntoMedioX, puntoMedioY;

	Dcel();
	Dcel(const char *nombre_fichero);
	Dcel(int numVertices, int numCaras, int numAristas);

	void cargarDcel(const char *nombreFichero);
	void cargarDcelBmp(const char *nombreFichero);

	void dibujarVertices(float obx, float oby, float obz);
	void dibujarAristas(float obx, float oby, float obz);
	void dibujarCaras(float obx, float oby, float obz);

	void dibujarCuadricula();

	//Asignación de elementos a la dcel
	void setVertice(int numV, float x, float y, float z, int aIncid);
	void setCara(int numC, int aIncid);
	void setArista(int numA, int aAnterior, int aSiguiente, int aGemela, int vOrigen, int cIncid);

	//Muestra de la malla en modo texto para depuración
	void mostrarInfoTexto(void);
	int vert2int(VERTICE *puntero, VERTICE *inicio) {return (puntero - inicio);}
	int cara2int(CARA *puntero, CARA *inicio) {return (puntero - inicio);}
	int aris2int(ARISTA *puntero, ARISTA *inicio) {return (puntero - inicio);}

	void incActual(void);
	void guardar(const char *nombreFichero);

	float getCentroX() {return puntoMedioX;}
	float getCentroY() {return puntoMedioY;}
    void ReverseFloat(unsigned int* inFloat);
	//float getCentroZ();

	~Dcel();
};

#endif /* DCEL_H_ */
