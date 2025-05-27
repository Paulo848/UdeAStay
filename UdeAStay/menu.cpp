#include "menu.h"
#include <iostream>
#include <limits>

int showLoginMenu()
{

    int min = 1, max = 2;

    std::cout << "1 : Iniciar sesion como Anfitrion." << std :: endl;
    std::cout << "2 : Iniciar sesion como Huesped." << std :: endl;
    std::cout << "0 : Salir de la aplicacion." << std :: endl;

    return showRangoMenu(min,max);

}
int showAnfitrionMenu()
{

    int min = 1, max = 3;

    std::cout << "1 : Actualizar historico." << std :: endl;
    std::cout << "2 : Consultar reservaciones activas." << std :: endl;
    std::cout << "3 : Anular reservacion." << std :: endl;
    std::cout << "0 : Cerrar sesion." << std :: endl;

    return showRangoMenu(min,max);

}
int showHuespedMenu()
{

    int min = 1, max = 2;

    std::cout << "1 : Reservar alojamiento." << std :: endl;
    std::cout << "2 : Anular reservacion." << std :: endl;
    std::cout << "0 : Cerrar sesion." << std :: endl;

    return showRangoMenu(min,max);

}
int showReservarMenu()
{

    int min = 1, max = 2;

    std::cout << "1 : Hacer busqueda por parametros." << std :: endl;
    std::cout << "2 : Hacer busqueda por codigo de alojamiento." << std :: endl;
    std::cout << "0 : Regresar al menu anterior." << std :: endl;

    return showRangoMenu(min,max);

}

int showFiltrosMenu()
{

    int min = 1, max = 3;

    std::cout << "1 : Aplicar filtro de costo maximo de noche." << std :: endl;
    std::cout << "2 : Aplicar filtro de puntuacion minima por anfitrion." << std :: endl;
    std::cout << "3 : Aplicar los dos anteriores filtros." << std :: endl;
    std::cout << "0 : Cancelar busqueda por filtros." << std :: endl;

    return showRangoMenu(min,max);

}

int showRangoMenu(int min,int max)
{

    int input = -1;
    bool inputvalido = false;

    do
    {
        std::cout << "Ingrese 0 para salir, o un numero entre "
                  << min << " y " << max << ":" << std::endl;

        if (!(std::cin >> input))
        {
            // No se ingresó un entero
            std::cin.clear();    // Restablece el estado de cin
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
                );                  // Descarta hasta el salto de línea
            std::cout << "Error: entrada invalida, debe ser un número."
                      << std::endl;
        }

        else if (input == 0 || (input >= min && input <= max))
        {
            // Valor válido: puede ser 0 (salir) o dentro de [min,max]
            inputvalido = true;
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
                );
        }

        else
        {
            std::cout << "Opcion fuera de rango. Intente nuevamente." << std::endl;
        }
    }
    while(!inputvalido);

    return input;
}
