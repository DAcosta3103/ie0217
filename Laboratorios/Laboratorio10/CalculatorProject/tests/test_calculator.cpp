#include <gtest/gtest.h>
#include "../src/Calculator.hpp"

Calculator calc;

TEST(CalculatorTests, Addition) {
    EXPECT_DOUBLE_EQ(calc.add(3.0, 4.0), 7.0);
}

TEST(CalculatorTests, Subtraction) {
    EXPECT_DOUBLE_EQ(calc.subtract(10.0, 4.0), 6.0);
}

TEST(CalculatorTests, Multiplication) {
    EXPECT_DOUBLE_EQ(calc.multiply(3.0, 5.0), 15.0);
}

TEST(CalculatorTests, Division) {
    EXPECT_DOUBLE_EQ(calc.divide(10.0, 2.0), 5.0);
}

TEST(CalculatorTests, DivisionByZero) {
    EXPECT_THROW(calc.divide(10.0, 0), std::invalid_argument);
}

