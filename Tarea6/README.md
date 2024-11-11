# Tarea 6 IE-0*17: Sistema de Administración en Paralelo y Depuración de Código

Para esta tarea se realizan dos ejercicios: la programación de un script en C++ de un sistema de administración de solicitudes en paralelo


## Insrucciones para correr el código

Considerando que se tiene instalado un compilador GCC para C++, lo primero es **situarse en la carpeta raíz _Tarea6_**. Ambos códigos se ejecutarán en orden, primero mostrando el menú para el manejo del árbol binario, y una vez se elige la opción de salir de ese programa se entra al programa de la lista enlazada de cancioness. Gracias al Makefile, solo es necesario un comando en línea para compilar y correr todo:

```
make
```

## Análisis del Sistema de Administración de Solicitudes en Paralelo 

### Explicación del Uso de Mecanismos de Sincronización
**Uso de Mutex (`mtx` y `stats_mtx`)**

*Justificación*: El `mutex` (`mtx`) se usa para proteger el acceso concurrente al búfer compartido (`buffer`). Sin un `mutex`, múltiples hilos de clientes y operadores podrían acceder y modificar el búfer al mismo tiempo, causando condiciones de carrera, inconsistencias en los datos y potenciales fallos.

- `stats_mtx`: Este `mutex` protege el acceso a los vectores `tiempos_espera` y `tiempos_procesamiento` que almacenan las estadísticas de rendimiento. Dado que estos vectores son accesibles desde múltiples hilos (operadores), el `mutex` asegura que las operaciones de escritura en estos vectores no se interrumpan ni produzcan inconsistencias.

**Uso de Semáforos (`empty_slots` y `full_slots`)**

- `empty_slots`: Este semáforo de conteo permite a los clientes (productores) añadir elementos al búfer solo cuando hay espacio disponible (buffer no lleno). `empty_slots` se inicializa con el tamaño del búfer (`BUFFER_SIZE`), de modo que cada cliente adquiere un "slot vacío" antes de añadir una solicitud. Cuando un operador extrae una solicitud, libera un "slot vacío" permitiendo que otros clientes puedan agregar más elementos.

- `full_slots`: Similarmente, el semáforo `full_slots` permite que los operadores (consumidores) procesen solicitudes solo cuando el búfer contiene al menos un elemento. Este semáforo se inicializa en `0,` y cada vez que un cliente añade una solicitud al búfer, se incrementa el conteo de `full_slots`, lo cual permite a los operadores adquirir y procesar solicitudes en el orden correcto.

*Justificación*: Los semáforos permiten gestionar de forma eficiente la capacidad del búfer y sincronizar los productores y consumidores, evitando condiciones de sobrecarga (cuando el buffer está lleno) y subutilización (cuando el buffer está vacío).

**Uso de Variables de Condición (`cv_client` y `cv_operator`)**
- `cv_client`: Esta `condition_variable` se usa para notificar a los clientes cuando un operador ha liberado espacio en el búfer. Si el búfer estaba lleno y un cliente intentaba añadir una solicitud, podría esperar en esta variable de condición hasta que se le notifique que hay espacio disponible.

- `cv_operator`: Similarmente, esta variable de condición notifica a los operadores cuando una solicitud ha sido añadida al búfer. Si el búfer estaba vacío y un operador intentaba extraer una solicitud, podría esperar en esta variable de condición hasta recibir una notificación de que una solicitud está disponible.

*Justificación*: Las variables de condición se utilizan aquí para evitar la "espera activa", permitiendo que los hilos se duerman y se despierten solo cuando es necesario. Esto optimiza el uso de CPU y permite una mayor eficiencia en el procesamiento de solicitudes.

### Análisis de Escenarios con pruebas realizadas

Se realizan tres pruebas distintas:  1000 clientes y 1000 operadores, 1000 clientes y 100 operadores; y 100 clientes y 1000 operadores. 

**Variación del Tamaño del Búfer**

*Tamaño pequeño del búfer*: Con un búfer pequeño, los clientes podrían encontrar el búfer lleno con más frecuencia, lo que causaría que se bloqueen hasta que un operador procese una solicitud. Esto podría llevar a un bajo rendimiento del sistema debido a una mayor espera de los clientes. Un tamaño de búfer pequeño es adecuado solo si el número de clientes y operadores es pequeño y los tiempos de procesamiento son rápidos.

