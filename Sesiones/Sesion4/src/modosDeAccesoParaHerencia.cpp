/* A continuación se tiene un tipo de ejemplo de cómo funcionan los distintos tipos de acceso para las herencias de clases */

class Base {
    public:
        int x;
    protected:
        int y;
    private:
        int z;
};

// La siguiente clase derivada mantiene los niveles de acceso originales
class PublicDerived: public Base {
    // x is public
    // y is protected
    // z is not accessible from PublicDerived
};

// La siguiente clase derivada mantiene los privados y vuelve el resto protegidos
class ProtectedDerived: protected Base {
    // x is protected
    // y is protected
    // z is not accessible from PublicDerived
};


// La siguiente clase derivada vuelve a todos los archivos privados
class PrivateDerived: private Base {
    // x is private
    // y is private
    // z is not accessible from PublicDerived
};