#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <string>
#include "utilid.h"


// Clase que representa una fecha en el calendario gregoriano.
// Permite consultar, modificar y validar fechas. Soporta años bisiestos
class Fecha
{
public:

    // Constructor que crea una fecha valída.
    // Si se ingresa una fecha invalida se lanza un mensaje de error.
    Fecha(int dia = 1, int mes = 1, int anio = 1);

    Fecha(const Fecha& otra_fecha);

    // Constructor desde un string, la cadena debe tener formato "AAAA-MM-DD"
    Fecha(const std::string& fechaStr);

    // Retorna el día actual.
    int GetDia() const;

    // Retorna el mes actual.
    int GetMes() const;

    // Retorna el año actual.
    int GetAnio() const;

    // Funcion que modifica los datos de la fecha actual.
    // Si se ingresa una fecha invalida lanza un mensaje de error.
    int CambiarFecha(int dia, int mes, int anio);

    // Funcion que imprime la fecha.
    void imprimir() const;

    // Operadores de comparación
    bool operator==(const Fecha& otra) const;
    bool operator< (const Fecha& otra) const;

    // Retorna la diferencia en días entre esta fecha y 'otra'.
    int DiferenciaEnDias(const Fecha& otra) const;

    // Convierte la fecha a una cadena (por ejemplo "2025-05-20").
    std::string ToString() const;

private:

    int dia_;
    int mes_;
    int anio_;
    bool bisiesto_;  // indica si el año almacenado es bisiesto


    // Funcion que verifica que una fecha sea valida del calendario gregoriano.
    bool FechaValida(int dia, int mes, int anio) const;

    // Recalcula el campo 'bisiesto_' según el valor de 'anio_'.
    void CalcularBisiesto();

};

#endif
