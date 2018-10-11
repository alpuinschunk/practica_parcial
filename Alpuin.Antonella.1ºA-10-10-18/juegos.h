#ifndef JUEGOS_INCLUDE_H
#define JUEGOS_INCLUDE_H

typedef struct
{
    int codigoJuego;
    char descripcion[51];
    float importe;
    int isEmpty;
} eJuegos;


/** \brief inicializa el menu de juegos
 *
 * \param list Array de la estructura eJuegos
 * \param len tamaño del array
 * \return -1 si no se encuentra nada. 0 si esta ok.
 *
 */
int inicializarJuego(eJuegos* list, int len);

/** \brief busca un espacio libre en el sistema
 *
 * \param list Array de la estructura eJuegos
 * \param len tamaño del array
 * \return el espacio libre o -1 si no hay espacio
 *
 */
int buscarEspacioLibreJuegos(eJuegos list[], int len);

/** \brief muestra la lista de juegos ingresados
 *
 * \param list Array de la estructura eJuegos
 * \param len tamaño del array
 * \return 0
 *
 */
int mostrarJuegos(eJuegos* list, int len);

/** \brief da de alta un juego
 *
 * \param list Array de la estructura eJuegos
 * \param len tamaño del array
 * \return -1 para error. 0 para ok.
 *
 */
int agregarJuego(eJuegos list[], int len);///agregar juego


/** \brief busca un juego por medio de un codigo ingresado
 *
 * \param list Array de la estructura eJuegos
 * \param len tamaño del array
 * \return el codigo encontrado o -1 para no encontrado
 *
 */
int buscarJuegoPorCodigo(eJuegos list[], int len, int codigoJuego);

/** \brief muestra un solo juego
 *
 * \param list Variable de eJuegos
 * \return -
 *
 */
void mostrarJuego(eJuegos list);

/** \brief modifica un juego
 *
 * \param list Array de la estructura eJuegos
 * \param len tamaño del array
 * \return  0 para ok, -1 para error
 *
 */
int modificarJuego(eJuegos* list, int len);///modificar juego

/** \brief elimina un juego
 *
 * \param list Array de la estructura eJuegos
 * \param len Tamaño del array
 * \return -1
 *
 */
int borrarJuego(eJuegos list[], int len);///borrar juego

/** \brief ordena la descripcion de forma ascendente y el importe de forma descendente
 *
 * \param list Array de la estructura eJuegos
 * \param len tamaño del array
 * \return 0
 *
 */
int ordenarJuegos(eJuegos* list, int len);///Listar

/** \brief
 *
 * \param juego array de la estructura eJuegos
 * \param len
 * \return int 0
 *
 */
int menuJuegos(eJuegos juego[],int len);





#endif // JUEGOS_INCLUDE_H
