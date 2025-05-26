#ifndef HUESPED_H
#define HUESPED_H

#include <string>
#include "fecha.h"

class Reservacion;

// Clase que representa un huésped en el sistema
class Huesped
{
private:
    std::string    name_;        // Nombre del huésped
    std::string    numDocum_;    // Número de documento
    Fecha          dateReg_;     // Fecha de registro
    int            puntuacion_;  // Puntuación promedio
    Reservacion**  reservas_;    // Arreglo dinámico de reservaciones

public:
    // Constructor
    Huesped(const std::string& name,
            const std::string& numDocum,
            const Fecha& dateReg,
            int puntuacion,
            Reservacion** reservas);

    // Getters
    std::string    getName() const;
    std::string    getNumDocum() const;
    Fecha          getDateReg() const;
    int            getPuntuacion() const;
    Reservacion**  getReservas() const;
};

#endif
