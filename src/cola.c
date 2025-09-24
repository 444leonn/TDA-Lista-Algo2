#include "cola.h"
#include "aux.h"

struct cola {
	nodo_t *nodo_cabecera;
	nodo_t *ultimo_nodo;
	size_t cantidad;
};

cola_t *cola_crear()
{
	return calloc(1, sizeof(cola_t));
}

bool cola_encolar(cola_t *cola, void *elemento)
{
	if (cola == NULL)
		return false;

	nodo_t *nuevo_nodo = malloc(sizeof(nodo_t));
	if (nuevo_nodo == NULL)
		return false;
	nuevo_nodo->dato = elemento;
	nuevo_nodo->proximo = NULL;

	if (cola->nodo_cabecera == NULL) {
		cola->nodo_cabecera = nuevo_nodo;
		cola->ultimo_nodo = nuevo_nodo;
		cola->cantidad++;
		return true;
	}

	cola->ultimo_nodo->proximo = nuevo_nodo;
	cola->ultimo_nodo = cola->ultimo_nodo->proximo;
	cola->cantidad++;

	return true;
}

void *cola_desencolar(cola_t *cola)
{
	if (cola == NULL || cola_cantidad(cola) == 0)
		return NULL;

	void *dato = cola->nodo_cabecera->dato;
	nodo_t *nodo_aux = cola->nodo_cabecera;
	cola->nodo_cabecera = cola->nodo_cabecera->proximo;

	free(nodo_aux);

	cola->cantidad--;

	return dato;
}

void *cola_ver_primero(cola_t *cola)
{
	if (cola == NULL || cola_cantidad(cola) == 0)
		return NULL;
	return cola->nodo_cabecera->dato;
}

size_t cola_cantidad(cola_t *cola)
{
	if (cola == NULL)
		return 0;
	return cola->cantidad;
}

void cola_destruir(cola_t *cola)
{
	if (cola == NULL)
		return;

	nodo_t *p_nodo = cola->nodo_cabecera;
	while (p_nodo != NULL) {
		nodo_t *nodo_aux = p_nodo;
		p_nodo = p_nodo->proximo;
		if (nodo_aux != NULL)
			free(nodo_aux);
	}

	free(cola);
}
