<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# TDA LISTA/PILA/COLA

## Repositorio de (Nombre Apellido) - (Padrón) - (Mail)

- Para la compilacion y ejecucion del programa de provee un **makefile**.

  - Compilar:

    ```bash
    # compilar el programa
    make tda
    # compilar las pruebas
    make pruebas_alumno
    ```

  - Ejecutar:

    ```bash
    # correr el programa
    make ejecutar PARAMETROS="<parametros>"
    # correr con el programa valgrind
    make valgrind PARAMETROS="<parametros>"
    # correr las pruebas
    make correr_pruebas
    ```

    > [!IMPORTANT]
    > Los _parametros_ que se deben pasar entre "" corresponden a el nombre de un archivo con pokemones, y tres parametros extra los cuales son busqueda, nombre o id, nombre del pokemon buscado o ID del pokemon buscado.
    > Ejemplo: `make ejecutar PARAMETROS="./ejemplos/normal.csv buscar nombre Pikachu"` o `make ejecutar PARAMETROS="./ejemplos/normal.csv buscar id 1"`

    

- Para ejecutar:

```bash
línea de ejecución
```

- Para ejecutar con valgrind:

```bash
línea con valgrind
```
---
##  Funcionamiento

Explicación de cómo funcionan las estructuras desarrolladas en el TP y el funcionamiento general del mismo.

Aclarar en esta parte todas las decisiones que se tomaron al realizar el TP, cosas que no se aclaren en el enunciado, fragmentos de código que necesiten explicación extra, etc.

Incluir **EN TODOS LOS TPS** los diagramas relevantes al problema (mayormente diagramas de memoria para explicar las estructuras, pero se pueden utilizar otros diagramas si es necesario).

### Por ejemplo:

El programa funciona abriendo el archivo pasado como parámetro y leyendolo línea por línea. Por cada línea crea un registro e intenta agregarlo al vector. La función de lectura intenta leer todo el archivo o hasta encontrar el primer error. Devuelve un vector con todos los registros creados.

<div align="center">
<img width="70%" src="img/diagrama1.svg">
</div>

En el archivo `sarasa.c` la función `funcion1` utiliza `realloc` para agrandar la zona de memoria utilizada para conquistar el mundo. El resultado de `realloc` lo guardo en una variable auxiliar para no perder el puntero original en caso de error:

```c
int *vector = realloc(vector_original, (n+1)*sizeof(int));

if(vector == NULL)
    return -1;
vector_original = vector;
```


<div align="center">
<img width="70%" src="img/diagrama2.svg">
</div>

---

## Respuestas a las preguntas teóricas
Incluír acá las respuestas a las preguntas del enunciado (si aplica).
