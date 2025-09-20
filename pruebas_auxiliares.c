#include <stdio.h>

// // ARREGLAR
void* lista_eliminar_elemento(lista_t* lista, size_t posicion)
{
    void *dato_eliminado = NULL;

    if (lista == NULL || lista_vacia(lista))
        return NULL;

    if (posicion == 0) {
        void* dato_eliminado = lista->dato;
        lista_t* nodo_eliminado = lista;
        lista = lista->nodo_siguiente;
        free(nodo_eliminado);

        return dato_eliminado;
    }

    lista_t* aux = lista;
    size_t i = 0;
    while (i < posicion - 1 && aux->nodo_siguiente != NULL) {
        aux = aux->nodo_siguiente;
    }

    if (aux->nodo_siguiente == NULL)
        return NULL;

    lista_t* nodo_eliminado = aux->nodo_siguiente;
    dato_eliminado = nodo_eliminado->dato;

    aux->nodo_siguiente = nodo_eliminado->nodo_siguiente;
    free(nodo_eliminado);

    return dato_eliminado;
}


void lista_insertar_devuelve_null_para_posicion_invalida()
{
	lista_t* lista = lista_crear();
	int* dato = malloc(sizeof(int));
	*dato = DATO_EJEMPLO;

	bool insertado = lista_insertar(lista, dato, 4);
	pa2m_afirmar(insertado == false, "Insertar un elemento en una posicion invalida no lo inserta, devuelve false.");
	if (lista != NULL) {
		lista_destruir(lista);
	    free(dato);
	}
}

void lista_insertar_devuelve_true_para_posicion_valida()
{
	lista_t* lista = lista_crear();
	int* dato = malloc(sizeof(int));
	*dato = DATO_EJEMPLO;

	bool insertado = lista_insertar(lista, dato, 4);
	pa2m_afirmar(insertado == true, "Insertar un elemento en una posicion valida lo inserta, devuelve true.");
	if (lista != NULL) {
		lista_destruir(lista);
	    free(dato);
	}
}

void lista_eliminar_elemento_lista_vacia_devuelve_null()
{
	lista_t* lista = lista_crear();
	int* eliminado = lista_eliminar_elemento(lista, 0);
	pa2m_afirmar(eliminado == NULL, "Eliminar un elemento de la lista inexistente retorna NULL.");
	if (lista != NULL) {
		lista_destruir(lista);
	}
}

void lista_eliminar_elemento_posicion_0_devuelve_el_elemento()
{
	lista_t* lista = lista_crear();
	int* dato = malloc(sizeof(int));
	int* dato1 = malloc(sizeof(int));
	if (lista != NULL) {
		*dato = DATO_EJEMPLO;
		*dato1 = DATO_EJEMPLO;
		lista_agregar(lista, dato);
		lista_agregar(lista, dato1);
	}
	int* dato_eliminado = lista_eliminar_elemento(lista, 0);
	pa2m_afirmar(*dato_eliminado == DATO_EJEMPLO, "Eliminar un elemento de la lista retorna el elemento. (devolvio: %ld)", *dato_eliminado);
	if (lista != NULL)
		lista_destruir(lista);
	if (dato != NULL)
		free(dato);
	if (dato1 != NULL)
	    free(dato1);
}

void lista_eliminar_elemento_posicion_1_devuelve_el_elemento()
{
	lista_t* lista = lista_crear();
	int* dato = malloc(sizeof(int));
	int* dato1 = malloc(sizeof(int));
	if (lista != NULL) {
		*dato = DATO_EJEMPLO;
		*dato1 = DATO_EJEMPLO;
		lista_agregar(lista, dato);
		lista_agregar(lista, dato1);
	}
	int* dato_eliminado = lista_eliminar_elemento(lista, 1);
	pa2m_afirmar(*dato_eliminado == DATO_EJEMPLO, "Eliminar un elemento de la lista retorna el elemento. (devolvio: %ld)", *dato_eliminado);
	if (lista != NULL)
		lista_destruir(lista);
	if (dato != NULL)
		free(dato);
	if (dato1 != NULL)
	    free(dato1);
}
