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
    printf("\n>>Juegos<<\n\n");
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

    printf("\n\n>>Clientes<<\n\n");
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
///INFORMES

void cargarDescripcionJuego(eJuegos juego[], int lenJuego, int codigoJuego, char cadena[])
{

    for(int i=0; i < lenJuego; i++)
    {
        if( juego[i].codigoJuego == codigoJuego)
        {
            strcpy(cadena, juego[i].descripcion);
            break;
        }
    }
}
void cargarApellidoCliente(eCliente cliente[], int len, int codigoCliente, char cadena[])
{
    for(int i=0; i < len; i++)
    {
        if( cliente[i].codigoCliente == codigoCliente)
        {
            strcpy(cadena, cliente[i].apellido);
            break;
        }
    }
}

/*void listarClientesPorJuego(eCliente list[],int len, eJuegos juego[], int lenJuego)
{
    int codigoJuego;
    char descripcion[20];
    int flag = 0;

    codigoJuego = elegirJuego(juego, lenJuego);

    cargarDescripcion(juego, len, codigoJuego, descripcion);

    system("cls");
    printf("Clientes por juego %s\n\n", descripcion);
    for(int i=0; i< len; i++)
    {
        if(list[i].isEmpty == 1 && list[i].codigoJuego == codigoJuego)
        {
            mostrarCliente(list[i], juego, lenJuego);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay empleados para mostrar\n\n");
    }

}*/
void listarAlquilerPorJuego(eAlquiler list[],int len, eJuegos juego[], int lenJuego,eCliente cliente[],int lenCliente)
{
    eAlquiler alquiler;
    int codigoJuego;
    char descripcion[20];
    int flag = 0;

    codigoJuego = elegirJuego(juego, lenJuego);

    cargarDescripcionJuego(juego, len, codigoJuego, descripcion);

    system("cls");
    printf("Clientes por juego %s\n\n", descripcion);
    for(int i=0; i< len; i++)
    {
        if(list[i].isEmpty == 1 && list[i].codigoJuego == codigoJuego)
        {
            mostrarAlquiler(alquiler, juego, lenJuego,cliente,lenCliente);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay empleados para mostrar\n\n");
    }

}

void mostrarAlquiler(eAlquiler list, eJuegos juego[], int lenJuego,eCliente cliente[],int lenCliente)
{
    char descripcion[50];
    char apellido[50];

    cargarDescripcionJuego(juego, lenJuego, list.codigoJuego, descripcion);
    cargarApellidoCliente(cliente,lenCliente,list.codigoCliente,apellido);

    printf("\nJUEGO\tCODIGO ALQUILER\tCODIGO CLIENTE\tAPELLIDO\n\n");
    printf("%s\t%d\t%d\t%s\n\n",descripcion,list.codigoAlquiler,list.codigoCliente,apellido);
}


/*
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
}*/

int menuListar(eAlquiler alquiler[],int len ,eJuegos juego[],int lenJuego,eCliente cliente[],int lenCliente)
{

    int opcion=0;

    do
    {
        system("pause");
        system("cls");
        printf("--MENU LISTAR--\n\n");
        printf("1- ALQUILER POR JUEGO\n");
        printf("2- \n");
        printf("3- \n");
        printf("4- \n");
        printf("5- \n\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            listarAlquilerPorJuego(alquiler,len,juego,lenJuego,cliente,lenCliente);
            //contador++;
            break;
        case 2:
            /*if(contador==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                modificarCliente(cliente,len, );
            }*/
            break;
        case 3:
            /*if(contador==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                borrarCliente(cliente,len);
            }*/
            break;
        case 4:
            /*if(contador==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                ordenarClientes(cliente,len);
            }*/
            break;
        case 5:
            printf("Saliendo..\n\n");
            opcion=5;
            system("pause");
            break;
        default:
            printf("Opcion incorrecta\n\n");
            break;
        }

    }
    while(opcion!=5);
    return opcion;
}
