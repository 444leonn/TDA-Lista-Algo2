#include "pa2m.h"
#include "src/cola.h"
#include "src/lista.h"
#include "src/pila.h"
#include "src/aux.h"
#include "src/constantes.h"
#include <stdlib.h>

int comparador_enteros(const void *primer_dato, const void *segundo_dato)
{
	int p_primer_dato = *(int *)primer_dato;
	int p_segundo_dato = *(int *)segundo_dato;
	if (p_primer_dato > p_segundo_dato)
		return 1;
	else if (p_primer_dato < p_segundo_dato)
		return -1;

	return 0;
}

void destructor_enteros(void *dato_entero)
{
	free(dato_entero);
}

lista_t *crear_y_cargar_lista()
{
	lista_t *lista = lista_crear();
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
	lista_t *lista = lista_crear();
	pa2m_afirmar(lista != NULL, "Lista crear devuelve la lista.");
	if (lista != NULL) {
		lista_destruir(lista);
	}
}

void lista_vacia_devuelve_true_si_no_tiene_elementos()
{
	lista_t *lista = lista_crear();

	bool resultado = lista_vacia(lista);

	pa2m_afirmar(resultado == true,
		     "Funcion lista_vacia devuelve true para una lista vacia.");
	if (lista != NULL) {
		lista_destruir(lista);
	}
}

void lista_vacia_devuelve_false_si_tiene_elementos()
{
	lista_t *lista = crear_y_cargar_lista();

	bool resultado = lista_vacia(lista);

	pa2m_afirmar(
		resultado == false,
		"Funcion lista_vacia devuelve false para una lista no vacia.");
	if (lista != NULL)
		lista_destruir_todo(lista, destructor_enteros);
}

void lista_cantidad_devuelve_0_para_lista_nula()
{
	lista_t *lista = NULL;
	size_t cantidad = lista_cantidad(lista);
	pa2m_afirmar(
		cantidad == 0,
		"Lista cantidad devuelve 0 para una lista NULA. (devolvio: %ld)",
		cantidad);
}

void lista_cantidad_devuelve_la_cantidad_de_elementos()
{
	lista_t *lista = crear_y_cargar_lista();

	size_t cantidad = lista_cantidad(lista);
	pa2m_afirmar(
		cantidad == 3,
		"Lista cantidad devuelve la cantidad de elementos. (devolvio: %ld)",
		cantidad);

	if (lista != NULL)
		lista_destruir_todo(lista, destructor_enteros);
}

void lista_agregar_devuelve_false_si_no_agrega()
{
	bool agregado = lista_agregar(NULL, NULL);

	pa2m_afirmar(agregado == false,
		     "Agregar un elemento la lista no lo agrega.");
}

void lista_agregar_devuelve_true_si_agrega()
{
	lista_t *lista = lista_crear();
	int *dato = malloc(sizeof(int));
	*dato = DATO_EJEMPLO_1;

	bool agregado = lista_agregar(lista, dato);
	pa2m_afirmar(agregado == true,
		     "Agregar un elemento la lista lo agrega.");

	if (lista != NULL)
		lista_destruir_todo(lista, destructor_enteros);
}

void lista_insertar_devuelve_null_para_posicion_invalida()
{
	lista_t *lista = lista_crear();
	int *dato = malloc(sizeof(int));
	*dato = DATO_EJEMPLO_1;

	bool insertado = lista_insertar(lista, dato, 4);
	pa2m_afirmar(
		insertado == false,
		"Insertar un elemento en una posicion invalida no lo inserta, devuelve false.");
	if (lista != NULL) {
		lista_destruir(lista);
		free(dato);
	}
}

void lista_insertar_devuelve_true_para_posicion_valida()
{
	lista_t *lista = crear_y_cargar_lista();

	int *otro_dato = malloc(sizeof(int));
	*otro_dato = DATO_EJEMPLO_2;

	bool insertado = lista_insertar(lista, otro_dato, 1);
	pa2m_afirmar(
		insertado == true,
		"Insertar un elemento en una posicion valida lo inserta, devuelve true.");
	if (lista != NULL) {
		lista_destruir_todo(lista, destructor_enteros);
	}
}

