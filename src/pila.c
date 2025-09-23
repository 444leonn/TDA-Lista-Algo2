#include "pila.h"
#include "aux.h"

struct pila {
    nodo_t* nodo_tope;
    size_t cantidad;
};

pila_t* pila_crear()
{
    return calloc(1, sizeof(pila_t));
}

bool pila_apilar(pila_t* pila, void* elemento)
{
    if (pila == NULL)
        return false;

    nodo_t *nuevo_nodo = malloc(sizeof(nodo_t));
    if (nuevo_nodo == NULL)
        return false;
    nuevo_nodo->dato = elemento;
    nuevo_nodo->proximo = NULL;

    if (pila->nodo_tope == NULL) {
        pila->nodo_tope = nuevo_nodo;
        pila->cantidad++;
        return true;
    }
    pila->nodo_tope->proximo = nuevo_nodo;
    pila->nodo_tope = pila->nodo_tope->proximo;
    pila->cantidad++;

    return true;
}
