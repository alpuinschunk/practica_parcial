#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"
#include "directores.h"

#include "utn.h"
#define MAX 3
#define DIR 2

int main()
{
    char seguir  = 's';

    ePeliculas peliculitas[MAX];
    eDirectores directorcitos[DIR];
    inicializarPeliculas( peliculitas, MAX);
    inicializarDirectores(directorcitos, DIR);
    char auxiliarNombre[51];
    int lugarLibre;
    int lugarLibreMenu;
    int flagPeliculas=0;
    int flagDirectores=0;
    do
    {
        switch(menuDeOpciones())
        {
        case 1:
            flagPeliculas=1;
            lugarLibre=espacioLibrePeliculas(peliculitas, MAX );
            if(lugarLibre!=-1)
            {
                agregarPelicula(peliculitas, MAX, directorcitos, DIR);
            }
            else
            {
                printf("No hay espacio libre!!\n");
            }

            system("pause");
            system("cls");
            break;
        case 2:
            if(flagPeliculas==1)
            {
                modificarPeliculas(peliculitas, MAX, lugarLibre,directorcitos, DIR);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 3:
            if(flagPeliculas==1)
            {
               removerPelicula(peliculitas, MAX, peliculitas[MAX].id);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;

        case 4:
            flagDirectores=1;
            lugarLibreMenu=espacioLibreDirectores(directorcitos, DIR);
            if(lugarLibreMenu !=-1)
            {
                agregarDirector(directorcitos, DIR);
                strcpy(auxiliarNombre, directorcitos[DIR].nombre);
            }
            else
            {
                printf("No hay espacio libre!\n");
            }

            system("pause");
            system("cls");
            break;
        case 5:
            if(flagDirectores==1)
            {
                removerDirector(directorcitos, DIR, auxiliarNombre);

            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 6:
            if(flagDirectores==1 && flagPeliculas==1)
            {
               opcionesInformar(peliculitas, MAX, directorcitos, DIR);
            }
            else
            {
                printf("No hay datos que mostrar!\n");
            }
            system("pause");
            system("cls");
            break;
        case 7:
            seguir  = 'n';
            break;
        default:
            printf("Se ingresaron mal los datos\n");
        }

    }
    while(seguir == 's');

    return 0;
}
