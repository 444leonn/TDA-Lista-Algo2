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
    nodo_t* nodo_aux = pila->nodo_tope;
    pila->nodo_tope = nuevo_nodo;
    
    pila->nodo_tope->proximo = nodo_aux;

    pila->cantidad++;

    return true;
}

void* pila_desapilar(pila_t* pila)
{
    if (pila == NULL || pila_cantidad(pila) == 0)
        return NULL;

    void* dato = pila->nodo_tope->dato;
    nodo_t* nodo_aux = pila->nodo_tope;
    pila->nodo_tope = pila->nodo_tope->proximo;

    free(nodo_aux);

    return dato;
}

void *pila_ver_primero(pila_t *pila)
{
    if (pila == NULL || pila_cantidad(pila) == 0)
        return NULL;
    return pila->nodo_tope->dato;
}

size_t pila_cantidad(pila_t *pila)
{
    if (pila == NULL)
        return 0;
    return pila->cantidad;
}

void pila_destruir(pila_t *pila)
{
    if (pila == NULL)
        return;

    nodo_t* p_nodo = pila->nodo_tope;
    while (p_nodo != NULL) {
        nodo_t* nodo_aux = p_nodo;
        p_nodo = p_nodo->proximo;
        if (nodo_aux != NULL)
            free(nodo_aux);
    }

    free(pila);
}
