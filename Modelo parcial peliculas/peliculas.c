#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "peliculas.h"
#include "directores.h"

static int generarId()
{
    static int idPeliculas=0;
    idPeliculas++;
    return idPeliculas;
}

int inicializarPeliculas(ePeliculas* list, int len)
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

int buscarEspacioLibrePeliculas(ePeliculas list[], int len)
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

///ALTA PELICULAS
int agregarPeliculas(ePeliculas list[], int len)
{

    ePeliculas nuevaPelicula;

    int retorno=-1;
    int indice;

    system("cls");
    printf("  *** Alta Peliculas ***\n\n");

    indice = buscarEspacioLibrePeliculas(list, len);


    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        getString("Ingrese el titulo de la pelicula: ",nuevaPelicula.titulo);

        getValidInt("Ingrese el anio de creacion: ",&nuevaPelicula.anio,1100,2018);

        getValidString("Ingrese la nacionalidad: ",nuevaPelicula.nacionalidad,3,50 );

        getValidString("Ingrese el nombre del director: ",nuevaPelicula.director,3,50 );


        nuevaPelicula.idPelicula=generarId();//ID
        nuevaPelicula.isEmpty=0;
        retorno=0;

        list[indice]=nuevaPelicula;

    }
    system("pause");
    return retorno;
}


int mostrarPeliculas(ePeliculas list[], int len)
{
    for(int i=0; i<len; i++)
    {
        if(!list[i].isEmpty)
        {
            printf("Id: %d Titulo: %s Anio: %d Nacionalidad: %s Director: %s\n\n",list[i].idPelicula,list[i].titulo,list[i].anio,list[i].nacionalidad,list[i].director);
        }

    }
    system("pause");
    return 0;
}
