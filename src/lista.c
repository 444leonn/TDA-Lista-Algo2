#include "lista.h"
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

bool lista_agregar(lista_t *lista, void *dato)
{
    if (lista == NULL || dato == NULL)
        return false;
    
    

}
