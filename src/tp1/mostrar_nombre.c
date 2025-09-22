#include "mostrar_nombre.h"
#include "aux_tp1.h"

#include <stdio.h>

struct pokes_agrupados *crear_pokes(size_t capacidad_inicial)
{
	struct pokes_agrupados *pokes = malloc(sizeof(struct pokes_agrupados));
	if (!pokes)
		return NULL;

	pokes->pokemones = reservar_pokemones(capacidad_inicial);
	if (!pokes->pokemones) {
		free(pokes);
		return NULL;
	}

	pokes->cantidad = 0;

	return pokes;
}

void liberar_pokes(struct pokes_agrupados *pokes)
{
	if (pokes != NULL) {
		for (int i = 0; i < pokes->cantidad; i++) {
			free(pokes->pokemones[i].nombre);
		}
		free(pokes->pokemones);
		free(pokes);
	}
}

bool insertar_pokemon(struct pokemon *pokemon, void *pokes)
{
	struct pokes_agrupados *_pokes = pokes;
	if (_pokes == NULL) {
		return false;
	}

	_pokes->pokemones[_pokes->cantidad] = *pokemon;

	size_t tamaño = strlen(pokemon->nombre) + 1;
	_pokes->pokemones[_pokes->cantidad].nombre =
		copiar_nombre(tamaño, pokemon->nombre);

	_pokes->cantidad++;

	return true;
}

void mostrar_ordenados_por_nombre(struct pokes_agrupados *pokes)
{
	if (pokes == NULL)
		return;

	ordenar_pokemones(pokes->pokemones, pokes->cantidad, comparador_nombre);

	for (int i = 0; i < pokes->cantidad; i++) {
		mostrar_pokemon(&pokes->pokemones[i], NULL);
	}
}