void lista_eliminar_elemento_lista_vacia_devuelve_null()
{
	lista_t *lista = lista_crear();

	int *eliminado = lista_eliminar_elemento(lista, 0);

	pa2m_afirmar(
		eliminado == NULL,
		"Eliminar un elemento de la lista inexistente retorna NULL.");
	if (lista != NULL) {
		lista_destruir(lista);
	}
}

void lista_eliminar_elemento_posicion_0_devuelve_el_elemento()
{
	lista_t *lista = crear_y_cargar_lista();

	int *dato_eliminado = lista_eliminar_elemento(lista, 0);
	pa2m_afirmar(
		*dato_eliminado == DATO_EJEMPLO_1,
		"Eliminar un elemento de la lista retorna el elemento. (devolvio: %ld)",
		*dato_eliminado);

	if (dato_eliminado != NULL)
		free(dato_eliminado);
	if (lista != NULL)
		lista_destruir_todo(lista, destructor_enteros);
}

void lista_eliminar_elemento_posicion_1_devuelve_el_elemento()
{
	lista_t *lista = crear_y_cargar_lista();

	int *dato_eliminado = lista_eliminar_elemento(lista, 1);
	pa2m_afirmar(
		*dato_eliminado == DATO_EJEMPLO_2,
		"Eliminar un elemento de la lista retorna el elemento. (devolvio: %ld)",
		*dato_eliminado);

	if (dato_eliminado != NULL)
		free(dato_eliminado);
	if (lista != NULL)
		lista_destruir_todo(lista, destructor_enteros);
}

void lista_buscar_posicion_no_lo_encuentra()
{
	lista_t *lista = lista_crear();
	int *dato = malloc(sizeof(int));
	*dato = DATO_EJEMPLO_1;
	int *otro_dato = malloc(sizeof(int));
	*otro_dato = DATO_EJEMPLO_2;

	lista_agregar(lista, dato);
	int posicion_buscada =
		lista_buscar_posicion(lista, otro_dato, comparador_enteros);

	pa2m_afirmar(posicion_buscada == -1,
		     "Buscar elemento en lista no lo encuentra. (devolvio: %d)",
		     posicion_buscada);

	if (lista)
		lista_destruir_todo(lista, destructor_enteros);
	if (otro_dato)
		free(otro_dato);
}

void lista_buscar_posicion_devuelve_la_posicion()
{
	lista_t *lista = crear_y_cargar_lista();

	int *otro_dato = malloc(sizeof(int));
	*otro_dato = DATO_EJEMPLO_2;

	int posicion_buscada =
		lista_buscar_posicion(lista, otro_dato, comparador_enteros);
	pa2m_afirmar(
		posicion_buscada == 1,
		"Buscar la posicion de un elemento devuelve la posicion. (devolvio: %d)",
		posicion_buscada);
	if (lista)
		lista_destruir_todo(lista, destructor_enteros);
	if (otro_dato != NULL)
		free(otro_dato);
}

void lista_buscar_elemento_no_lo_encuentra_retorna_null()
{
	lista_t *lista = lista_crear();

	int *elemento_buscado = lista_buscar_elemento(lista, 0);
	pa2m_afirmar(
		elemento_buscado == NULL,
		"Buscar un elemento por posicion no lo encuentra y retorna NULL");

	if (lista != NULL)
		lista_destruir(lista);
}

void lista_buscar_elemento_lo_encuentra_retorna_elemento()
{
	lista_t *lista = crear_y_cargar_lista();

	int *elemento_buscado = lista_buscar_elemento(lista, 0);
	pa2m_afirmar(
		*elemento_buscado == DATO_EJEMPLO_1,
		"Buscar un elemento por posicion lo encuentra y lo retorna. (devolvio: %ld)",
		*elemento_buscado);

	if (lista != NULL)
		lista_destruir_todo(lista, destructor_enteros);
}

void iterador_crear_devuelve_null_para_lista_nula()
{
	lista_iterador_t *iterador = lista_iterador_crear(NULL);
	pa2m_afirmar(iterador == NULL,
		     "Crear un iterador con Lista NULA devuelve NULL.");
}

void iterador_crear_devuelve_el_iterador_correctamente()
{
	lista_t *lista = crear_y_cargar_lista();
	lista_iterador_t *iterador = lista_iterador_crear(lista);
	pa2m_afirmar(
		iterador != NULL,
		"Crear un iterador con Lista correcta devuelve el iterador.");
	if (iterador != NULL)
		lista_iterador_destruir(iterador);
	if (lista != NULL)
		lista_destruir_todo(lista, destructor_enteros);
}

