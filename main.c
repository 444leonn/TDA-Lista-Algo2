#include "src/lista.h"
#include "src/tp1.h"
#include "src/aux_tp1.h"
#include "src/constantes.h"

#include <stdio.h>
#include <string.h>

bool agregar_pokemon_en_lista(struct pokemon *pokemon, void *lista)
{
	if (lista == NULL)
		return false;
	lista_t *_lista = lista;

	lista_agregar(_lista, pokemon);

	return true;
}

int comparador_nombres(const void *pokemon, const void *nombre_buscado)
{
	const struct pokemon *_pokemon = pokemon;
	const char *_nombre_buscado = nombre_buscado;

	if (strcmp(_pokemon->nombre, _nombre_buscado) > 0)
		return 1;
	if (strcmp(_pokemon->nombre, _nombre_buscado) < 0)
		return -1;
	return 0;
}

int comparador_ids(const void *pokemon, const void *id_buscado)
{
	const struct pokemon *_pokemon = pokemon;
	const char *c_id_buscado = id_buscado;
	int _id_buscado = atoi(c_id_buscado);

	if (_pokemon->id > _id_buscado)
		return 1;
	if (_pokemon->id < _id_buscado)
		return -1;
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc < 4) {
		printf(TROJO
		       "Error, debe ingresar una cantidad de parametros valida." TNORMAL
		       "\n");
		return 1;
	}

	tp1_t *tp = tp1_leer_archivo(argv[1]);
	if (tp == NULL) {
		printf(TROJO "Error, ha fallado la lectura del archivo." TNORMAL
			     "\n");
		return 1;
	}

	if (strcmp(argv[2], "buscar") != 0) {
		printf(TROJO "Error, parametro ingresado invalido." TNORMAL
			     "\n");
		tp1_destruir(tp);
		return 1;
	}

	lista_t *pokemones_enlazados = lista_crear();
	if (pokemones_enlazados == NULL) {
		printf(TROJO
		       "Error, no se ha podido reservar la memoria." TNORMAL
		       "\n");
	}
	tp1_con_cada_pokemon(tp, agregar_pokemon_en_lista, pokemones_enlazados);

	struct pokemon *pokemon_buscado = NULL;
	if (strcmp(argv[3], "nombre") == 0) {
		int posicion_pokemon_buscado = lista_buscar_posicion(
			pokemones_enlazados, argv[4], comparador_nombres);
		if (posicion_pokemon_buscado != POSICION_INVALIDA) {
			pokemon_buscado = lista_buscar_elemento(
				pokemones_enlazados,
				(size_t)posicion_pokemon_buscado);

			mostrar_pokemon(pokemon_buscado, NULL);
		} else {
			printf(TROJO
			       "Error, el pokemon no ha sido encontrado." TNORMAL
			       "\n");
		}
	} else if (strcmp(argv[3], "id") == 0) {
		int posicion_pokemon_buscado = lista_buscar_posicion(
			pokemones_enlazados, argv[4], comparador_ids);
		if (posicion_pokemon_buscado != POSICION_INVALIDA) {
			pokemon_buscado = lista_buscar_elemento(
				pokemones_enlazados,
				(size_t)posicion_pokemon_buscado);

			mostrar_pokemon(pokemon_buscado, NULL);
		} else {
			printf(TROJO
			       "Error, el pokemon no ha sido encontrado." TNORMAL
			       "\n");
		}
	} else {
		printf(TROJO "Error, opcion de busqueda invalida" TNORMAL "\n");
	}

	tp1_destruir(tp);
	lista_destruir(pokemones_enlazados);

	return 0;
}
