#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

typedef struct{
    int codigoMenu;
    char descripcion[51];
    float importe;

    int isEmpty;
}StMenues;

void menu_menuPrincipal(void);
void menu_menuModificar(StMenues [], int);
void menu_initMenues(StMenues [], int);
int menu_buscarPorID(StMenues[], int, int);
void menu_funcionPrincipal(StMenues [], int);
int menu_alta(StMenues [], int);
void menu_modificar(StMenues [], int);
int menu_baja(StMenues [], int);
void menu_listar(StMenues [], int);
void menu_mostrar(StMenues [], int);
int menu_mostrar2(StMenues [], int);

#endif // MENUES_H_INCLUDED
