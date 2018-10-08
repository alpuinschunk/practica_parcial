#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "directores.h"

int inicializarDirectores(eDirectores* list, int len)
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

int buscarEspacioLibreDirectores(eDirectores list[], int len)
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

///ALTA DIRECTORES
int agregarDirectores(eDirectores list[], int len)
{

    eDirectores nuevoDirector;

    int retorno=-1;
    int indice;

    system("cls");
    printf("  *** Alta Directores ***\n\n");

    indice = buscarEspacioLibreDirectores(list, len);


    if(indice == -1)
    {
        printf("No hay suficiente lugar\n\n");
    }
    else
    {
        getValidString("Ingrese el nombre del director: ",nuevoDirector.nombre,3,50);

        getValidInt("Ingrese la fecha de nacimiento\nAnio: ",&nuevoDirector.fecha.anio,1900,2018);
        getValidInt("Mes: ",&nuevoDirector.fecha.mes,1,12);
        getValidInt("Dia: ",&nuevoDirector.fecha.dia,1,31);

        getValidString("Ingrese la nacionalidad: ",nuevoDirector.nacionalidad,3,50 );

        nuevoDirector.isEmpty=0;
        retorno=0;

        list[indice]=nuevoDirector;

    }
    system("pause");

    return retorno;
}

int mostrarDirectores(eDirectores list[], int len)
{
    for(int i=0; i<len; i++)
    {
        if(!list[i].isEmpty)
        {
            printf("Nombre: %s Fecha de nacimiento: %d/%d/%d Nacionalidad %s\n\n",list[i].nombre,list[i].fecha.dia,list[i].fecha.mes,list[i].fecha.anio,list[i].nacionalidad);
        }
        else
        {
            printf("No hay datos para mostrar\n");
        }
    }
    system("pause");
    return 0;
}

