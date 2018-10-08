#include <stdio.h>
#include <stdlib.h>
#include "almuerzo.h"
#include "empleados.h"
#include "menu.h"
#define CANTA 2000
#define CANTE 100
#define CANTM 20

int main()
{
    int opcion=0;
    eAlmuerzo almuerzos[CANTA];
    eEmpleado empleado[CANTE];
    eMenu menu[CANTM];
    inicializarAlmuerzo(almuerzos,CANTA);

    do
    {
        system("cls");
        printf("--ABM--\n\n");
        printf("1- Menu\n");
        printf("2- Empleados\n");
        printf("3- Alta almuerzos\n");
        printf("4- Salir\n\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1://MENU COMIDAS
            menuMenus();
            break;
        case 2://MENU EMPLEADOS
            menuEmpleados();
            break;
        case 3:
            agregarAlmuerzo(almuerzos,CANTA,empleado,CANTE,menu,CANTM);
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
