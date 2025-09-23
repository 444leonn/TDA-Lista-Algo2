#include "pa2m.h"
#include "src/cola.h"
#include "src/lista.h"
#include "src/pila.h"
#include "src/aux.h"
#include "src/constantes.h"
#include <stdlib.h>

lista_t* crear_y_cargar_lista()
{
    lista_t* lista = lista_crear();
    if (lista != NULL) {
        int *dato_1 = malloc(sizeof(int));
        if (dato_1 != NULL) {
            *dato_1 = DATO_EJEMPLO_1;
            lista_agregar(lista, dato_1);
        }
        
        int *dato_2 = malloc(sizeof(int));
        if (dato_2 != NULL) {
            *dato_2 = DATO_EJEMPLO_2;
            lista_agregar(lista, dato_2);
        }

        int *dato_3 = malloc(sizeof(int));
        if (dato_3 != NULL) {
            *dato_3 = DATO_EJEMPLO_3;
            lista_agregar(lista, dato_3);
        }
    }

    return lista;
}

void lista_crear_devuelve_la_lista()
{
	lista_t* lista = lista_crear();
	pa2m_afirmar(lista != NULL, "Lista crear devuelve la lista.");
	if (lista != NULL) {
		lista_destruir(lista);
	}
}

void lista_vacia_devuelve_true_si_no_tiene_elementos()
{
	lista_t* lista = lista_crear();

    bool resultado = lista_vacia(lista);

	pa2m_afirmar(resultado == true, "Funcion lista_vacia devuelve true para una lista vacia.");
	if (lista != NULL) {
		lista_destruir(lista);
	}
}

void lista_vacia_devuelve_false_si_tiene_elementos()
{
    lista_t* lista = crear_y_cargar_lista();

    bool resultado = lista_vacia(lista);

	pa2m_afirmar(resultado == false, "Funcion lista_vacia devuelve false para una lista no vacia.");
	if (lista != NULL)
		lista_destruir_todo(lista, destructor_enteros);
}

void lista_cantidad_devuelve_0_para_lista_nula()
{
	lista_t* lista = NULL;
	size_t cantidad = lista_cantidad(lista);
	pa2m_afirmar(cantidad == 0, "Lista cantidad devuelve 0 para una lista NULA. (devolvio: %ld)", cantidad);
}

void lista_cantidad_devuelve_la_cantidad_de_elementos()
{
    lista_t* lista = crear_y_cargar_lista();

	size_t cantidad = lista_cantidad(lista);
	pa2m_afirmar(cantidad == 3, "Lista cantidad devuelve la cantidad de elementos. (devolvio: %ld)", cantidad);

	if (lista != NULL)
		lista_destruir_todo(lista, destructor_enteros);
}

void lista_agregar_devuelve_false_si_no_agrega()
{
	bool agregado = lista_agregar(NULL, NULL);

	pa2m_afirmar(agregado == false, "Agregar un elemento la lista no lo agrega.");

}

void lista_agregar_devuelve_true_si_agrega()
{
	lista_t* lista = lista_crear();
	int* dato = malloc(sizeof(int));
	*dato = DATO_EJEMPLO_1;

    bool agregado = lista_agregar(lista, dato);
	pa2m_afirmar(agregado == true, "Agregar un elemento la lista lo agrega.");

	if (lista != NULL)
		lista_destruir_todo(lista, destructor_enteros);
}

void lista_insertar_devuelve_null_para_posicion_invalida()
{
	lista_t* lista = lista_crear();
	int* dato = malloc(sizeof(int));
	*dato = DATO_EJEMPLO_1;

	bool insertado = lista_insertar(lista, dato, 4);
	pa2m_afirmar(insertado == false, "Insertar un elemento en una posicion invalida no lo inserta, devuelve false.");
	if (lista != NULL) {
		lista_destruir(lista);
	    free(dato);
	}
}

