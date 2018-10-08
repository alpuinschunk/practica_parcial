#ifndef PELICULAS_INCLUDE_H
#define PELICULAS_INCLUDE_H

typedef struct
{
    int idPelicula;
    char titulo[51];
    int anio;
    char nacionalidad[51];
    //eDirectores director;
    char director[51];
    int isEmpty;

}ePeliculas;

int inicializarPeliculas(ePeliculas* list, int len);
int buscarEspacioLibrePeliculas(ePeliculas list[], int len);
int agregarPeliculas(ePeliculas list[], int len);

int mostrarPeliculas(ePeliculas list[], int len);






#endif // PELICULAS_INCLUDE_H
