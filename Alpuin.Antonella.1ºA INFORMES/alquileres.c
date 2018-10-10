#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "alquileres.h"
#include "cliente.h"
#include "juegos.h"

static int generarCodigoAlquiler()
{
    static int codigoAlquiler=0;
    codigoAlquiler++;
    return codigoAlquiler;
}

int inicializarAlquiler(eAlquiler* list, int len)
{
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty = 0;
    }

    return 0;
}

int buscarEspacioLibreAlquiler(eAlquiler list[], int len)
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
int elegirJuego(eJuegos juego[], int len)
{
    int retorno=-1;
    int codigoJuego;
    printf("Juegos\n\n");
    mostrarJuegos(juego,len);

    printf("\nSeleccione juego: ");
    scanf("%d", &codigoJuego);
    for(int i=0; i < len; i++)
    {
        if(juego[i].codigoJuego==codigoJuego&&juego[i].isEmpty==1)
        {
            retorno=codigoJuego;
            break;
        }
    }
    return retorno;
}

int elegirCliente(eCliente cliente[], int len)
{
    int codigoCliente;
    int retorno=-1;

    printf("\n\nClientes\n\n");
    mostrarClientes(cliente,len);
    printf("\nSeleccione cliente: ");
    scanf("%d", &codigoCliente);
    for(int i=0; i < len; i++)
    {
        if(cliente[i].codigoCliente==codigoCliente&&cliente[i].isEmpty==1)
        {
            retorno=codigoCliente;
            break;
        }
    }
    return retorno;
}


int agregarAlquiler(eAlquiler alquiler[], int lenAlquiler,eCliente cliente[], int lenCliente, eJuegos juego[], int lenJuego)
{
    eAlquiler nuevoAlquiler;
    int retorno=-1;
    int indice;

    indice=buscarEspacioLibreAlquiler(alquiler,lenAlquiler);

    system("cls");
    printf("  *** Alta Alquiler ***\n\n");


    if(indice == -1)
    {
        printf("No hay suficiente lugar\n\n");
    }
    else
    {
        nuevoAlquiler.codigoJuego=elegirJuego(juego,lenJuego);
        if(nuevoAlquiler.codigoJuego==-1)
        {
            printf("Codigo de juego no encontrado");
        }
        else
        {
            nuevoAlquiler.codigoCliente=elegirCliente(cliente,lenCliente);
            if(nuevoAlquiler.codigoCliente==-1)
            {
                printf("Codigo de cliente no encontrado");
            }
            else
            {
                getValidInt("Ingrese la fecha\nDia: ",&nuevoAlquiler.fecha.dia,1,31);
                getValidInt("Mes: ",&nuevoAlquiler.fecha.mes,1,12);
                getValidInt("Anio: ",&nuevoAlquiler.fecha.anio,1900,2018);
                nuevoAlquiler.codigoAlquiler=generarCodigoAlquiler();//ID
                nuevoAlquiler.isEmpty=1;
                alquiler[indice]=nuevoAlquiler;
                retorno=0;
                system("cls");
                printf("INFORMACION INGRESADA\n");
                printf("-----------------------------------\n\n");
                printf("CODIGO ALQUILER\tCODIGO JUEGO\tCODIGO CLIENTE\tFECHA\n\n");
                printf("%d\t\t%d\t\t%d\t\t %d/%d/%d\n", nuevoAlquiler.codigoAlquiler, nuevoAlquiler.codigoJuego,nuevoAlquiler.codigoCliente,nuevoAlquiler.fecha.dia, nuevoAlquiler.fecha.mes, nuevoAlquiler.fecha.anio);
                system("pause");


            }
        }


    }

    return retorno;
}





int mostrarAlquiler(eAlquiler alquiler[], int lenAlquiler,eCliente cliente[], int lenCliente, eJuegos juego[], int lenJuego)
{

    char descripcionJuego[20];
    char apellidoCliente[20];

    for(int i=0; i< lenAlquiler; i++)
    {
        for(int j = 0; j < lenCliente; j++)
        {
            if(alquiler[i].codigoCliente == cliente[j].codigoCliente)
            {
                strcpy(apellidoCliente, cliente[j].apellido);
                break;
            }
        }
        for(int k = 0; k < lenJuego; k++)
        {
            if(alquiler[i].codigoJuego == juego[k].codigoJuego)
            {
                strcpy(descripcionJuego, juego[k].descripcion);
                break;
            }
        }

        printf("%d  %d %10s\n", alquiler[i].codigoAlquiler, alquiler[i].codigoCliente, descripcionJuego);
        system("pause");
    }
    return 0;
}

