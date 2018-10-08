#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "peliculas.h"
#include "directores.h"
#include "utn.h"

static int generarNextId()
{
    static int id=-1;

    id ++;

    return id;
}

int inicializarPeliculas(ePeliculas* lista, int len)
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

int menuDeOpciones()
{
    int opcion;
    //system("cls");
    printf("-----Menu de opciones-----\n\n");
    printf("1. Alta peliculas\n");
    printf("2. Modificar pelicula\n");
    printf("3. Baja pelicula\n");
    printf("4. Alta director\n");
    printf("5. Baja director\n");
    printf("6. Informar \n");
    printf("7. Salir\n");
    printf("Elija una opcion:\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int espacioLibrePeliculas(ePeliculas* lista, int len)
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

int mostrarUnaPelicula(ePeliculas* lista, int indice)
{
    int retorno=-1;
    if( lista!= NULL)
    {
        if(lista[indice].isEmpty==0)
        {
            printf("%d\t    %s\t    %d\t    %s\t    %s \n\n", lista[indice].id, lista[indice].titulo, lista[indice].anio, lista[indice].nacionalidad, lista[indice].nombreDirector);
            retorno=0;
        }
    }
    return retorno;

}

int mostrarTodasLasPeliculas(ePeliculas* lista, int len)
{
    int retorno=-1;
    int i;
    if(lista!= NULL)
    {
        printf("ID\t    TITULO\t    ANIO\t    NACIONALIDAD\t    DIRECTOR\n");
        for( i=0; i<len ; i ++ )
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarUnaPelicula(lista, i);
                retorno=0;
            }
        }
    }
    return retorno;
}

int buscarPeliculaPorId(ePeliculas* lista, int len, int id)
{
    int i;
    int retorno=-1;
    if( lista!= NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(lista[i].id == id && lista[i].isEmpty==0)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int elegirDirector(eDirectores* lista, int len)
{
    int retorno=-1;
    char nombreDirector[51];
    if(lista!=NULL)
    {
        printf("Seleccione director:");
        fflush(stdin);
        gets(nombreDirector);
        retorno=0;
    }
    return retorno;
}

int agregarPelicula(ePeliculas* lista, int len, eDirectores* listaDirector, int lenDirector)
{
    ePeliculas auxiliarPelicula;
    int lugarLibre = espacioLibrePeliculas(lista, len);
    int retorno=-1;
    int coinciden;
    //char auxNombre[51];
    //char auxNacionalidad[51];
    //int auxAnio;

    if(lista !=  NULL)
    {
        if(lugarLibre != -1)
        {
            getValidString("Ingrese titulo de la pelicula: ", "Error, titulo no valido.", auxiliarPelicula.titulo);
            auxiliarPelicula.anio = getValidInt("Ingrese anio de la pelicula: ","Error, anio no valido.", 0, 2023);
            getValidString("Ingrese nacionalidad de la pelicula: ","Error, nacionalidad no valida.", auxiliarPelicula.nacionalidad);
            auxiliarPelicula.id = generarNextId();
            getValidString("Ingrese director :", "Error", auxiliarPelicula.nombreDirector);
            coinciden=buscarDirectorPorNombre(listaDirector, lenDirector, auxiliarPelicula.nombreDirector);
            if(coinciden==-1)
            {
                printf("No existe ese director!!!\n");
                retorno=-1;

            }
            if(coinciden!=-1)
            {
                auxiliarPelicula.id=generarNextId();
                printf("Director agregado con exito!!");
                auxiliarPelicula.isEmpty =0;
                lista[lugarLibre]=auxiliarPelicula;
                retorno=0;
            }


        }
    }
    return retorno;
}

int removerPelicula(ePeliculas* lista, int len, int id)
{
    int index;
    int i;
    int retorno=-1;

    if(lista!=NULL)
    {
        printf("Ingrese el id de la pelicula que desa eliminar: ");
        scanf("%d",&id);
        index=buscarPeliculaPorId(lista, len, id);

        if(lista[index].isEmpty==0)
        {
            printf("ID\t   TITULO\t   ANIO\t   NACIONALIDAD\t   DIRECTOR\n");
            mostrarUnaPelicula(lista, index);
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
                printf("No existe ese id!! \n");
                break;
            }
            retorno=0;
        }
    }
    return retorno;
}

int modificarPeliculas(ePeliculas* lista,int len,  int id, eDirectores* listaDirector, int lenDirector)
{
    int index;
    int cambiar;
    char newTitulo[51];
    char newNacionalidad[51];
    int newAnio;
    int coinciden;
    char newDirector[51];
    int retorno=-1;
    char continuar='n';

    printf("Ingrese el Id. de pelicula que desea modificar:\n");
    scanf("%d", &id);
    index=buscarPeliculaPorId(lista, len, id);

    if(lista!=NULL)
    {
        if(index >= 0)
        {
            do
            {
                printf("ID\t    TITULO\t    ANIO\t    NACIONALIDAD\t    DIRECTOR\n");
                mostrarUnaPelicula(lista, index);
                //llamar funcion que me muesstra los datos de esa posicion
                printf("\n\nSeleccione la opcion que desea modificar:");
                printf("\n1. Titulo\n");
                printf("2. Anio\n");
                printf("3. Nacionalidad\n");
            printf("4. Director\n");
            scanf("%d", &cambiar);
            switch(cambiar)
            {
            case 1:

                getValidString("Ingrese titulo de la pelicula: ", "Error, titulo no valido.",newTitulo);
                strcpy(lista[index].titulo, newTitulo);
                break;

            case 2:
                newAnio= getValidInt("Ingrese anio de la pelicula: ","Error, anio no valido.", 0, 2023);
                lista[index].anio= newAnio;
                break;
            case 3:
                getValidString("Ingrese nacionalidad de la pelicula: ","Error, nacionalidad no valida.", newNacionalidad);
                strcpy(lista[index].nacionalidad,newNacionalidad);
                break;
            case 4:
                getValidString("Ingrese director :", "Error", newDirector);
                coinciden=buscarDirectorPorNombre(listaDirector, lenDirector, newDirector);
                if(coinciden==-1)
                {
                    printf("No existe ese director!!!\n");
                    retorno=-1;

                }
                else
                {
                     strcpy(lista[index].nombreDirector, newDirector);
                }


                break;

            default :
                printf("Dato no valido\n");
            }

            printf("Desea continuar? s/n \n :");
            fflush(stdin);
            scanf("%c",&continuar);
            system("pause");
            system("cls");
        }
        while(continuar=='s' || continuar=='S');
    }
    else if(index < 0)
    {
        printf("No existe ese Id. \n");
    }

    retorno=0;     // }

}

return retorno;
}

int opcionesInformar(ePeliculas* lista,int len, eDirectores* listaDirector, int lenDirector)
{
    int retorno=-1;
    int elijaOpcion;
    if(lista!=NULL && listaDirector!=NULL)
    {
            printf("1. Mostrar peliculas\n");
                printf("2. Mostrar directores\n");
        printf("Elija la opcion: ");
        scanf("%d",&elijaOpcion);
    switch(elijaOpcion)
    {
    case 1:
        mostrarTodasLasPeliculas(lista, len);
        break;
    case 2:
        mostrarTodasLosDirectores(listaDirector, lenDirector);
        break;
    default:
        printf("Opcion incorrecta!\n");
    }
    retorno=0;
    }

    return retorno;

}



