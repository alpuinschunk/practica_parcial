#ifndef DIRECTORES_INCLUDE_H
#define DIRECTORES_INCLUDE_H

typedef struct
{
    int anio;
    int mes;
    int dia;
}eFecha;

typedef struct
{
    char nombre[51];
    eFecha fecha;
    char nacionalidad[51];
    int isEmpty;
}eDirectores;

int inicializarDirectores(eDirectores* list, int len);
int buscarEspacioLibreDirectores(eDirectores list[], int len);
int agregarDirectores(eDirectores list[], int len);

int mostrarDirectores(eDirectores list[], int len);




#endif // DIRECTORES_INCLUDE_H