void iterador_hay_mas_elementos_devuelve_false_para_lista_vacia()
{
	lista_t *lista = lista_crear();
	lista_iterador_t *iterador = lista_iterador_crear(lista);

	bool mas_elementos = lista_iterador_hay_mas_elementos(iterador);

	pa2m_afirmar(
		mas_elementos == false,
		"hay_mas_elementos() en un Iterador de una Lista sin elementos devuelve false.");
	if (lista != NULL)
		lista_destruir(lista);
	if (iterador != NULL)
		lista_iterador_destruir(iterador);
}

void iterador_hay_mas_elementos_devuelve_true()
{
	lista_t *lista = crear_y_cargar_lista();
	lista_iterador_t *iterador = lista_iterador_crear(lista);

	bool mas_elementos = lista_iterador_hay_mas_elementos(iterador);

	pa2m_afirmar(
		mas_elementos = true,
		"hay_mas_elementos() en un Iterador de una Lista con elementos aun por iterar devuelve true");

	if (iterador != NULL)
		lista_iterador_destruir(iterador);
	if (lista != NULL)
		lista_destruir_todo(lista, destructor_enteros);
}

void iterador_hay_mas_elementos_devuelve_false_al_iterar_todo()
{
	lista_t *lista = crear_y_cargar_lista();
	lista_iterador_t *iterador = lista_iterador_crear(lista);

	while (lista_iterador_hay_mas_elementos(iterador)) {
		lista_iterador_siguiente(iterador);
	}

	bool mas_elementos = lista_iterador_hay_mas_elementos(iterador);

	pa2m_afirmar(
		mas_elementos == false,
		"hay_mas_elementos() devuelve false para un Iterador luego de llegar al fin de las iteraciones");

	if (iterador != NULL)
		lista_iterador_destruir(iterador);
	if (lista != NULL)
		lista_destruir_todo(lista, destructor_enteros);
}

void iterador_obtener_actual_devuelve_null_para_lista_vacia()
{
	lista_t *lista = lista_crear();
	lista_iterador_t *iterador = lista_iterador_crear(lista);

	int *dato = lista_iterador_obtener_actual(iterador);

	pa2m_afirmar(
		dato == NULL,
		"Obtener el elemento de la actual Iteracion devuelve NULL para una Lista vacia.");

	if (iterador != NULL)
		lista_iterador_destruir(iterador);
	if (lista != NULL)
		lista_destruir(lista);
}

void iterador_obtener_actual_devuelve_el_elemento()
{
	lista_t *lista = crear_y_cargar_lista();
	lista_iterador_t *iterador = lista_iterador_crear(lista);

	int *dato = lista_iterador_obtener_actual(iterador);

	pa2m_afirmar(
		dato != NULL,
		"Obtener el elemento de la actual Iteracion devuelve el elemento.");

	if (iterador != NULL)
		lista_iterador_destruir(iterador);
	if (lista != NULL)
		lista_destruir_todo(lista, destructor_enteros);
}

void pila_crear_retorna_una_nueva_pila()
{
	pila_t *pila = pila_crear();
	pa2m_afirmar(pila != NULL, "Crear una nueva pila, retorna la pila.");
	if (pila != NULL)
		pila_destruir(pila);
}

void pila_apilar_elemento_en_pila_invalida_retorna_false()
{
	bool apilado = pila_apilar(NULL, NULL);

	pa2m_afirmar(
		apilado == false,
		"Apilar un elemento en una Pila invalida no lo apila y devuelve false.");
}

void pila_apilar_elemento_retorna_true_al_apilar()
{
	pila_t *pila = pila_crear();
	int *dato = malloc(sizeof(int));
	*dato = DATO_EJEMPLO_1;

	bool apilado = pila_apilar(pila, dato);

	pa2m_afirmar(
		apilado == true,
		"Apila un elemento en una Pila valida lo apila y devuelve true.");

	if (pila != NULL)
		pila_destruir(pila);
	if (dato != NULL)
		free(dato);
}

void pila_desapilar_con_pila_invalida_retorna_null()
{
	void *dato_desapilado = pila_desapilar(NULL);
	pa2m_afirmar(dato_desapilado == NULL,
		     "Desapilar de una Pila invalida devuelve NULL.");
}

