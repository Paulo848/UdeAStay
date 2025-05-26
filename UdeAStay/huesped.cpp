#include "huesped.h"

// Constructor
Huesped::Huesped(const std::string& name,
                 const std::string& numDocum,
                 const Fecha& dateReg,
                 int puntuacion,
                 Reservacion** reservas)
    : name_(name),
    numDocum_(numDocum),
    dateReg_(dateReg),
    puntuacion_(puntuacion),
    reservas_(reservas)
{
}

// Getters
std::string Huesped::getName() const
{
    return name_;
}

std::string Huesped::getNumDocum() const
{
    return numDocum_;
}

Fecha Huesped::getDateReg() const
{
    return dateReg_;
}

int Huesped::getPuntuacion() const
{
    return puntuacion_;
}

Reservacion** Huesped::getReservas() const
{
    return reservas_;
}
