#include "lista.h"
#include "aux.h"
#include <stdio.h>

struct lista {
    struct nodo *primer_nodo;
    size_t cantidad;
};

lista_t *lista_crear()
{
    return calloc(1, sizeof(lista_t));
}

bool lista_vacia(lista_t *lista) {
    if (lista == NULL)
      return false;
    return lista->cantidad == 0;
}

size_t lista_cantidad(lista_t *lista) {
    if (lista == NULL)
      return 0;
    return lista->cantidad;
}

bool lista_agregar(lista_t *lista, void *dato)
{
    if (lista == NULL)
        return false;
    
    nodo_t* p_nodo = lista->primer_nodo;
    while (p_nodo->nodo_siguiente != NULL) {
        p_nodo = p_nodo->nodo_siguiente;
    }
    
    if (p_nodo->nodo_siguiente == NULL) {
        p_nodo->nodo_siguiente = calloc(1, sizeof(nodo_t));
        if (p_nodo->nodo_siguiente == NULL)
            return false;
        p_nodo->dato = dato;
        lista->cantidad++;
    }

    return true;
}

nodo_t *insertar_recursivo(nodo_t *nodo, void *dato, size_t posicion) {
    if (nodo == NULL)
      return NULL;

    if (posicion == 0) {
      nodo_t *nuevo_nodo = malloc(sizeof(nodo_t));
      if (nuevo_nodo == NULL)
        return NULL;
      nuevo_nodo->dato = dato;
      nuevo_nodo->nodo_siguiente = nodo;
      return nuevo_nodo;
    }

    nodo->nodo_siguiente =
        insertar_recursivo(nodo->nodo_siguiente, dato, posicion - 1);
    return nodo;
}

bool lista_insertar(lista_t *lista, void *elemento, size_t posicion) {
    if (lista == NULL || elemento == NULL)
      return false;

    lista->primer_nodo = insertar_recursivo(lista->primer_nodo, elemento, posicion);
    if (lista->primer_nodo != NULL) {
      lista->cantidad++;
      return true;
    }

    return false;
}

void *lista_eliminar_elemento(lista_t *lista, size_t posicion) {
    if (lista == NULL)
        return NULL;
    
    nodo_t* p_nodo = lista->primer_nodo;
    nodo_t* nodo_aux = p_nodo;
    if (p_nodo == NULL)
        return NULL;

    if (posicion == 0) {
        lista->primer_nodo = p_nodo->nodo_siguiente;
        void* dato_eliminado = p_nodo->dato;
        free(p_nodo);
        
        return dato_eliminado;
    }

    size_t i = 0;
    while (i < posicion) {
        nodo_aux = p_nodo;
        p_nodo = p_nodo->nodo_siguiente;
        if (p_nodo == NULL)
            return NULL;
        i++;
    }
    if (i == posicion) {
        nodo_aux->nodo_siguiente = p_nodo->nodo_siguiente;
        void* dato_elimnado = p_nodo->dato;
        free(p_nodo);
        lista->cantidad--;
     
        return dato_elimnado;
    }

    return NULL;
}

int lista_buscar_posicion(lista_t* lista, void* elemento, int (*comparador)(const void*, const void*))
{
    if (lista == NULL || elemento == NULL)
        return -1;
    
    int posicion = 0;
    nodo_t* p_nodo = lista->primer_nodo;
    while (p_nodo != NULL) {
        if (comparador(p_nodo->dato, elemento) == 0) {
            return posicion;
        }
        p_nodo = p_nodo->nodo_siguiente;
        posicion++;
    }
    
    return -1;
}


void lista_destruir_todo(lista_t* lista, void (*destructor)(void*))
{
    if (lista == NULL)
        return;

    nodo_t* p_nodo = lista->primer_nodo;
    while (p_nodo != NULL) {
        nodo_t* nodo_aux = p_nodo;
        p_nodo = p_nodo->nodo_siguiente;
        if (nodo_aux != NULL) {
            if (nodo_aux->dato != NULL)
                destructor(nodo_aux->dato);
            free(nodo_aux);
        }
    }

    free(lista);
}


void lista_destruir(lista_t *lista)
{
    if (lista == NULL)
        return;

    nodo_t* p_nodo = lista->primer_nodo;
    while (p_nodo != NULL) {
        nodo_t* nodo_aux = p_nodo;
        p_nodo = p_nodo->nodo_siguiente;
        if (nodo_aux != NULL)
            free(nodo_aux);
    }

    free(lista);
}
