# ie0217 Sesión 15: Depuración, gdb, valgrin

Para esta sesión se estudian ldistintas herramientas de debuggeo, algunas incluidas con el comilador GCC, como es el caso de ASan. Las herramientas instaladas son:
- Valgrind
- GDB (GNU Debugger)
- Helgrind
- ASan (Address Sanitizer)


## Cómo correr los archivos de código

Lo más importante es cerciorarnos de tener un compilador para C++ instalado. En este caso usaremos GCC Compiler.

Ahora bien, una vez estamos listos, lo primero es estar en la carpeta referente a la Sesión 9, la cual se llama _'Sesion15'_, y dentro de ella se encuentra la carpeta _'src'_ para todo el código fuente utilizado en la sesión. Seguidamente, se recomienda crear un solo archivo ejecutable, y compilar y recompilarlo según sea necesario, dependiendo del tema que se quiera abordar a partir de los códigos. Notando que el archivo ejecutable ejemplo se llama **exe**, y el script origen ejemplo se llama _codigoEj.cpp_, los comandos de terminal a usar son los siguientes:

```
cd Sesiones/Sesion15/src
g++ -o exe codigoEj.cpp
./exe
```
