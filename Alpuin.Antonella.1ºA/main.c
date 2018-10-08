#include <stdio.h>
#include <stdlib.h>
#include "alquileres.h"
#include "cliente.h"
#include "juegos.h"
#define CANT_ALQ 5
#define CANT_JUE  20
#define CANT_CLI 100

int main()
{
    int opcion=0;
    int flag=0;

    eAlquiler alquiler[CANT_ALQ];
    eCliente cliente[CANT_CLI];
    eJuegos juego[CANT_JUE];

    inicializarAlquiler(alquiler,CANT_ALQ);

    do
    {
        system("cls");
        printf("--ABM--\n\n");
        printf("1- Juegos\n");
        printf("2- Clientes\n");
        printf("3- Alta Alquileres\n");
        printf("4- Salir\n\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1://MENU COMIDAS
            menuJuegos();
            flag=1;
            break;
        case 2://MENU EMPLEADOS
            flag=2;
            menuClientes();
            break;
        case 3:
            if(flag!=1&&flag!=2)
            {
                printf("Debe ingresar juegos o peliculas antes de ingresar el alquiler\n\n");
                system("pause");
            }
            else
            {
                agregarAlquiler(alquiler,CANT_ALQ,cliente,CANT_CLI,juego,CANT_JUE);
            }
            break;
        case 4:
            printf("Saliendo..\n\n");
            opcion=4;
            system("pause");
            break;
        default:
            printf("Opcion incorrecta\n\n");
            system("pause");
            break;
        }
    }
    while(opcion!=4);

    return 0;
}
