#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "empleados.h"
#define CANTE 100



static int generarNextId()
{
    static int idEmpleado=999;
    idEmpleado++;
    return idEmpleado;
}

int inicializarEmpleado(eEmpleado* list, int len)
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

int buscarEspacioLibreEmpleado(eEmpleado list[], int len)
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

///ALTA EMPLEADO
int agregarEmpleado(eEmpleado list[], int len,eSector sectores[], int lenSector)
{

    eEmpleado nuevoEmpleado;

    int retorno=-1;
    int indice;

    system("cls");
    printf("  *** Alta Empleado ***\n\n");

    indice = buscarEspacioLibreEmpleado(list, len);


    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        getValidString("Ingrese el apellido: ",nuevoEmpleado.apellido,3,50 );
        getValidString("Ingrese el nombre: ",nuevoEmpleado.nombre,3,50 );

        getValidSexo("Ingrese el sexo: ",&nuevoEmpleado.sexo);
        getValidFloat("Ingrese el salario: ",&nuevoEmpleado.sueldo,0,100000);

        getValidInt("Ingrese la fecha de ingreso a la empresa\nAnio: ",&nuevoEmpleado.fechaIngreso.anio,1900,2018);
        getValidInt("Mes: ",&nuevoEmpleado.fechaIngreso.mes,1,12);
        getValidInt("Dia: ",&nuevoEmpleado.fechaIngreso.dia,1,31);


        nuevoEmpleado.idSector=elegirSector(sectores,5);
        nuevoEmpleado.idEmpleado=generarNextId();//ID
        nuevoEmpleado.isEmpty=0;
        retorno=0;

        list[indice]=nuevoEmpleado;

    }
    return retorno;
}


int buscarEmpleadoPorId(eEmpleado list[], int len, int idEmpleado)
{
    int retorno=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].idEmpleado==idEmpleado)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void mostrarEmpleado(eEmpleado list, eSector sectores[], int lenSector)
{
    char descripcion[20];
    cargarDescripcion(sectores,lenSector,list.idSector,descripcion);
    printf("%d\t%s\t%s\t\t%c\t%.2f\t%d/%d/%d\t%s\n\n",list.idEmpleado,list.nombre,list.apellido,list.sexo,list.sueldo,list.fechaIngreso.dia,list.fechaIngreso.mes,list.fechaIngreso.anio,descripcion);
}

int mostrarEmpleados(eEmpleado list[], int len, eSector sectores[], int lenSector)
{
    printf("ID\tNOMBRE\tAPELLIDO\tSEXO\tSUELDO\t\tFECHA INGRESO\t SECTOR\n\n");
    for(int i=0; i<len; i++)
    {
        if(!list[i].isEmpty)
        {
            mostrarEmpleado(list[i],sectores,lenSector);
        }
    }
    return 0;
}


