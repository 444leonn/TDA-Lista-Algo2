#include "lista.h"
#include "aux.h"
#include <stdio.h>

struct lista {
    nodo_t* primer_nodo;
    size_t cantidad;
};

lista_t *lista_crear()
{
    return calloc(1, sizeof(lista_t));
}

bool lista_vacia(lista_t *lista)
{
    if (lista == NULL)
        return false;
    return lista->cantidad == 0;
}

size_t lista_cantidad(lista_t *lista)
{
    if (lista == NULL)
        return 0;
    return lista->cantidad;
}

nodo_t* agregar_recursivo(noto_t* nodo, void* dato)
{
    if (nodo == NULL) {
        nodo_t* nuevo_nodo = malloc(sizeof(nodo_t));
        if (nuevo_nodo == NULL)
            return NULL;
        nuevo_nodo->dato = dato;
        nuevo_nodo->nodo_siguiente = NULL;
        return nuevo_nodo;
    }

    nodo->nodo_siguiente = agregar_recursivo(nodo->nodo_siguiente, dato);
    return nodo;
}

bool lista_agregar(lista_t *lista, void *dato)
{
    if (lista == NULL || dato == NULL)
        return false;
    
    lista->primer_nodo = agregar_recursivo(lista->primer_nodo, dato);
    if (lista->primer_nodo != NULL) {
        lista->cantidad++;
        return true;
    }

    return false;
}

nodo_t* insertar_recursivo(nodo_t* nodo, void* dato, size_t posicion)
{
    if (nodo == NULL)
        return NULL;

    if (posicion == 0) {
        nodo_t* nuevo_nodo = malloc(sizeof(nodo_t));
        if (nuevo_nodo == NULL)
            return NULL;
        nuevo_nodo->dato = dato;
        nuevo_nodo->nodo_siguiente = nodo;
        return nuevo_nodo;
    }

    nodo->nodo_siguiente = insertar_recursivo(nodo->nodo_siguiente, dato, posicion - 1);
    return nodo;
}

bool lista_insertar(lista_t* lista, void* elemento, size_t posicion)
{
    if (lista == NULL || elemento == NULL)
        return false;

    lista->primer_nodo = insertar_recursivo(lista->primer_nodo, dato, posicion);
    if (lista->primer_nodo != NULL) {
        lista->cantidad++;
        return true;
    }

    return false;
}

void* lista_eliminar_elemento(lista_t* lista, size_t posicion)
{
    if (lista == NULL)
        return NULL;


}