void lista_insertar_devuelve_true_para_posicion_valida()
{
    lista_t* lista = crear_y_cargar_lista();

 	int* otro_dato = malloc(sizeof(int));
	*otro_dato = DATO_EJEMPLO_2;

    bool insertado = lista_insertar(lista, otro_dato, 1);
	pa2m_afirmar(insertado == true, "Insertar un elemento en una posicion valida lo inserta, devuelve true.");
	if (lista != NULL) {
		lista_destruir_todo(lista, destructor_enteros);
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
    lista_t* lista = crear_y_cargar_lista();

    int* dato_eliminado = lista_eliminar_elemento(lista, 0);
	pa2m_afirmar(*dato_eliminado == DATO_EJEMPLO_1, "Eliminar un elemento de la lista retorna el elemento. (devolvio: %ld)", *dato_eliminado);
	
    if (dato_eliminado != NULL)
        free(dato_eliminado);
    if (lista != NULL)
		lista_destruir_todo(lista, destructor_enteros);
}

void lista_eliminar_elemento_posicion_1_devuelve_el_elemento()
{
	lista_t* lista = crear_y_cargar_lista();

    int* dato_eliminado = lista_eliminar_elemento(lista, 1);
	pa2m_afirmar(*dato_eliminado == DATO_EJEMPLO_2, "Eliminar un elemento de la lista retorna el elemento. (devolvio: %ld)", *dato_eliminado);

    if (dato_eliminado != NULL)
        free(dato_eliminado);
    if (lista != NULL)
		lista_destruir_todo(lista, destructor_enteros);
}

void lista_buscar_posicion_no_lo_encuentra()
{
	lista_t* lista = lista_crear();
	int* dato = malloc(sizeof(int));
	*dato = DATO_EJEMPLO_1;
	int *otro_dato = malloc(sizeof(int));
	*otro_dato = DATO_EJEMPLO_2;

	lista_agregar(lista, dato);
	int posicion_buscada = lista_buscar_posicion(lista, otro_dato, comparador_enteros);

	pa2m_afirmar(posicion_buscada == -1, "Buscar elemento en lista no lo encuentra. (devolvio: %d)", posicion_buscada);

	if (lista)
		lista_destruir_todo(lista, destructor_enteros);
	if (otro_dato)
        free(otro_dato);
}

void lista_buscar_posicion_devuelve_la_posicion()
{
	lista_t* lista = crear_y_cargar_lista();

    int *otro_dato = malloc(sizeof(int));
	*otro_dato = DATO_EJEMPLO_2;

	int posicion_buscada = lista_buscar_posicion(lista, otro_dato, comparador_enteros);
	pa2m_afirmar(posicion_buscada == 1, "Buscar la posicion de un elemento devuelve la posicion. (devolvio: %d)", posicion_buscada);
	if (lista)
		lista_destruir_todo(lista, destructor_enteros);
    if (otro_dato != NULL)
        free(otro_dato);
}

void lista_buscar_elemento_no_lo_encuentra_retorna_null()
{
    lista_t* lista = lista_crear();

    int* elemento_buscado = lista_buscar_elemento(lista, 0);
    pa2m_afirmar(elemento_buscado == NULL, "Buscar un elemento por posicion no lo encuentra y retorna NULL");
    
    if (lista != NULL)
        lista_destruir(lista);
}

void lista_buscar_elemento_lo_encuentra_retorna_elemento()
{
    lista_t* lista = crear_y_cargar_lista();

    int* elemento_buscado = lista_buscar_elemento(lista, 0);
    pa2m_afirmar(*elemento_buscado == DATO_EJEMPLO_1, "Buscar un elemento por posicion lo encuentra y lo retorna. (devolvio: %ld)", *elemento_buscado);

    if (lista != NULL)
        lista_destruir_todo(lista, destructor_enteros);
}

void iterador_crear_devuelve_null_para_lista_nula()
{
    lista_iterador_t* iterador = lista_iterador_crear(NULL);
    pa2m_afirmar(iterador == NULL, "Crear un iterador con Lista NULA devuelve NULL.");
}

void iterador_crear_devuelve_el_iterador_correctamente()
{
    lista_t* lista = crear_y_cargar_lista();
    lista_iterador_t* iterador = lista_iterador_crear(lista);
    pa2m_afirmar(iterador != NULL, "Crear un iterador con Lista correcta devuelve el iterador.");
    if (iterador != NULL)
        lista_iterador_destruir(iterador);
    if (lista != NULL)
        lista_destruir_todo(lista, destructor_enteros);
}

void iterador_hay_mas_elementos_devuelve_false_para_lista_vacia()
{
    lista_t* lista = lista_crear();
    lista_iterador_t* iterador = lista_iterador_crear(lista);
    
    bool mas_elementos = lista_iterador_hay_mas_elementos(iterador);

    pa2m_afirmar(mas_elementos == false, "hay_mas_elementos() en un Iterador de una Lista sin elementos devuelve false.");
    if (lista != NULL)
        lista_destruir(lista);
    if (iterador != NULL)
        lista_iterador_destruir(iterador);
}

void iterador_hay_mas_elementos_devuelve_true()
{
    lista_t* lista = crear_y_cargar_lista();
    lista_iterador_t* iterador = lista_iterador_crear(lista);

    bool mas_elementos = lista_iterador_hay_mas_elementos(iterador);

    pa2m_afirmar(mas_elementos = true, "hay_mas_elementos() en un Iterador de una Lista con elementos aun por iterar devuelve true");

    if (iterador != NULL)
        lista_iterador_destruir(iterador);
    if (lista != NULL)
        lista_destruir_todo(lista, destructor_enteros);
}

void iterador_hay_mas_elementos_devuelve_false_al_iterar_todo()
{
    lista_t* lista = crear_y_cargar_lista();
    lista_iterador_t* iterador = lista_iterador_crear(lista);

    while (lista_iterador_hay_mas_elementos(iterador)) {
        lista_iterador_siguiente(iterador);
    }

    bool mas_elementos = lista_iterador_hay_mas_elementos(iterador);

    pa2m_afirmar(mas_elementos == false, "hay_mas_elementos() devuelve false para un Iterador luego de llegar al fin de las iteraciones");

    if (iterador != NULL)
        lista_iterador_destruir(iterador);
    if (lista != NULL)
        lista_destruir_todo(lista, destructor_enteros);
}

void iterador_obtener_actual_devuelve_null_para_lista_vacia()
{
    lista_t* lista = lista_crear();
    lista_iterador_t* iterador = lista_iterador_crear(lista);
    
    int* dato = lista_iterador_obtener_actual(iterador);

    pa2m_afirmar(dato == NULL, "Obtener el elemento de la actual Iteracion devuelve NULL para una Lista vacia.");

    if (iterador != NULL)
        lista_iterador_destruir(iterador);
    if (lista != NULL)
        lista_destruir(lista);
}

void iterador_obtener_actual_devuelve_el_elemento()
{
    lista_t* lista = crear_y_cargar_lista();
    lista_iterador_t* iterador = lista_iterador_crear(lista);
    
    int* dato = lista_iterador_obtener_actual(iterador);

    pa2m_afirmar(dato != NULL, "Obtener el elemento de la actual Iteracion devuelve el elemento.");

    if (iterador != NULL)
        lista_iterador_destruir(iterador);
    if (lista != NULL)
        lista_destruir_todo(lista, destructor_enteros);
}

int main()
{
	pa2m_nuevo_grupo("============== Pruebas de Lista ===============");
	pa2m_nuevo_grupo("Pruebas de Creacion de Lista");
	lista_crear_devuelve_la_lista();
	pa2m_nuevo_grupo("Pruebas de Lista Vacia:");
	lista_vacia_devuelve_true_si_no_tiene_elementos();
	lista_vacia_devuelve_false_si_tiene_elementos();
	pa2m_nuevo_grupo("Pruebas de Cantidad de Lista:");
	lista_cantidad_devuelve_0_para_lista_nula();
	lista_cantidad_devuelve_la_cantidad_de_elementos();
	pa2m_nuevo_grupo("Pruebas de Agregar Elementos en Lista:");
	lista_agregar_devuelve_false_si_no_agrega();
	lista_agregar_devuelve_true_si_agrega();
	pa2m_nuevo_grupo("Pruebas de Inserscion Elementos en Lista:");
	lista_insertar_devuelve_null_para_posicion_invalida();
	lista_insertar_devuelve_true_para_posicion_valida();
	pa2m_nuevo_grupo("Pruebas de Eliminar Elementos en Lista:");
	lista_eliminar_elemento_lista_vacia_devuelve_null();
	lista_eliminar_elemento_posicion_0_devuelve_el_elemento();
	lista_eliminar_elemento_posicion_1_devuelve_el_elemento();
	pa2m_nuevo_grupo("Pruebas de Busqueda Elemento en Lista:");
	lista_buscar_posicion_no_lo_encuentra();
	lista_buscar_posicion_devuelve_la_posicion();
    lista_buscar_elemento_no_lo_encuentra_retorna_null();
    lista_buscar_elemento_lo_encuentra_retorna_elemento();
    pa2m_nuevo_grupo("Pruebas de Iterador de Lista:");
    iterador_crear_devuelve_null_para_lista_nula();
    iterador_crear_devuelve_el_iterador_correctamente();
    iterador_hay_mas_elementos_devuelve_false_para_lista_vacia();
    iterador_hay_mas_elementos_devuelve_true();
    iterador_hay_mas_elementos_devuelve_false_al_iterar_todo();
    iterador_obtener_actual_devuelve_null_para_lista_vacia();
    iterador_obtener_actual_devuelve_el_elemento();

	pa2m_nuevo_grupo("============== Pruebas de Pila ===============");

	pa2m_nuevo_grupo("============== Pruebas de Cola ===============");

	return pa2m_mostrar_reporte();
}
