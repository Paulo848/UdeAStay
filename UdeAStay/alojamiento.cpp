#include "Alojamiento.h"
#include "Reservacion.h"

// Constructor
Alojamiento::Alojamiento(int codigoAlojam,
                         const Anfitrion& nameAnfitrion,
                         const std::string& departamento,
                         const std::string& municipio,
                         const std::string& tipo,
                         const std::string& direccion,
                         int precioNoche,
                         char** amenidades,
                         Reservacion** reservas)
    : codigoAlojam_(codigoAlojam)
    , nameAnfitrion_(nameAnfitrion)
    , departamento_(departamento)
    , municipio_(municipio)
    , tipo_(tipo)
    , direccion_(direccion)
    , precioNoche_(precioNoche)
    , amenidades_(amenidades)
    , reservas_(reservas)
{
}

int Alojamiento::getCodigoAlojam() const
{
    return codigoAlojam_;
}

std::string Alojamiento::getMunicipio() const
{
    return municipio_;
}

std::string Alojamiento::getTipo() const
{
    return tipo_;
}

int Alojamiento::getPrecioNoche() const
{
    return precioNoche_;
}

int Alojamiento::getPuntuacionAnfitrion() const
{
    return nameAnfitrion_.getPuntuacion();
}

Reservacion** Alojamiento::getReservas() const
{
    return reservas_;
}
