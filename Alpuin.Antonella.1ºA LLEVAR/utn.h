#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char str[]) ;
int esNumericoFlotante(char str[]);
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);

int getStringNumerosFlotantes(char mensaje[],char input[]);
int getValidInt(char requestMessage[],int*auxInt, int lowLimit, int hiLimit);

//int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void cleanStdin(void);
int getValidString(char requestMessage[], char *input, int lowLimit, int highLimit);
//void getValidString(char requestMessage[],char errorMessage[], char input[]);
//int getValidFloat(float* input, char requestMessage[],char errorMessage[], float lowLimit, float hiLimit);
int getValidFloat(char requestMessage[],float * input, float lowLimit, float hiLimit);

char getValidSexo(char mensaje[],char*input);
int getValidFecha();

int getStringEsAlfaNumerico(char requesetMenssage[],char *input);
int getValidStringAlfaNumerico(char requestMessage[], char *input, int lowLimit, int highLimit);


#endif
