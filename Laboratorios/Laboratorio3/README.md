# ie0217 Laboratorio 3

El laboratorio 3 trata sobre un ejercicio de **Programación ORientada a Objetos (POO)**: se tiene una clase base 'Empleado', la cual hereda dos clases, una para empleados de tiempo completo y otra para empleados de medio tiempo. Dentro de la clase base creamos un método virtual puro, de manera que esta se vuelve una clase abstracta. Una clase abstracta es aquella que contiene al menos un método virtual puro, y a partir de estas no se pueden crear objetos. 

## Instrucciones para compilar el código

Es requisito tener instalado un compilador de C++, este código se creó teniendo GCC Compiler. Una vez dentro de la carpeta raíz 'Laboratorio3', es necesario ingresar a la carpeta de source codes. Dentro de ella, se crea un archivo ejecutable a partir de los códigos de la carpeta, de manera que se peude visaulizar el ejercicio funcioando.

```
g++ main.cpp empleado.cpp empleadoTiempoCompleto.cpp empleadoMedioTiempo.cpp -o empleados
./empleados
```
