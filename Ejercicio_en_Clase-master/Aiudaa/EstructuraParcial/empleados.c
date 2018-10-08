#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "utn.h"

static int generarNextId() //Genero un unico id por cada empleado que se ingresa
{
    static int id = 0;

    id ++;

    return id;
}

int inicializarEmpleados(eEmpleados* lista, int len)
{
    int i;
    int retorno=-1;

    if(lista !=NULL)
    {
        for(i=0; i<len ; i ++)
        {
            lista[i].isEmpty=1;

        }
        retorno = 0;

    }

    return retorno;

}

int buscarLugarLibreEmpleados(eEmpleados* lista, int len)
{
    int i;
    int retorno=-1;

    if(lista !=NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(lista[i].isEmpty==1)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int menuDeOpciones() //Agregar mas opciones

{
    int opcion;
    //system("cls");
    printf("-----Menu de opciones-----\n\n");
    printf("1. Alta empleado \n");
    printf("2. Modificar empleado \n");
    printf("3. Baja empleado\n");
    printf("4. Informar empleado\n");
    printf("5. Salir\n");
    printf("Elija una opcion:\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int mostrarUnEmpleado(eEmpleados* lista, int indice)
{
    int retorno=-1;
    if(lista!= NULL)
    {
        printf("%d   %d    %s    %s     %c     %f    %d    %d    %d   %d \n  ", lista[indice].idSector, lista[indice].legajo, lista[indice].apellido, lista[indice].nombre, lista[indice].sexo, lista[indice].salario, lista[indice].fechaIngresoEmpleado.dia, lista[indice].fechaIngresoEmpleado.mes, lista[indice].fechaIngresoEmpleado.anio, lista[indice].idSector);
        retorno=0;
    }

    return retorno;
}

int mostrarEmpleados(eEmpleados* lista, int len)
{
    int i;
    int retorno=-1;
    if(lista!= NULL)
    {
        for( i = 0; i<len ; i++)
        {
            mostrarUnEmpleado(lista, i);
        }
        retorno=0;
    }
    return retorno;
}

int buscarEmpleadoPorId(eEmpleados* lista, int len, int id)
{
    int i;
    int retorno=-1;
    if(lista!= NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(lista[i].legajo == id && lista[i].isEmpty == 0 )
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int agregarEmpleado(eEmpleados* lista, int len, eSector *sector,int sectorLen)
{
    eEmpleados auxiliarEmpleados;
    int lugarLibre=buscarLugarLibreEmpleados(lista, len);
    int retorno=-1;

    if(lista!=NULL)
    {
        if(lugarLibre != -1)
        {

            getValidString("Ingrese apellido : ", "Error, no valido.", auxiliarEmpleados.apellido);
            getValidString("Ingrese nombre: ","Error, no valido.", auxiliarEmpleados.nombre);

            printf("Ingrese sexo : \n");
            fflush(stdin);
            scanf("%c",&auxiliarEmpleados.sexo);

            auxiliarEmpleados.salario = getValidFloat("Ingrese salario: ","Error, no valido.", 0, 1000000);

            auxiliarEmpleados.fechaIngresoEmpleado.dia = getValidInt("Ingrese dia ingreso: ","Error, no valido.", 1, 30);
            auxiliarEmpleados.fechaIngresoEmpleado.mes = getValidInt("Ingrese dia mes: ","Error, no valido.", 1, 12);
            auxiliarEmpleados.fechaIngresoEmpleado.anio = getValidInt("Ingrese dia anio: ","Error, no valido.", 2000, 2018);
            auxiliarEmpleados.idSector = getValiSector(sector , sectorLen);
            auxiliarEmpleados.legajo = generarNextId();
            auxiliarEmpleados.isEmpty =0;
            lista[lugarLibre]=auxiliarEmpleados;
        }
        else
        {
            printf("No hay lugar libre\n");
            system("pause");
            system("cls");
        }

        retorno=0;

    }

    return retorno;
}

int getValiSector(eSector* sectores, int len){

    int retorno = -1;
    int i,id;
    char continuar;
    do{
        printf("Ingrese el id del sector: ");
        scanf("%d",&id);
        for( i=0; i<len;i++){
            if(sectores[i].id == id){
                retorno = id;
                continuar = 'n';
                break;
            }
        }
        if(i == len){
            fflush(stdin);
            printf("Id no encontrado! Desea continuar? s/n");
            scanf("%c",&continuar);
        }
    }while(continuar == 's');
    return retorno;
}

