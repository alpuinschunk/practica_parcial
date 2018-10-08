#ifndef ALQUILER_INCLUDE_H
#define ALQUILER_INCLUDE_H
#include "juegos.h"
#include "cliente.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int codigoAlquiler;
    int codigoCliente;
    int codigoJuego;
    int isEmpty;
    eFecha fecha;

}eAlquiler;

/** \brief inicializa el el menu alquiler
 *
 * \param list Array de la estructura eAlquiler
 * \param len tamaño del array
 * \return -1 si no se encuentra nada. 0 si esta ok.
 *
 */
int inicializarAlquiler(eAlquiler* list, int len);

/** \brief busca un espacio libre en el sistema
 *
 * \param list Array de la estructura eAlquier
 * \param len tamaño del array
 * \return el espacio libre o -1 si no hay espacio
 *
 */
int buscarEspacioLibreAlquiler(eAlquiler list[], int len);


int mostrarAlquiler(eAlquiler alquiler[], int lenAlquiler,eCliente cliente[], int lenCliente, eJuegos juego[], int lenJuego);


int agregarAlquiler(eAlquiler alquiler[], int lenAlquiler,eCliente cliente[], int lenCliente, eJuegos juego[], int lenJuego);

#endif // ALQUILER_INCLUDE_H


