#include "src/lista.h"
#include "src/tp1/tp1.h"
#include "src/tp1/aux_tp1.h"
#include "src/tp1/mostrar_nombre.h"
#include "src/constantes.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc < 4) {
		printf(TROJO
		       "Error, debe ingresar una cantidad de parametros valida." TNORMAL
		       "\n");
		return 1;
	}

	tp1_t *tp = tp1_leer_archivo(argv[1]);
	if (tp == NULL) {
		printf(TROJO "Error, ha fallado la lectura del archivo." TNORMAL
			     "\n");
		return 1;
	}

	return 0;
}
