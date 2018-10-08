#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

typedef struct
{
    int id; //codigo menu autoincremental
    char descripcion[51];// validar
    int importe; //debe ser mayot a cero
    //int isEmpty;
}eMenu; // alta, baja, modificacion

#endif
