# IE0217 Tarea 5

Esta tarea trata sobre dos scripts: un sistema de reseñas de cursos y profesores usando MySQL y un sistema de publicaciones en redes sociales usando MongoDB.

# Parte Teórica

## 1. Diferencia entre bases de datos relacionales y no relacionales++

Las bases de datos relacionales y no relacionales difieren en varios aspectos:

- Estructura de datos:

Las bases de datos relacionales organizan la información en tablas con columnas y filas, donde cada fila representa una instancia y cada columna un atributo.
Las bases de datos no relacionales, como las bases de datos de documentos, clave-valor, grafos y familia de columnas, almacenan los datos en estructuras más flexibles.
- Casos de uso:

Las bases de datos relacionales son ideales para aplicaciones donde la consistencia y la integridad de los datos son cruciales, como en sistemas financieros.
Las bases de datos no relacionales son preferibles cuando se requiere escalabilidad horizontal y flexibilidad, como en aplicaciones de redes sociales o gestión de contenido.
- Escalabilidad:

Las bases de datos relacionales suelen escalar de forma vertical (aumentando la capacidad del servidor).
Las bases de datos no relacionales están diseñadas para escalar horizontalmente, distribuyendo la carga entre varios servidores.

[Referencia](https://www.w3schools.com/sql/sql_intro.asp)

## **2. ¿Qué es SQL y cuál es su importancia en la gestión de bases de datos relacionales?**

SQL (Structured Query Language) es un lenguaje de programación utilizado para interactuar con bases de datos relacionales, permitiendo realizar operaciones como consultar, insertar, actualizar y eliminar datos.

Algunos ejemplos de operaciones comunes con SQL:

- **SELECT:** Recupera datos de una o varias tablas.
- **INSERT:** Agrega nuevos registros a una tabla.
- **UPDATE:** Modifica registros existentes en una tabla.
- **DELETE:** Elimina registros de una tabla.


[Referencia](https://www.w3schools.com/sql/sql_intro.asp)

## **3. Componentes de una tabla de bases de datos SQL**

- **Nombre de la tabla:** Identifica a la tabla dentro de la base de datos.
- **Columnas:** Definen los atributos de la tabla; cada columna tiene un tipo de datos específico.
- **Filas o registros:** Cada fila es una instancia de los datos, representando una entrada en la tabla.
- **Clave primaria:** Identificador único para cada fila de la tabla.
- **Claves foráneas:** Enlazan una tabla con otra, creando relaciones entre tablas.


[Referencia](https://www.w3schools.com/sql/sql_intro.asp)

## **4. Operaciones CRUD y su implementación en bases de datos relacionales y no relacionales**

Las operaciones CRUD son las cuatro operaciones fundamentales para manipular datos en una base de datos:

- **Create (Crear):** En bases de datos relacionales, se realiza con el comando +INSERT+. En bases de datos no relacionales, la operación puede variar según la estructura, como +db.collection.insertOne+ en MongoDB.
- **Read (Leer):** Utilizando +SELECT+ en SQL para obtener datos. En bases no relacionales, se puede usar +db.collection.find+ en MongoDB.
- **Update (Actualizar):** Modifica registros; en SQL, es +UPDATE+, y en MongoDB, +db.collection.updateOne+.
- **Delete (Eliminar):** Remueve registros; en SQL es +DELETE+, y en MongoDB es +db.collection.deleteOne+.


[Referencia](https://www.w3schools.com/sql/sql_intro.asp)

## **5. Tres comandos SQL básicos**

- **SELECT:** Se usa para consultar datos. Ejemplo: +SELECT nombre FROM Productos+; consulta todos los nombres en la tabla +Productos+.

- **INSERT:** Agrega nuevos registros. Ejemplo: +INSERT INTO Productos (nombre, precio) VALUES ('Televisor', 299.99)+; agrega un televisor con precio de 299.99.
- **DELETE:** Elimina registros. Ejemplo: +DELETE FROM Productos WHERE id = 5+; elimina el producto con ID 5.


[Referencia](https://www.w3schools.com/sql/sql_intro.asp)

## **6. Tres comandos SQL de nivel intermedio o avanzado**

- **JOIN:** Permite combinar filas de dos o más tablas basadas en una relación común. Ejemplo: +SELECT Productos.nombre, Categorias.nombre FROM Productos JOIN Categorias ON Productos.id_categoria = Categorias.id+.
- **GROUP BY:** Agrupa filas que tienen el mismo valor en columnas especificadas. Ejemplo: +SELECT categoria, COUNT(*) FROM Productos GROUP BY categoria+; cuenta los productos en cada categoría.
- **HAVING:** Filtra resultados después de un +GROUP BY+. Ejemplo: +SELECT categoria, AVG(precio) FROM Productos GROUP BY categoria HAVING AVG(precio) > 100+.


[Referencia](https://www.w3schools.com/sql/sql_intro.asp)

## **7. JOIN en SQL y tipos de JOIN**

**JOIN:** Permite combinar datos de dos o más tablas según un criterio.

Tipos de JOIN:

- **INNER JOIN:** Devuelve solo los registros con coincidencias en ambas tablas. Usar cuando se desea solo la intersección de los datos.
- **LEFT JOIN:** Devuelve todos los registros de la tabla izquierda y las coincidencias de la tabla derecha, si existen. Útil cuando se necesita conservar toda la información de una tabla.
- **RIGHT JOIN:** Devuelve todos los registros de la tabla derecha y las coincidencias de la tabla izquierda, si existen. Utilizar cuando se quiere toda la información de la tabla derecha.


[Referencia](https://www.w3schools.com/sql/sql_intro.asp)

## **8. Consulta para obtener nombres y precios de productos en categorías "Electrónica" o "Deportes"**
```sql
SELECT nombre, precio AS costo FROM Productos 
WHERE categoria IN ('Electrónica', 'Deportes') AND en_stock = TRUE AND precio < 300 
ORDER BY costo ASC
```


[Referencia](https://www.w3schools.com/sql/sql_intro.asp)

## **9. Consulta para productos de color "azul" y peso menor a 1 kg**
```sql
SELECT nombre FROM Productos 
WHERE detalles_color = 'Azul' AND detalles_peso < 1 
ORDER BY nombre ASC
```


[Referencia](https://www.w3schools.com/sql/sql_intro.asp)

## **10. Consulta para el precio promedio de productos en la categoría "Hogar"**
```sql
SELECT AVG(precio) FROM Productos 
WHERE categoria = 'Hogar' AND en_stock = TRUE
```


[Referencia](https://www.w3schools.com/sql/sql_intro.asp)

## **11. Ataque de SQL Injection y cómo prevenirlo**

Un ataque de SQL Injection ocurre cuando un atacante manipula consultas SQL al ingresar código malicioso en campos de entrada. Esto permite acceder, modificar o eliminar datos de la base.

Algunas de las prácticas recomendadas son:

- **Usar consultas preparadas:** Previenen la inyección directa de código SQL.
- **Validar y limpiar entradas:** Asegura que los datos ingresados cumplen ciertos criterios.
- **Usar ORM:** Herramientas de mapeo objeto-relacional (ORM) minimizan la construcción manual de consultas SQL.


[Referencia](https://www.w3schools.com/sql/sql_intro.asp)

## **12. Rol de un servidor y un cliente en un sistema de gestión de bases de datos (DBMS)**


- **Servidor:** Almacena, gestiona y proporciona acceso a los datos. Responde a las solicitudes de los clientes y ejecuta las operaciones en la base de datos.
- **Cliente:** Solicita y presenta la información al usuario. En una arquitectura cliente-servidor, el cliente envía solicitudes al servidor, y el servidor procesa y envía los resultados al cliente.


[Referencia](https://www.w3schools.com/sql/sql_intro.asp)

## **13. Motor de bases de datos y ejemplos**

Un motor de bases de datos es el software que permite almacenar, recuperar y manipular datos dentro de una base de datos.

Los ejemplos son:

- **MySQL:** Base de datos relacional popular y de código abierto.
- **PostgreSQL:** Base de datos relacional avanzada con soporte para extensiones y tipos de datos complejos.
- **MongoDB:** Base de datos NoSQL orientada a documentos, ideal para aplicaciones con grandes volúmenes de datos no estructurados.

[Referencia](https://learn.microsoft.com/en-us/sql/relational-databases/databases/databases?view=sql-server-ver16)


## **14. Uso de MySQL**

MySQL es adecuado para aplicaciones que requieren consistencia y operaciones transaccionales, como sistemas de gestión de datos estructurados con relaciones definidas. Se recomienda su uso cuando la base de datos es pequeña o mediana, y en aplicaciones web o de software empresarial donde los datos se estructuran en tablas.

[Referencia](https://learn.microsoft.com/en-us/sql/relational-databases/databases/databases?view=sql-server-ver16)

## **15. Características de SQLite**

SQLite es adecuado para aplicaciones ligeras debido a su naturaleza embebida, sin necesidad de servidor. Es conveniente para dispositivos móviles y aplicaciones pequeñas que requieren almacenamiento de datos local, como en aplicaciones móviles o en entornos de desarrollo y prueba.

[Referencia](https://learn.microsoft.com/en-us/sql/relational-databases/databases/databases?view=sql-server-ver16)

## **16. Tipos de bases de datos NoSQL**

- **Clave-Valor:** Asocia una clave única con un valor, eficiente para consultas rápidas. Ejemplo: Redis, con comando +SET clave valor+.
- **Familia de Columnas:** Organiza los datos en columnas y filas agrupadas en familias, útil para grandes volúmenes de datos distribuidos. Ejemplo: Cassandra, con comando +INSERT INTO tabla (columna) VALUES (valor)+.
- **Grafos:** Representa datos como nodos y relaciones, útil para redes sociales o sistemas de recomendación. Ejemplo: Neo4j, con consulta +MATCH (a)-[r]->(b) RETURN a, r, b+.
- **Documentales:** Almacena datos en documentos tipo JSON, flexible para datos heterogéneos. Ejemplo: MongoDB, comando +db.collection.insertOne({clave: "valor"})+.

[Referencia](https://cloud.google.com/discover/what-is-nosql)

## **17. Colección en MongoDB**

En MongoDB, una colección es un grupo de documentos que almacenan datos relacionados, similar a una tabla en SQL. Sin embargo, a diferencia de una tabla, los documentos de una colección no requieren un esquema fijo, lo que permite almacenar datos de diversas estructuras en la misma colección.

[Referencia](https://www.mongodb.com/es/company/what-is-mongodb)

## **18. Diferencias de rendimiento y escalabilidad entre bases de datos SQL y NoSQL**

Las bases de datos SQL son consistentes y adecuadas para datos estructurados, pero su escalabilidad es limitada y se basa en la verticalidad. Las bases de datos NoSQL son más escalables horizontalmente y rápidas para datos no estructurados, siendo ideales para aplicaciones que gestionan grandes cantidades de datos en tiempo real, como redes sociales.

[Referencia](https://www.integrate.io/blog/the-sql-vs-nosql-difference/#:~:text=SQL%20databases%20are%20relational%2C%20and,NoSQL%20databases%20are%20horizontally%20scalable.)