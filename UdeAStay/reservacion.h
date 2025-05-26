#ifndef RESERVACION_H
#define RESERVACION_H

#include <string>
#include "fecha.h"
#include "alojamiento.h"

// Clase que representa una reservación realizada por un huésped
class Reservacion
{
private:
    int         codigoReserva_;      // Código único de la reservación
    Alojamiento codigoAlojam_;       // Alojamiento reservado
    std::string numDocumHuesped_;    // Documento del huésped
    Fecha       dateEntrada_;        // Fecha de entrada
    int         numNoches_;          // Número de noches
    std::string metodoPago_;         // Método de pago
    int         monto_;              // Monto total
    char*       anotaciones_;        // Notas adicionales

public:
    // Constructor
    Reservacion(int codigoReserva,
                const Alojamiento& codigoAlojam,
                const std::string& numDocumHuesped,
                const Fecha& dateEntrada,
                int numNoches,
                const std::string& metodoPago,
                int monto,
                char* anotaciones);

    // Getters
    int         getCodigoReserva() const;
    Alojamiento getAlojamiento() const;
    std::string getNumDocumHuesped() const;
    Fecha       getDateEntrada() const;
    int         getNumNoches() const;
    std::string getMetodoPago() const;
    int         getMonto() const;
    char*       getAnotaciones() const;
};

#endif // RESERVACION_H
