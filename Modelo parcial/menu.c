#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "menu.h"
#define CANTM 20


static int generarNextId()
{
    static int idMenu=999;
    idMenu++;
    return idMenu;
}

int inicializarMenu(eMenu* list, int len)
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

int buscarEspacioLibreMenu(eMenu list[], int len)
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

///ALTA MENU
int agregarMenu(eMenu list[], int len)
{
    eMenu nuevoMenu;
    int retorno=-1;
    int indice;

    system("cls");
    printf("  *** Alta Menu ***\n\n");

    indice = buscarEspacioLibreMenu(list, len);


    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        getValidString("Ingrese comida: ",nuevoMenu.descripcion,3,20);

        getValidFloat("Ingrese el importe: ",&nuevoMenu.importe,0,10000);

        nuevoMenu.idComida=generarNextId();//ID
        nuevoMenu.isEmpty=0;
        retorno=0;

        list[indice]=nuevoMenu;

    }
    return retorno;
}


int buscarMenuPorId(eMenu list[], int len, int idComida)
{
    int retorno=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].idComida==idComida)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void mostrarMenu(eMenu list)
{
    printf("Id: %d Comida: %s Importe: %.2f\n\n",list.idComida,list.descripcion,list.importe);
}

int mostrarMenus(eMenu* list, int len)
{
    for(int i=0; i<len; i++)
    {
        if(!list[i].isEmpty)
        {
            printf("Id: %d Comida: %s Importe: $%.2f \n\n",list[i].idComida,list[i].descripcion,list[i].importe);
        }
    }
    return 0;
}

///BAJA MENU
int borrarMenu(eMenu list[], int len)
{
    int idComida;
    int found;
    char borrar;

    system("cls");
    printf("  *** Baja Menu ***\n\n");

    getValidInt("Ingrese el ID de la comida que desea eliminar\n",&idComida,1000,9999999);

    found=buscarMenuPorId(list,len,idComida);

    if(found==-1)
    {
        printf("Menu no encontrado\n");
    }
    else
    {
        mostrarMenu(list[found]);

        getValidString("¿Esta seguro de que quiere eliminar este menu? s/n\n",&borrar,1,1);

        if(borrar=='s')
        {
            list[found].isEmpty=1;
            printf("Menu eliminado\n\n");
        }
        else
        {
            printf("Cancelado\n\n");
        }
    }

    return -1;
}

///MODIFICACION MENU
int modificarMenu(eMenu* list, int len)
{
    int idComida;
    int retorno=-1;
    int found;
    char modificar;

    system("cls");
    printf("  *** Modificacion Menu ***\n\n");

    getValidInt("Ingrese el ID del menu que desea modificar\n",&idComida,1000,9999999);

    found=buscarMenuPorId(list,len,idComida);

    if(found == -1)
    {
        printf("Menu no encontrado\n");
    }
    else
    {
        mostrarMenu(list[found]);

        getValidString("¿Esta seguro de que quiere modificar este menu? s/n\n",&modificar,1,1);

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
                getValidString("Ingrese el nombre de la comida: \n",list[found].descripcion,3,30);
                break;
            case 2:
                getValidFloat("Enter el importe: \n",&list[found].importe,1,999999);
                break;
            case 3:
                opcion=5;
                retorno=0;
                break;
            default:
                printf("Wrong option: \n");
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
    return retorno;
}

int ordenarMenu(eMenu* list, int len)
{
    eMenu menu;

    system("cls");
    printf("  ***  Menu ***\n\n");
    ///importe descendente y descripcion ascendente
    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(list[i].importe<list[j].importe)
            {
                menu = list[i];
                list[i] = list[j];
                list[j] = menu;
            }

            else if((list[i].importe==list[j].importe)&&strcmp(list[i].descripcion,list[j].descripcion)>0)
            {
                menu = list[i];
                list[i] = list[j];
                list[j] = menu;
            }
        }
    }

    mostrarMenus(list,len);

    return 0;
}
int menuMenus()
{
    int opcionMenu=0;
    int contadorMenu=0;

    eMenu menu[CANTM];
    inicializarMenu(menu,CANTM);

    do
    {
        system("pause");
        system("cls");
        printf("--MENU MENUES--\n\n");
        printf("1- ALTA\n");
        printf("2- MODIFICACION\n");
        printf("3- BAJA\n");
        printf("4- LISTAR\n");
        printf("5- SALIR\n\n");
        fflush(stdin);
        scanf("%d",&opcionMenu);

        switch(opcionMenu)
        {
        case 1:
            agregarMenu(menu,CANTM);
            contadorMenu++;
            break;
        case 2:
            if(contadorMenu==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                modificarMenu(menu,CANTM);
            }

            break;
        case 3:
            if(contadorMenu==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                borrarMenu(menu,CANTM);
            }
            break;
        case 4:
            if(contadorMenu==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                ordenarMenu(menu,CANTM);
            }
            break;
        case 5:
            printf("Saliendo..\n\n");
            opcionMenu=5;
            system("pause");
            break;
        default:
            printf("Opcion incorrecta\n\n");
            system("pause");
            break;
        }

    }
    while(opcionMenu!=5);

    return 1;
}
