#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}StAlmuerzoFecha;

typedef struct{
    int codigoAlmuerzo;
    int codigoMenu;
    int legajoEmpleado;
    StAlmuerzoFecha fecha;

    int isEmpty;
}StAlmuerzo;


void almuerzo_initAlmuerzos(StAlmuerzo[], int);
void almuerzo_menuPrincipal(void);
void almuerzo_funcionPrincipal(StEmpleado [], StSector [], StMenues [], StAlmuerzo [], int , int , int , int );
int almuerzo_alta(StEmpleado [], StSector [], StMenues [], StAlmuerzo [], int , int , int , int );


#endif // ALMUERZO_H_INCLUDED

