#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "almuerzo.h"
#include "menu.h"
#include "empleados.h"


static int generarNextId()
{
    static int idAlmuerzo=0;
    idAlmuerzo++;
    return idAlmuerzo;
}

int inicializarAlmuerzo(eAlmuerzo* list, int len)
{
    int retorno=0;

    if(list==NULL)
    {
        if(len<=0)
        {
            retorno = -1;
        }
    }
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty = 1;
    }

    return retorno;
}

int buscarEspacioLibreAlmuerzo(eAlmuerzo list[], int len)
{
    int i;
    int retorno = -1;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int agregarAlmuerzo(eAlmuerzo almuerzos[], int lenAlmuerzos,eEmpleado empleado[], int lenEmpleado, eMenu menus[], int lenMenus)
{

    eAlmuerzo nuevoAlmuerzo;

    int retorno=-1;
    int indice;

    system("cls");
    printf("  *** Alta Almuerzos ***\n\n");

    indice = buscarEspacioLibreAlmuerzo(almuerzos, lenAlmuerzos);


    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        getValidInt("Ingrese la fecha\nAnio: ",&nuevoAlmuerzo.fecha.anio,1900,2018);
        getValidInt("Mes: ",&nuevoAlmuerzo.fecha.mes,1,12);
        getValidInt("Dia: ",&nuevoAlmuerzo.fecha.dia,1,31);

        getValidInt("Ingrese el legajo del empleado\n",&nuevoAlmuerzo.idEmpleado,1000,9999999);

        getValidInt("Ingrese el codigo del menu\n",&nuevoAlmuerzo.idComida,1000,9999999);


        nuevoAlmuerzo.idAlmuerzo=generarNextId();//ID
        nuevoAlmuerzo.isEmpty=0;


        almuerzos[indice]=nuevoAlmuerzo;
        for (int i=0;i<lenAlmuerzos;i++)
        {
            printf("INFORMACION INGRESADA\n");
            printf("ID: %d  Fecha de almuerzo %d/%d/%d  Nombre Empleado: %s %s Menu Elegido: %s\n", almuerzos[i].idAlmuerzo, almuerzos[i].fecha.dia, almuerzos[i].fecha.mes, almuerzos[i].fecha.anio, empleado[(almuerzos[i].idEmpleado)].apellido, empleado[(almuerzos[i].idEmpleado)].nombre, menus[almuerzos[i].idComida].descripcion);
        }
        retorno=0;

    }
    return retorno;
}
/*
int menuAlmuerzos()
{
    int opcionAlmuerzo=0;
    int contadorAlmuerzo=0;

    eAlmuerzo almuerzo[CANTE];
    inicializarAlmuerzo(almuerzo,CANTE);

    do
    {
        system("pause");
        system("cls");
        printf("--MENU ALMUERZOS--\n\n");
        printf("1- ALTA\n");
        printf("2- \n");
        printf("3- BAJA\n");
        printf("4- LISTAR\n");
        printf("5- SALIR\n\n");
        fflush(stdin);
        scanf("%d",&opcionAlmuerzo);

        switch(opcionAlmuerzo)
        {
        case 1:
            agregarAlmuerzo(almuerzo,CANTE);
            contadorEmpleado++;
            break;
        case 2:

        case 5:
            printf("Saliendo..\n\n");
            opcionAlmuerzo=5;
            system("pause");
            break;
        default:
            printf("Opcion incorrecta\n\n");
            break;
        }

    }
    while(opcionEmpleado!=5);
    return 2;
}*/



