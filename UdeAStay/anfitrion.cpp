#include "anfitrion.h"
#include "alojamiento.h"

// Constructor
Anfitrion::Anfitrion(const std::string& name,
                     const std::string& numDocum,
                     const Fecha& dateReg,
                     int puntuacion,
                     Alojamiento** alojamientos)
    : name_(name),
    numDocum_(numDocum),
    dateReg_(dateReg),
    puntuacion_(puntuacion),
    alojamientos_(alojamientos)
{
}

// Getters
std::string Anfitrion::getName() const
{
    return name_;
}

std::string Anfitrion::getNumDocum() const
{
    return numDocum_;
}

Fecha Anfitrion::getDateReg() const
{
    return dateReg_;
}

int Anfitrion::getPuntuacion() const
{
    return puntuacion_;
}

Alojamiento** Anfitrion::getAlojamientos() const
{
    return alojamientos_;
}
