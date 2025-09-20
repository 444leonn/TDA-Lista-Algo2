#include "lista.h"
#include <stdio.h>

struct lista {
    void* dato;
    lista_t* nodo_siguiente;
};

lista_t* lista_crear()
{
    return calloc(1, sizeof(lista_t));
}

bool lista_vacia(lista_t *lista)
{
    if (lista == NULL || (lista->nodo_siguiente == NULL && lista->dato == NULL))
        return true;
    return false;
}

size_t lista_cantidad(lista_t *lista)
{
    if (lista == NULL)
        return 0;

    lista_t* puntero_inicio = lista;

    size_t cantidad = 0;
    while (lista->nodo_siguiente != NULL) {
        lista = lista->nodo_siguiente;
        cantidad++;
    }

    lista = puntero_inicio;

    return cantidad;
}

bool lista_agregar(lista_t *lista, void *dato)
{
    if (lista == NULL)
        return false;

    lista_t* p_inicio_lista = lista;

    while (lista->nodo_siguiente != NULL)
        lista = lista->nodo_siguiente;

    if (lista->nodo_siguiente == NULL) {
        lista->dato = dato;
        lista->nodo_siguiente = lista_crear();
    }

    lista = p_inicio_lista;

    return true;
}

int lista_buscar_posicion(lista_t* lista, void* elemento, int (*comparador)(const void*, const void*))
{
    int posicion = -1, i = 0;

    if (lista == NULL || elemento == NULL || comparador == NULL || lista_vacia(lista))
        return posicion;

    lista_t *p_inicio_lista = lista;
    bool encontrado = false;


    while (lista->nodo_siguiente != NULL && !encontrado) {
        if (comparador(lista->dato, elemento) == 0) {
            encontrado = true;
            posicion = i;
        }
        lista = lista->nodo_siguiente;
        i++;
    }

    lista = p_inicio_lista;

    return posicion;
}

void lista_destruir_todo(lista_t* lista, void (*destructor)(void*))
{
    if (lista == NULL || destructor == NULL)
        return;

    if (lista->nodo_siguiente == NULL) {
        destructor(lista->dato);
        free(lista);
        return;
    }
    lista_destruir_todo(lista->nodo_siguiente, destructor);
    destructor(lista->dato);
    free(lista);
}

void lista_destruir(lista_t *lista)
{
    if (lista == NULL)
        return;

    if (lista->nodo_siguiente == NULL) {
        free(lista);
        return;
    }
    lista_destruir(lista->nodo_siguiente);
    free(lista);
}
