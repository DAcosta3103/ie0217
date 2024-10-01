# IE0217 Sesión 11: Resumen de SQL y Bases de Datos

Para esta sesión se estudian SQL y las bases de datos. En lugar de tener ejemplos programados de los comandos, se crea una especie de resumen sobre la información vista en la presentación referenete a la sesión: conceptos de SQL y las bases de datos como tal, así como comandos y sus respectivas descripciones. 

## Tipos de Bases de Datos
- **Relacionales**: Usan tablas para organizar los datos. Cada tabla contiene:
  - **Filas** (Registros)
  - **Columnas** (Atributos)
- **No Relacionales**: Almacenan datos de manera flexible, como:
  - **Documentos** (Ej. JSON)
  - **Pares Clave-Valor**
  - **Grafo** (Nodos y aristas)
  - **Columna Ancha** (Datos organizados por columnas)

## Principales Conceptos en SQL

| Término               | Descripción                                                                 |
|-----------------------|-----------------------------------------------------------------------------|
| **Tabla (Table)**      | Estructura principal donde se almacenan los datos.                          |
| **Fila (Row/Record)**  | Representa un único registro dentro de una tabla.                           |
| **Columna (Field)**    | Atributo o característica de los datos.                                     |
| **Clave Primaria**     | Identifica de manera única cada fila.                                       |
| **Clave Extranjera**   | Relaciona una tabla con otra.                                               |
| **Índice (Index)**     | Mejora la velocidad de las operaciones de consulta.                         |
| **Vista (View)**       | Tabla virtual basada en una consulta.                                       |

## Claves en Bases de Datos

- **Clave Primaria**: Identifica de manera única una fila en la tabla.
- **Clave Candidata**: Atributos que pueden identificar de manera única una fila.
- **Clave Alterna**: Clave candidata que no se selecciona como clave primaria.
- **Clave Compuesta**: Combinación de dos o más columnas para identificar de manera única una fila.
- **Clave Única**: Similar a la clave primaria, pero puede admitir valores NULL.
- **Clave Externa**: Atributo que toma valores de otra tabla.

## Operaciones CRUD

1. **Create (Crear)**: Crear una base de datos o tabla.
   ```sql
   CREATE DATABASE nombre_base_datos;
   CREATE TABLE nombre_tabla (columna1 tipo_dato, columna2 tipo_dato, ...);
   ```

2. **Read (Leer)**: Consultar datos en una tabla.
   ```sql
   SELECT * FROM nombre_tabla;
   ```

3. **Update (Actualizar)**: Modificar registros existentes.
   ```sql
   UPDATE nombre_tabla SET columna1 = valor1 WHERE condicion;
   ```

4. **Delete (Eliminar)**: Eliminar registros o tablas.
   ```sql
   DELETE FROM nombre_tabla WHERE condicion;
   DROP TABLE nombre_tabla;
   ```

## Comandos SQL para Manipulación de Datos

| Comando              | Descripción                                                                                       |
|----------------------|---------------------------------------------------------------------------------------------------|
| `INSERT INTO`        | Inserta nuevas filas en una tabla.                                                                 |
| `UPDATE`             | Modifica registros existentes en una tabla.                                                        |
| `DELETE`             | Elimina filas de una tabla.                                                                        |
| `SELECT`             | Consulta datos de una tabla.                                                                       |
| `SELECT INTO`        | Copia datos de una tabla a otra.                                                                   |
| `INSERT INTO SELECT` | Copia registros de una tabla a otra tabla existente.                                               |

## Joins en SQL

- **INNER JOIN**: Combina filas de dos tablas donde las columnas coinciden.
   ```sql
   SELECT columnas FROM tabla1 INNER JOIN tabla2 ON tabla1.columna = tabla2.columna;
   ```

- **LEFT JOIN**: Selecciona todas las filas de la tabla izquierda y las coincidencias de la derecha.
   ```sql
   SELECT columnas FROM tabla1 LEFT JOIN tabla2 ON tabla1.columna = tabla2.columna;
   ```

- **RIGHT JOIN**: Selecciona todas las filas de la tabla derecha y las coincidencias de la izquierda.
   ```sql
   SELECT columnas FROM tabla1 RIGHT JOIN tabla2 ON tabla1.columna = tabla2.columna;
   ```

- **FULL OUTER JOIN**: Selecciona todas las filas cuando hay coincidencias en cualquiera de las tablas.
   ```sql
   SELECT columnas FROM tabla1 FULL OUTER JOIN tabla2 ON tabla1.columna = tabla2.columna;
   ```

- **CROSS JOIN**: Combina todas las filas de las dos tablas sin ninguna condición de coincidencia.
   ```sql
   SELECT columnas FROM tabla1 CROSS JOIN tabla2;
   ```

- **SELF JOIN**: Une una tabla consigo misma.
   ```sql
   SELECT columnas FROM tabla1 t1, tabla1 t2 WHERE t1.columna = t2.columna;
   ```

## Modificación de Tablas

| Comando               | Descripción                                                                              |
|-----------------------|------------------------------------------------------------------------------------------|
| `CREATE TABLE`        | Crear una tabla nueva.                                                                    |
| `DROP TABLE`          | Eliminar una tabla existente.                                                             |
| `ALTER TABLE`         | Modificar la estructura de una tabla, como agregar o eliminar columnas.                   |
| `BACKUP DATABASE`     | Crear una copia de seguridad de la base de datos.                                         |

## Restricciones en SQL

| Restricción  | Descripción                                                                |
|--------------|----------------------------------------------------------------------------|
| **NOT NULL** | La columna no puede contener valores NULL.                                 |
| **UNIQUE**   | Asegura que todos los valores de una columna son únicos.                   |
| **PRIMARY KEY** | Identifica de manera única una fila en la tabla.                        |
| **FOREIGN KEY** | Relaciona una columna con la clave primaria de otra tabla.              |

## Seguridad en SQL: SQL Injection

El **SQL Injection** es una técnica donde se ejecutan comandos SQL malintencionados a través de campos de entrada o parámetros en la URL, lo que puede dar acceso no autorizado a la base de datos.

## Copias de Seguridad

- **BACKUP DATABASE**: Crear una copia de seguridad de la base de datos.
   ```sql
   BACKUP DATABASE nombre_base_datos TO DISK = 'ruta_de_respaldo';
   ```

