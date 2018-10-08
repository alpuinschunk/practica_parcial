#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "directores.h"
#include "peliculas.h"

int inicializarDirectores(eDirectores* lista, int len)
{
    int i;
    int retorno=-1;
    if( lista != NULL )
    {
        for(i=0; i<len ; i ++)
        {
            lista[i].isEmpty=1;
        }
        retorno = 0;
    }

    return retorno;

}


int espacioLibreDirectores(eDirectores* lista, int len)
{
    int i;
    int retorno=-1;
    if( lista != NULL)
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

int mostrarUnDirector(eDirectores* lista, int indice)
{
    int retorno=-1;
    if( lista!= NULL)
    {
        if(lista[indice].isEmpty==0)
        {
           printf("%s\t    %s\t    %d/%d/%d\n\n", lista[indice].nombre, lista[indice].paisOrigen, lista[indice].nacimiento.dia, lista[indice].nacimiento.mes, lista[indice].nacimiento.anio);
           retorno=0;
        }
    }
    return retorno;

}

int mostrarTodasLosDirectores(eDirectores* lista, int len)
{
    int retorno=-1;
    int i;
    if(lista!= NULL)
    {
        printf("NOMBRE\t    PAIS DE ORIGEN\t    FECHA DE NACIMIENTO\n");
        for( i=0; i<len ; i ++ )
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarUnDirector(lista, i);
                retorno=0;
            }
        }
    }
    return retorno;
}

int buscarDirectorPorNombre(eDirectores* lista, int len, char nombre[])
{
    int i;
    int retorno=-1;
    if( lista!= NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(strcmp(lista[i].nombre,nombre)==0 && lista[i].isEmpty==0)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int agregarDirector(eDirectores* lista, int len)
{
    eDirectores auxiliarDirectores;
    int lugarLibre = espacioLibreDirectores(lista, len);
    int retorno=-1;
    int  esta;
    //char auxNombre[51];
    //char auxNacionalidad[51];
    //int auxAnio;

    if(lista !=  NULL)
    {
        if(lugarLibre== -1)
        {
            printf("No hay espacio libre para los directores!!!");
        }
        else
        {
            getValidString("Ingrese nombre del director: ", "Error, no valido.", auxiliarDirectores.nombre);
            esta =buscarDirectorPorNombre(lista, len, auxiliarDirectores.nombre);

            if(esta!=-1)
            {
                printf("Existe un autor con ese nombre");
            }
            else
            {
                            //Tiene que ser unico
            getValidString("Ingrese pais de origen del director: ", "Error, no valido.", auxiliarDirectores.paisOrigen);
            auxiliarDirectores.nacimiento.dia = getValidInt("Ingrese dia: ","Error, dia no valido.", 1, 31);
            auxiliarDirectores.nacimiento.mes = getValidInt("Ingrese mes: ","Error, mes no valido.", 1, 12);
            auxiliarDirectores.nacimiento.anio = getValidInt("Ingrese anio: ","Error, anio no valido.", 1000, 2018);
            //auxiliarPelicula.id = generarNextId();
            auxiliarDirectores.isEmpty =0;
            lista[lugarLibre]=auxiliarDirectores;

            }

            retorno=0;
        }
    }
    return retorno;
}

int removerDirector(eDirectores* lista, int len, char nombre[])
{
    int index;
    int i;
    int retorno=-1;

    if(lista!=NULL)
    {
        printf("Ingrese el nombre del director que desea eliminar: ");
        fflush(stdin);
        gets(nombre);
        index=buscarDirectorPorNombre(lista, len, nombre);

        if(lista[index].isEmpty==0)
        {
            // printf("ID\t   TITULO\t   ANIO\t   NACIONALIDAD\n");
             mostrarUnDirector(lista, index);
        }
        //Tendria que preguntar si quiere eliminar la pelicula
        for( i=0 ; i<len ; i++)
        {
            if(index>=0)
            {
                printf("El usuario fue eliminado!\n");
                lista[index].isEmpty=1;
                break;
            }
            else
            {
                printf("No existe ese nombre!! \n");
                break;
            }
            retorno=0;
        }
    }
    return retorno;
}
