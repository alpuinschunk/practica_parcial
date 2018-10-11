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
 * \param len tama�o del array
 * \return -1 si no se encuentra nada. 0 si esta ok.
 *
 */
int inicializarAlquiler(eAlquiler* list, int len);

/** \brief busca un espacio libre en el sistema
 *
 * \param list Array de la estructura eAlquier
 * \param len tama�o del array
 * \return el espacio libre o -1 si no hay espacio
 *
 */
int buscarEspacioLibreAlquiler(eAlquiler list[], int len);

/** \brief alta de alquiler relacionando juego - cliente - fecha - codigo de alquiler
 *
 * \param alquiler Array de estructura eAlquiler
 * \param lenAlquiler longitud del array
 * \param cliente Array de estructura eCliente
 * \param lenCliente longitud del array
 * \param juego Array de estructura eJuego
 * \param lenJuego longitud del array
 * \return -1 para error, 0 para ok.
 *
 */
int agregarAlquiler(eAlquiler alquiler[], int lenAlquiler,eCliente cliente[], int lenCliente, eJuegos juego[], int lenJuego);


/** \brief lista los juegos cargados y pide que se ingrese un codigo para elegir un juego
 *
 * \param juego Array de la estructura eJuegos
 * \param len Longitud del array
 * \return retorna el codigo del juego
 *
 */
int elegirJuego(eJuegos juego[], int len);

/** \brief lista los clientes cargados y pide que se ingrese un codigo para elegir un cliente
 *
 * \param cliente Array de la estructura eCliente
 * \param len Longitud del array
 * \return retorna el codigo del cliente
 *
 */
int elegirCliente(eCliente cliente[], int len);

/** \brief carga el nombre del juego al codigo del juego
 *
 * \param juego Array de la estructura eJuegos
 * \param lenJuego longitud del array juego
 * \param codigoJuego codigo del juego
 * \param cadena char en el que se guardara la descripcion
 * \return void
 *
 */
void cargarDescripcionJuego(eJuegos juego[], int lenJuego, int codigoJuego, char cadena[]);


/** \brief lista los alquileres de los clientes por juego
 *
 * \param list[] Array de la estructura eCliente
 * \param len longitud del array eCliente
 * \param juego[] Array de la la estructura eJuegos
 * \param lenJuego longitud del array eJuegos
 * \return void
 *
 */
void listarClientesPorJuego(eCliente list[],int len, eJuegos juego[], int lenJuego);


/** \brief lista los clientes que alquilaron un juego determinado
 *
 * \param list eAlquiler
 * \param lenAlquiler int
 * \param juego[] eJuegos
 * \param lenJuego int
 * \param cliente[] eCliente
 * \param lenCliente int
 * \return void
 *
 */
void mostrarAlquilerPorJuego(eAlquiler list, int lenAlquiler ,eJuegos juego[], int lenJuego,eCliente cliente[],int lenCliente);

/** \brief muestra los juegos que fueron alquilados por un cliente determinado
 *
 * \param list eAlquiler
 * \param lenAlquier int
 * \param juego[] eJuegos
 * \param lenJuego int
 * \param cliente[] eCliente
 * \param lenCliente int
 * \return void
 *
 */
void mostrarAlquilerPorCliente(eAlquiler list,int lenAlquier, eJuegos juego[], int lenJuego,eCliente cliente[],int lenCliente);

/** \brief muestra las opciones para los informes
 *
 * \param alquiler[] eAlquiler
 * \param len int
 * \param juego[] eJuegos
 * \param lenJuego int
 * \param cliente[] eCliente
 * \param lenCliente int
 * \return int
 *
 */
int menuListar(eAlquiler alquiler[],int len ,eJuegos juego[],int lenJuego,eCliente cliente[],int lenCliente);

/** \brief promedia el importe de los juegos ingresados e informa cauntos no superan el promedio
 *
 * \param list[] eJuegos
 * \param len int
 * \return int
 *
 */
int promedioImporte(eJuegos list[],int len);

/** \brief lista los juegos que fueron alquilados por un cliente determinado
 *
 * \param list[] eAlquiler
 * \param len int
 * \param juego[] eJuegos
 * \param lenJuego int
 * \param cliente[] eCliente
 * \param lenCliente int
 * \return void
 *
 */
void listarAlquilerPorJuego(eAlquiler list[],int len, eJuegos juego[], int lenJuego,eCliente cliente[],int lenCliente);

/** \brief muestra los juegos que fueron alquilados por un cliente determinado
 *
 * \param list[] eAlquiler
 * \param len int
 * \param juego[] eJuegos
 * \param lenJuego int
 * \param cliente[] eCliente
 * \param lenCliente int
 * \return void
 *
 */
void listarAlquilerPorCliente(eAlquiler list[],int len, eJuegos juego[], int lenJuego,eCliente cliente[],int lenCliente);

/** \brief ordena los importes de manera descendente
 *
 * \param list eJuegos*
 * \param len int
 * \return int
 *
 */
int ordenarImporte(eJuegos* list, int len);

#endif // ALQUILER_INCLUDE_H


