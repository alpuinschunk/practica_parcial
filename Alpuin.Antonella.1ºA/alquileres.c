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

int buscarEspacioLibreAlquiler(eAlquiler list[], int len)
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

        printf("%d  %d %10s   %10s\n", alquiler[i].codigoAlquiler, alquiler[i].codigoCliente, apellidoCliente, descripcionJuego);
        system("pause");
    }
    return 0;
}
int agregarAlquiler(eAlquiler alquiler[], int lenAlquiler,eCliente cliente[], int lenCliente, eJuegos juego[], int lenJuego)
{

    eAlquiler nuevoAlquiler;
    int retorno=-1;
    int indice;
    int foundCliente;
    int foundJuego;

    indice=buscarEspacioLibreAlquiler(alquiler,lenAlquiler);

    system("cls");
    printf("  *** Alta Alquiler ***\n\n");


    if(indice == -1)
    {
        printf("No hay suficiente lugar\n\n");
    }
    else
    {
        getValidInt("Ingrese la fecha\nDia: ",&nuevoAlquiler.fecha.dia,1,31);
        getValidInt("Mes: ",&nuevoAlquiler.fecha.mes,1,12);
        getValidInt("Anio: ",&nuevoAlquiler.fecha.anio,1900,2018);



        //mostrarClientes(cliente,lenCliente);
        getValidInt("Ingrese el codigo del cliente (a partir de 1000): \n",&nuevoAlquiler.codigoCliente,1000,9999999);

        //mostrarJuegos(juego,lenJuego);
        getValidInt("Ingrese el codigo del juego (a partir de 100): \n",&nuevoAlquiler.codigoJuego,100,9999999);

        foundCliente = buscarClientePorCodigo(cliente, lenCliente,nuevoAlquiler.codigoCliente);
        foundJuego = buscarJuegoPorCodigo(juego,lenJuego,nuevoAlquiler.codigoJuego);

        if(foundCliente == -1)
        {
            printf("Cliente no encontrado\n");
            system("pause");
        }
        else
        {
            nuevoAlquiler.codigoAlquiler=generarCodigoAlquiler();//ID
            nuevoAlquiler.isEmpty=0;
            alquiler[indice]=nuevoAlquiler;
            retorno=0;
        }

        if(foundJuego == -1)
        {
            printf("Juego no encontrado\n");
            system("pause");
        }
        else
        {
            nuevoAlquiler.codigoAlquiler=generarCodigoAlquiler();//ID
            nuevoAlquiler.isEmpty=0;
            alquiler[indice]=nuevoAlquiler;
            retorno=0;
        }

    }

    //mostrarAlquiler(alquiler,lenAlquiler,cliente,lenCliente,juego,lenJuego);

    return retorno;
}





