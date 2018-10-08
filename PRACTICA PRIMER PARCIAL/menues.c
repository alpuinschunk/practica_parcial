#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "empleado.h"
#include "menues.h"
#include "almuerzo.h"

void menu_menuPrincipal()
{
    printf("[1] AGREGAR MENU\n");
    printf("[2] MODIFICAR MENU\n");
    printf("[3] ELIMINAR MENU\n");
    printf("[4] LISTAR\n\n");
    printf("[5] SALIR\n");
}

void menu_menuModificar(StMenues arrayMenues[], int ID)
{
    printf("/////MODIFY MENU/////\n");
    printf("\nSE MODIFICARA LA INFORMACION DE ESTE MENU\n");
    printf("ID Menu: %d  Descripcion: %s   Precio: %.2f\n", arrayMenues[ID].codigoMenu, arrayMenues[ID].descripcion, arrayMenues[ID].importe);
    printf("\n/////////////////////////\n");
    printf("[1] MODIFICAR DESCRIPCION  \n");
    printf("[2] MODIFICAR IMPORTE\n");
    printf("[3] EXIT\n");
}

void menu_initMenues(StMenues arrayMenues[], int CANT)
{
    for(int i=0; i<CANT; i++)
    {
        arrayMenues[i].codigoMenu = i+1;
        arrayMenues[i].isEmpty = 1;
    }
}

