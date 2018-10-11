#ifndef CLIENTE_INCLUDE_H
#define CLIENTE_INCLUDE_H

typedef struct
{
    int codigoCliente;
    int codigoJuego;
    char apellido[51];
    char nombre[51];
    char sexo;
    char domicilio[51];
    int isEmpty;
} eCliente;

/** \brief inicializa el menu de clientes
 *
 * \param list Array de la estructura eCliente
 * \param len tamaño del array
 * \return -1 si no se encuentra nada. 0 si esta ok.
 *
 */
int inicializarCliente(eCliente* list, int len);

/** \brief busca un espacio libre en el sistema
 *
 * \param list Array de la estructura eCliente
 * \param len tamaño del array
 * \return el espacio libre o -1 si no hay espacio
 *
 */
int buscarEspacioLibreCliente(eCliente list[], int len);

/** \brief da de alta un cliente
 *
 * \param list Array de la estructura eCliente
 * \param len tamaño del array
 * \return -1 para error. 0 para ok.
 *
 */
int agregarCliente(eCliente list[], int len);


/** \brief menu de ABM clientes
 *
 * \param cliente array de la estructuraa eCliente
 * \param len longitud del array
 * \return opcion elegida
 *
 */
int menuClientes(eCliente cliente[],int len);

/** \brief busca un cliente por medio de un codigo ingresado
 *
 * \param list Array de la estructura eCliente
 * \param len tamaño del array
 * \return el codigo encontrado o -1 para no encontrado
 *
 */
int buscarClientePorCodigo(eCliente list[], int len, int codigoCliente);

/** \brief muestra un solo cliente
 *
 * \param list Variable de eCliente
 * \return -
 *
 */
void mostrarCliente(eCliente list);

/** \brief muestra la lista de clientes ingresados
 *
 * \param list Array de la estructura eCliente
 * \param len tamaño del array
 * \return 0
 *
 */
int mostrarClientes(eCliente list[], int len);

/** \brief modifica un cliente
 *
 * \param list Array de la estructura eCliente
 * \param len tamaño del array
 * \return  0 para ok, -1 para error
 *
 */
int modificarCliente(eCliente list[], int len);

/** \brief elimina un cliente
 *
 * \param list Array de la estructura eCliente
 * \param len Tamaño del array
 * \return -1
 *
 */
int borrarCliente(eCliente list[], int len);

/** \brief ordena la apellido de forma ascendente y el nombre de forma ascendente
 *
 * \param list Array de la estructura eCliente
 * \param len tamaño del array
 * \return 0
 *
 */
int ordenarClientes(eCliente* list, int len);




#endif // CLIENTE_INCLUDE_H
