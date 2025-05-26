#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include <string>
#include "anfitrion.h"

class Reservacion;

// Clase que representa un alojamiento ofrecido por un anfitrión
class Alojamiento
{
private:
    int            codigoAlojam_;    // Código único del alojamiento
    Anfitrion      nameAnfitrion_;   // Anfitrión propietario
    std::string    departamento_;     // Departamento donde se ubica
    std::string    municipio_;        // Municipio donde se ubica
    std::string    tipo_;             // Tipo de alojamiento (casa, apto, etc.)
    std::string    direccion_;        // Dirección exacta
    int            precioNoche_;      // Precio por noche
    char**         amenidades_;       // Lista de amenidades (termina con nullptr)
    Reservacion**  reservas_;         // Arreglo de punteros a Reservacion

public:
    // Constructor
    Alojamiento(int codigoAlojam,
                const Anfitrion& nameAnfitrion,
                const std::string& departamento,
                const std::string& municipio,
                const std::string& tipo,
                const std::string& direccion,
                int precioNoche,
                char** amenidades,
                Reservacion** reservas);

    // Getters
    int            getCodigoAlojam() const;
    std::string    getMunicipio() const;
    std::string    getTipo() const;
    int            getPrecioNoche() const;
    int            getPuntuacionAnfitrion() const;
    Reservacion**  getReservas() const;
};

#endif // ALOJAMIENTO_H
