#include "Fecha.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include "utilid.h"

// Constructor
Fecha::Fecha(int dia, int mes, int anio)
    : dia_(1), mes_(1), anio_(1), bisiesto_(false)
{
    if (!FechaValida(dia, mes, anio))
    {
        std::cerr << "ERROR: fecha inválida\n";
        throw std::invalid_argument("Fecha inválida");
    }
    dia_  = dia;
    mes_  = mes;
    anio_ = anio;
    CalcularBisiesto();
}

// Constructor copia
Fecha::Fecha(const Fecha& otra_fecha)
    : dia_(otra_fecha.dia_),
    mes_(otra_fecha.mes_),
    anio_(otra_fecha.anio_),
    bisiesto_(otra_fecha.bisiesto_)
{
}

// Constructor a partir de un string "AAAA-MM-DD"
Fecha::Fecha(const std::string& fechaStr)
{
    // Validar formato “AAAA-MM-DD”
    if (fechaStr.size() != 10 || fechaStr[4] != '-' || fechaStr[7] != '-')
    {
        std::cerr << "Error: formato de fecha inválido: " << fechaStr << std::endl;
        throw std::invalid_argument("Formato de fecha inválido");
    }

    // Extraer año, mes y día
    int anio = std::stoi(fechaStr.substr(0, 4));
    int mes  = std::stoi(fechaStr.substr(5, 2));
    int dia  = std::stoi(fechaStr.substr(8, 2));

    // Validar rango de fecha
    if (!FechaValida(dia, mes, anio))
    {
        std::cerr << "Error: fecha fuera de rango: " << fechaStr << std::endl;
        throw std::out_of_range("Fecha inválida");
    }

    // Asignar atributos y calcular bisiesto
    dia_   = dia;
    mes_   = mes;
    anio_  = anio;
    CalcularBisiesto();
}

// Getters
int Fecha::GetDia() const
{
    return dia_;
}

int Fecha::GetMes() const
{
    return mes_;
}

int Fecha::GetAnio() const
{
    return anio_;
}

// Cambiar la fecha completa
int Fecha::CambiarFecha(int dia, int mes, int anio)
{
    if (!FechaValida(dia, mes, anio))
        return -1;
    dia_   = dia;
    mes_   = mes;
    anio_  = anio;
    CalcularBisiesto();
    return 0;
}

// Imprimir fecha
void Fecha::imprimir() const
{
    std::cout << GetDia() << "-" << GetMes() << "-" << GetAnio() << std::endl;
}


// Operadores de comparación
bool Fecha::operator==(const Fecha& otra) const
{
    return dia_  == otra.dia_  &&
           mes_  == otra.mes_  &&
           anio_ == otra.anio_;
}

bool Fecha::operator<(const Fecha& otra) const
{
    if (anio_ < otra.anio_)
    {
        return true;
    }
    else if (anio_ > otra.anio_)
    {
        return false;
    }

    // mismos años → comparar meses
    if (mes_ < otra.mes_)
    {
        return true;
    }
    else if (mes_ > otra.mes_)
    {
        return false;
    }

    // mismos años y meses → comparar días
    return dia_ < otra.dia_;
}

// Retorna la diferencia en días entre esta fecha y 'otra'.

int Fecha::DiferenciaEnDias(const Fecha& otra) const
{
    int d1 = DiasDesdeInicio(anio_, mes_, dia_);
    int d2 = DiasDesdeInicio(otra.anio_, otra.mes_, otra.dia_);

    // Puedes usar abs() o el operador ternario:
    return (d1 > d2) ?   (d1 - d2): (d2 - d1);
}

// Convierte la fecha a una cadena (por ejemplo "2025-05-20").

std::string Fecha::ToString() const
{
    char fechachar[11];
    int a = anio_, m = mes_, d = dia_;

    // AAAA
    for (int i = 3; i >= 0 ; i--)
    {
        fechachar[i] = char('0' + (a % 10));
        a /= 10;
    }

    fechachar[4] = '-';

    //MM
    for (int i = 6; i >= 5 ; i--)
    {
        fechachar[i] = char('0' + (m % 10));
        m /= 10;
    }

    fechachar[7] = '-';

    //DD
    for (int i = 9; i>= 8 ; i--)
    {
        fechachar[i] = char('0' + (d % 10));
        d /= 10;
    }

    fechachar[10] = '\0';

    return std :: string (fechachar);

}

// Método privado para validar fecha
bool Fecha::FechaValida(int dia, int mes, int anio) const
{
    if (dia < 1 || dia > 31) return false;
    if (mes < 1 || mes > 12) return false;

    switch (mes)
    {
    case 4: case 6: case 9: case 11:
        if (dia > 30) return false;
        break;

    case 2:
        if ((anio % 4 == 0) && (anio % 100 != 0 || anio % 400 == 0))
        {
            if (dia > 29) return false;
        }
        else if (dia > 28) return false;
        break;

    default:
        if (dia > 31) return false;
    }

    return true;
}

void Fecha::CalcularBisiesto()
{
    // Un año es bisiesto si:
    // - Es divisible por 400, o
    // - Es divisible por 4 y no es divisible por 100.
    if ((anio_ % 400 == 0) ||
        (anio_ % 4 == 0 && anio_ % 100 != 0))
    {
        bisiesto_ = true;
    }
    else
    {
        bisiesto_ = false;
    }
}
