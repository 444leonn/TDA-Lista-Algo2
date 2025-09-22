#include "lista.h"
#include "aux.h"
#include <stdio.h>

struct lista {
    struct nodo *primer_nodo;
    struct nodo *ultimo_nodo;
    size_t cantidad;
};

struct lista_iterador {
    lista_t* lista;
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
    
    nodo_t *nuevo_nodo = malloc(sizeof(nodo_t));
    if (nuevo_nodo == NULL)
        return false;
    nuevo_nodo->dato = dato;
    nuevo_nodo->nodo_siguiente = NULL;

    if (lista->primer_nodo == NULL) {
        lista->primer_nodo = nuevo_nodo;
        lista->ultimo_nodo = nuevo_nodo;
        lista->cantidad++;
        return true;
    }

    lista->ultimo_nodo->nodo_siguiente = nuevo_nodo;
    lista->ultimo_nodo = lista->ultimo_nodo->nodo_siguiente;

    lista->cantidad++;

    return true;
}

bool lista_insertar(lista_t* lista, void* elemento, size_t posicion)
{
    if (lista == NULL)
        return false;

    nodo_t* nuevo_nodo = malloc(sizeof(nodo_t));
    if (nuevo_nodo == NULL)
        return false;
    nuevo_nodo->dato = elemento;
    
    nodo_t* p_nodo = lista->primer_nodo;
    nodo_t* nodo_aux = p_nodo;
    size_t i = 0;
    while (i < posicion) {
        if (p_nodo == NULL) {
            free(nuevo_nodo);
            return false;
        }
        nodo_aux = p_nodo;
        p_nodo = p_nodo->nodo_siguiente;
        i++;
    }
    
    nodo_aux->nodo_siguiente = nuevo_nodo;
    nuevo_nodo->nodo_siguiente = p_nodo;
    lista->cantidad++;
    
    return true;
}

void *lista_eliminar_elemento(lista_t *lista, size_t posicion) {
    if (lista == NULL || posicion >= lista->cantidad)
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
    if (lista == NULL)
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

void* lista_buscar_elemento(lista_t* lista, size_t posicion)
{
    if (lista == NULL || posicion >= lista->cantidad)
        return NULL;

    nodo_t* p_nodo = lista->primer_nodo;
    size_t i = 0;
    while (i < posicion) {
        p_nodo = p_nodo->nodo_siguiente;
        i++;
    }

    return p_nodo->dato;
}

size_t lista_con_cada_elemento(lista_t* lista, bool (*f)(void*, void*), void* extra)
{
    if (lista == NULL || f == NULL || lista_vacia(lista))
        return 0;

    size_t cantidad_aplicados = 0;
    bool aplicado = true;

    nodo_t* p_nodo = lista->primer_nodo;
    while (p_nodo != NULL && aplicado) {
        aplicado = f(p_nodo->dato, extra);
        p_nodo = p_nodo->nodo_siguiente;
        cantidad_aplicados++;
    }

    return cantidad_aplicados;
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
