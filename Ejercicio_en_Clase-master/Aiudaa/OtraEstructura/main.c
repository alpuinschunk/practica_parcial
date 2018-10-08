#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"
#include "utn.h"
#define MAX 3

int main()
{
    char seguir  = 's';

    ePeliculas peliculitas[MAX];

    inicializarPeliculas( peliculitas, MAX);

     int lugarLibre;

    do
    {
        switch(menuDeOpciones())
        {
        case 1:
            lugarLibre=espacioLibrePeliculas(peliculitas, MAX );
            if(lugarLibre!=-1)
            {
                agregarPelicula(peliculitas, MAX);
            }
            else
            {
                printf("No hay espacio libre!!\n");
            }

            system("pause");
            system("cls");
            break;
        case 3:
            removerPelicula(peliculitas, MAX, peliculitas[MAX].id);
            system("pause");
            system("cls");
            break;
        case 5:
            seguir  = 'n';
            break;
        }

    }while(seguir == 's');

    return 0;
}
