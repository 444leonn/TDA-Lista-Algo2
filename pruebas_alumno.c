#include "pa2m.h"
#include "src/cola.h"
#include "src/lista.h"
#include "src/pila.h"
#include "src/aux.h"
#include "src/constantes.h"
#include <stdlib.h>

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
	pa2m_afirmar(lista_vacia(lista) == true, "Funcion lista_vacia devuelve true para una lista vacia.");
	if (lista != NULL) {
		lista_destruir(lista);
	}
}

void lista_vacia_devuelve_false_si_tiene_elementos()
{
	lista_t* lista = lista_crear();
	int* dato = malloc(sizeof(int));
	*dato = DATO_EJEMPLO_1;
	if (lista != NULL) {
		lista_agregar(lista, dato);
	}
	pa2m_afirmar(lista_vacia(lista) == false, "Funcion lista_vacia devuelve false para una lista no vacia.");
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
	lista_t* lista = lista_crear();
	int* dato = malloc(sizeof(int));
	*dato = DATO_EJEMPLO_1;
	if (lista != NULL) {
		lista_agregar(lista, dato);
	}

	size_t cantidad = lista_cantidad(lista);
	pa2m_afirmar(cantidad == 1, "Lista cantidad devuelve la cantidad de elementos. (devolvio: %ld)", cantidad);

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

void lista_buscar_posicion_no_lo_encuentra()
{
	lista_t* lista = lista_crear();
	int* dato = malloc(sizeof(int));
	*dato = DATO_EJEMPLO_1;
	int *otro_dato = malloc(sizeof(int));
	*otro_dato = DATO_EJEMPLO_2;

	lista_agregar(lista, dato);
	int posicion_buscada = lista_buscar_posicion(lista, dato, comparador_enteros);

	pa2m_afirmar(posicion_buscada == -1, "Buscar elemento en lista no lo encuentra. (devolvio: %d)", posicion_buscada);

	if (lista)
		lista_destruir_todo(lista, destructor_enteros);
	if (otro_dato)
        free(otro_dato);
}

void lista_buscar_posicion_devuelve_la_posicion()
{
	lista_t* lista = lista_crear();
	int* dato = malloc(sizeof(int));
	*dato = DATO_EJEMPLO_1;
	int *otro_dato = malloc(sizeof(int));
	*otro_dato = DATO_EJEMPLO_2;
	int *otro_dato_mas = malloc(sizeof(int));
	*otro_dato_mas = DATO_EJEMPLO_3;

	lista_agregar(lista, dato);
	lista_agregar(lista, otro_dato);
	lista_agregar(lista, otro_dato_mas);

	int posicion_buscada = lista_buscar_posicion(lista, otro_dato, comparador_enteros);
	pa2m_afirmar(posicion_buscada == 1, "Buscar elemento por posicion en lista devuelve la posicion. (devolvio: %d)", posicion_buscada);
	if (lista)
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
	//pa2m_nuevo_grupo("Pruebas de Inserscion Elementos en Lista:");
	//lista_insertar_devuelve_null_para_posicion_invalida();
	//lista_insertar_devuelve_true_para_posicion_valida();
	pa2m_nuevo_grupo("Pruebas de Eliminar Elementos en Lista:");
	//lista_eliminar_elemento_lista_vacia_devuelve_null();
	//lista_eliminar_elemento_posicion_0_devuelve_el_elemento();
	//lista_eliminar_elemento_posicion_1_devuelve_el_elemento();
	pa2m_nuevo_grupo("Pruebas de Busqueda Elemento en Lista:");
	lista_buscar_posicion_no_lo_encuentra();
	lista_buscar_posicion_devuelve_la_posicion();

	pa2m_nuevo_grupo("============== Pruebas de Pila ===============");

	pa2m_nuevo_grupo("============== Pruebas de Cola ===============");

	return pa2m_mostrar_reporte();
}
