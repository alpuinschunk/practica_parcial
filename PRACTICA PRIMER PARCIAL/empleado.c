#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "empleado.h"
#include "menues.h"
#include "almuerzo.h"

void menu()
{
    printf("[1] INGRESAR AL MENU DE EMPLEADOS\n");
    printf("[2] INGRESAR AL MENU DE MENUES\n");
    printf("[3] AGREGAR UN ALMUERZO\n");
    printf("[4] LISTAR\n\n");
    printf("[5] SALIR\n");
}

void empleado_menu()
{
    printf("[1] AGREGAR EMPLEADO\n");
    printf("[2] MODIFICAR EMPLEADO\n");
    printf("[3] ELIMINAR EMPLEADO\n");
    printf("[4] LISTAR\n\n");
    printf("[5] SALIR\n");
}

void empleado_menuModificar(StEmpleado arrayEmpleados[], int ID, StSector arraySectores[], int IDSector)
{
    printf("/////MODIFY MENU/////\n");
    printf("\nLA INFORMACION DE ESTE EMPLEADO SERA MODIFICADA\n");
    printf("Apellido: %s   Nombre: %s  Sexo: %c  Sueldo: %.2f  Fecha de ingreso: %d/%d/%d sector:  %s\n", arrayEmpleados[ID].apellido, arrayEmpleados[ID].nombre, arrayEmpleados[ID].sexo, arrayEmpleados[ID].sueldo, arrayEmpleados[ID].fecha.dia, arrayEmpleados[ID].fecha.mes, arrayEmpleados[ID].fecha.anio, arraySectores[arrayEmpleados[ID].IDSector-1].descripcion);
    printf("\n/////////////////////////\n");
    printf("[1] MODIFICAR APELLIDO  \n");
    printf("[2] MODIFICAR NOMBRE\n");
    printf("[3] MODIFICAR SEXO\n");
    printf("[4] MODIFICAR SALARIO\n");
    printf("[5] MODIFICAR FECHA DE INGRESO\n");
    printf("[6] MODIFICAR SECTOR\n\n");
    printf("[7] EXIT\n");
}



void empleado_initEmpleados(StEmpleado arrayEmpleados[], int CANT)
{
    for(int i=0; i<CANT; i++)
    {
        arrayEmpleados[i].legajo = i+1;
        arrayEmpleados[i].isEmpty = 1;
    }
}

void empleado_initSectores(StSector arraySectores[])
{
    arraySectores[0].idSector = 1;
    strcpy(arraySectores[0].descripcion, "CONTABILIDAD");

    arraySectores[1].idSector = 2;
    strcpy(arraySectores[1].descripcion, "AUDITORIA");

    arraySectores[2].idSector = 3;
    strcpy(arraySectores[2].descripcion, "RRHH");

    arraySectores[3].idSector = 4;
    strcpy(arraySectores[3].descripcion, "COMPRAS");

    arraySectores[4].idSector = 5;
    strcpy(arraySectores[4].descripcion, "VENTAS");
}

