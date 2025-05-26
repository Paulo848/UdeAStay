#include "utilid.h"

// Convierte una fecha en número de días desde 01/01/0001
int DiasDesdeInicio(int anio, int mes, int dia)
{
    int añosCompletos = anio - 1;
    int dias = añosCompletos * 365
               + añosCompletos / 4
               - añosCompletos / 100
               + añosCompletos / 400;

    int diasPorMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    for (int m = 1; m < mes; m++)
    {
        dias += diasPorMes[m - 1];

        // Añade el día extra de febrero en año bisiesto
        if (m == 2 &&
            ((anio % 400 == 0) ||
             (anio % 4 == 0 && anio % 100 != 0)))
        {
            dias += 1;
        }
    }

    dias += dia;
    return dias;
}
