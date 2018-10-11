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
    inicializarCliente(cliente,CANT_CLI);
    inicializarJuego(juego,CANT_JUE);

    harcodearCliente(cliente);



    do
    {
        system("cls");
        printf("--ABM--\n\n");
        printf("1- Juegos\n");
        printf("2- Clientes\n");
        printf("3- Alta Alquileres\n");
        printf("4- Listar\n");
        printf("5- Salir\n\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1://MENU COMIDAS
            menuJuegos(juego,CANT_JUE);
            flag=1;
            break;
        case 2://MENU EMPLEADOS
            flag=2;
            menuClientes(cliente,CANT_CLI);
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
        case 4://LISTAR
            menuListar(alquiler,CANT_ALQ,juego,CANT_JUE,cliente,CANT_CLI);
            break;
        case 5:
            printf("Saliendo..\n\n");
            opcion=5;
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
