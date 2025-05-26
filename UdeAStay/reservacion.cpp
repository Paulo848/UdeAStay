#include "reservacion.h"

// Constructor
Reservacion::Reservacion(int codigoReserva,
                         const Alojamiento& codigoAlojam,
                         const std::string& numDocumHuesped,
                         const Fecha& dateEntrada,
                         int numNoches,
                         const std::string& metodoPago,
                         int monto,
                         char* anotaciones)
    : codigoReserva_(codigoReserva)
    , codigoAlojam_(codigoAlojam)
    , numDocumHuesped_(numDocumHuesped)
    , dateEntrada_(dateEntrada)
    , numNoches_(numNoches)
    , metodoPago_(metodoPago)
    , monto_(monto)
    , anotaciones_(anotaciones)
{
}

// Getters
int Reservacion::getCodigoReserva() const
{
    return codigoReserva_;
}

Alojamiento Reservacion::getAlojamiento() const
{
    return codigoAlojam_;
}

std::string Reservacion::getNumDocumHuesped() const
{
    return numDocumHuesped_;
}

Fecha Reservacion::getDateEntrada() const
{
    return dateEntrada_;
}

int Reservacion::getNumNoches() const
{
    return numNoches_;
}

std::string Reservacion::getMetodoPago() const
{
    return metodoPago_;
}

int Reservacion::getMonto() const
{
    return monto_;
}

char* Reservacion::getAnotaciones() const
{
    return anotaciones_;
}
