#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "negocio.h"

static int generarNextId() //Genero un unico id por cada empleado que se ingresa
{
    static int id = 0;

    id ++;

    return id;
}

int inicializarEmpleados(eEmpleados* lista, int len)
{
    int i;
    int retorno=-1;

    if(lista !=NULL)
    {
        for(i=0; i<len ; i ++)
        {
            lista[i].isEmpty=1;

        }
        retorno = 0;

    }

    return retorno;

}

int buscarLugarLibreEmpleados(eEmpleados* lista, int len)
{
    int i;
    int retorno=-1;

    if(lista !=NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(lista[i].isEmpty==1)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int menuDeOpciones()
{
    int opcion;
    //system("cls");
    printf("-----Menu de opciones-----\n\n");
    printf("1. Alta\n");
    printf("2. Modificar\n");
    printf("3. Baja\n");
    printf("4. Informar\n");
    printf("5. Salir\n");
    printf("Elija una opcion:\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}




