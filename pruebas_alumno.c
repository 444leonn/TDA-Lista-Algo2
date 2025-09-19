#include "pa2m.h"
#include "src/cola.h"
#include "src/lista.h"
#include "src/pila.h"
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
	int* dato;
	*dato = 5;
	if (lista != NULL) {
		lista_agregar(lista, dato);
	}
	pa2m_afirmar(lista_vacia(lista) == false, "Funcion lista_vacia devuelve false para una lista no vacia.");
	if (lista != NULL) {
		lista_destruir(lista);
	}
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
	int* dato;
	*dato = 5;
	if (lista != NULL) {
		lista_agregar(lista, dato);
	}
	lista_agregar(lista, dato);

	size_t cantidad = lista_cantidad(lista);
	pa2m_afirmar(cantidad == 1, "Lista cantidad devuelve la cantidad de elementos. (devolvio: %ld)", cantidad);

	if (lista != NULL) {
		lista_destruir(lista);
	}
}

void lista_agregar_devuelve_false_si_no_agrega()
{
	bool agregado = lista_agregar(NULL, NULL);

	pa2m_afirmar(agregado == false, "Agregar un elemento la lista no lo agrega.");

}

void lista_agregar_devuelve_true_si_agrega()
{
	lista_t* lista = lista_crear();
	int* dato;
	*dato = 5;

	bool agregado = lista_agregar(lista, dato);
	pa2m_afirmar(agregado == true, "Agregar un elemento la lista lo agrega.");

	if (lista != NULL) {
		lista_destruir(lista);
	}
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


	pa2m_nuevo_grupo("============== Pruebas de Pila ===============");

	pa2m_nuevo_grupo("============== Pruebas de Cola ===============");

	return pa2m_mostrar_reporte();
}
