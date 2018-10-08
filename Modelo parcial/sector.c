/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "empleados.h"
#include "sector.h"

eSector sectores[] =
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"},
        {6, "Otro"}

    };

int elegirSector(eSector sectores[], int len)
{
    //int retorno;
    int idSector;
    printf("\nSectores\n\n");

    for(int i=0; i < len; i++)
    {
        printf("%d %s\n", sectores[i].idSector, sectores[i].descripcion);
    }

    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);

    if(idSector==6)
    {
        cargarDescripcion(&sectores[i],len,idSector,sectores[i].descripcion);
    }*/



    /*return idSector;
}

void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[])
{

    for(int i=0; i < tamSector; i++)
    {
        if( sectores[i].idSector == idSector)
        {
            strcpy(cadena, sectores[i].descripcion);
            break;
        }
    }
}*/
