# CMake generated Testfile for 
# Source directory: /home/diego/ie0217/newRepo/ie0217/Sesiones/Sesion16/CalculatorTests
# Build directory: /home/diego/ie0217/newRepo/ie0217/Sesiones/Sesion16/CalculatorTests/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_calculator "/home/diego/ie0217/newRepo/ie0217/Sesiones/Sesion16/CalculatorTests/build/test_calculator")
set_tests_properties(test_calculator PROPERTIES  _BACKTRACE_TRIPLES "/home/diego/ie0217/newRepo/ie0217/Sesiones/Sesion16/CalculatorTests/CMakeLists.txt;17;add_test;/home/diego/ie0217/newRepo/ie0217/Sesiones/Sesion16/CalculatorTests/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
