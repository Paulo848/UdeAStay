#ifndef STUBS_H
#define STUBS_H

// ----- acciones del anfitrion -----
int actualizarHistorico();          // case 1 – anfitrion
int consultarReservasActivas();     // case 2 – anfitrion
int anularReservacionAnfitrion();   // case 3 – anfitrion

// ----- acciones del huesped -----
int buscarPorParametros();          // case 1-1 – huesped
int buscarPorCodigoAlojamiento();   // case 1-2 – huesped
int anularReservacionHuesped();     // case 2 – huesped

#endif
