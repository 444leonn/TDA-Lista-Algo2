#ifndef AUX_H_
#define AUX_H_

typedef nodo {
    void* dato;
    nodo_t* nodo_siguiente;
} nodo_t;

int comparador_enteros(const void* primer_dato, const void* segundo_dato);

void destructor_enteros(void* dato_entero);

#endif // AUX_H_
