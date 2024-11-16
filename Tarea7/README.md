# Tarea 7 IE-0217: Pruebas Automatizadas y Continuous Integration en el Desarrollo de Software

Para esta tarea se realiza un script para añadir componentes eléctricos referentes a cada impedancia (Resistor, Capacitor, Inductor), así como la habilidad de calcular el valor de la impedancia equivalente al sumar estas en serie o paralelo. Cabe destacar que no es posible sumar impedancias de categorías distintas. 

Seguidamente, se le realizan tests de software al script con las distintas herramientas vistas en clase:
- Google Test
- Code Coverage (lcov)
- Github Actions


## Cómo correr el código




## Explicación del Software Testing

### Google Test
 
Primero, se realizan archivos de testing en C++, utilizando Google Test. Un código de ejemplo para la prueba de validación del método *agregarComponente*, donde se agrega una resistencia al inventario y luego se añaden más de esa misma, es el siguiente:

```cpp
// Se prueba el caso donde se agrega un componente y luego una mayor cantidad del mismo componente
TEST(InventarioTest, AgregarCantidadExistente) {
    Inventario inventario;
    inventario.agregarComponente(`Resistencia`, `Resistencia`, 10, `Resistencia de 10 ohms`);
    inventario.agregarComponente(`Resistencia`, `Resistencia`, 5, `Resistencia de 10 ohms`);

    testing::internal::CaptureStdout();
    inventario.listarComponentes();
    string output = testing::internal::GetCapturedStdout();
    
    // Se espera que la cantidad final sea de 15
    EXPECT_NE(output.find(`Cantidad: 15`), string::npos);
}
```

Algunas otras pruebas para _inventario_ y _calculos_, son las siguientes:
- Reducir la cantidad de componentes en el inventario
- Reducir una cantidad de componentes dle inventario de tal forma que la cantidad resultante sea negativa (inválida)
- Buscar un componente que no existe en el inventario
- Capacitancias en paralelo con argumentos invalidos
- Prueba válida para el método de sumar resistencias en serie
- El manejo del error de lista vacía (no se brindaron argumentos para los valores de las resistencias, capacitancias, etc.)

entre otras.

El procedimiento segiudo para compilar los archivos ejecutables utilizando el archivo *CMakelists.txt* se realiza desde la carpeta raíz _Tarea7_. Los comandos utilizados para la terminal son los siguientes:

```bash
mkdir build 
cd build
cmake ..
make
```

Al compilar todo con el archivo *CMakefile.txt*, se generan dos ejecutables para el testing: *testCalculos* y *testInventario*. El resultado de ejecutar estos archivos para validar las pruebas de ambos scripts de testing se puede notar en las dos siguientes imágenes:


Pruebas exitosas para calculos.cpp
![Pruebas exitosas para calculos.cpp](imagenes/PruebaCalculosGoogleTest.png)


Pruebas exitosas para inventario.cpp
![Pruebas exitosas para inventario.cpp](imagenes/PruebaInventarioGoogleTest.png)


Se nota que las pruebas realizadas fueron exitosas, por lo que se testea y debuggea correctamente el código. 

### Code Coverage

Luego de correr los archivos test generados, se procede a trabajar el code coverage para el script, utilizando `lcov`. Para generar el reporte, se actualiza el archivo `CMakeLists.txt` para habilitar la cobertura de código, y se procede con los siguientes comandos en terminal dentro de la carpeta *build*:

```bash
# Se capturan los datos con lcov
lcov --capture --directory . --output-file coverage.info  

# Se filtran archivos no relevantes
lcov --remove coverage.info '/usr/*' '*/tests/*' --output-file coverage.filtered.info

# Se genera el reporte en formato HTML
genhtml coverage.filtered.info --output-directory coverage-report

# Se visualiza el reporte, en este caso para Linux
xdg-open coverage-report/index.html
```

Los resultados del reporte se notan en la siguiente imagen:

![Resultados reporte HTML](imagenes/ReporteHTML.png)

Las líneas no cubiertas por pruebas se notan en esta imagen:
![Pruebas faltantes](imagenes/LineasNoCubiertasInventario.png)

Para cubrir estas líneas, de manera que se pueda tener un 100% de cobertura en el código, solo sería necesario agregar dos pruebas:
- Prueba para añadir una cantidad menor o igual a cero de algún componente
- Prueba para reducir una cantidad de un componente que no existe en el inventario

### Functional Testing

Se realiza una prueba funcional para probar el flujo correcto del script de `inventario.cpp`. La prueba sigue los siguientes pasos:

```cpp
// Paso 1: Agregar componentes y verificar que los componentes se agregaron correctamente

// Paso 2: Reducir una cantidad válida


// Paso 3: Intentar reducir una cantidad inválida (más de lo disponible)

// Paso 4: Verificar que el inventario final es correcto

// Paso 5: Buscar un componente en específico

```
Se espera que la prueba de resultados positivos, en el sentido de que las pruebas funcionen correctamente y se testee bien el script.

![Test de las pruebas funcionales](imagenes/MakeFunctionalTesting.png)

### Test-Driven Development