void pila_desapilar_con_pila_vacia_retorna_null()
{
	pila_t *pila = pila_crear();
	void *dato_desapilado = pila_desapilar(pila);

	pa2m_afirmar(dato_desapilado == NULL,
		     "Desapilar de una Pila vacia devuelve NULL.");

	if (pila != NULL)
		pila_destruir(pila);
}

void pila_desapilar_elemento_del_tope_devuelve_elemento()
{
	pila_t *pila = pila_crear();
	int *dato_1 = malloc(sizeof(int));
	*dato_1 = DATO_EJEMPLO_1;

	pila_apilar(pila, dato_1);

	void *dato_desapilado = pila_desapilar(pila);
	pa2m_afirmar(
		dato_desapilado != NULL,
		"Desapilar de una Pila con elemento devuelve el elemento.");

	if (pila != NULL)
		pila_destruir(pila);
	if (dato_desapilado != NULL)
		free(dato_desapilado);
}

void pila_desapilar_elemento_del_tope_con_varios_elementos_devuelve_elemento()
{
	pila_t *pila = pila_crear();
	int *dato_1 = malloc(sizeof(int));
	if (dato_1 != NULL) {
		*dato_1 = DATO_EJEMPLO_1;
		pila_apilar(pila, dato_1);
	}

	int *dato_2 = malloc(sizeof(int));
	if (dato_2 != NULL) {
		*dato_2 = DATO_EJEMPLO_2;
		pila_apilar(pila, dato_2);
	}

	void *dato_desapilado = pila_desapilar(pila);
	pa2m_afirmar(
		dato_desapilado != NULL,
		"Desapilar de una Pila con mas de un elemento devuelve el elemento.");

	if (pila != NULL)
		pila_destruir(pila);
	if (dato_desapilado != NULL)
		free(dato_desapilado);
	if (dato_1 != NULL)
		free(dato_1);
}

void pila_ver_primero_devuelve_null_con_pila_invalida()
{
	void *primer_dato = pila_ver_primero(NULL);
	pa2m_afirmar(
		primer_dato == NULL,
		"Ver el Primer elemento de una Pila Invalida devuelve NULL.");
}

void pila_ver_primero_devuelve_null_con_pila_vacia()
{
	pila_t *pila = pila_crear();

	void *primer_dato = pila_ver_primero(pila);
	pa2m_afirmar(primer_dato == NULL,
		     "Ver el Primer elemento de una Pila Vacia devuelve NULL.");

	if (pila != NULL)
		pila_destruir(pila);
}

void pila_ver_primero_devuelve_el_tope_de_pila()
{
	pila_t *pila = pila_crear();
	int *dato_1 = malloc(sizeof(int));
	if (dato_1 != NULL) {
		*dato_1 = DATO_EJEMPLO_1;
		pila_apilar(pila, dato_1);
	}

	int *dato_2 = malloc(sizeof(int));
	if (dato_2 != NULL) {
		*dato_2 = DATO_EJEMPLO_2;
		pila_apilar(pila, dato_2);
	}

	void *primer_dato = pila_ver_primero(pila);
	pa2m_afirmar(primer_dato != NULL,
		     "Ver Primer elemento de la Pila devuelve el elemento.");

	if (pila != NULL)
		pila_destruir(pila);
	if (primer_dato != NULL)
		free(primer_dato);
	if (dato_1 != NULL)
		free(dato_1);
}

void pila_cantidad_devuelve_cantidad_de_elementos()
{
	pila_t *pila = pila_crear();
	int *dato_1 = malloc(sizeof(int));
	if (dato_1 != NULL) {
		*dato_1 = DATO_EJEMPLO_1;
		pila_apilar(pila, dato_1);
	}

	int *dato_2 = malloc(sizeof(int));
	if (dato_2 != NULL) {
		*dato_2 = DATO_EJEMPLO_2;
		pila_apilar(pila, dato_2);
	}

	size_t cantidad_elementos = pila_cantidad(pila);
	pa2m_afirmar(
		cantidad_elementos == 2,
		"Cantidad de elementos de la Pila devuelve la cantidad. (devolvio: %ld)",
		cantidad_elementos);

	if (pila != NULL)
		pila_destruir(pila);
	if (dato_1 != NULL)
		free(dato_1);
	if (dato_2 != NULL)
		free(dato_2);
}

