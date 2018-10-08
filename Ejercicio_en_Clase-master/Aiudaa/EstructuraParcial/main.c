#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPLEADOS 2
#include "empleados.h"
#include "utn.h"
#include "sector.h"

int main()
{
    char seguir= 's';

    eEmpleados empleados[EMPLEADOS];

    eSector sectores[25];
    sectores[0].id = 0;
    strcpy(sectores[0].descripcion, "oficinas" ) ;
    sectores[1].id = 1;
    strcpy(sectores[1].descripcion , "recepcion");




    inicializarEmpleados( empleados, EMPLEADOS );

    do
    {
        switch(menuDeOpciones())
        {
        case 1:

            agregarEmpleado(empleados, EMPLEADOS,sectores,2);

            system("cls");
            break;
        case 4:
            mostrarEmpleados(empleados, EMPLEADOS);
            break;
        case 5:

            seguir='n';
            break;
        }
    }while(seguir=='s' || seguir=='S');


    return 0;
}
