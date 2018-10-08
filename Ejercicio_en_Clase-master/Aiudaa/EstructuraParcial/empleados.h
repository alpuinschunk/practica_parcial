#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include "fecha.h"
#include "sector.h"

typedef struct
{
    int legajo;//autoincremental
    char apellido[51];//validar
    char nombre[51];//validar
    char sexo;//validar
    float salario; //mayor a cero
    int idSector;
    eFecha fechaIngresoEmpleado;
    int isEmpty;

}eEmpleados; //alta, baja, modificacion

int inicializarEmpleados(eEmpleados* lista, int len);
int buscarLugarLibreEmpleados(eEmpleados* lista, int len);
int menuDeOpciones();
int mostrarUnEmpleado(eEmpleados* lista, int indice);
int buscarEmpleadoPorId(eEmpleados* lista, int len, int id);
int agregarEmpleado(eEmpleados* lista, int len,eSector* sector,int sectorLen);
int mostrarEmpleados(eEmpleados* lista, int len);
int getValiSector(eSector* sectores, int len);

#endif
