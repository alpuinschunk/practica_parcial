#ifndef ALMUERZO_INCLUDE_H
#define ALMUERZO_INCLUDE_H
#include "menu.h"
#include "empleados.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFechaAlm;

typedef struct
{
    int idAlmuerzo;
    int idEmpleado;
    int idComida;
    int isEmpty;
    eFechaAlm fecha;

}eAlmuerzo;

int inicializarAmpuerzo(eAlmuerzo* list, int len);
int buscarEspacioLibre(eAlmuerzo list[], int len);
int agregarAlmuerzo(eAlmuerzo almuerzos[], int lenAlmuerzos,eEmpleado empleado[], int lenEmpleado, eMenu menus[], int lenMenus);
int buscarEspacioLibreAlmuerzo(eAlmuerzo list[], int len);

#endif // ALMUERZO_INCLUDE_H*/
