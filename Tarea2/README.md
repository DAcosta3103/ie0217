# IE0217 Tarea 2: Tienda virtual

El presente código se encarga de realizar un sistema de gestión para una tienda en línea. El código consta de un menú principal interactivo, el cual tiene 4 opciones:

1. **Agregar producto**
2. **Registrar cliente**
3. **Agregar producto al carrito**
4. **Procesar compra**
5. **Salir**

La opción de _agregar producto_ permite al usuario añadir un producto a la lista de productos disponibles para la compra, una vez un producto es añadido, se peude proceder a añadirlo al carrito de algún cliente. Puede escoger si es un producto físico o virtual.
La opción _registrar cliente_ permite al usuario añadir un cliente nuevo y escoger si es regular o premium.
La opción _agregar producto al carrito_ agrega un producto seleccionado por el usuario al carrito de un cliente seleccionado por el usuario.
La opción _procesar compra_ despliega en pantalla los productos del carrito, sus detalles, y el precio a pagar de un cliente seleccionado por el usuario.
La opción _salir_ termina el programa.

A partir del programa se crea una [página](https://tienda-virtual-tarea-2-c00041.netlify.app/functions.html) en Netlify, la cual contiene una visaulización distinta del código.

## Instrucciones para correr el programa

Una vez en el folder de Tarea2, solo es necesario escribir 'make run' en la línea de comandos.
```
make run
```

# Parte Teórica

## 1. ¿Qué es la programación orientada a objetos y cuáles son sus principios fundamentales?
Se trata de un paradigma de programación que organiza el diseño de software en torno a "objetos", que son instancias de clases. Cada objeto encapsula datos y comportamientos relacionados, lo que permite una gestión más eficiente de sistemas complejos y facilita la reutilización de código.
1. Abstracción: La abstracción es el principio que permite simplificar y clarificar los conceptos y comportamientos complejos mediante la creación de modelos o representaciones abstractas y simplificadas. Son modelos resumidos que solo contienen las partes importantes o los aspectos relevantes de un sistema u objeto, eliminando los detalles confusos. Este principio se puede definir como las características específicas el objeto, los mismos que lo distinguen de los demás tipos de objetos.  
2. Herencia, esta permite crear nuevas clases a partir de clases existentes, reutilizando el código y los comportamientos de sus ancestros. La nueva clase se conoce como subclase o derivada, mientras que la clase original se llama superclase o base. Tiene la capacidad de crear objetos especializados a partir de objetos más generales, y añadir o modificar sus propiedades y comportamientos de manera independiente.  
3. Polimorfismo, la capacidad de responder de diferentes maneras a un mismo mensaje o método, según su tipo o contexto. Es decir, un objeto puede comportarse de forma distinta según la situación, sin necesidad de conocer su tipo específico. Esto aumenta la flexibilidad y compatibilidad de los objetos, permite interactuar con ellos de manera genérica y de formas más predecibles.  


[Referencia](https://webdesigncusco.com/los-4-principios-fundamentales-de-la-programacion-orientada-a-objetos-poo/#:~:text=Conclusión%3A-,La%20programación%20orientada%20a%20objetos%20es%20un%20paradigma%20de%20programación,%2C%20herencia%2C%20polimorfismo%20y%20abstracción.
)h

## 2. Mencione y explique al menos tres problemas clásicos de programación que POO es capaz de resolver.
1. Simulación de Sistemas Complejos: Este paradigma es bueno para modelar y simular sistemas complejos del mundo real, como una fábrica, un ecosistema o una red de tráfico. Cada entidad relevante del sistema se representa como un objeto con sus propiedades y comportamientos. Los objetos interactúan entre sí siguiendo reglas definidas, permitiendo simular la dinámica del sistema completo. Esto facilita el análisis, la predicción y la optimización de sistemas complejos.
2. Desarrollo de Videojuegos: Cada elemento del juego, como personajes, enemigos, armas, niveles, etc. se modela como un objeto con sus características y acciones. Esto permite una estructura modular y reutilizable del código, facilitando el desarrollo y mantenimiento de juegos complejos. Además, el polimorfismo es clave para implementar diferentes tipos de enemigos o armas que comparten una interfaz común.
3. Gestión de Datos Empresariales
En el ámbito empresarial, se usa para gestionar grandes volúmenes de datos de una manera organizada y eficiente. Por ejemplo, en un sistema de gestión de clientes, cada cliente se representa como un objeto con atributos como nombre, dirección, historial de compras, etc. Estos objetos se agrupan en clases según el tipo de cliente (individual, empresa, etc.). Esto facilita operaciones como búsqueda, filtrado, ordenación y actualización de datos, esenciales en aplicaciones empresariales.

[Referencia](https://profile.es/blog/que-es-la-programacion-orientada-a-objetos/)

## 3. *.    Describe el polimorfismo y proporciona ejemplos de polimorfismo de tipo y polimorfismo de operador en C++.**  
De igual, manera, esto se cubre en la pregunta 1, pero aún así se responde aquí. El polimorfismo habla de la capacidad de un objeto en particular de tomar varias formas, hay dos tipos, el de operador y el de tipo. un objeto puede comportarse de forma distinta según la situación, sin necesidad de conocer su tipo específico. Esto aumenta la flexibilidad y compatibilidad de los objetos, permite interactuar con ellos de manera genérica y de formas más predecibles.Con un ejemplo de la vida real, se puede relacionar a por ejemplo, el significado de una palabra dependiendo de dónde y cuándo se utilice, no es lo mismo decir una palabra cómo 'puravida' luego de recibir un golpe a decir 'pura vida' al iniciar una conversación, una de ellas es para mostrar que estámos bien y la otra es un saludo para comenzar la conversación. Acá está el ejemplo:  

```
#include <iostream>
using namespace std;

class Animal {
public:
    void info() {
        cout << "I am an animal." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "I am a Dog. Woof woof." << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "I am a Cat. Meow." << endl;
    }
};

int main() {
    // Create object of Dog class
    Dog dog1;
    cout << "Dog Class: " << endl;
    dog1.info();  // Parent Class function
    dog1.bark();

    // Create object of Cat class
    Cat cat1;
    cout << "\nCat Class: " << endl;
    cat1.info();  // Parent Class function
    cat1.meow();

    return 0;
}
```

## 4. Describa el concepto de abstracción y brinde un ejemplo de su implementación en POO.
 La abstracción se refiere a la simplificación de la realidad mediante la identificación de las características esenciales y la supresión de los detalles innecesarios. Este enfoque facilita la creación de sistemas más comprensibles, mantenibles y eficientes.Ejemplo de esto en la vida real, podría ser el uso de mapas conceptuales o esquemas para facilitar el entendimiento de distintos conceptos.

## 5 Describa el concepto de encapsulamiento y brinde un ejemplo de su implementación en POO.
De la misma forma, sí bien este tema se cubrió en la pregunta 1, ahora se va a aclarar un poco más, este consiste en ocultar los detalles internos de un objeto y exponer solo lo que es necesario para el exterior. En otras palabras, se agrupan datos (atributos) y los métodos (funciones) que operan en esos datos en una única unidad, y se controla el acceso a dicha unidad. Esto ayuda a mantener la integridad y la coherencia del objeto, y proporciona una interfaz clara y definida para interactuar con él.
En C++, el encapsulamiento se logra mediante el uso de clases y modificadores de acceso, como public, private y protected. Un ejemplo de la vida real puede ser la información clasificada en las agencias gubernamentales, donde solo cierta información se expone dependiendo del rango del individuo.
Aquí hay un ejemplo que ilustra cómo se implementa el encapsulamiento en C++:  

```
#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string color;

protected:
    string type;

public:
    void run() {
        cout << "I can run -- BASE!" << endl;
    }

    void eat() {
        cout << "I can eat!" << endl;
    }

    void sleep() {
        cout << "I can sleep!" << endl;
    }

    void setColor(string clr) {
        color = clr;
    }

    string getColor() {
        return color;
    }
};

class Dog : public Animal {
public:
    void run() {
        cout << "I can run -- DERIVED!" << endl;
    }

    void setType(string tp) {
        type = tp;
    }

    void displayInfo(string c) {
        cout << "I am a " << type << endl;
        cout << "My color is " << c << endl;
    }

    void bark() {
        cout << "I can bark! Woof woof!!" << endl;
    }
};

int main() {
    Dog dog1;
    dog1.run();
    dog1.eat();
    dog1.sleep();
    dog1.setColor("black");
    dog1.bark();
    dog1.setType("Doberman");
    dog1.displayInfo(dog1.getColor());

    return 0;
}
```

## 6. Defina los conceptos de clase, objeto, método y atributo de la programación orientada a objetos y brinde un ejemplo de la vida real (No de programación) que los describa intuitivamente.
Una clase es una plantilla o modelo que define las características y comportamientos de un conjunto de objetos. Podemos pensar en una clase como un molde que se utiliza para crear diferentes ejemplares de un mismo tipo de objeto. Un objeto es una instancia de una clase. Representa una entidad individual con sus propias características y capacidades. Cada objeto creado a partir de una clase es único, pero comparte las mismas propiedades definidas en la clase. Un método es una acción o comportamiento que un objeto puede realizar. Es una función definida dentro de una clase que describe lo que el objeto puede hacer. Un atributo es una característica o propiedad que define el estado de un objeto. Representa la información que un objeto contiene o que lo describe.
Para el ejemplo de la vida real, imaginemos una panadería. En este contexto: la clase sería "Pan". Esta clase define las características comunes de todos los tipos de pan, como el nombre, el peso, los ingredientes y las funciones que puede realizar, como hornear, cortar y servir. Los objetos serían los diferentes tipos de pan que se producen en la panadería, como el pan de trigo, el pan de centeno, el pan de maíz, etc. Cada uno de estos panes es una instancia única de la clase "Pan", con sus propios atributos y métodos. Los atributos de cada pan podrían ser su nombre, peso, ingredientes, fecha de elaboración, etc. Estos atributos describen las características específicas de cada pan. Los métodos de cada pan podrían ser hornear, cortar, servir, enfriar, etc. Estas acciones definen lo que cada pan puede hacer.

[Referencia](https://immune.institute/blog/programacion-orientada-a-objetos/)

## 7. Mencione qué elementos tiene el “boilerplate” de una clase y explique cada uno
El boilerplate se refiere a la estructura básica y repetitiva que se utiliza para definir una clase en programación, especialmente en lenguajes orientados a objetos, sus elementos típicos son:
1. Declaración de la Clase: Primer elemento que se encuentra en el boilerplate. Define el nombre de la clase y, en algunos lenguajes, puede incluir especificadores de acceso (como public, private, protected) que determinan la visibilidad de la clase.
2. Constructor: Un método especial que se llama cuando se crea una instancia de la clase. Su propósito es inicializar los atributos de la clase. Puede tener parámetros para permitir la configuración de los atributos al momento de instanciar la clase.
3. Atributos o Propiedades: Son las variables que almacenan el estado de la clase. Se declaran dentro de la clase y pueden tener diferentes tipos de acceso. Los atributos pueden ser inicializados directamente o a través del constructor.
4. Métodos: Funciones definidas dentro de la clase que permiten realizar acciones con los atributos de la clase o proporcionar funcionalidad. Los métodos pueden ser públicos o privados, dependiendo de si se desea que sean accesibles desde fuera de la clase.
5. Métodos Getters y Setters:  Son métodos que permiten acceder y modificar los atributos de la clase de manera controlada. Los getters devuelven el valor de un atributo, mientras que los setters permiten modificarlo.

[Referencia](https://www.archittect.com/es/blog/boilerplate-code)

## 8. Qué es el constructor de una clase? ¿Para qué sirve?
El constructor es un método especial dentro de una clase que se utiliza para inicializar los atributos de la clase cuando se crea una nueva instancia. Dentro de sus aspectos característicos se encuentran: este lleva el mismo nombre que la clase y no tiene un tipo de retorno, ni siquiera void, puede tener parámetros para permitir la configuración de los atributos al momento de instanciar la clase.
Sus propositos son varios, puede ser usado para inicializar atributos, asignar recursos o validar parámetros. 

[Referencia](https://lenguajesdeprogramacion.net/diccionario/que-significa-constructor-en-programacion-orientada-a-objetos/)

## 9. ¿Qué es instanciar un objeto en el contexto de POO? ¿Para qué sirve?
Es el proceso de crear una instancia (u objeto) a partir de una clase. Esto permite obtener un objeto concreto con sus propios valores de atributos y comportamientos definidos por la clase. Dentro de sus funciones están, crear objetos concretos, inicializar atributos, reusar código, encapsular datos y comportamiento, 

[Referencia](https://learn.microsoft.com/es-es/dotnet/csharp/fundamentals/object-oriented/objects)

## 10. ¿Cuáles son las diferencias entre los especificadores de acceso públicos, privados y protegidos?

| Especificador | Accesibilidad                                   | Uso Principal                                                      |
|---------------|-------------------------------------------------|--------------------------------------------------------------------|
| public        | Accesible desde cualquier clase y paquete       | Métodos y atributos que deben ser accesibles globalmente            |
| private       | Accesible solo dentro de la propia clase        | Encapsulamiento y protección de datos                              |
| protected     | Accesible en la misma clase, subclases y mismo paquete | Herencia, permitiendo acceso a subclases                       |

## 11. Qué es el destructor de una clase y para qué aplicaciones es conveniente usarlo?
El destructor es una función miembro especial que se invoca automáticamente cuando un objeto es destruido o sale del ámbito. Su principal función es liberar los recursos que el objeto ha adquirido durante su vida útil, como memoria, conexiones a bases de datos o archivos abiertos. Dentro de las otras funciones que cumple, se puede destacar, las desvinculación de los recursos y el cierre de las conexiones. 

[Referencia](https://learn.microsoft.com/es-es/cpp/cpp/destructors-cpp?view=msvc-170)

## 12. Explique qué es la sobrecarga de operadores y proporcione un ejemplo de cómo se implementa en C++.
La sobrecarga es una característica de la programación orientada a objetos que permite redefinir el comportamiento de los operadores (como +, -, *, ==, etc.) para trabajar con objetos de clases personalizadas. Esto significa que se puede especificar cómo se deben comportar los operadores cuando se aplican a instancias de una clase, lo que permite hacer el código más intuitivo y legible.
Mediante este método es posible facilitar la manipulación de objetos, mejorar la legibilidad del código y personalizar el comportamiento del código. Este sería un posible ejemplo de su uso, primero defino la clase vector y luego hago la sobre carga:

```
class Vector {
private:
    float x, y; // Componentes del vector

public:
    // Constructor
    Vector(float x = 0, float y = 0) : x(x), y(y) {}

    // Sobrecarga del operador +
    Vector operator+(const Vector& v) {
        return Vector(this->x + v.x, this->y + v.y);
    }

    // Método para mostrar el vector
    void mostrar() const {
        std::cout << "Vector(" << x << ", " << y << ")" << std::endl;
    }
};
int main() {
    Vector v1(2.0, 3.0);
    Vector v2(1.0, 4.0);
    
    Vector v3 = v1 + v2; // Uso de la sobrecarga del operador +

    v3.mostrar(); // Imprime: Vector(3, 7)

    return 0;
}
```
[Referencia](https://learn.microsoft.com/es-es/cpp/cpp/operator-overloading?view=msvc-170)

## 13. ¿Qué es la herencia en POO?

La herencia permite que una clase adquiera propiedades y métodos de otra clase, promoviendo la reutilización de código. También vuelve menos engorroso el código, más fácil de manejar, y hasta puede ser más eficiente.

[Referencia](https://ifgeekthen.nttdata.com/s/post/herencia-en-programacion-orientada-objetos-MCPV3PCZDNBFHSROCCU3JMI7UIJQ?language=es)

## 14.  Mencione las diferencias entre la herencia pública, privada o protegida de una clase, qué sucede al heredar cada tipo.
Las diferencias se enlistan a continuación:
1. **Herencia pública:** Los miembros públicos y protegidos de la clase base permanecen accesibles en la clase derivada.
2. **Herencia privada:** Todos los miembros heredados se vuelven privados.
3. **Herencia protegida:** Los miembros públicos y protegidos se vuelven protegidos.

## 15.a A cuáles de estas variables puede acceder un objeto instanciado de la clase Base, a cuales no puede acceder y por qué.

- **Clase Base**: Un objeto instanciado de la clase `Base` puede acceder a todas las variables que sean **públicas** y **protegidas** de la clase. No puede acceder a las variables que sean privadas, ya que estas están restringidas solo al acceso desde dentro de la misma clase.

## 15.b A cuáles de estas variables puede acceder un objeto instanciado de la clase Derived, a cuales no puede acceder y por qué.

- **Clase Derived**: Un objeto instanciado de la clase `Derived`, que hereda de `Base`, puede acceder a las variables **públicas** y **protegidas** de `Base`, además de sus propias variables. No puede acceder a las variables privadas de `Base`, ya que la herencia no permite el acceso directo a miembros privados.

[Referencia](https://ifgeekthen.nttdata.com/s/post/herencia-en-programacion-orientada-objetos-MCPV3PCZDNBFHSROCCU3JMI7UIJQ?language=es)

## 16. ¿Qué es una clase amiga y para qué se usa? ¿Cómo se define?

Una _clase amiga_ es una clase que tiene permiso para acceder a los miembros privados y protegidos de otra clase. Esto es útil cuando dos clases necesitan cooperar estrechamente y una clase necesita acceder a la implementación interna de otra.

- **Uso**: Las clases amigas permiten que dos clases tengan un nivel alto de colaboración sin exponer sus miembros internos de forma pública.
  
- **Definición**: Se define usando la palabra clave `friend` en la clase que concede el acceso:
```cpp
class ClaseA {
    friend class ClaseAmiga;  // ClaseAmiga puede acceder a miembros privados de ClaseA
private:
    int valorPrivado;
};
```

[Referencia](https://docs.hektorprofe.net/cpp/11-clases/02-funciones-clases-amigas/)

## 17. ¿Qué es una función amiga y para qué se usa? ¿Cúal es la manera de definirla?

Una _función amiga_ es una función que tiene acceso a los miembros privados y protegidos de una clase, pero que no es parte de esa clase. Las funciones amigas son útiles cuando una función no pertenece a la clase, pero necesita interactuar con sus datos privados.

**Uso:** Se utiliza para permitir acceso externo limitado a los datos de la clase sin exponer todos los miembros públicamente.

**Definición:** Se declara con la palabra reservada _friend_ dentro de la clase:

```cpp
class ClaseA {
    friend void funcionAmiga(ClaseA& obj);  // Permite que funcionAmiga acceda a miembros privados
private:
    int valorPrivado;
};

void funcionAmiga(ClaseA& obj) {
    obj.valorPrivado = 10;  // Accede al miembro privado de ClaseA
}
```

[Referencia](https://docs.hektorprofe.net/cpp/11-clases/02-funciones-clases-amigas/)

## 18. Explique la importancia de los métodos virtuales en C++ y cómo se utilizan en la implementación de polimorfismo.

Los métodos virtuales en son esenciales para implementar el polimorfismo dinámico y generar abstracción (como el nombre del curso) en las clases. Permiten que una función en una clase base sea sobrescrita por una función con el mismo nombre en una clase derivada y que el tipo correcto de la función sea invocado en tiempo de ejecución, incluso si el tipo del objeto es tratado como el de la clase base.

**Importancia:** Sin métodos virtuales, el compilador invocaría los métodos de la clase base, aunque el objeto sea de una clase derivada. Los métodos virtuales permiten que la función adecuada se invoque dependiendo del tipo real del objeto, no del tipo del puntero o referencia.

La implementación es la siguiente:

```cpp
class Animal {
public:
    virtual void hacerSonido() { cout << "Sonido genérico"; }
};

class Perro : public Animal {
public:
    void hacerSonido() override { cout << "Ladrido"; }
};

void reproducirSonido(Animal& a) {
    a.hacerSonido();  // Ejecuta el método adecuado según el tipo real del objeto
}

int main() {
    Perro p;
    reproducirSonido(p);  // Imprime "Ladrido"
}
```


[Referencia](https://www.ibm.com/docs/es/i/7.5?topic=only-virtual-functions-c)



