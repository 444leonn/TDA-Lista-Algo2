CFLAGS=-std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O2 -g
VFLAGS=--leak-check=full --track-origins=yes --track-origins=yes

tda:
	gcc main.c ./src/*.c ./src/tp1/*.c $(CFLAGS) -o tda

ejecutar: tda
	./tda $(PARAMETROS)

valgrind: tda
	valgrind $(VFLAGS) ./tda $(PARAMETROS)

pruebas_alumno:
	gcc ./pruebas_alumno.c ./src/*.c $(CFLAGS) -o pruebas_alumno

correr-pruebas: pruebas_alumno
	valgrind $(VFLAGS) ./pruebas_alumno

