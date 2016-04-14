#Script created automatically on Sun Apr  7 00:15:37 BST 2013
#If you want to add parameters, modify the file auto.conf

EXE=game
CC=g++

MAINDIR=/home/alejandro/programs/juego1
SRCPATH=${MAINDIR}/src
OBJPATH=${MAINDIR}/obj
BINPATH=${MAINDIR}/bin

OPTC=-I/usr/include/SDL -g
OPTL=-lGL -lSDL

OBJ1=Camara
OBJ2=ControlFlujo
OBJ3=Dcel
OBJ4=Juego
OBJ5=Objeto
OBJ6=principal
OBJ7=Ventana
OBJ= ${OBJPATH}/${OBJ1}.o ${OBJPATH}/${OBJ2}.o ${OBJPATH}/${OBJ3}.o ${OBJPATH}/${OBJ4}.o ${OBJPATH}/${OBJ5}.o ${OBJPATH}/${OBJ6}.o ${OBJPATH}/${OBJ7}.o

${BINPATH}/${EXE}: ${OBJ}
	${CC} ${OBJ} -o ${BINPATH}/${EXE} ${OPTL}

${OBJPATH}/Camara.o: ${SRCPATH}/Camara.cpp
	${CC} -c ${SRCPATH}/Camara.cpp -o ${OBJPATH}/Camara.o ${OPTC}

${OBJPATH}/ControlFlujo.o: ${SRCPATH}/ControlFlujo.cpp
	${CC} -c ${SRCPATH}/ControlFlujo.cpp -o ${OBJPATH}/ControlFlujo.o ${OPTC}

${OBJPATH}/Dcel.o: ${SRCPATH}/Dcel.cpp
	${CC} -c ${SRCPATH}/Dcel.cpp -o ${OBJPATH}/Dcel.o ${OPTC}

${OBJPATH}/Juego.o: ${SRCPATH}/Juego.cpp
	${CC} -c ${SRCPATH}/Juego.cpp -o ${OBJPATH}/Juego.o ${OPTC}

${OBJPATH}/Objeto.o: ${SRCPATH}/Objeto.cpp
	${CC} -c ${SRCPATH}/Objeto.cpp -o ${OBJPATH}/Objeto.o ${OPTC}

${OBJPATH}/principal.o: ${SRCPATH}/principal.cpp
	${CC} -c ${SRCPATH}/principal.cpp -o ${OBJPATH}/principal.o ${OPTC}

${OBJPATH}/Ventana.o: ${SRCPATH}/Ventana.cpp
	${CC} -c ${SRCPATH}/Ventana.cpp -o ${OBJPATH}/Ventana.o ${OPTC}
clean:
	rm -f ${OBJPATH}/* ${BINPATH}/${EXE}
