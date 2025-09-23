<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# TDA LISTA/PILA/COLA

## Repositorio de Leon Acosta - 113246 - leacosta@fi.uba.ar 

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
> Los parametros que se deben pasar entre "" corresponden al nombre de un archivo con pokemones, y tres parametros extra los cuales son busqueda, nombre o id, nombre del pokemon buscado o ID del pokemon buscado. 
>
> Ejemplo: `make ejecutar PARAMETROS="./ejemplos/normal.csv buscar nombre Pikachu"` O `make ejecutar PARAMETROS="./ejemplos/normal.csv buscar id 1"`

---

##  Funcionamiento

El programa funciona recibiendo por parametro el nombre de un archivo el cual contiene datos de pokemones, se encarga de hacer las verificaciones necesarias.
Luego se encarga de leerlo linea por linea, y parseando cada linea en una estructura de _pokemon_, cada pokemon es almacenado luego en una estructura `tp1_t`.
A partir de esa estructura es que se utiliza la implementacion del **TDA Lista** por nodos simplemente enlazados.
En donde cada nodo guarda la referencia a cada pokemon de la lista.
Utilizando las primitivas del _TDA Lista_ es que podemos realizar la busqueda del elemento dentro de la misma y finalmente mostrarlo.

---

## Respuestas a las preguntas teóricas

### Listas

Una _lista_ es una forma estructurada de almacenar dato/elementos. Esta misma admite ciertas operaciones que podemos aplicarle, para poder utilzar la informacion que almacenamos dentro de ella.
Se caracteriza por permitir recorrer y acceder a los elementos que estan dentro de ella sin restricciones.

Entre sus operaciones encontramos:

- Crear una lista.
- Verifcar si la lista esta vacia.
- Verificar la cantidad de elementos dentro de ella.
- Insertar, ya sea al final o en una posicion deseada.
- Obtener el elemento de una determinada posicion.
- Borrar un elemento de una determinada posicion.
- Destruir la lista.

Cuando hablamos de la implementacion de una lista, podemos utilizar diversas maneras, modificando como se encuentran dispuestos en memoria los elementos de la misma.

- **Como Arreglos:** En esta implementacion los elementos de una lista implementada como arreglo o vector se encuentran ubicados en memoria contigua, uno continuo con el otro. Podemos utilizar un arreglo con tamaño predefinido o un arreglo dinamico.
El arreglo de tamaño predefinido tiene como restriccion que no podremos almacenar mas de la cantidad de elementos preestablecida. Y el arreglo en memoria dinamica, tiene como reestriccion que frente a la necesidad de almacenar una gran cantidad de elementos, podemos llegar a encontrarnos con que no existe un espacio de memoria contigua lo suficientemenete grande como para poder almacenar la lista.
- **Nodos Enalazados:** Esta forma de implementacion de la lista consiste en almacenar el dato o elemento y una referencia a otro nodo. Esta forma de implementacion puede ser simple o doblemente enlazada.
    - **Simplemente Enlazada:** En esta implementacion cada nodo guarda una unicamente referencia al proximo nodo.
    - **Doblemente Enlazada:** A diferencia de la simplemente enlazada esta implementacion agrega una referencia mas, para almacenar tambien la referencia al nodo anterior.
