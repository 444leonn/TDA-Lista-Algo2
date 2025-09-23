#include "cola.h"
#include "aux.h"

struct cola {
    nodo_t* nodo_cabecera;
    nodo_t* ultimo_nodo;
    size_t cantidad;
};

cola_t *cola_crear();

bool cola_encolar(cola_t *cola, void *elemento);

void *cola_desencolar(cola_t *cola);

void *cola_ver_primero(cola_t *cola);

size_t cola_cantidad(cola_t *cola);

void cola_destruir(cola_t *cola);