Primero se realiza un script para un simple testing con una prueba para cada método referente a las capacitancias: 
- Combinación de capacitancias en serie
- Combinación de capacitancias en paralelo
- Combinación de capacitancais en serie y paralelo

Seguidamente, se implemente una nueva función `capacitanciaEquivalenteSerieParalelo` en el archivo `calculos.cpp`, la cual se ve así:

```cpp
double Calculos::capacitanciaEquivalenteSerieParalelo(const vector<double>& serie, const vector<double>& paralelo) {
    validarValores(serie);
    validarValores(paralelo);

    double serieEq = capacitanciaSerie(serie);
    double paraleloEq = capacitanciaParalelo(paralelo);

    // Combinar serie y paralelo (asumimos que están en paralelo)
    return serieEq + paraleloEq;
}
```

Entonces, se le brindan dos listas de datos a la función: los valores de las capacitancias en serie y en paralelo. Las pruebas realizadas se nombran a continuación:
- Prueba válida para capacitancia equivalente combinada en serie y paralelo
- Prueba con una lista vacía para serie
- Prueba con valores negativos en paralelo
- Prueba con ambas listas vacías

Las pruebas se pasan con éxito, como se nota en la imagen:
![Pruebas para capacitancia equivalente](imagenes/ResultadosTestCapacitanciaEq.png)

### Github Actions

#### **1. Continuous Integration (CI)**

El flujo de trabajo de CI realiza lo siguiente:
1. **Instalación de Dependencias:**
   - Descarga e instala herramientas necesarias como `CMake`, `GoogleTest` y `LCOV`.
   - Clona el repositorio de GoogleTest para ejecutar las pruebas unitarias.

2. **Compilación del Proyecto:**
   - Compila los archivos fuente del proyecto junto con los tests utilizando `CMake`.

3. **Ejecución de Pruebas Unitarias:**
   - Ejecuta los binarios generados de las pruebas unitarias (`testInventario`, `testCalculos`, etc.).
   - Asegura que todas las pruebas pasen exitosamente.

4. **Reporte de Cobertura de Código:**
   - Genera un reporte de cobertura de código utilizando `LCOV`.
   

##### **Artefactos Generados por CI:**
- **coverage-report:** Contiene un reporte HTML que detalla la cobertura de código del proyecto.

---

#### **2. Continuous Delivery (CD)**

El flujo de trabajo de CD realiza lo siguiente:
1. **Empaquetado de Binarios:**
   - Los binarios generados (como `testInventario`, `testCalculos`, etc.) se comprimen en un archivo `.tar.gz` para su distribución.

2. **Subida de Binarios como Artefactos:**
   - El archivo comprimido con los binarios se sube como artefacto descargable en GitHub Actions bajo el nombre `Tarea7-binaries`.

3. **Simulación de Despliegue:**
   - Al final del flujo, se imprime el siguiente mensaje en los logs de **GitHub Actions**:
     `Despliegue exitoso: los binarios están listos para ser distribuidos.`

##### **Artefactos Generados por CD:**
- **Tarea7-binaries:** Archivo comprimido `.tar.gz` que contiene los binarios del proyecto.

---

#### **3. Configuración del Workflow**

El pipeline está configurado en el archivo `.github/workflows/ci_cd_Tarea7.yml`. A continuación, se describen las etapas principales:

##### **build-and-test**
1. **Checkout del Código:**
   Clona el repositorio.
2. **Instalación de Dependencias:**
   Instala herramientas como `CMake`, `GoogleTest` y `LCOV`.
3. **Compilación:**
   Compila el proyecto y genera binarios para las pruebas.
4. **Ejecución de Pruebas:**
   Ejecuta las pruebas unitarias generadas.
5. **Generación de Reporte de Cobertura:**
   Genera un reporte de cobertura de código en formato HTML.

##### **package-and-deploy**
1. **Empaquetado:**
   Comprime los binarios generados en un archivo `.tar.gz`.
2. **Subida de Binarios:**
   Sube el archivo comprimido como artefacto descargable.
3. **Simulación de Despliegue:**
   Imprime un mensaje indicando que el despliegue fue exitoso.


Como se puede ver en las siguientes imágenes, el proceso realizado por github actions fue exitoso, de tal forma que ambos dan "Success!", y se genera el mensae de éxito **"Los binarios están listos para ser distribuidos"**.

![Resumen Github Actions](imagenes/ResumenGithubActions.png)

![Mensaje de exito en Github Actions](imagenes/MensajeExitoGithubActions.png)

Ahora bien, para implementar este flujo en un proyecto real se podría realizar lo siguiente:
1. **Automatización de Despliegue Real:**
   - Modifica el paso "Simulate deployment" para realizar una acción real, como copiar binarios a un servidor o ejecutar un script de despliegue.

2. **Notificaciones:**
   - Añade integraciones para notificar al equipo (por ejemplo, usando Slack o correo) cuando el despliegue sea exitoso.

3. **Personalización:**
   - Adapta el pipeline a las necesidades específicas del proyecto, como configuraciones adicionales de compilación o pruebas de integración.


## Parte Teórica