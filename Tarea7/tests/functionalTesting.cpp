#include <gtest/gtest.h>
#include "../src/inventario.hpp"

using namespace std;

// Prueba funcional: Flujo completo de agregar, reducir y listar componentes
TEST(FunctionalTest, InventarioFlujoCompleto) {
    Inventario inventario;

    // Paso 1: Agregar componentes
    inventario.agregarComponente("Resistencia", "Resistencia", 10, "Resistencia de 10k ohms");
    inventario.agregarComponente("Capacitor", "Capacitor", 20, "Capacitor de 100uF");
    inventario.agregarComponente("Inductor", "Inductor", 15, "Inductor de 500mH");
    
    // Verificar que los componentes se agregaron correctamente
    testing::internal::CaptureStdout();
    inventario.listarComponentes();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Resistencia"), string::npos);
    EXPECT_NE(output.find("Capacitor"), string::npos);
    EXPECT_NE(output.find("Inductor"), string::npos);

    // Paso 2: Reducir una cantidad válida
    inventario.reducirComponente("Resistencia", 5);
    testing::internal::CaptureStdout();
    inventario.listarComponentes();
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Cantidad: 5"), string::npos);

    // Paso 3: Intentar reducir una cantidad inválida (más de lo disponible)
    EXPECT_THROW(inventario.reducirComponente("Capacitor", 25), runtime_error);

    // Paso 4: Verificar que el inventario final es correcto
    testing::internal::CaptureStdout();
    inventario.listarComponentes();
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Cantidad: 5"), string::npos);   // 'Resistencia' se redujo en 5
    EXPECT_NE(output.find("Cantidad: 20"), string::npos);  // 'Capacitor' no cambió
    EXPECT_NE(output.find("Cantidad: 15"), string::npos);  // 'Inductor' no cambió

    // Paso 5: Buscar un componente en específico
    testing::internal::CaptureStdout();
    inventario.buscarComponente("Inductor");
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Inductor"), string::npos);
}
