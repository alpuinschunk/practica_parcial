#ifndef MENU_INCLUDE_H
#define MENU_INCLUDE_H

typedef struct
{
    int idComida;
    char descripcion[51];
    float importe;
    int isEmpty;
} eMenu;

/** \brief inicializa el menu
 *
 * \param list Array de la estructura eMenu
 * \param len tamaño del array
 * \return -1 si no se encuentra nada. 0 si esta ok.
 *
 */
int inicializarMenu(eMenu* list, int len);

/** \brief busca un espacio libre en el sistema
 *
 * \param list Array de la estructura eMenu
 * \param len tamaño del array
 * \return el espacio libre o -1 si no hay espacio
 *
 */
int buscarEspacioLibreMenu(eMenu list[], int len);

/** \brief muestra la lista de menus ingresados
 *
 * \param list Array de la estructura eMenu
 * \param len tamaño del array
 * \return 0
 *
 */
int mostrarMenus(eMenu* list, int len);

/** \brief da de alta un menu
 *
 * \param list Array de la estructura eMenu
 * \param len tamaño del array
 * \return -1 para error. 0 para ok.
 *
 */
int agregarMenu(eMenu list[], int len);///agregar menu


/** \brief busca un menu por medio de un ID ingresado
 *
 * \param list Array de la estructura eMenu
 * \param len tamaño del array
 * \return el ID encontrado o -1 para no encontrado
 *
 */
int buscarMenuPorId(eMenu list[], int len, int id);

/** \brief muestra un solo menu
 *
 * \param list Variable de eMenu
 * \return -
 *
 */
void mostrarMenu(eMenu list);

/** \brief elimina un menu, liberando un espacio
 *
 * \param list Array de la estructura eMenu
 * \param len Tamaño del array
 * \return -1
 *
 */
int borrarMenu(eMenu list[], int len);///borrar menu


/** \brief modifica un menu
 *
 * \param list Array de la estructura eMenu
 * \param len tamaño del array
 * \return  0 para ok, -1 para error
 *
 */
int modificarMenu(eMenu* list, int len);///modificar menu


/** \brief ordena la descripcion de forma ascendente y el importe de forma descendente
 *
 * \param list Array de la estructura eMenu
 * \param len tamaño del array
 * \return 0
 *
 */
int ordenarMenu(eMenu* list, int len);///Listar

int menuMenus();





#endif // MENU_INCLUDE_H
