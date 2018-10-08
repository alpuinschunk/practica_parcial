#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "empleado.h"
#include "menues.h"
#include "almuerzo.h"

void almuerzo_initAlmuerzos(StAlmuerzo arrayAlmuerzos[], int CANT)
{
    for(int i=0; i<CANT; i++)
    {
        arrayAlmuerzos[i].codigoAlmuerzo = i+1;
        arrayAlmuerzos[i].isEmpty = 1;
    }
}

void almuerzo_menuPrincipal()
{
    printf("[1] AGREGAR ALMUERZO\n");
    printf("[2] LISTAR\n\n");
    printf("[3] SALIR\n");
}

void almuerzo_funcionPrincipal(StEmpleado arrayEmpleados[], StSector arraySectores[], StMenues arrayMenues[], StAlmuerzo arrayAlmuerzos[], int EMPLEADOS_CANT, int SECTORES_CANT, int MENU_CANT, int ALMUERZO_CANT)
{
    int exit = 0;
    char option = 'x';
    int check;
    int contador=0;
    do
    {
        system("cls");
        almuerzo_menuPrincipal();

        printf("\nType Your Option: ");
        option = getch();

        switch(option)
        {
        case '1': //AGREGAR ALMUERZO//
                check = almuerzo_alta(arrayEmpleados, arraySectores, arrayMenues, arrayAlmuerzos, EMPLEADOS_CANT, SECTORES_CANT, MENU_CANT, ALMUERZO_CANT);
                if(check==-1)
                {
                    printf("ERROR. No se pudo dar de alta o no hay mas espacio libre\n");
                    system("pause");
                }else
                {
                    contador++;
                }
            break;
        case '2':   //LISTAR//
            if(contador>0)
            {
                //almuerzo_listar(arrayMenues, CANT);
                //almuerzo_mostrar(arrayMenues, CANT);
            }else
            {
                printf("Ingrese un almuerzo primero\n");
                system("pause");
            }
            break;
        case '3':   //SALIR//
            exit = 1;
            break;
        default:
            printf("Incorrect Input\n");
            system("pause");
        break;
        }

    }
    while(exit == 0);
}

int almuerzo_alta(StEmpleado arrayEmpleados[], StSector arraySectores[], StMenues arrayMenues[], StAlmuerzo arrayAlmuerzos[], int EMPLEADOS_CANT, int SECTORES_CANT, int MENU_CANT, int ALMUERZO_CANT)
{
    int status, check;
    int maximum;

    for(int i=0; i<ALMUERZO_CANT; i++)
    {
        if(arrayAlmuerzos[i].isEmpty == 1)
        {

            do{
            system("cls");
            check = getInt(&arrayAlmuerzos[i].fecha.dia, "Ingrese Dia del almuerzo: (1-31): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 31);
            }while(check!=1);

            do{
            system("cls");
            check = getInt(&arrayAlmuerzos[i].fecha.mes, "Ingrese Mes del almuerzo: (1-12): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 12);
            }while(check!=1);

            do{
            system("cls");
            check = getInt(&arrayAlmuerzos[i].fecha.anio, "Ingrese Anio del almuerzo: (1960-2018): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1960, 2018);
            }while(check!=1);


            do{
            maximum = empleado_mostrar2(arrayEmpleados, EMPLEADOS_CANT, arraySectores);
            system("cls");
            check = getInt(&arrayAlmuerzos[i].legajoEmpleado, "Ingrese Legajo de empleado: ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, maximum);
            }while(check!=1);

            do{
            maximum = menu_mostrar2(arrayMenues, MENU_CANT);
            system("cls");
            check = getInt(&arrayAlmuerzos[i].legajoEmpleado, "Ingrese Codigo de Menu: ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, maximum);
            }while(check!=1);

            arrayAlmuerzos[i].isEmpty = 0;

            printf("INFORMACION INGRESADA\n");
            printf("ID: %d  Fecha de almuerzo %d/%d/%d  Nombre Empleado: %s %s Menu Elegido: %s\n", arrayAlmuerzos[i].codigoAlmuerzo, arrayAlmuerzos[i].fecha.dia, arrayAlmuerzos[i].fecha.mes, arrayAlmuerzos[i].fecha.anio, arrayEmpleados[(arrayAlmuerzos[i].legajoEmpleado)-1].apellido, arrayEmpleados[(arrayAlmuerzos[i].legajoEmpleado)-1].nombre, arrayMenues[arrayAlmuerzos[i].codigoMenu].descripcion);
            system("pause");
            status = 0;
            break;
        }else{
            status = -1;
        }
    }

    return status;
}
