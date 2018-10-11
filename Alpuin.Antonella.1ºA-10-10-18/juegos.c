#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "juegos.h"


static int generarCodigoJuego()
{
    static int codigoJuego=99;
    codigoJuego++;
    return codigoJuego;
}

int inicializarJuego(eJuegos* list, int len)
{

    for(int i=0; i<len; i++)
    {
        list[i].isEmpty = 0;
    }

    return 0;
}

int buscarEspacioLibreJuegos(eJuegos list[], int len)
{
    int i;
    int retorno = -1;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

///ALTA Juego
int agregarJuego(eJuegos list[], int len)
{
    eJuegos nuevoJuego;
    int retorno=-1;
    int indice;

    system("cls");
    printf("  *** Alta Juegos ***\n\n");

    indice = buscarEspacioLibreJuegos(list, len);


    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        getValidString("Ingrese el nombre del juego: ",nuevoJuego.descripcion,3,20);

        getValidFloat("Ingrese el importe: ",&nuevoJuego.importe,0,10000);

        nuevoJuego.codigoJuego=generarCodigoJuego();//ID
        nuevoJuego.isEmpty=1;
        retorno=0;

        list[indice]=nuevoJuego;

    }
    return retorno;
}


int buscarJuegoPorCodigo(eJuegos list[], int len, int codigoJuego)
{
    int retorno=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].codigoJuego==codigoJuego)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}


void mostrarJuego(eJuegos list)
{
    printf("Codigo: %d Nombre: %s Importe: %.2f\n\n",list.codigoJuego,list.descripcion,list.importe);
}

int mostrarJuegos(eJuegos* list, int len)
{
    printf("CODIGO\tNOMBRE\tIMPORTE\n\n");
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            printf("%d\t%s\t$%.2f \n\n",list[i].codigoJuego,list[i].descripcion,list[i].importe);
        }
    }
    return 0;
}

///MODIFICACION JUEGOS

int modificarJuego(eJuegos* list, int len)
{
    int codigoComida;
    int retorno=-1;
    int found;
    char modificar;

    system("cls");
    printf("  *** Modificacion Juego ***\n\n");

    getValidInt("Ingrese el codigo del juego que desea modificar\n",&codigoComida,100,9999999);

    found=buscarJuegoPorCodigo(list,len,codigoComida);

    if(found >= 0 && list[found].isEmpty == 1)
    {
        mostrarJuego(list[found]);

        getValidString("¿Esta seguro de que quiere modificar este juego? s/n\n",&modificar,1,1);

        if(modificar=='s')
        {
            int opcion=0;
            printf("--MENU--\n\n");
            printf("1- Descripcion \n");
            printf("2- Importe \n");
            printf("3- Salir\n\n");
            fflush(stdin);
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                getValidString("Ingrese el nombre del juego: \n",list[found].descripcion,3,30);
                break;
            case 2:
                getValidFloat("Ingrese el importe: \n",&list[found].importe,1,999999);
                break;
            case 3:
                opcion=5;
                retorno=0;
                break;
            default:
                printf("Opcion incorrecta \n");
                system("pause");
                break;
            }
            printf("Modificacion completada\n\n");
        }
        else
        {
            printf("Modificacion cancelada\n\n");
        }
    }
    else
    {
        printf("Menu no encontrado\n");
    }
    return retorno;
}

///BAJA JUEGOS
int borrarJuego(eJuegos list[], int len)
{
    int codigoJuego;
    int found;
    char borrar;

    system("cls");
    printf("  *** Baja Juegos ***\n\n");

    getValidInt("Ingrese el codigo del juego desea eliminar\n",&codigoJuego,100,9999999);

    found=buscarJuegoPorCodigo(list,len,codigoJuego);

    if(found>= 0 && list[found].isEmpty == 1)
    {
        mostrarJuego(list[found]);

        getValidString("¿Esta seguro de que quiere eliminar este juego? s/n\n",&borrar,1,1);

        if(borrar=='s')
        {
            list[found].isEmpty=0;
            printf("Juego eliminado\n\n");
        }
        else
        {
            printf("Cancelado\n\n");
        }
    }
    else
    {
        printf("Menu no encontrado\n");
    }

    return -1;
}

///ORDENAR JUEGOS
int ordenarJuegos(eJuegos* list, int len)
{
    eJuegos juego;

    system("cls");
    printf("  ***  Juegos ***\n\n");
    ///importe descendente y descripcion ascendente
    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(list[i].importe<list[j].importe)
            {
                juego = list[i];
                list[i] = list[j];
                list[j] = juego;
            }

            else if((list[i].importe==list[j].importe)&&strcmp(list[i].descripcion,list[j].descripcion)>0)
            {
                juego = list[i];
                list[i] = list[j];
                list[j] = juego;
            }
        }
    }

    mostrarJuegos(list,len);

    return 0;
}

///MENU DE JUEGOS
int menuJuegos(eJuegos juego[], int len)
{
    int opcionJuego=0;
    int contadorJuego=0;

    do
    {
        system("pause");
        system("cls");
        printf("--MENU JUEGOS--\n\n");
        printf("1- ALTA\n");
        printf("2- MODIFICACION\n");
        printf("3- BAJA\n");
        printf("4- LISTAR\n");
        printf("5- SALIR\n\n");
        fflush(stdin);
        scanf("%d",&opcionJuego);

        switch(opcionJuego)
        {
        case 1:
            agregarJuego(juego,len);
            contadorJuego++;
            break;
        case 2:
            if(contadorJuego==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                modificarJuego(juego,len);
            }

            break;
        case 3:
            if(contadorJuego==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                borrarJuego(juego,len);
            }
            break;
        case 4:
            if(contadorJuego==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                ordenarJuegos(juego,len);
            }
            break;
        case 5:
            printf("Saliendo..\n\n");
            opcionJuego=5;
            system("pause");
            break;
        default:
            printf("Opcion incorrecta\n\n");
            system("pause");
            break;
        }

    }
    while(opcionJuego!=5);

    return opcionJuego;
}
