#ifndef DIRECTORES_H_INCLUDED
#define DIRECTORES_H_INCLUDED
typedef struct
{
    int dia, mes, anio;

}eFecha;

typedef struct
{
    char nombre[51];
    eFecha nacimiento;
    char paisOrigen[51];
    int isEmpty;

}eDirectores;

int inicializarDirectores(eDirectores* lista, int len);
int espacioLibreDirectores(eDirectores* lista, int len);
int mostrarUnDirector(eDirectores* lista, int indice);
int mostrarTodasLosDirectores(eDirectores* lista, int len);
int buscarDirectorPorNombre(eDirectores* lista, int len, char nombre[]);
int agregarDirector(eDirectores* lista, int len);
int removerDirector(eDirectores* lista, int len, char nombre[]);

#endif