///BAJA MENU
int borrarEmpleado(eEmpleado list[], int len,eSector sectores[], int lenSector)
{

    int idEmpleado;
    int found;
    char borrar;

    system("cls");
    printf("  *** Baja Empleado ***\n\n");

    getValidInt("Ingrese el ID del empleado que desea dar de baja\n",&idEmpleado,1000,9999999);

    found=buscarEmpleadoPorId(list,len,idEmpleado);

    if(found==-1)
    {
        printf("Empleado no encontrado\n");
    }
    else
    {
        mostrarEmpleado(list[found],sectores,lenSector);

        getValidString("¿Esta seguro de que quiere dar de baja a este empleado? s/n\n",&borrar,1,1);

        if(borrar=='s')
        {
            list[found].isEmpty=1;
            printf("Empleado dado de baja\n\n");
        }
        else
        {
            printf("Cancelado\n\n");
        }
    }
    return -1;
}
///MODIFICACION EMPLEADO
int modificarEmpleado(eEmpleado list[], int len,eSector sectores[], int lenSector)
{
    eEmpleado empleadoModificado;
    int idEmpleado;
    int retorno=-1;
    int found;
    char modificar;

    system("cls");
    printf("  *** Modificacion Empleado ***\n\n");

    getValidInt("Ingrese el ID del empleado que desea modificar\n",&idEmpleado,1000,9999999);

    found=buscarEmpleadoPorId(list,len,idEmpleado);

    if(found == -1)
    {
        printf("Empleado no encontrado\n");
    }
    else
    {
        mostrarEmpleado(list[found], sectores, lenSector);

        getValidString("¿Esta seguro de que quiere modificar este empleado? s/n\n",&modificar,1,1);

        if(modificar=='s')
        {
            int opcion=0;
            printf("--MENU--\n\n");
            printf("1- Apellido \n");
            printf("2- Nombre \n");
            printf("3- Sexo\n");
            printf("4- Sueldo\n");
            printf("5- Fecha de ingreso\n");
            printf("6- Sector\n");
            printf("7- Salir\n\n");
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
                getValidFloat("Ingrese el sueldo: \n",&list[found].sueldo,1,999999);
                break;
            case 5://fecha de ingreso
                getValidInt("Ingrese la fecha de ingreso\nAnio: ",&empleadoModificado.fechaIngreso.anio,1900,2018);
                getValidInt("Mes: \n",&empleadoModificado.fechaIngreso.mes,1,12);
                getValidInt("Dia: \n",&empleadoModificado.fechaIngreso.dia,1,31);
                break;
            case 6://sector

                break;
            case 7:
                opcion=7;
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

int ordenarEmpleado(eEmpleado* list, int len,eSector sectores[], int lenSector)
{
    eEmpleado empleado;

    system("cls");
    printf("  ***  Empleados ***\n\n");
    ///apellido ascendente y nombre ascendente
    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(strcmp(list[i].apellido,list[j].apellido)>0)
            {
                empleado = list[i];
                list[i] = list[j];
                list[j] = empleado;
            }

            if(strcmp(list[i].apellido,list[j].apellido)==0&&strcmp(list[i].nombre,list[j].nombre)>0)
            {
                empleado = list[i];
                list[i] = list[j];
                list[j] = empleado;
            }

        }
    }

    mostrarEmpleados(list,len,sectores, lenSector);

    return 0;

}
///SECTORES
int elegirSector(eSector sectores[], int len)
{

    int idSector;
    printf("\nSectores\n\n");
    for(int i=0; i < len; i++)
    {
        printf("%d %s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);
    return idSector;
}
void cargarDescripcion(eSector sectores[], int lenSector, int idSector, char cadena[])
{

    for(int i=0; i < lenSector; i++)
    {
        if( sectores[i].id == idSector)
        {
            strcpy(cadena, sectores[i].descripcion);
            break;
        }
    }
}
/*void harcodearEmpleados(eEmpleado x[])
{

    eEmpleado y[]=
    {
        {1111,"medina" ,"ana", 'f', 15000, 12,10,1998,5},
        {3333,"diaz" ,"luis", 'm', 25000,13,12,1965 ,4},
        {4444,"rosas" ,"alberto", 'm', 10000,19,9,2004 ,5},
        {5555, "rogelia","julia", 'f', 30000,15,4,1978 ,1},
        {1313,"mamona" ,"julieta", 'f', 23000,21,8,1999, 2},
        {4545,"prama" ,"andrea", 'f', 31000,26,1,1972 ,5},
        {3232,"monro" ,"mauro", 'm', 27000,17,6,1962 ,5},
    };

    for(int i=0; i<7; i++)
    {
        x[i] = y[i];
    }

}*/
///ABM EMPLEADOS
int menuEmpleados()
{
    eSector sectores[] =
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };

    int opcionEmpleado=0;
    int contadorEmpleado=0;
    eEmpleado empleado[CANTE];
    inicializarEmpleado(empleado,CANTE);
    //harcodearEmpleados(empleado);

    do
    {
        system("pause");
        system("cls");
        printf("--MENU EMPLEADOS--\n\n");
        printf("1- ALTA\n");
        printf("2- MODIFICACION\n");
        printf("3- BAJA\n");
        printf("4- LISTAR\n");
        printf("5- SALIR\n\n");
        fflush(stdin);
        scanf("%d",&opcionEmpleado);

        switch(opcionEmpleado)
        {
        case 1:
            agregarEmpleado(empleado,CANTE,sectores,5);
            contadorEmpleado++;
            break;
        case 2:
            if(contadorEmpleado==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                modificarEmpleado(empleado,CANTE,sectores,5);
            }
            break;
        case 3:
            if(contadorEmpleado==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                borrarEmpleado(empleado,CANTE,sectores,5);
            }
            break;
        case 4:
            if(contadorEmpleado==0)
            {
                printf("No hay datos ingresados\n");
            }
            else
            {
                ordenarEmpleado(empleado,CANTE,sectores,5);
            }
            break;
        case 5:
            printf("Saliendo..\n\n");
            opcionEmpleado=5;
            system("pause");
            break;
        default:
            printf("Opcion incorrecta\n\n");
            break;
        }

    }
    while(opcionEmpleado!=5);
    return 2;
}

