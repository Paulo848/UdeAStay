#include "mainMenu.h"
#include "menu.h"      // showLoginMenu, showAnfitrionMenu, etc.
#include <iostream>
#include "stubs.h"

// ---------------------------------------------------------------------------
// Flujo para ANFITRION
// ---------------------------------------------------------------------------
int flujoAnfitrion()
{
    int opcion = showAnfitrionMenu();

    while (opcion != 0)
    {
        switch (opcion)
        {
            case 1:
            {
                actualizarHistorico();
                break;
            }
            case 2:
            {
                consultarReservasActivas();
                break;
            }
            case 3:
            {
                anularReservacionAnfitrion();
                break;
            }
            default:
            {
                // La validacion de rango ya ocurre en showAnfitrionMenu
                break;
            }
        }

        opcion = showAnfitrionMenu();
    }

    return 0;          // 0 indica "volver" al menu anterior
}

// ---------------------------------------------------------------------------
// Flujo para HUESPED
// ---------------------------------------------------------------------------
int flujoHuesped()
{
    int opcionHuesped = showHuespedMenu();

    while (opcionHuesped != 0)
    {
        switch (opcionHuesped)
        {
        case 1:
        {
            // ---- Sub-menu "Reservar alojamiento" ----
            int opcionReserva = showReservarMenu();

            while (opcionReserva != 0)
            {
                switch (opcionReserva)
                {
                case 1:
                {
                    buscarPorParametros();

                    int filtros = showFiltrosMenu();

                    switch (filtros)
                    {
                        case 1:
                        {
                            std::cout << "Ingrese costo maximo por noche" << std::endl;
                            break;
                        }
                        case 2:
                        {
                            std::cout << "Ingrese puntuacion minima del anfitrion" << std::endl;
                            break;
                        }
                        case 3:
                        {
                            std::cout << "Ingrese costo maximo por noche" << std::endl;
                            std::cout << "Ingrese puntuacion minima del anfitrion" << std::endl;
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }

                    break;
                }
                case 2:
                {
                    buscarPorCodigoAlojamiento();
                    break;
                }
                default:
                {
                    break;
                }
                }

                opcionReserva = showReservarMenu();
            }

            break;
        }
        case 2:
        {
            anularReservacionHuesped();
            break;
        }
        default:
        {
            break;
        }
        }

        opcionHuesped = showHuespedMenu();
    }

    return 0;
}

// ---------------------------------------------------------------------------
// Menu principal
// ---------------------------------------------------------------------------
int mainMenu()
{
    int usuario = showLoginMenu();

    while (usuario != 0)
    {
        switch (usuario)
        {
            case 1:
            {
                flujoAnfitrion();
                break;
            }
            case 2:
            {
                flujoHuesped();
                break;
            }
            default:
            {
                // La validacion de rango ya esta en showLoginMenu
                break;
            }
        }

        usuario = showLoginMenu();
    }

    return 0;          // Permite que main() devuelva 0 al S.O.
}
