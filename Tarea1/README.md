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
./calculadora a, b, c, ..., x, y, z         
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


