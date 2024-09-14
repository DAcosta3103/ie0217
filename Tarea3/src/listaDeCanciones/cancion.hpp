#ifndef CANCION_HPP
#define CANCION_HPP

#include <string>

using namespace std;

class Cancion {
    private:
        string titulo, artista;
        double duracion;

    public:
        Cancion(string titulo, string artista, double duracion);

        string getTitulo() const;

        string getArtista() const;

        double getDuracion() const;

};





#endif