void pila_cantidad_devuelve_0_para_pila_invalida()
{
	size_t cantidad_elementos = pila_cantidad(NULL);
	pa2m_afirmar(
		cantidad_elementos == 0,
		"Cantidad de elementos de la Pila devuelve 0 para lista invalida. (devolvio: %ld)",
		cantidad_elementos);
}

void cola_crear_retorna_una_nueva_cola()
{
	cola_t *cola = cola_crear();
	pa2m_afirmar(cola != NULL, "Crear una nueva cola, retorna la cola.");

	if (cola != NULL)
		cola_destruir(cola);
}

void cola_encolar_elemento_en_cola_invalida_retorna_false()
{
	bool encolado = cola_encolar(NULL, NULL);

	pa2m_afirmar(
		encolado == false,
		"Encolar un elemento en una Cola invalida no lo encola y devuelve false.");
}

void cola_encolar_elemento_retorna_true_al_encolar()
{
	cola_t *cola = cola_crear();
	int *dato = malloc(sizeof(int));
	*dato = DATO_EJEMPLO_1;

	bool acolado = cola_encolar(cola, dato);

	pa2m_afirmar(
		acolado == true,
		"Encolar un elemento en una Cola valida lo encola y devuelve true.");

	if (cola != NULL)
		cola_destruir(cola);
	if (dato != NULL)
		free(dato);
}

void cola_desencolar_con_cola_invalida_retorna_null()
{
	void *dato_desencolado = cola_desencolar(NULL);
	pa2m_afirmar(dato_desencolado == NULL,
		     "Desencolar de una Cola invalida devuelve NULL.");
}

void cola_desencolar_con_cola_vacia_retorna_null()
{
	cola_t *cola = cola_crear();
	void *dato_desencolado = cola_desencolar(cola);

	pa2m_afirmar(dato_desencolado == NULL,
		     "Desencolar de una Cola vacia devuelve NULL.");

	if (cola != NULL)
		cola_destruir(cola);
}

void cola_desencolar_elemento_del_tope_devuelve_elemento()
{
	cola_t *cola = cola_crear();
	int *dato_1 = malloc(sizeof(int));
	*dato_1 = DATO_EJEMPLO_1;

	cola_encolar(cola, dato_1);

	void *dato_desencolado = cola_desencolar(cola);
	pa2m_afirmar(
		dato_desencolado != NULL,
		"Desencolar de una Cola con elemento devuelve el elemento.");

	if (cola != NULL)
		cola_destruir(cola);
	if (dato_desencolado != NULL)
		free(dato_desencolado);
}

void cola_desencolar_elemento_del_tope_con_varios_elementos_devuelve_elemento()
{
	cola_t *cola = cola_crear();
	int *dato_1 = malloc(sizeof(int));
	if (dato_1 != NULL) {
		*dato_1 = DATO_EJEMPLO_1;
		cola_encolar(cola, dato_1);
	}

	int *dato_2 = malloc(sizeof(int));
	if (dato_2 != NULL) {
		*dato_2 = DATO_EJEMPLO_2;
		cola_encolar(cola, dato_2);
	}

	void *dato_desencolado = cola_desencolar(cola);
	pa2m_afirmar(
		dato_desencolado != NULL,
		"Desencolar de una Cola con mas de un elemento devuelve el elemento.");

	if (cola != NULL)
		cola_destruir(cola);
	if (dato_desencolado != NULL)
		free(dato_desencolado);
	if (dato_2 != NULL)
		free(dato_2);
}

void cola_ver_primero_devuelve_null_con_cola_invalida()
{
	void *primer_dato = cola_ver_primero(NULL);
	pa2m_afirmar(
		primer_dato == NULL,
		"Ver el Primer elemento de una cola Invalida devuelve NULL.");
}

void cola_ver_primero_devuelve_null_con_cola_vacia()
{
	cola_t *cola = cola_crear();

	void *primer_dato = cola_ver_primero(cola);
	pa2m_afirmar(primer_dato == NULL,
		     "Ver el Primer elemento de una cola Vacia devuelve NULL.");

	if (cola != NULL)
		cola_destruir(cola);
}

