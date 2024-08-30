# Tarea 1 IE-0217


Para la resolución de esta tarea, se hicieron dos programas: un conversor de unidades de longitud, peso y temperatura; y una calculadora de estadisticas y búsqueda en un arreglo. Para cada ejercicio se realizaron tres archivos: un headerfile _.hpp_, un archivo fuente _.cpp_ y un archivo correspondiente al main, también de la forma _.cpp_. La documentación de los códigos se hace en formato Doxygen, a partir de la cual se crea una [página a través de Netlify](https://66d1d83b2b9c543fe8098d40--boisterous-toffee-4b240c.netlify.app/index.html). 

## Insrucciones para correr el código

Considerando que se tiene instalado un compilador GCC para C++, lo primero es situarse en la carpeta Tarea1. El código de la calculadora le pide a un usuario un arreglo de enteros desde la línea de comandos a la hora de ejecutar el código, sin embargo, en el Makefile se da un array predeterminado de {2, 5, 3, 7, 10, 3}, el cual se puede cambiar directamente desde el Makefile en la línea de **CALCULADORA_ARGS**. Ahora bien, una vez se está ubicado en Tarea1/, solo es necesario correr el comando _make run_. 

```
cd Tarea1
make run

```

Si se quisieran correr los programas por separado, se pueden seguir comandos distintos.

### Instrucciones para correr el Conversor de Unidades

Se unen los dos archivos _.cpp_ y se crea un ejecutable usando el compilador. Note que estas instrucciones son para la línea de comandos de Ubuntu. Las instrucciones son las siguientes:
```
g++ conversorDeUnidades.cpp mainConversorDeUnidades.cpp -o conversor
./conversor
```


### Instrucciones para correr la Calculadora de Estadísticas y Búsqueda en un Arreglo

Se unen los dos archivos _.cpp_ y se crea un ejecutable usando el compilador. Note que estas instrucciones son para la línea de comandos de Ubuntu. También, debe tener en cuenta que se necesita un arreglo ingresado desde la línea de comandos, el cual puede tener una longitud y determinada por el usuario, pero deben ser números enteros. Las instrucciones son las siguientes, donde _a, b, c, ..., x, y, z_ representan números enteros:
```
g++ calculadoraEstadisticas.cpp mainCalculadoraEstadisticas.cpp -o calculadora
./calculadora a b c ... x y z         // No hay separador entre los numeros, solo espacio
```

# Parte Teórica 

Se procede a responder las preguntas correspondientes a la parte teórica de la tarea.

## 1. ¿Cuáles son las diferencias entre los lenguajes compilados e interpretados? Brinde un ejemplo de cada uno.

En lenguajes compilados se traduce todo a lenguaje máquina por un compilador antes de que se pueda ejecutar, de ahí el nombre "compilados"; un ejemplo es C. Los lenguajes interpretados son leídos línea por línea por un intérprete, y se corren en tiempo real; un ejemplo es Python. 

### Referencias: 

Se vio en la sesión 1, sin embargo, acá hay una [página](https://kb.iu.edu/d/agsz) que lo respalda.

## 2. ¿Qué son los tipos de datos en C++? ¿Cuáles son sus clasificaciones? Brinde dos ejemplos de cada clasificación.

En C++, los tipos de datos definen qué tipo de valor puede almacenar una variable y qué operaciones se pueden realizar con ella. Los tipos de datos son muchos y se clasifican en varias categorías principales:

### 1. Tipos de Datos Básicos (Primitivos)
- **Enteros**
  1. `int` — Ejemplo: `int edad = 25;`
  2. `long long` — Ejemplo: `long long distancia = 1234567890123;`

- **Caracteres**
  1. `char` — Ejemplo: `char inicial = 'A';`
  2. `char` — Ejemplo: `char letra = 'z';`

- **Punto Flotante**
  1. `float` — Ejemplo: `float altura = 1.75f;`
  2. `double` — Ejemplo: `double pi = 3.14159265358979;`

- **Booleanos**
  1. `bool` — Ejemplo: `bool esActivo = true;`
  2. `bool` — Ejemplo: `bool tieneError = false;`

### 2. Tipos de Datos Derivados
- **Arrays (Arreglos)**
  1. `int numeros[5] = {1, 2, 3, 4, 5};`
  2. `char caracteres[] = {'a', 'b', 'c'};`

- **Punteros**
  1. `int* ptr = &edad;`
  2. `double* ptrD = &pi;`

### 3. Tipos de Datos Compuestos (Definidos por el Usuario)
- **Estructuras (`struct`)**
  1. 
     ```cpp
     struct Persona {
         std::string nombre;
         int edad;
     };
     Persona persona1 = {"Juan", 30};
     ```
  2. 
     ```cpp
     struct Punto {
         int x;
         int y;
     };
     Punto p1 = {10, 20};
     ```

- **Clases (`class`)**
  1. 
     ```cpp
     class Coche {
     public:
         std::string marca;
         int velocidad;
         void acelerar() { velocidad += 10; }
     };
     Coche coche1;
     coche1.marca = "Toyota";
     coche1.velocidad = 60;
     coche1.acelerar();
     ```
  2. 
     ```cpp
     class Rectangulo {
     private:
         int ancho;
         int alto;
     public:
         Rectangulo(int a, int b) : ancho(a), alto(b) {}
         int area() { return ancho * alto; }
     };
     Rectangulo r(10, 20);
     ```

### 4. Tipos de Datos Enumerados (`enum`)
- **Enumeraciones (`enum`)**
  1. 
     ```cpp
     enum Color { ROJO, VERDE, AZUL };
     Color colorFavorito = ROJO;
     ```
  2. 
     ```cpp
     enum Dia { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES };
     Dia diaHoy = MIERCOLES;
     ```

### Referencia:

[Geeks for geeks](https://www.geeksforgeeks.org/cpp-data-types/)

## 3. Explique qué es un linker en el contexto de un lenguaje de programación compilado. ¿Cuál es su función principal y por qué es esencial en el proceso de compilación?

Un linker es una herramienta que combina archivos objeto generados por el compilador en un único archivo ejecutable. Su función principal es resolver símbolos (funciones, variables) entre archivos y asignar direcciones de memoria. También puede incorporar bibliotecas estáticas y optimizar el código.

### Funciones Principales del Linker

1. **Enlazar archivos objeto**: Combina varios archivos en uno.
2. **Resolver símbolos**: Conecta referencias a funciones y variables con sus definiciones.
3. **Asignación de memoria**: Ajusta direcciones en el código.
4. **Generar ejecutable**: Produce el archivo ejecutable final.
5. **Incorporar bibliotecas**: Integra bibliotecas externas en el programa.

Finalmente, la importancia se debe a que es esencial para integrar módulos, resolver dependencias y generar un programa ejecutable que funcione correctamente.

### Referencias:

[Geeks for geeks](https://www.geeksforgeeks.org/linker/)

## 4. ¿Cuál es la diferencia entre usar el operador ‘=’ y ‘==’? Brinde un ejemplo para cada uno.

El operador _==_ normalmente se usa en condicionales para verificar si una variable es igual a otra variable o valor. Por otra parte, _=_ se usa para instanciar que algo es igual a otra cosa, normalmente que una variable toma cierto valor; no pregunta, instancia.

1. **Ejemplo 1:** if(var1 == 0) {cout << "var 1 es igual a cero" << endl;} 
2. **Ejemplo 2:** var2 = 4;      cout << "var 2 es igual " << var2 << endl;     // Esto imprime que var2 es igual a 4.

### Referencias:

Se vio en clases durante la primera sesión. [Sesión 1](https://youtu.be/TvvR8dhodHQ?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob)

## 5. Observe el siguiente código, indique qué imprime el programa en la iteración número 7 y 9 del ciclo, explique el porqué.
## Línea 7: sum+= i;
## Línea 9: std::cout << result << std::endl;

La **línea 7** utiliza el operador _+=_ lo que significa que si se tienen dos variables _a_ y _b_, dado _a += b_ es lo mismo que _a = a + b_.
La **línea 9** imprime en pantalla el valor de resultado, donde _result = sum_ si **i** módulo 3 es 0; y en caso contrario es _result = 0_

### Referencias:

Se vio en clases, durante la primera sesión. [Sesión 1](https://youtu.be/TvvR8dhodHQ?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob)

## 6. Explique el proceso de pasar argumentos a la función principal. ¿Cuál es el primer elemento de ‘argv[ ]’?

### Pasar argumentos a la función principal en C++

El proceso de pasar argumentos a la función principal implica utilizar los parámetros `int argc` y `char* argv[]` en la declaración de `main`. 

1. **`argc`**: Es el número de argumentos pasados desde la línea de comandos, incluido el nombre del programa (el cual es le primero).
2. **`argv[]`**: Es un arreglo de punteros a cadenas de caracteres (strings), que contiene los argumentos pasados. 

### Primer elemento de `argv[]`

El primer elemento `argv[0]` es siempre el nombre del programa o la ruta utilizada para ejecutarlo.

### Referencias:

El tema se estudió en clases, está en la presentación del profesor y también se empleó en la parte práctica de la tarea. [Sesión 1](https://youtu.be/TvvR8dhodHQ?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob)

## 7. ¿Cuál es la diferencia entre declarar e inicializar una variable?

Cuando se declara una variable, solo se instancia su tipo; mientras que cuando se inicializa una variable, se le da un valor a esta.

## Referencias:

[Sesión 1](https://youtu.be/TvvR8dhodHQ?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob)

## 8. ¿Para qué sirven los modificadores en C++?

Los modificadores peuden cambair distintas propiedades y comportamientos de variables, como el signo o el tamaño. Los modificadores _signed_ y _unsigned_ tienen que ver con los signos de los números (negativos y positivos); mientras que _short_ y _long_ cambian el tamaño de la variable.

### Referencias:

[Geeks for geeks](https://www.geeksforgeeks.org/cpp-type-modifiers/)

## 9. ¿Qué es la sobrecarga de funciones en C++ y cómo se utiliza?

La sobrecarga de funciones se refiere a ponerle el mismo nombre a varias funciones. La manera de utilizarlas, y la razón por las que el compilador las diferencia, es debido al tipo de valor que retornan, o el tipo de parámetro que reciben. Por ejemplo:

```
int mostrarNota(int a);
double mostrarNota(double a)
```
Estas dos funciones se llaman igual pero se diferencian de dos maneras: una devuelve int y tiene un int de parámetro, mientras que la otra retorna un flotante y tiene uno como parámetro.

### Referencias:

[Sesión 1](https://youtu.be/TvvR8dhodHQ?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob)

## 10. ¿Cuál es la diferencia entre una variable local y una local estática?

La principal diferencia entre la variable local y la variable estática es que el valor de la variable estática persiste al final del programa.

## Referencias:

Presentación 1 de Introducción a C++ y la [Sesión 1](https://youtu.be/TvvR8dhodHQ?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob) del profe.

## 11. ¿Qué es el type casting?

Type casting se refiere a la accion de transformar una variable de un tipo a otro tipo, como por ejemplo de double a int. Existen de tipo explícita e implícita.

1. **Ejemplo Implícito:**- El compilador convierte automáticamente un tipo de dato a otro si es necesario y seguro. No se requiere intervención del programador.

```
int main () {

    // se le asigna un valor entero a la variable num_int
    int num_int = 9;

    // se declara una variable tipo doble

    double num_double;

    // conversion implicita
    // se le asigna un valor entero a una variable doble

    num_double = num_int;

    cout << "num_int = " << num_int << endl;
    cout << "num_double = " << num_double << endl;

    return 0;
}

```

2. **Ejemplo Explícito**: El programador convierte manualmente el tipo de dato usando sintaxis de C. Es el más flexible, pero también el menos seguro, ya que permite convertir entre tipos sin verificación estricta.

```

int main() {

    // declaramos una variable de tipo doble
    double num_double = 3.56;
    cout << "num_double = " << num_double << endl;

    // conversion estilo C de doble a entero
    int num_int1 = (int)num_double;
    cout << "num_int1 = " << num_int1 << endl;

    // conversion estilo C de doble a entero
    int num_int2 = int(num_double);
    cout << "num_int2 = " << num_int2 << endl;

    return 0;
}
```
### Referencias:

Los ejemplos fueron tomados de la sesión 3, pero la explicación fue referenciada de [Javapoint](https://www.javatpoint.com/type-casting-in-cpp)

## 12. ¿Cuál es la principal diferencia entre un bucle ‘do-while’ y un bucle ‘while’?

El bucle while empieza solo cuando se cumple una condición, y luego de eso el bucle se mantiene corriendo mientras se cumpla. Por otra parte, el bucle do-while siempre realiza una iteración y es hasta después de esta que tiene un condicional, si se cumple se vuelve a iterar el bucle, si no entonces se sigue.

### Referencias

La presentación #1 de introducción a C++ del profe, junto con el video de la [sesión 1](https://youtu.be/TvvR8dhodHQ?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob)


## 13. Explique por qué es útil y común dividir el código en archivos .hpp, .cpp y main.cpp en C++. Describa el propósito específico de cada tipo de archivo.

Lo principal es el orden que se mantiene, y también es común dejar las declaraciones separadas del archivo fuente para que eel código sea más fácil de cambiar en un futuro también 
1. En el .hpp, van las declaraciones de las funciones, clases, constructores, métodos, etc. Se ponen los parámetros pero no las descripciones. 
2. En el .cpp está el archivo fuente, el cuál tiene la descripción de todas las funciones excepto la main.
3. El main.cpp solo va la función main, no es necesario que el archivo se llame main. A partir de esta función corre el programa.


### Referencias:

Presentación #2 sobre la introducción a C++ del profesor. Además, resulta útil escuchar la expliacación de la teoría en el [video de la sesión 3](https://youtu.be/dycqokbGZ3k?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob), o ver una [duda resuelta en Stack Overflow](https://stackoverflow.com/questions/41087485/how-to-divide-class-in-c-into-hpp-and-cpp-files)

## 14. ¿Qué hace la sentencia ‘goto’ y por qué es considerada una mala práctica en la programación moderna? ¿Qué alternativas se pueden usar en su lugar?

La sentencia 'goto' es una orden de tipo jump que se le da al programa para que salte a alguna etiqueta que uno settea. Es mala práctica porque se puede traer abajo la lógica del código o puede ser complicado manejarlo. En lugar de eso se podrían hacer funciones axiliares, jugar con _break_ y _continue_, o hasta implementar ciclos **for** o **while**.

### Referencias:

Presentación #2 sobre la introducción a C++ del profesor. Además, resulta útil escuchar la expliacación de la teoría en el [video de la sesión 3](https://youtu.be/dycqokbGZ3k?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob)

## 15. ¿Para qué se utiliza la directiva ‘#ifndef’ y por qué es importante?

Significa "if not defined", y siempre se pregunta al inicio del headerfile que si la definición que estamos haciendo existe. Si no existe, todo bien, se define; pero si sí existe entonces no entra a ese "if".

### Referencias:

[Esta página](https://www.cprogramming.com/reference/preprocessor/ifndef.html#:~:text=%23ifndef%20checks%20whether%20the%20given,is%20present%2C%20%23endif%20statement.) complementa bien el conocimiento adquirido al usar este tipo de programas.

## 16. ¿Qué es un puntero y para qué es útil? ¿Cómo se declara e inicializa?

Un puntero es un tipo variable que apunta a una dirección de memoria. Pueden tener distintos tipos, como punteros int, float, char, string, etc. La manera de declararlo es "tipoDeVariable* puntero", por ejemplo "int* puntero". La manera de inicializarlo es igualarlo a una dirección de memoria, lo cual normalmente se hace con &. Por ejemplo: "puntero = &var1" es un puntero de tipo entero que apunta a la dirección de memoria donde está guardada var1.

```
// tipos de punteros, inicializados con el asterisco(*) para demostrar que son tipo puntero

char* ptr1;
int* ptr2:

int* ptr3;
ptr3 = &var1    // almacena la direccion en memoria de var1 dentro de ptr3
cout << "el valor de var1 es" << *ptr3 << endl;     // *ptr3 es el puntero de-referenciado, por lo que me dice el valor almacenado en la ubicacion del pointer
```
## Referencias

Presentación #2 sobre la introducción a C++ del profesor. Además, resulta útil escuchar la expliacación de la teoría en el [video de la sesión 3](https://youtu.be/dycqokbGZ3k?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob).

## 17. ¿Cuál es la diferencia entre pasar parámetros por valor, por referencia y por puntero?

Al pasar un parámetro como **valor** se pasa una copia de este y el original no se ve afectado.
Por otra parte, si se usan de **referencia o puntero**, puede llegar a afectar el valor original, pero los punteros usan la dirección de memoria. Además, normalmente uno sabe que en el peor de los casos puede volver a inicializar el puntero o referencia en 0.

### Referencias

Presentación 1 de Introducción a C++ y la [Sesión 2](https://youtu.be/TvvR8dhodHQ?list=PLYVKm6dCj8SstdJH)

## 18. Cuando se usa un puntero para apuntar a un arreglo en C++, ¿a qué valor o direcciónapunta inicialmente? Describa cómo sería la forma de acceder a todos los datos de ese arreglo mediante el puntero

Cuando se apunta a un arreglo el puntero apunta al inicio del arreglo (arg[0]), y la manera de acceder a los datos es mediante un ciclo for y  de-referenciando el puntero. Se hace un ciclo for que aumente en 1 el puntero cada iteración, de modo que se va recorriendo (array[puntero++]), y podemos obtener el dato en esa dirección con la sintaxis "*puntero", lo cual representa el valor guardado en la dirección a la cual apunta puntero 

### Referencia:

Trabajo realizado en clase, o presentación sobre punteros del profesor, junto con su [video](https://youtu.be/dycqokbGZ3k?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob) de la sesión 2.

## 19. ¿En qué caso es conveniente usar el operador ‘->’ en punteros y por qué es beneficioso?

Cuando se está trabajando con clases es recomendable usar el operador -> junto con la palabra reservada 'this'. De esta manera, el compilador sabe que estamos hablando de *esta* clase, y la dirección en la que está guardado el atributo con el que estamos tratando. El operador 'flechita' es mejor para clases.

### Referencias:

Más información sobre [el operador flechita](https://www.educative.io/answers/what-is-the-arrow-operator-in-c-cpp)

## 20. ¿Cuál es la manera de implementar punteros dobles, triples, etc? Brinde un ejemplo de en qué caso sería beneficioso usar esta implementación.

### Implementación
- **Puntero doble**: Es un puntero que apunta a otro puntero.
- **Puntero triple**: Es un puntero que apunta a un puntero doble, y así sucesivamente.
La manera de obtener un puntero que apunta a otro, es solo igualar el punteroDoble par a que apunte a la dirección del otro

#### Ejemplo de puntero doble
```cpp
int x = 10;
int *p = &x;      // Puntero simple a 'x'
int **pp = &p;    // Puntero doble a 'p'
```
Un uso beneficioso sería con matrices, ya que se necesita conocer la dirección del puntero principal, y eso se puede hacer con otro puntero

### Referencias:

Presentación #2 sobre la introducción a C++ del profesor. Además, resulta útil escuchar la expliacación de la teoría en el [video de la sesión 3](https://youtu.be/dycqokbGZ3k?list=PLYVKm6dCj8SstdJHy0h7SRPF0L1coOZob).

## 21. ¿Qué es el puntero this en C++?

Cuando se usa 'this' es porque estamos trabajando con punteros que apuntan a atributos en clases. Al usar 'this', el compilador sabe que estamos hablando de *esta* clase, y la dirección en la que está guardado el atributo con el que estamos tratando.

## 22. ¿Qué es un puntero nullptr? 

Cuándo apunta al final de un string o a 'nada'. Básicamente apunta a NULL y se usa cuando se necesita tomar en cuenta el valor 'NULL' para la lógica del programa.

### Referencias:

[CPlusPlus pointers](https://cplusplus.com/doc/tutorial/pointers/)

## 23. ¿Qué es una función prototipo

El prototipo de una función es cuando se declara una función pero solo se instancia cuáles serán sus parámetros, no el cuerpo de esta misma. Normalmente se declara un prototipo si la función se requiere en una línea pero aún no ha sido descrita.

### Referencias

Presentación 1 de Introducción a C++ y la [Sesión 2](https://youtu.be/TvvR8dhodHQ?list=PLYVKm6dCj8SstdJH)

## 24. ¿Dónde y cómo se guardan las variables que se crean en C++? Explique la diferencia entre el almacenamiento de variables locales y globales.

Las **variables locales** se crean dentro de una función o un bloque de código y se almacenan en la _pila_ (stack). Estas variables existen solo durante la ejecución de la función o bloque donde fueron declaradas. Cuando la función termina, las variables locales se destruyen y la memoria se libera.

Por otra parte, las variables globales se crean fuera de cualquier función y se almacenan en la zona de datos del programa. Estas variables están disponibles en todo el programa, es decir, pueden ser accedidas desde cualquier función. La memoria para las variables globales se asigna una vez cuando el programa inicia y se libera cuando el programa termina.

### Referencias:

[Geeks for geekss](https://www.geeksforgeeks.org/scope-of-variables-in-c/)


## 25

Un **memory leak** (fuga de memoria) ocurre cuando un programa reserva memoria dinámica (por ejemplo, utilizando `new` en C++), pero no libera esta memoria adecuadamente después de que ya no es necesaria. Como resultado, la memoria sigue ocupada y no está disponible para otros usos, lo que puede llevar a un agotamiento de memoria y a un rendimiento deficiente o incluso a un fallo del programa. Algunas causas comúnes pueden ser:
1. No liberar memoria 
2. Pérdida de punteros

### Referencias:

[Geeks for geekss](https://www.geeksforgeeks.org/memory-leak-in-c-and-how-to-avoid-it/)

## 26. ¿Qué es memoria dinámica?

La **memoria dinámica** se refiere a la memoria que se asigna durante la ejecución del programa, es decir, en tiempo de ejecución. Esta memoria se maneja mediante funciones o operadores que permiten reservar y liberar bloques de memoria según las necesidades del programa. Se utiliza cuando el tamaño de los datos no se conoce en tiempo de compilación o cuando se necesita una cantidad variable de memoria.

## Referencias:

En este link se tiene explicada la [diferencia entre memorias](https://www.geeksforgeeks.org/difference-between-static-and-dynamic-memory-allocation-in-c/)

## 27. ¿Qué es memoria estática?

La **memoria estática** se refiere a la memoria que se asigna en tiempo de compilación y permanece durante toda la vida del programa. Esto incluye variables globales, estáticas y constantes. Este tipo de memoria nos resulta útil para variables que necesitan mantener su valor a lo largo de la vida del programa o que deben ser accesibles desde cualquier parte del código.

## Referencias:

En este link se tiene explicada la [diferencia entre memorias](https://www.geeksforgeeks.org/difference-between-static-and-dynamic-memory-allocation-in-c/)
