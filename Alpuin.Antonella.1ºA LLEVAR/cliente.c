#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "cliente.h"

///ISEMPTY = 1 SON AQUELLOS QUE ESTAN LLENOS
static int generarCodigoCliente()
{
    static int codigoCliente=999;
    codigoCliente++;
    return codigoCliente;
}

int inicializarCliente(eCliente* list, int len)
{

    for(int i=0; i<len; i++)
    {
        list[i].isEmpty = 0;
    }

    return 0;
}

int buscarEspacioLibreCliente(eCliente list[], int len)
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

///ALTA CLIENTE
int agregarCliente(eCliente list[], int len)
{

    eCliente nuevoCliente;

    int retorno=-1;
    int indice;

    system("cls");
    printf("  *** Alta Cliente ***\n\n");

    indice = buscarEspacioLibreCliente(list, len);


    if(indice == -1)
    {
        printf("No hay suficiente lugar\n\n");
    }
    else
    {
        getValidString("Ingrese el apellido: ",nuevoCliente.apellido,3,50 );
        getValidString("Ingrese el nombre: ",nuevoCliente.nombre,3,50 );

        getValidSexo("Ingrese el sexo: ",&nuevoCliente.sexo);
        getValidString("Ingrese su domicilio: ",nuevoCliente.domicilio,3,50);

        nuevoCliente.codigoCliente=generarCodigoCliente();//ID
        nuevoCliente.isEmpty=1;
        retorno=0;

        list[indice]=nuevoCliente;

    }
    return retorno;
}

int buscarClientePorCodigo(eCliente list[], int len, int codigoCliente)
{
    int retorno=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].codigoCliente==codigoCliente)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void mostrarCliente(eCliente list/*, eJuegos juego[], int lenJuego*/)
{
    //char descripcion[50];
    //cargarDescripcion(juego,lenJuego,list.codigoJuego,descripcion)
    printf("%d\t%s\t%s\t\t%c\t%s\n\n",list.codigoCliente,list.apellido,list.nombre,list.sexo,list.domicilio/*,descripcion*/);
}

int mostrarClientes(eCliente list[], int len)
{
    printf("CODIGO\tNOMBRE\tAPELLIDO\tSEXO\tDOMICILIO\n\n");//\tJUEGO
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            mostrarCliente(list[i]);
        }
    }
    return 0;
}

///MODIFICAR CLIENTES
int modificarCliente(eCliente list[], int len)
{
    int codigoCliente;
    int retorno=-1;
    int found;
    char modificar;
    int opcion=0;

    system("cls");
    printf("  *** Modificacion Cliente ***\n\n");

    getValidInt("Ingrese el codigo del cliente que desea modificar\n",&codigoCliente,1000,9999999);

    found=buscarClientePorCodigo(list,len,codigoCliente);

    if(found>= 0 && list[found].isEmpty == 1)
    {

        mostrarCliente(list[found]);

        getValidString("¿Esta seguro de que quiere modificar este cliente? s/n\n",&modificar,1,1);

        if(modificar=='s')
        {
            printf("--MENU--\n\n");
            printf("1- Apellido \n");
            printf("2- Nombre \n");
            printf("3- Sexo\n");
            printf("4- Domicilio\n");
            printf("5- Salir\n\n");
            fflush(stdin);
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                getValidString("Ingrese el apellido: \n",list[found].apellido,3,50);
                break;
            case 2:
                getValidString("Ingrese el nombre: \n",list[found].nombre,3,50);
                break;
            case 3:
                getValidSexo("Ingrese el sexo: \n",&list[found].sexo);
                break;
            case 4:
                getValidString("Ingrese su domicilio (sin espacios): ",list[found].domicilio,3,50);
                break;
            case 5:
                opcion=5;
                retorno=0;
                break;
            default:
                printf("Opcion incorrecta: \n");
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
    else
    {
        printf("Cliente no encontrado\n");
    }
    return retorno;
}
///BAJA CLIENTES

int borrarCliente(eCliente list[], int len)
{
    int codigoCliente;
    int found;
    char borrar;

    system("cls");
    printf("  *** Baja Cliente ***\n\n");

    getValidInt("Ingrese el codigo del cliente que desea dar de baja\n",&codigoCliente,1000,9999999);

    found=buscarClientePorCodigo(list,len,codigoCliente);

    if(found>= 0 && list[found].isEmpty == 1)
    {
        mostrarCliente(list[found]);

        getValidString("¿Esta seguro de que quiere dar de baja a este cliente? s/n\n",&borrar,1,1);

        if(borrar=='s')
        {
            list[found].isEmpty=0;
            printf("Cliente dado de baja\n\n");
        }
        else
        {
            printf("Cancelado\n\n");
        }
    }
    else
    {
        printf("Cliente no encontrado\n");
    }
    return -1;
}
///LISTAR CLIENTES
int ordenarClientes(eCliente* list, int len)
{
    eCliente cliente;

    system("cls");
    printf("  ***  Clientes ***\n\n");

    //apellido ascendente y nombre ascendente
    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(strcmp(list[i].apellido,list[j].apellido)>0)
            {
                cliente = list[i];
                list[i] = list[j];
                list[j] = cliente;
            }

            if(strcmp(list[i].apellido,list[j].apellido)==0&&strcmp(list[i].nombre,list[j].nombre)>0)
            {
                cliente = list[i];
                list[i] = list[j];
                list[j] = cliente;
            }

        }
    }

    mostrarClientes(list,len);

    return 0;
}

///MENU CLIENTES
int menuClientes(eCliente cliente[], int len)
{

    int opcion=0;
    int contador=0;

    do
    {
        system("pause");
        system("cls");
        printf("--MENU CLIENTES--\n\n");
        printf("1- ALTA\n");
        printf("2- MODIFICACION\n");
        printf("3- BAJA\n");
        printf("4- LISTAR\n");
        printf("5- SALIR\n\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            agregarCliente(cliente,len);
            contador++;
            break;
        case 2:
            if(contador==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                modificarCliente(cliente,len);
            }
            break;
        case 3:
            if(contador==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                borrarCliente(cliente,len);
            }
            break;
        case 4:
            if(contador==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                ordenarClientes(cliente,len);
            }
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

void harcodearCliente(eCliente y[])
{
    eCliente x[]=
    {
        {15,"Diaz","Roberto",'f',"Yrigoyen 5623",1},
        {26,"Perez","Carlos",'f',"Reano 15",1},
        {30,"Gimenez","Gonzalo",'f',"Fajardo 1594",1},
        {68,"Soria","Ana",'f',"Lopez May 152",1},
        {75,"Baez","Brenda",'f',"General Rojo 15",1}
    };

    for(int i=0; i<5; i++)
    {
        y[i] = x[i];
    }
}
