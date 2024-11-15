#include <gtest/gtest.h>
#include "../src/inventario.hpp"

using namespace std;

// Se prueba el método para agregar un componente nuevo al inventario, en el caso donde el componente no existía antes
TEST(InventarioTest, AgregarComponenteNuevo) {
    Inventario inventario;
    inventario.agregarComponente("Resistencia", "Resistencia", 10, "Resistencia de 10 ohms");
    testing::internal::CaptureStdout();
    inventario.listarComponentes();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Resistencia"), string::npos);
}

// Se prueba el caso donde se agrega un componente y luego una mayor cantidad del mismo componente
TEST(InventarioTest, AgregarCantidadExistente) {
    Inventario inventario;
    inventario.agregarComponente("Resistencia", "Resistencia", 10, "Resistencia de 10 ohms");
    inventario.agregarComponente("Resistencia", "Resistencia", 5, "Resistencia de 10 ohms");

    testing::internal::CaptureStdout();
    inventario.listarComponentes();
    string output = testing::internal::GetCapturedStdout();
    
    // Se espera que la cantidad final sea de 15
    EXPECT_NE(output.find("Cantidad: 15"), string::npos);
}

// Se prueba el método para reducir la cantidad de componentes en el inventario
TEST(InventarioTest, ReducirCantidadValida) {
    Inventario inventario;
    inventario.agregarComponente("Resistencia", "Resistencia", 10, "Resistencia de 10 ohms");
    inventario.reducirComponente("Resistencia", 5);

    testing::internal::CaptureStdout();
    inventario.listarComponentes();
    string output = testing::internal::GetCapturedStdout();

    // Se espera que la cantidad final dea 10 - 5 = 5
    EXPECT_NE(output.find("Cantidad: 5"), string::npos);
}

// Se prueba reducir una cantidad de tal forma que la cantidad resultante sea negativa (inválida)
TEST(InventarioTest, ReducirCantidadInvalida) {
    Inventario inventario;
    inventario.agregarComponente("Resistencia", "Resistencia", 10, "Resistencia de 10 ohms");
    EXPECT_THROW(inventario.reducirComponente("Resistencia", 15), runtime_error);
}

// Se prueba el método para buscar un componente existente en el inventario
TEST(InventarioTest, BuscarComponenteExistente) {
    Inventario inventario;
    inventario.agregarComponente("Capacitor", "Capacitor", 10, "Capacitor de 100uF");
    testing::internal::CaptureStdout();
    inventario.buscarComponente("Capacitor");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Capacitor"), string::npos);
}

// Se prueba buscar un componente que no existe
TEST(InventarioTest, BuscarComponenteInexistente) {
    Inventario inventario;
    inventario.agregarComponente("Resistencia", "Resistencia", 10, "Resistencia de 10 ohms");

    testing::internal::CaptureStdout(); // Captura la salida estándar
    inventario.buscarComponente("Capi");
    std::string output = testing::internal::GetCapturedStdout();

    // Verifica que el mensaje de "Componente no encontrado" esté presente
    EXPECT_NE(output.find("Componente no encontrado."), std::string::npos);
}


// Se prueba listar los componentes añadidos
TEST(InventarioTest, ListarComponentesConElementos) {
    Inventario inventario;
    inventario.agregarComponente("Resistencia", "Resistencia", 10, "Resistencia de 10 ohms");
    inventario.agregarComponente("Capacitor", "Capacitor", 5, "Capacitor de 100uF");

    testing::internal::CaptureStdout(); // Captura la salida estándar
    inventario.listarComponentes();
    string output = testing::internal::GetCapturedStdout();

    // Verifica que se encuentren ambos componentes en la salida
    EXPECT_NE(output.find("Resistencia"), string::npos);
    EXPECT_NE(output.find("Capacitor"), string::npos);
}

// se prueba listar componentes cuando no hay ninguno añadido (resultado inválido)
TEST(InventarioTest, ListarComponentesVacia) {
    Inventario inventario;

    testing::internal::CaptureStdout(); // Captura la salida estándar
    inventario.listarComponentes();
    std::string output = testing::internal::GetCapturedStdout();

    // Verifica que el mensaje de inventario vacío sea mostrado
    EXPECT_NE(output.find("El inventario está vacío."), std::string::npos);
}

