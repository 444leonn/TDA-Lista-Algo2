#include "aux.h"
#include <stdlib.h>

int comparador_enteros(const void* primer_dato, const void* segundo_dato)
{
    int p_primer_dato = *(int*)primer_dato;
    int p_segundo_dato = *(int*)segundo_dato;
    if (p_primer_dato > p_segundo_dato)
        return 1;
    else if (p_primer_dato < p_segundo_dato)
        return -1;

    return 0;
}

void destructor_enteros(void* dato_entero)
{
    free(dato_entero);
}
