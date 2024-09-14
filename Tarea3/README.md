# Tarea 1 IE-0217


Para la resolución de esta tarea, se hicieron dos programas: uno referente a un arbol binario, y uno referente a una lista enlazada. El programa del árbol binario le presenta al usuario con un árbol predefinido y un menú interactivo, en el que tiene opciones para:
- Insertar un nodo
- Eliminar un nodo
- Imprimir el árbol
- Calcular la altura del árbol
- Verificar si el árbol está balanceado
- Salir del programa

Asimismo, el programa de la lista enlazada le presenta al usuario con una lista de canciones, con 3 canciones predefinidas. Las canciones tienen título, artista y duración. También contiene un menú interactivo con las siguientes opciones:
- Insertar una nueva canción al inicio de la lista
- Insertar una nueva canción al final de la lista
- Insertar una nueva canción en una posición específica de la lista
- Eliminar una canción
- Modificar los datos de una canción existente
- Imprimir la lista de canciones
- Salir del programa

Para los códigos, se creó una [página a través de Netlify](https://tarea3-ie0217-c00041.netlify.app/index.html) a partir de la documentación de Doxygen. 

## Insrucciones para correr el código

Considerando que se tiene instalado un compilador GCC para C++, lo primero es **situarse en la carpeta raíz _Tarea3_**. Ambos códigos se ejecutarán en orden, primero mostrando el menú para el manejo del árbol binario, y una vez se elige la opción de salir de ese programa se entra al programa de la lista enlazada de cancioness. Gracias al Makefile, solo es necesario un comando en línea para compilar y correr todo:

```
make
```


# Parte Teórica 

Se procede a responder las preguntas correspondientes a la parte teórica de la tarea.

## 1. Explique cada sección del nivel de usuario de la memoria (Text, Heap, Stack, etc..) ¿Cuáles de estas secciones son de memoria dinámica?

- Text: Contiene el código ejecutable del programa. Es de solo lectura y no cambia durante la ejecución.
- Data: Se divide en dos partes:
    - .data: Contiene variables globales y estáticas inicializadas.
    - .bss: Contiene variables globales y estáticas no inicializadas.
- Heap: Es la sección de la memoria utilizada para la asignación dinámica. El programador puede solicitar y liberar memoria durante la ejecución del programa.
- Stack: Utilizado para el almacenamiento de variables locales y control de funciones (retornos y parámetros). Es una estructura LIFO y su tamaño se ajusta automáticamente durante la ejecución.
**Solo el heap** es considerado memoria dinámica ya que su tamaño puede cambiar en tiempo de ejecución.

[Referencia](https://www.it.uc3m.es/pbasanta/asng/course_notes/dynamic_memory_es.html)

## 2. Considerando que existen cuatro variables en el código (globalVar, staticVar, localVar y dynamicVar), mencione en qué sección de la memoria se almacena cada variable y explique el porqué

- _globalVar_ se almacena en la sección .data porque es una variable global inicializada.
- _staticVar_ también se almacena en la sección .data si está inicializada o en .bss si no lo está.
- _localVar_ se almacena en el stack, ya que es una variable local de la función.
- _dynamicVar_ se almacena en el heap, ya que se asigna dinámicamente usando new o malloc.

[Referencia](https://www.include-poetry.com/Code/C++/Introduccion/Variables/)

## 3. ¿Cuál es la diferencia entre memoria dinámica y memoria estática? Brinde un ejemplo de qué tipos de variables se almacenan en cada tipo.

- **Memoria estática:** Se asigna en tiempo de compilación y su tamaño no puede cambiar durante la ejecución. Ejemplo: variables globales y estáticas.
- **Memoria dinámica:** Se asigna en tiempo de ejecución y su tamaño puede cambiar durante la ejecución. Ejemplo: memoria asignada con new o malloc.

[Referencia](https://www.include-poetry.com/Code/C++/Introduccion/)

## 4. ¿Cómo se accede a la memoria dinámica del heap? Brinde un ejemplo programado de cómo guardar un valor en una posición de memoria ubicada ahí.

La memoria dinámica se accede mediante _punteros_. Ejemplo:
```cpp
int* ptr = new int;
*ptr = 5;
```
[Referencia](https://docs.hektorprofe.net/cpp/07-punteros-memoria/07-memoria-dinamica/)

## 5. ¿Por qué es importante liberar la memoria asignada dinámicamente cuando ya no se esté utilizando?

Si no se libera la memoria asignada dinámicamente, se produce una fuga de memoria lo que reduce la cantidad de memoria disponible y puede llevar a que el sistema se quede sin memoria.

[Referencia](https://docs.hektorprofe.net/cpp/07-punteros-memoria/07-memoria-dinamica/)
## 6. ¿Para que se utilizan las funciones malloc, calloc y realloc? ¿Qué parámetros recibe cada una?

- **_malloc_(size_t size):** Asigna un bloque de memoria de tamaño size bytes.
- **_calloc_(size_t num, size_t size):** Asigna un bloque de memoria para un arreglo de num elementos, inicializados a cero.
- **_realloc_(void* ptr, size_t new_size):** Cambia el tamaño del bloque de memoria apuntado por ptr a new_size bytes.

[Referencia](https://docs.hektorprofe.net/cpp/07-punteros-memoria/07-memoria-dinamica/)

## 7. Mencione las diferencias entre el uso de free y delete. ¿En qué contexto se utilizaría cada uno?

- _free_ se utiliza para liberar memoria asignada por malloc, calloc, o realloc.
- _delete_ se utiliza para liberar memoria asignada con new.
- _delete_ llama al destructor del objeto, mientras que free no lo hace.

[Referencia](https://es.stackoverflow.com/questions/199157/cual-es-la-diferencia-entre-delete-vs-delete-vs-free#:~:text=free%20%3A%20Es%20la%20m%C3%A1s%20simple,memoria%20reservada%20por%20el%20mismo)

## 8. Explique la diferencia entre new y malloc en C++. ¿Cuándo deberı́a utilizar uno sobre el otro?

_new:_ Inicializa objetos y llama a constructores. Ejemplo:
```cpp
int* ptr = new int(5);
```
_malloc:_ Solo asigna memoria, no llama a constructores. Ejemplo:
```cpp
int* ptr = (int*)malloc(sizeof(int));
```

Se debe usar _new_ en C++ ya que es compatible con los constructores y destructores.


[Referencia](https://es.quora.com/Cu%C3%A1l-es-la-diferencia-entre-malloc-y-new-en-C#:~:text=new%20llama%20al%20constructor%20apropiado,memoria%20de%20heap%20(mont%C3%B3n).)

## 9. Explique el concepto de punteros inteligentes (smart pointers) y proporcione ejemplos de su uso.

Los smart pointers son objetos que gestionan automáticamente la memoria, liberándola cuando ya no se necesita. También, tienen la ventaja de que no debemos declarar su tipo de variable, ellos mismos decifran a qué están apuntando y se preparan para devolver ese valor.

Ejemplos:

**unique_ptr:** Mantiene la propiedad única de un objeto.
**shared_ptr:** Permite que varios punteros compartan la propiedad de un objeto.
**weak_ptr:** Proporciona acceso no propietario a un objeto gestionado por shared_ptr.
Ejemplo:

```cpp
unique_ptr<int> p1(new int(10));
```

[Referencia](https://www.geeksforgeeks.org/smart-pointers-cpp/)
## 10. Mencione qué es un algoritmo y explique qué características básicas debería tener.

Un algoritmo es un conjunto de instrucciones para resolver un problema específico; y debería tener las siguientes características: finito, definido, eficiente y debe tener entradas y salidas.

[Referencia](https://youtu.be/5zgSXS4_Epk?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob)

## 11. ¿Qué es la complejidad y eficiencia de un algoritmo? ¿De qué manera se miden?

La complejidad mide los recursos requeridos por un algoritmo, como tiempo (complejidad temporal) y espacio (complejidad espacial).
Se mide comúnmente con la notación Big O, como _O(n^2)_, _O(n log n)_, entre otros.

[Referencia](https://youtu.be/5zgSXS4_Epk?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob)

## 12. ¿Cuál es la diferencia entre las estructuras de datos lineales y no-lineales? Mencione dos ejemplos de cada una.

- _Lineales:_ Los elementos se organizan secuencialmente. Ejemplos: arreglos, listas enlazadas.
- _No lineales:_ Los elementos se organizan jerárquicamente. Ejemplos: árboles, grafos.

## 13. Explique cómo funciona la estructura Stack.

Es una estructura con política de reemplazo tipo LIFO (Last In, First Out).Sus operaciones principales son: push (insertar) y pop (eliminar). Push pone algo en el 'top' y pop elimina lo que esté en el 'top'.

[Referencia](https://youtu.be/5zgSXS4_Epk?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob)

## 14. Explique cómo funciona la estructura Queue.

Es una estructura con política de reemplazo FIFO (First In, First Out)., como una fila del cine. Sus operaciones principales son: enqueue (insertar) y dequeue (eliminar).

[Referencia](https://youtu.be/5zgSXS4_Epk?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob)

## 15. Explique cómo funciona la estructura Lista Enlazada.

Consiste en nodos donde cada nodo contiene un dato y un puntero al siguiente nodo. Es útil ya que permite inserción y eliminación eficiente, en cualquier posición de la lista.

[Referencia](https://youtu.be/5zgSXS4_Epk?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob)

## 16. Explique cómo funciona la estructura Árbol. ¿Qué características presenta esta estructura?

Es una estructura jerárquica con un nodo raíz y subnodos. Algunas características son:
- _Nodo:_ Es una entidad que contiene una clave o valor y punteros a sus nodos secundarios. Los últimos nodos de cada ruta se denominan nodos hoja o nodos externos que no contienen un enlace/puntero a nodos secundarios. El nodo que tiene al menos un nodo hijo se denomina **nodo interno**.
- _Ariste:_ Es el vínculo entre dos nodos cualesquiera.
- _Raíz:_ Es el nodo más alto de un árbol.
- _Altura de un nodo:_ Es el número de aristas desde el nodo hasta la hoja más profunda (es decir, el camino más largo desde el nodo hasta un nodo de hoja).
- _Profundidad de un nodo:_ Es el número de aristas desde la raíz hasta el nodo.
- _Altura de un árbol:_ Es la altura del nodo raíz o la profundidad del nodo más profundo.
- _Grado de un nodo:_ Es el número total de ramas de ese nodo.
- _Bosque:_ Un conjunto de árboles separados se llama bosque.

[Referencia](https://youtu.be/5zgSXS4_Epk?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob)

## 17. Explique los tipos de recorridos que se le pueden aplicar a un árbol.

- _Recorrido en orden:_ Primero, todos los nodos en el subárbol izquierdo. Luego, el nodo raíz. Finalmente todos los nodos en el subárbol derecho.
- _Recorrido de pre-orden:_ Primero, el nodo raíz. Luego, todos los nodos en el subárbol izquierdo. Finalmente todos los nodos en el subárbol derecho.
- _Recorrido post-orden:_ Primero, todos los nodos en el subárbol izquierdo. Luego, todos los nodos en el subárbol derecho. Finalmente, el nodo raíz.

[Referencia](https://youtu.be/5zgSXS4_Epk?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob)


## 18. ¿Cuál es la diferencia entre un árbol y un árbol binario? Mencione y explique tres tipos de árboles binarios.

Un árbol binario es un tipo de árbol donde cada nodo tiene a lo sumo dos subramas (hijos).
Tipos de árboles binarios:
- _Árbol Binario Completo:_ Todos los niveles están completamente llenos.
- _Árbol Binario de Búsqueda (ABB):_ Los nodos a la izquierda tienen valores menores y los de la derecha mayores.
- _Árbol AVL:_ Árbol binario de búsqueda balanceado. La diferencia de altura entre subárboles no es mayor a 1.

[Referencia](https://youtu.be/5zgSXS4_Epk?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob)