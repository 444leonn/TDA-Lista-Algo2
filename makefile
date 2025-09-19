##
# TDA-Lista-113246
#
# @file
# @version 0.1
CFLAGS=-std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O2 -g
VFLAGS=--leak-check=full --track-origins=yes --track-origins=yes

tda:
	gcc main.c ./src/*.c $(CFLAGS) -o tda

ejecutar: tda
	./tda $(PARAMETROS)

valgrind: tda
	valgrind $(VFLAGS) ./tp1 $(PARAMETROS)

pruebas_alumno:
	gcc ./pruebas_alumno.c ./src/*.c $(CFLAGS) -o pruebas_alumno

correr-pruebas: pruebas_alumno
	valgrind $(VFLAGS) ./pruebas_alumno

# end
