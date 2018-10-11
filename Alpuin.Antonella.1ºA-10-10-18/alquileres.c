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
    system("cls");
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

    system("cls");
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

///ALTA ALQUILER
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

///a) y b)PROMEDIO Y TOTAL

int promedioImporte(eJuegos list[],int len)
{
    float promedio;
    int contador=0;
    int contadorJuego=0;
    int total=0;


    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            total=total+list[i].importe;
            contador++;
            promedio=total/contador;
        }
    }

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==1&&(list[i].importe)<promedio)
        {
            contadorJuego++;
        }
    }

    printf("Total y promedio importes\n\n");
    printf("Total de importes: %d\n",total);
    printf("Promedio importes: %.2f\n",promedio);
    printf("Juegos que no superan el importe promedio: %d\n",contadorJuego);
    return promedio;
}

///------
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

///c) CLIENTE POR JUEGO
void listarAlquilerPorJuego(eAlquiler list[],int len, eJuegos juego[], int lenJuego,eCliente cliente[],int lenCliente)
{
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
            mostrarAlquilerPorJuego(list[i],len, juego, lenJuego,cliente,lenCliente);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay alquileres para mostrar\n\n");
    }

}
///D) JUEGO POR CLIENTE
void listarAlquilerPorCliente(eAlquiler list[],int len, eJuegos juego[], int lenJuego,eCliente cliente[],int lenCliente)
{
    int codigoCliente;
    char apellido[20];
    int flag = 0;

    codigoCliente = elegirCliente(cliente, lenCliente);

    cargarApellidoCliente(cliente, lenCliente, codigoCliente, apellido);

    system("cls");
    printf("Juegos por cliente %s\n\n", apellido);
    for(int i=0; i< len; i++)
    {
        if(list[i].isEmpty == 1 && list[i].codigoCliente == codigoCliente)
        {
            mostrarAlquilerPorCliente(list[i],len, juego, lenJuego,cliente,lenCliente);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay alquileres para mostrar\n\n");
    }

}

///MOSTRAR ALQUILER DE CLIENTE POR JUEGO
void mostrarAlquilerPorJuego(eAlquiler list,int lenAlquier, eJuegos juego[], int lenJuego,eCliente cliente[],int lenCliente)
{
    char descripcion[50];
    char apellido[50];

    cargarDescripcionJuego(juego, lenJuego, list.codigoJuego,descripcion);
    cargarApellidoCliente(cliente,lenCliente,list.codigoCliente,apellido);

    printf("JUEGO: %s\nCODIGO ALQUILER: %d\nFECHA: %d/%d/%d\nCODIGO CLIENTE: %d\nAPELLIDO: %s\n\n",descripcion,list.codigoAlquiler,list.fecha.dia, list.fecha.mes, list.fecha.anio,list.codigoCliente,apellido);

}

///MOSTRAR ALQUILER DE JUEGO POR CLIENTE
void mostrarAlquilerPorCliente(eAlquiler list,int lenAlquier, eJuegos juego[], int lenJuego,eCliente cliente[],int lenCliente)
{
    char apellido[50];
    char descipcion[50];

    cargarApellidoCliente(cliente,lenCliente,list.codigoCliente,apellido);
    cargarDescripcionJuego(juego, lenJuego, list.codigoJuego, descipcion);

    printf("CODIGO CLIENTE: %d\nAPELLIDO: %s\nCODIGO ALQUILER: %d\nFECHA: %d/%d/%d\nJUEGO: %s\n\n",list.codigoCliente,apellido,list.codigoAlquiler,list.fecha.dia, list.fecha.mes, list.fecha.anio,descipcion);
}


///i) JUEGOS ORDENADOS POR IMPORTE DESCENDENTE
int ordenarImporte(eJuegos* list, int len)
{
    eJuegos juego;
    int flagNoEstaOrdenado=1;

    system("cls");
    printf("  ***  Juegos ***\n\n");
    ///importe descendente
    while(flagNoEstaOrdenado==1)
    {
        flagNoEstaOrdenado=0;
        for(int j=1; j<len; j++)
        {
            if(list[j].importe>list[j-1].importe)
            {
                juego = list[j];
                list[j] = list[j-1];
                list[j-1] = juego;
                flagNoEstaOrdenado=1;
            }
        }
    }

    mostrarJuegos(list,len);

    return 0;
}

///j) JUEGOS ORDENADOS POR APELLIDO DESCENDENTE
/*void ordenarPorApellido(eCliente * cliente, int lenCliente)
{
    int p, j;
    eCliente auxCliente;
    for (p = 1; p < lenCliente; p++)
    {
        auxCliente = cliente[p].apellido;
        j = p - 1;
        while ((j >= 0) && (auxCliente < cliente[j].apellido))
        {
            cliente[j + 1].apellido = cliente[j].apellido;
            j--;
        }
        cliente[j + 1].apellido = auxCliente;
    }
}*/


int menuListar(eAlquiler alquiler[],int len,eJuegos juego[],int lenJuego,eCliente cliente[],int lenCliente)
{

    int opcionListar=0;

    do
    {
        system("pause");
        system("cls");
        printf("--MENU LISTAR--\n\n");
        printf("1- Promedio y total de los importes. Y los  juegos que no superan el promedio\n");
        printf("2- Listar todos los clientes que alquilaron un juego determinado\n");
        printf("3- Listar todos los juegos que fueron alquilados por un cliente determinado\n");
        printf("4- Ordenar juegos por importe descendente\n\n");
        printf("10-Salir\n\n");
        fflush(stdin);
        scanf("%d",&opcionListar);

        switch(opcionListar)
        {
        case 1:
            promedioImporte(juego,lenJuego);
            break;
        case 2:
            listarAlquilerPorJuego(alquiler,len,juego,lenJuego,cliente,lenCliente);
            break;
        case 3:
            listarAlquilerPorCliente(alquiler,len,juego,lenJuego,cliente,lenCliente);
            break;
        case 4:
            ordenarImporte(juego,lenJuego);
            break;
        case 5:
            break;
        case 10:
            printf("Saliendo..\n\n");
            opcionListar=10;
            system("pause");
            break;
        default:
            printf("Opcion incorrecta\n\n");
            break;
        }

    }
    while(opcionListar!=10);
    return opcionListar;
}
