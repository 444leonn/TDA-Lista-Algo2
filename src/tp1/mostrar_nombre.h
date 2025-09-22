#ifndef MOSTRAR_NOMBRE_H_
#define MOSTRAR_NOMBRE_H_

#include "tp1.h"
#include "aux_tp1.h"

#include <string.h>
#include <stdlib.h>

struct pokes_agrupados {
	struct pokemon *pokemones;
	size_t cantidad;
};

struct pokes_agrupados *crear_pokes(size_t capacidad_inicial);

void liberar_pokes(struct pokes_agrupados *pokes);

bool insertar_pokemon(struct pokemon *pokemon, void *pokes);

void mostrar_ordenados_por_nombre(struct pokes_agrupados *pokes);

#endif // MOSTRAR_NOMBRE_H_