int empleado_buscarPorID(StEmpleado arrayEmpleados[], int CANT, int ID)
{
    int index = -1;

    for(int i=0; i<CANT; i++)
    {
        if(arrayEmpleados[i].legajo == ID && arrayEmpleados[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}


void empleado_funcionPrincipal(StEmpleado arrayEmpleados[], int CANT, StSector arraySectores[], int CANT2)
{
    int exit = 0;
    char option = 'x';
    int check;
    int contadorEmpleados=0;
    do
    {
        system("cls");
        empleado_menu();

        printf("\nType Your Option: ");
        option = getch();

        switch(option)
        {
        case '1': //AGREGAR EMPLEADOS//
                check = empleado_alta(arrayEmpleados, CANT, arraySectores, CANT2);
                if(check==-1)
                {
                    printf("ERROR. No se pudo dar de alta o no hay mas espacio libre\n");
                    system("pause");
                }else
                {
                    contadorEmpleados++;
                }
            break;
        case '2': //MODIFICAR EMPLEADOS//
            if(contadorEmpleados>0)
            {
                empleado_modificar(arrayEmpleados, CANT, arraySectores, CANT2);
            }else
            {
                printf("Ingrese un empleado primero\n");
                system("pause");
            }
            break;
        case '3':   //ELIMINAR EMPLEADOS//
            if(contadorEmpleados>0)
            {
                check = empleado_baja(arrayEmpleados, CANT, arraySectores, CANT2);
                if(check==0)
                {
                    contadorEmpleados--;
                }
            }else
            {
                printf("Ingrese un empleado primero\n");
                system("pause");
            }
            break;
        case '4':   //LISTAR//
            if(contadorEmpleados>0)
            {
                empleado_listar(arrayEmpleados, CANT);
                empleado_mostrar(arrayEmpleados, CANT, arraySectores);
            }else
            {
                printf("Ingrese un empleado primero\n");
                system("pause");
            }
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

}


int empleado_alta(StEmpleado arrayEmpleados[], int CANT, StSector arraySectores[], int CANT2)
{
    int status, check;

    for(int i=0; i<CANT; i++)
    {
        if(arrayEmpleados[i].isEmpty == 1)
        {
            do{
            system("cls");
            check = getString(arrayEmpleados[i].apellido, "Ingrese Apellido: (Max 50): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 51);
            }while(check!=1);

            do{
            system("cls");
            check = getString(arrayEmpleados[i].nombre, "Ingrese Nombre: (Max 50): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 51);
            }while(check!=1);

            do{
                system("cls");
                check = getChar(&arrayEmpleados[i].sexo, "Ingrese sexo: (F or M): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 0, 1);
                arrayEmpleados[i].sexo = toupper(arrayEmpleados[i].sexo);
                if(!(arrayEmpleados[i].sexo=='F' || arrayEmpleados[i].sexo=='M'))
                {
                    check=-1;
                }else{
                    check=1;
                }
            }while(check!=1);

            do{
            system("cls");
            check = getFloat(&arrayEmpleados[i].sueldo, "Ingrese Sueldo: (>0): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 9999999);
            }while(check!=1);

            do{
            system("cls");
            check = getInt(&arrayEmpleados[i].fecha.dia, "Ingrese Dia de Ingreso: (1-31): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 31);
            }while(check!=1);

            do{
            system("cls");
            check = getInt(&arrayEmpleados[i].fecha.mes, "Ingrese Mes de Ingreso: (1-12): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 12);
            }while(check!=1);

            do{
            system("cls");
            check = getInt(&arrayEmpleados[i].fecha.anio, "Ingrese Anio de Ingreso: (1960-2018): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1960, 2018);
            }while(check!=1);

            do{
            system("cls");
            for(int j=0; j<CANT2; j++)
            {
                printf("ID: %d  //  SECTOR:  %s  \n", arraySectores[j].idSector, arraySectores[j].descripcion);
            }
            system("pause");
            check = getInt(&arrayEmpleados[i].IDSector, "Ingrese Sector: (1 - 5): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 5);
            }while(check!=1);

            arrayEmpleados[i].isEmpty = 0;

            printf("INFORMACION INGRESADA\n");
            printf("ID: %d  Apellido: %s   Nombre: %s  Sexo: %c  Sueldo: %.2f  Fecha de ingreso: %d/%d/%d sector:  %s\n", arrayEmpleados[i].IDSector, arrayEmpleados[i].apellido, arrayEmpleados[i].nombre, arrayEmpleados[i].sexo, arrayEmpleados[i].sueldo, arrayEmpleados[i].fecha.dia, arrayEmpleados[i].fecha.mes, arrayEmpleados[i].fecha.anio, arraySectores[arrayEmpleados[i].IDSector-1].descripcion);
            system("pause");
            status = 0;
            break;
        }else{
            status = -1;
        }
    }

    return status;
}

void empleado_modificar(StEmpleado arrayEmpleados[], int CANT, StSector arraySectores[], int CANT2)
{
    system("cls");
    int check = -1;
    int ID;
    int IDAux;
    do{ check = getInt(&IDAux, "Ingrese ID a buscar: (1 - 100): ", "[ERROR] Not a Valid ID\n", 1, 100);
    }while(check!=1);

    ID = empleado_buscarPorID(arrayEmpleados, CANT, IDAux);

    if(ID != -1)
    {
        int exit = 0;
        char option;
        do
        {
            system("cls");
            empleado_menuModificar(arrayEmpleados, ID, arraySectores, CANT2);

            printf("\nElija Opcion: ");
            option = getch();

            switch(option)
            {

                case '1': //MODIFICAR APELLIDO//
                    do{
                    system("cls");
                    check = getString(arrayEmpleados[ID].apellido, "Ingrese Apellido: (Max 50): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 51);
                    }while(check!=1);
                    break;
                case '2': //MODIFICAR NOMBRE//
                    do{
                    system("cls");
                    check = getString(arrayEmpleados[ID].nombre, "Ingrese Nombre: (Max 50): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 51);
                    }while(check!=1);
                    break;
                case '3': //MODIFY SEXO//
                    do{
                    system("cls");
                    check = getChar(&arrayEmpleados[ID].sexo, "Ingrese sexo: (F or M): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 0, 1);
                    arrayEmpleados[ID].sexo = toupper(arrayEmpleados[ID].sexo);
                        if(!(arrayEmpleados[ID].sexo=='F' || arrayEmpleados[ID].sexo=='M'))
                        {
                            check=-1;
                        }else{
                            check=1;
                        }
                    }while(check!=1);
                    break;
                case '4': //MODIFY SALARIO//
                    do{
                    system("cls");
                    check = getFloat(&arrayEmpleados[ID].sueldo, "Ingrese Sueldo: (>0): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 9999999);
                    }while(check!=1);
                    break;
                case '5': //MODIFICAR FECHA DE INGRESO//
                    do{
                    system("cls");
                    check = getInt(&arrayEmpleados[ID].fecha.dia, "Ingrese Dia de Ingreso: (1-31): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 31);
                    }while(check!=1);

                    do{
                    system("cls");
                    check = getInt(&arrayEmpleados[ID].fecha.mes, "Ingrese Mes de Ingreso: (1-12): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 12);
                    }while(check!=1);

                    do{
                    system("cls");
                    check = getInt(&arrayEmpleados[ID].fecha.anio, "Ingrese Anio de Ingreso: (1960-2018): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1960, 2018);
                    }while(check!=1);
                    break;
                case '6': //MODIFICAR SECTOR//
                    do{
                    system("cls");
                    for(int j=0; j<CANT2; j++)
                    {
                        printf("ID: %d  //  SECTOR:  %s  \n", arraySectores[j].idSector, arraySectores[j].descripcion);
                    }
                    system("pause");
                    check = getInt(&arrayEmpleados[ID].IDSector, "Ingrese Sector: (1 - 5): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 5);
                    }while(check!=1);
                    break;
                case '7':
                    exit = 1;
                    break;
                default:
                    printf("Incorrect Input\n");
                    system("pause");
                    break;
            }
        }while(exit==0);
    }else
    {
        printf("\nID NOT FOUND!\n");
        system("pause");
    }
}

int empleado_baja(StEmpleado arrayEmpleados[], int CANT, StSector arraySectores[], int CANT2)
{
    system("cls");
    int status;
    int check = -1;
    int ID, IDAux;
    char optionYN;
    do{ check = getInt(&IDAux, "Escriba ID de empleado  (1 - 100): ", "[ERROR] Not a Valid ID\n", 1, 100);
    }while(check!=1);

    ID = empleado_buscarPorID(arrayEmpleados, CANT, IDAux);

    if(ID != -1)
    {
        do
        {
            system("cls");
            printf("\nESTE EMPLEADO SERA ELIMINADO\n");
            printf("Apellido: %s   Nombre: %s  Sexo: %c  Sueldo: %.2f  Fecha de ingreso: %d/%d/%d sector:  %s\n", arrayEmpleados[ID].apellido, arrayEmpleados[ID].nombre, arrayEmpleados[ID].sexo, arrayEmpleados[ID].sueldo, arrayEmpleados[ID].fecha.dia, arrayEmpleados[ID].fecha.mes, arrayEmpleados[ID].fecha.anio, arraySectores[arrayEmpleados[ID].IDSector-1].descripcion);
            printf("\nARE YOU SURE? Y/N: ");
            optionYN = toupper(getch());
        }while(!(optionYN == 'Y' || optionYN == 'N'));

        if(optionYN == 'Y')
        {
            arrayEmpleados[ID].isEmpty = 1;
            printf("\nEL EMPLEADO HA SIDO ELIMINADO!\n");
            system("pause");
            status = 0;
        }else if(optionYN == 'N')
        {
            printf("\nOPERACION CANCELADA\n");
            system("pause");
        }
    }
    else
    {
        printf("\nID INGRESADO NO ENCONTRADO!\n");
        status = -1;
        system("pause");
    }
    return status;
}

void empleado_listar(StEmpleado arrayEmpleados[], int CANT)
{
    StEmpleado empleadoAux;
    for(int i=0; i<CANT-1; i++)
    {
        for(int j=i+1; j<CANT; j++)
        {
            if( (strcmp(arrayEmpleados[i].apellido, arrayEmpleados[j].apellido)>0) && arrayEmpleados[i].isEmpty==0 && arrayEmpleados[j].isEmpty==0)
            {
                empleadoAux = arrayEmpleados[i];
                arrayEmpleados[i] = arrayEmpleados[j];
                arrayEmpleados[j] = empleadoAux;
            }else if( (strcmp(arrayEmpleados[i].apellido, arrayEmpleados[j].apellido)==0) && arrayEmpleados[i].isEmpty==0 && arrayEmpleados[j].isEmpty==0)
            {
                if( (strcmp(arrayEmpleados[i].nombre, arrayEmpleados[j].nombre)>0) && arrayEmpleados[i].isEmpty==0 && arrayEmpleados[j].isEmpty==0)
                {
                    empleadoAux = arrayEmpleados[i];
                    arrayEmpleados[i] = arrayEmpleados[j];
                    arrayEmpleados[j] = empleadoAux;
                }
            }
        }
    }
}

void empleado_mostrar(StEmpleado arrayEmpleados[], int CANT, StSector arraySectores[])
{
    for (int i=0; i<CANT; i++)
    {
        if(arrayEmpleados[i].isEmpty==0)
        {
            printf("\nID Sector: %d  Apellido: %s   Nombre: %s  Sexo: %c  Sueldo: %.2f  Fecha de ingreso: %d/%d/%d sector:  %s\n", arrayEmpleados[i].IDSector, arrayEmpleados[i].apellido, arrayEmpleados[i].nombre, arrayEmpleados[i].sexo, arrayEmpleados[i].sueldo, arrayEmpleados[i].fecha.dia, arrayEmpleados[i].fecha.mes, arrayEmpleados[i].fecha.anio, arraySectores[arrayEmpleados[i].IDSector-1].descripcion);
        }
    }
    system("pause");
}

int empleado_mostrar2(StEmpleado arrayEmpleados[], int CANT, StSector arraySectores[])
{
    int contador = 0;
    for (int i=0; i<CANT; i++)
    {
        if(arrayEmpleados[i].isEmpty==0)
        {
            printf("\nLegajo: %d  ID Sector: %d  Apellido: %s   Nombre: %s  \n", arrayEmpleados[i].legajo, arrayEmpleados[i].IDSector, arrayEmpleados[i].apellido, arrayEmpleados[i].nombre);
            contador++;
        }
    }
    system("pause");
    return contador;
}
