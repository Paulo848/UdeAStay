#ifndef ANFITRION_H
#define ANFITRION_H

#include <string>
#include "Fecha.h"

class Alojamiento;

// Clase que representa un anfitrión del sistema
class Anfitrion
{
private:
    std::string   name_;         // Nombre del anfitrión
    std::string   numDocum_;     // Número de documento
    Fecha         dateReg_;      // Fecha de registro
    int           puntuacion_;   // Puntuación promedio
    Alojamiento** alojamientos_;  // Arreglo dinámico de alojamientos

public:
    // Constructor
    Anfitrion(const std::string& name,
              const std::string& numDocum,
              const Fecha& dateReg,
              int puntuacion,
              Alojamiento** alojamientos);

    // Getters
    std::string   getName() const;
    std::string   getNumDocum() const;
    Fecha         getDateReg() const;
    int           getPuntuacion() const;
    Alojamiento** getAlojamientos() const;
};

#endif
