#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}StEmpleadoFecha;

typedef struct{
    int legajo;
    char apellido[51];
    char nombre[51];
    char sexo;
    float sueldo;
    StEmpleadoFecha fecha;
    int IDSector;

    int isEmpty;
}StEmpleado;

typedef struct{
    int idSector;
    char descripcion[51];
}StSector;

////////////////////////////////////////////////////////////////////////////////////
/////////////////////       menu    ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Shows the main menu for the ABM program.
*
*/
void menu(void);
void empleado_menu(void);

void empleado_initEmpleados(StEmpleado[], int);
void empleado_initSectores(StSector[]);

int empleado_buscarPorID(StEmpleado [], int, int);
void empleado_funcionPrincipal(StEmpleado[], int, StSector[], int);
int empleado_alta(StEmpleado arrayEmpleados[], int CANT, StSector[], int);
void empleado_modificar(StEmpleado[], int, StSector [], int);
void empleado_menuModificar(StEmpleado [], int, StSector [], int );
int empleado_baja(StEmpleado[], int, StSector[], int);
void empleado_listar(StEmpleado[], int);
void empleado_mostrar(StEmpleado[], int, StSector[]);
int empleado_mostrar2(StEmpleado[], int, StSector[]);

#endif // EMPLEADO_H_INCLUDED