int menu_buscarPorID(StMenues arrayMenues[], int CANT, int ID)
{
    int index = -1;

    for(int i=0; i<CANT; i++)
    {
        if(arrayMenues[i].codigoMenu == ID && arrayMenues[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

void menu_funcionPrincipal(StMenues arrayMenues[], int CANT)
{
    int exit = 0;
    char option = 'x';
    int check;
    int contadorMenues=0;
    do
    {
        system("cls");
        menu_menuPrincipal();

        printf("\nType Your Option: ");
        option = getch();

        switch(option)
        {
        case '1': //AGREGAR MENU//
                check = menu_alta(arrayMenues, CANT);
                if(check==-1)
                {
                    printf("ERROR. No se pudo dar de alta o no hay mas espacio libre\n");
                    system("pause");
                }else
                {
                    contadorMenues++;
                }
            break;
        case '2': //MODIFICAR MENU//
            if(contadorMenues>0)
            {
                menu_modificar(arrayMenues, CANT);
            }else
            {
                printf("Ingrese un plato al menu primero\n");
                system("pause");
            }
            break;
        case '3':   //ELIMINAR MENU//
            if(contadorMenues>0)
            {
                check = menu_baja(arrayMenues, CANT);
                if(check==0)
                {
                    contadorMenues--;
                }
            }else
            {
                printf("Ingrese un plato al menu primero\n");
                system("pause");
            }
            break;
        case '4':   //LISTAR//
            if(contadorMenues>0)
            {
                menu_listar(arrayMenues, CANT);
                menu_mostrar(arrayMenues, CANT);
            }else
            {
                printf("Ingrese un plato al menu primero\n");
                system("pause");
            }
            break;
        case '5':   //SALIR//
            exit = 1;
            break;
        default:
            printf("Incorrect Input\n");
            system("pause");
        break;
        }

    }
    while(exit == 0);

}

int menu_alta(StMenues arrayMenues[], int CANT)
{
    int status, check;

    for(int i=0; i<CANT; i++)
    {
        if(arrayMenues[i].isEmpty == 1)
        {
            do{
            system("cls");
            check = getString(arrayMenues[i].descripcion, "Ingrese Descripcion: (Max 50): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 51);
            }while(check!=1);

            do{
            system("cls");
            check = getFloat(&arrayMenues[i].importe, "Ingrese Importe: (>0): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 9999999);
            }while(check!=1);

            arrayMenues[i].isEmpty = 0;

            printf("INFORMACION INGRESADA\n");
            printf("ID Menu: %d  Descripcion: %s   Precio: %.2f\n", arrayMenues[i].codigoMenu, arrayMenues[i].descripcion, arrayMenues[i].importe);
            system("pause");
            status = 0;
            break;
        }else{
            status = -1;
        }
    }

    return status;
}

void menu_modificar(StMenues arrayMenues[], int CANT)
{
    system("cls");
    int check = -1;
    int ID;
    int IDAux;
    do{ check = getInt(&IDAux, "Ingrese ID de Menu a buscar: (1 - 20): ", "[ERROR] Not a Valid ID\n", 1, 20);
    }while(check!=1);

    ID = menu_buscarPorID(arrayMenues, CANT, IDAux);

    if(ID != -1)
    {
        int exit = 0;
        char option;
        do
        {
            system("cls");
            menu_menuModificar(arrayMenues, ID);

            printf("\nElija Opcion: ");
            option = getch();

            switch(option)
            {

                case '1': //MODIFICAR DESCRIPCION//
                    do{
                    system("cls");
                    check = getString(arrayMenues[ID].descripcion, "Ingrese Descripcion: (Max 50): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 51);
                    }while(check!=1);
                    break;
                case '2': //MODIFICAR IMPORTE//
                    do{
                    system("cls");
                    check = getFloat(&arrayMenues[ID].importe, "Ingrese Importe: (>0): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 9999999);
                    }while(check!=1);
                    break;
                case '3':
                    exit = 1;
                    break;
                default:
                    printf("Incorrect Input\n");
                    system("pause");
                    break;
            }
        }while(exit==0);
    }else
    {
        printf("\nID NOT FOUND!\n");
        system("pause");
    }
}

int menu_baja(StMenues arrayMenues[], int CANT)
{
    system("cls");
    int status;
    int check = -1;
    int ID, IDAux;
    char optionYN;
    do{ check = getInt(&IDAux, "Escriba ID de menu  (1 - 100): ", "[ERROR] Not a Valid ID\n", 1, 20);
    }while(check!=1);

    ID = menu_buscarPorID(arrayMenues, CANT, IDAux);

    if(ID != -1)
    {
        do
        {
            system("cls");
            printf("\nESTE MENU SERA ELIMINADO\n");
            printf("ID Menu: %d  Descripcion: %s   Precio: %.2f\n", arrayMenues[ID].codigoMenu, arrayMenues[ID].descripcion, arrayMenues[ID].importe);
            printf("\nARE YOU SURE? Y/N: ");
            optionYN = toupper(getch());
        }while(!(optionYN == 'Y' || optionYN == 'N'));

        if(optionYN == 'Y')
        {
            arrayMenues[ID].isEmpty = 1;
            printf("\nEL MENU HA SIDO ELIMINADO!\n");
            system("pause");
            status = 0;
        }else if(optionYN == 'N')
        {
            printf("\nOPERACION CANCELADA\n");
            system("pause");
        }
    }
    else
    {
        printf("\nID INGRESADO NO ENCONTRADO!\n");
        status = -1;
        system("pause");
    }
    return status;
}

void menu_listar(StMenues arrayMenues[], int CANT)
{
    StMenues menuAux;
    for(int i=0; i<CANT-1; i++)
    {
        for(int j=i+1; j<CANT; j++)
        {
            if( (arrayMenues[i].importe > arrayMenues[j].importe) && arrayMenues[i].isEmpty==0 && arrayMenues[j].isEmpty==0)
            {
                menuAux = arrayMenues[i];
                arrayMenues[i] = arrayMenues[j];
                arrayMenues[j] = menuAux;
            }else if( (arrayMenues[i].importe == arrayMenues[j].importe) && arrayMenues[i].isEmpty==0 && arrayMenues[j].isEmpty==0)
            {
                if( (strcmp(arrayMenues[i].descripcion, arrayMenues[j].descripcion) > 0) && arrayMenues[i].isEmpty==0 && arrayMenues[j].isEmpty==0)
                {
                    menuAux = arrayMenues[i];
                    arrayMenues[i] = arrayMenues[j];
                    arrayMenues[j] = menuAux;
                }
            }
        }
    }
}

void menu_mostrar(StMenues arrayMenues[], int CANT)
{
    printf("\n\n");
    for (int i=0; i<CANT; i++)
    {
        if(arrayMenues[i].isEmpty==0)
        {
            printf("ID Menu: %d  Descripcion: %s   Precio: %.2f\n", arrayMenues[i].codigoMenu, arrayMenues[i].descripcion, arrayMenues[i].importe);
        }
    }
    system("pause");
}

int menu_mostrar2(StMenues arrayMenues[], int CANT)
{
    int contador=0;
    printf("\n\n");
    for (int i=0; i<CANT; i++)
    {
        if(arrayMenues[i].isEmpty==0)
        {
            printf("ID Menu: %d  Descripcion: %s   Precio: %.2f\n", arrayMenues[i].codigoMenu, arrayMenues[i].descripcion, arrayMenues[i].importe);
            contador++;
        }
    }
    system("pause");
    return contador;
}
