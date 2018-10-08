#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED
#include "directores.h"

typedef struct
{
    int id;
    char titulo[51];
    int anio;
    char nacionalidad[51];
    char nombreDirector[51]; //Unir con los directores
    int isEmpty;

}ePeliculas;


int inicializarPeliculas(ePeliculas* lista, int tam);

int menuDeOpciones();

int espacioLibrePeliculas(ePeliculas* lista, int tam);

int buscarPeliculaPorId(ePeliculas* lista, int tam, int id);

int agregarPelicula(ePeliculas* lista, int len, eDirectores* listaDirector, int lenDirector);

int mostrarUnaPelicula(ePeliculas* lista, int indice);

int removerPelicula(ePeliculas* lista, int tam, int id);

int mostrarTodasLasPeliculas(ePeliculas* lista, int len);

int modificarPeliculas(ePeliculas* lista,int len,  int id, eDirectores* listaDirector, int lenDirector);

int opcionesInformar(ePeliculas* lista,int len,eDirectores* listaDirector, int lenDirector);
#endif