void cola_ver_primero_devuelve_el_tope_de_cola()
{
	cola_t *cola = cola_crear();
	int *dato_1 = malloc(sizeof(int));
	if (dato_1 != NULL) {
		*dato_1 = DATO_EJEMPLO_1;
		cola_encolar(cola, dato_1);
	}

	int *dato_2 = malloc(sizeof(int));
	if (dato_2 != NULL) {
		*dato_2 = DATO_EJEMPLO_2;
		cola_encolar(cola, dato_2);
	}

	void *primer_dato = cola_ver_primero(cola);
	pa2m_afirmar(primer_dato != NULL,
		     "Ver Primer elemento de la cola devuelve el elemento.");

	if (cola != NULL)
		cola_destruir(cola);
	if (primer_dato != NULL)
		free(primer_dato);
	if (dato_2 != NULL)
		free(dato_2);
}

void cola_cantidad_devuelve_cantidad_de_elementos()
{
	cola_t *cola = cola_crear();
	int *dato_1 = malloc(sizeof(int));
	if (dato_1 != NULL) {
		*dato_1 = DATO_EJEMPLO_1;
		cola_encolar(cola, dato_1);
	}

	int *dato_2 = malloc(sizeof(int));
	if (dato_2 != NULL) {
		*dato_2 = DATO_EJEMPLO_2;
		cola_encolar(cola, dato_2);
	}

	size_t cantidad_elementos = cola_cantidad(cola);
	pa2m_afirmar(
		cantidad_elementos == 2,
		"Cantidad de elementos de la cola devuelve la cantidad. (devolvio: %ld)",
		cantidad_elementos);

	if (cola != NULL)
		cola_destruir(cola);
	if (dato_1 != NULL)
		free(dato_1);
	if (dato_2 != NULL)
		free(dato_2);
}

void cola_cantidad_devuelve_0_para_cola_invalida()
{
	size_t cantidad_elementos = cola_cantidad(NULL);
	pa2m_afirmar(
		cantidad_elementos == 0,
		"Cantidad de elementos de la cola devuelve 0 para lista invalida. (devolvio: %ld)",
		cantidad_elementos);
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
	pa2m_nuevo_grupo("Pruebas de Creacion de Pila");
	pila_crear_retorna_una_nueva_pila();

	pa2m_nuevo_grupo("Pruebas de Apilar:");
	pila_apilar_elemento_en_pila_invalida_retorna_false();
	pila_apilar_elemento_retorna_true_al_apilar();

	pa2m_nuevo_grupo("Pruebas de Desapilar:");
	pila_desapilar_con_pila_invalida_retorna_null();
	pila_desapilar_con_pila_vacia_retorna_null();
	pila_desapilar_elemento_del_tope_devuelve_elemento();
	pila_desapilar_elemento_del_tope_con_varios_elementos_devuelve_elemento();

	pa2m_nuevo_grupo("Pruebas de Ver Primero en Pila:");
	pila_ver_primero_devuelve_null_con_pila_invalida();
	pila_ver_primero_devuelve_null_con_pila_vacia();
	pila_ver_primero_devuelve_el_tope_de_pila();

	pa2m_nuevo_grupo("Pruebas de Cantidad de Pila:");
	pila_cantidad_devuelve_0_para_pila_invalida();
	pila_cantidad_devuelve_cantidad_de_elementos();

	pa2m_nuevo_grupo("============== Pruebas de Cola ===============");
	pa2m_nuevo_grupo("Pruebas de Creacion de Cola");
	cola_crear_retorna_una_nueva_cola();

	pa2m_nuevo_grupo("Pruebas de Apilar:");
	cola_encolar_elemento_en_cola_invalida_retorna_false();
	cola_encolar_elemento_retorna_true_al_encolar();

	pa2m_nuevo_grupo("Pruebas de Desencolar:");
	cola_desencolar_con_cola_invalida_retorna_null();
	cola_desencolar_con_cola_vacia_retorna_null();
	cola_desencolar_elemento_del_tope_devuelve_elemento();
	cola_desencolar_elemento_del_tope_con_varios_elementos_devuelve_elemento();

	pa2m_nuevo_grupo("Pruebas de Ver Primero en cola:");
	cola_ver_primero_devuelve_null_con_cola_invalida();
	cola_ver_primero_devuelve_null_con_cola_vacia();
	cola_ver_primero_devuelve_el_tope_de_cola();

	pa2m_nuevo_grupo("Pruebas de Cantidad de cola:");
	cola_cantidad_devuelve_0_para_cola_invalida();
	cola_cantidad_devuelve_cantidad_de_elementos();

	return pa2m_mostrar_reporte();
}
