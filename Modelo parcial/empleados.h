#ifndef EMPLEADOS_INCLUDE_H
#define EMPLEADOS_INCLUDE_H

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idEmpleado;
    char apellido[51];
    char nombre[51];
    char sexo;
    float sueldo;
    int idSector;
    eFecha fechaIngreso;
    int isEmpty;
} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];
    int isEmpty;
} eSector;

int inicializarEmpleado(eEmpleado* list, int len);
int buscarEspacioLibreEmpleado(eEmpleado list[], int len);
int agregarEmpleado(eEmpleado list[], int len,eSector sectores[], int lenSector);

void mostrarEmpleado(eEmpleado list, eSector sectores[], int tamSector);

int buscarEmpleadoPorId(eEmpleado list[], int len, int idEmpleado);
int mostrarEmpleados(eEmpleado list[], int len, eSector sectores[], int lenSector);
int borrarEmpleado(eEmpleado list[], int len,eSector sectores[], int lenSector);
int modificarEmpleado(eEmpleado list[], int len,eSector sectores[], int lenSector);
int ordenarEmpleado(eEmpleado* list, int len,eSector sectores[], int lenSector);

int elegirSector(eSector sectores[], int len);
void cargarDescripcion(eSector sectores[], int lenSector, int idSector, char cadena[]);
void harcodearEmpleados(eEmpleado x[]);

int menuEmpleados();



#endif // EMPLEADOS_INCLUDE_H
