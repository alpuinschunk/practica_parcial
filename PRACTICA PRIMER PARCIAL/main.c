#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "empleado.h"
#include "menues.h"
#include "almuerzo.h"

#define CANT_EMPLEADOS      100
#define CANT_SECTOR         5
#define CANT_MENUES          20
#define CANT_ALMUERZO       2000

int main()
{
    int exit = 0;
    char option = 'x';

    StEmpleado arrayEmpleados[CANT_EMPLEADOS];
    StSector arraySectores[CANT_SECTOR];
    StMenues arrayMenues[CANT_MENUES];
    StAlmuerzo arrayAlmuerzos[CANT_ALMUERZO];


    empleado_initEmpleados(arrayEmpleados, CANT_EMPLEADOS);
    menu_initMenues(arrayMenues, CANT_MENUES);
    almuerzo_initAlmuerzos(arrayAlmuerzos, CANT_ALMUERZO);
    empleado_initSectores(arraySectores);

    do
    {
        system("cls");
        menu();

        printf("\nType Your Option: ");
        option = getch();

        switch(option)
        {
        case '1': //INGRESAR AL MENU DE EMPLEADOS//
            empleado_funcionPrincipal(arrayEmpleados, CANT_EMPLEADOS, arraySectores, CANT_SECTOR);
            break;
        case '2': //INGRESAR AL MENU DE MENUES//
            menu_funcionPrincipal(arrayMenues, CANT_MENUES);
            break;
        case '3':   //AGREGAR UN ALMUERZO//
            almuerzo_funcionPrincipal(arrayEmpleados, arraySectores, arrayMenues, arrayAlmuerzos, CANT_EMPLEADOS, CANT_SECTOR, CANT_MENUES, CANT_ALMUERZO);
            break;
        case '4':   //LISTAR//
            break;
        case '5':   //SALIR//
            exit = 1;
            break;
        default:
            printf("Incorrect Input\n");
            system("pause");
        break;
        }

    }
    while(exit == 0);

    return 0;
}
