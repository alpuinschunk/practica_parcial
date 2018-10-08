#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"
#include "directores.h"
#include "utn.h"
#define CANTP 4
#define CANTD 4

int main()
{
    int opcion=0;
    int opcionListar=0;
   // int contadorPelicula=0;
   // int opcionPelicula=0;

   // int contadorDirector=0;
   // int opcionDirector=0;

    ePeliculas pelicula[CANTP];
    inicializarPeliculas(pelicula,CANTP);


    eDirectores director[CANTD];
    inicializarDirectores(director,CANTD);

    do
    {
        system("cls");
        printf("--ABM--\n\n");
        printf("1- ALTA PELICULAS\n");
        printf("2- MODIFICAR PELICULAS\n");
        printf("3- BAJA PELICULAS\n");
        printf("4- ALTA DIRECTORES\n");
        printf("5- BAJA DIRECTORES\n");
        printf("6- LISTAR\n");
        printf("7- Salir\n\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1://ALTAS PELICULAS
            agregarPeliculas(pelicula,CANTP);
            break;
        case 2: //MODIFICACION PELICULAS
            break;
        case 3://BAJA PELICULAS
            break;
        case 4://ALTA DIRECTORES
            agregarDirectores(director,CANTD);
            break;
        case 5://BAJA DIRECTORES
            break;
        case 6://LISTAR A- PELICULAS B- DIRECTORES
            printf("1)Peliculas\n1)Directores\n\n");
            fflush(stdin);
            scanf("%d",&opcionListar);
            switch(opcionListar)
            {
            case 1:
                mostrarPeliculas(pelicula,CANTP);
                break;
            case 2:
                mostrarDirectores(director,CANTD);
                break;
            default:
                printf("Opcion incorrecta\n");
                break;
            }
            system("pause");
            break;
        case 7:
            printf("Saliendo..\n\n");
            opcion=7;
            system("pause");
            break;
        default:
            printf("Opcion incorrecta\n\n");
            system("pause");
            break;
        }
    }
    while(opcion!=7);

    return 0;
}
