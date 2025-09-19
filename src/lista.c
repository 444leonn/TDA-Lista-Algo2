#include "lista.h"

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
    if (lista == NULL || lista->nodo_siguiente == NULL)
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

    lista_t* puntero_inicio = lista;
    while (lista->nodo_siguiente != NULL) {
        lista = lista->nodo_siguiente;
    }

    if (lista->nodo_siguiente == NULL) {
        lista_t* nuevo_nodo = lista_crear();
        nuevo_nodo->dato = dato;

        lista->nodo_siguiente = nuevo_nodo;
        lista = puntero_inicio;
        return true;
    }

    return false;
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
    lista_destruir_todo(lista->nodo_siguiente);
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