*Tamaño grande del búfer*: Con un búfer grande, el sistema permite que los clientes continúen agregando solicitudes sin bloquearse, incluso si los operadores están ocupados. Esto es útil en sistemas con muchos clientes, pero si el número de operadores es insuficiente, las solicitudes podrían acumularse, aumentando los tiempos de espera en el búfer.

**Variación del Número de Clientes**

*Mismos clientes que operadores*: Si el número de clientes es el mismo que el número de operadores, se espera que sea el caso donde la eficiencia es mayor en el programa, ya que no hay recursos desperdiciados y la relación entre clientes y operadores es de 1 a 1. Se realiza una prueba con 1000 clientes y 1000 operadores; los resultados se pueden observar en la siguiente imagen.

![Prueba 1000 clientes y 1000 operadores](imagenes/Prueba10001000.png)

*Más clientes que operadores*: Si el número de clientes es significativamente mayor que el de operadores, habrá un mayor tiempo de espera en el búfer, ya que más solicitudes esperan a ser procesadas. En este caso, un tamaño de búfer mayor podría ayudar a mitigar las esperas de los clientes. Se realiza una prueba con 1000 clientes y 100 operadores; los resultados se pueden observar en la siguiente imagen.

![Prueba 1000 clientes y 100 operadores](imagenes/Prueba1000100.png)

*Menos clientes que operadores*: Si el número de clientes es bajo en comparación con los operadores, los operadores podrían encontrarse esperando a que lleguen nuevas solicitudes, lo cual reduciría la eficiencia general del sistema. Este escenario sería menos óptimo en términos de rendimiento, ya que los operadores estarían subutilizados. Se realiza una prueba con 100 clientes y 100 operadores; los resultados se pueden observar en la siguiente imagen.

![Prueba 100 clientes y 1000 operadores](imagenes/Prueba1001000.png)

En general, se notan variaciones en las respuestas, sin embargo, no son tan grandes. Esto se podría deber al poder de la máquina en la cual se está corriendo el sistema, o en el número de clientes y operadores, el cual tal vez siendo mayor podría generar resultados más contrastantes.

### Posibles Problemas y Soluciones
**Problemas Potenciales**
*Condiciones de Carrera*:

- *Problema*: Sin un adecuado control de sincronización, múltiples hilos podrían acceder y modificar el mismo recurso (como el búfer o las métricas) de manera simultánea, causando inconsistencias en los datos.
- *Solución*: Se implementaron `mutex` para proteger el acceso al búfer (`mtx`) y a las estadísticas (`stats_mtx`). Los `mutex` aseguran que solo un hilo pueda acceder y modificar estos recursos a la vez, evitando condiciones de carrera.

*Deadlocks*:

- *Problema*: Si los hilos de clientes y operadores se quedan esperando indefinidamente en una condición que nunca se cumple (por ejemplo, si `sistema_activo` se establece en `false` mientras los semáforos aún están en espera), podrían producirse bloqueos.
- *Solución*: La implementación verifica `sistema_activo` después de cada operación de sincronización (como `acquire()` y `wait()`) para asegurar que los hilos puedan salir de sus bucles de manera ordenada. Además, al finalizar `mostrar_metricas()`, se notifica a todos los hilos usando `cv_client.notify_all()` y `cv_operator.notify_all()`, asegurando que ningún hilo se quede bloqueado al terminar el sistema.

*Espera Activa*:

- *Problema*: Sin las variables de condición (`cv_client` y `cv_operator`), los hilos de clientes y operadores podrían intentar acceder al búfer en ciclos constantes, consumiendo CPU de forma innecesaria mientras esperan que haya espacio o solicitudes en el búfer.
- *Solución*: Las variables de condición permiten que los hilos se duerman hasta que las condiciones específicas se cumplan (como disponibilidad de espacio o de solicitudes en el búfer), optimizando el uso de CPU y reduciendo la espera activa.
Otros Aspectos de Sincronización y Rendimiento

*Justificación de Semáforos y Búferes Limitados*: Los semáforos (`empty_slots` y `full_slots`) y el tamaño del búfer aseguran que el sistema maneje correctamente la producción y el consumo de solicitudes sin saturar la memoria ni forzar a los posibles clientes a esperar innecesariamente.

*Escalabilidad*: El diseño actual permite ajustar el tamaño del búfer, el número de clientes y el número de operadores según las necesidades del sistema, ofreciendo flexibilidad para adaptarse a diferentes escenarios de carga.


## Análisis del Ejercicio de Depuración






## Parte Teórica



