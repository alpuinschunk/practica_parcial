#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "utn.h"

////////////////////////////////////////////////////////////////////////////////////
///////////////////////////        getInt      /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Gets a integer value from the user.
*
*\param int* input a pointer to the number in question.
*\param char condition[] message displaying the valid input conditions to the user
*\param char error[] error message displayed in case of not fulfilling the estated conditions
*\param int rangeMinimum minimum range of value
*\param int rangeMaximum maximum range of value
*\return status -1 if conditions are not fulfilled, 1 if is everything ok
*
*/

int getInt(int* input, char condition[], char error[], int rangeMinimum, int rangeMaximum)
{
    system("cls");
    char stringAux[32001];
    char check;
    int numberCheck;
    int length;
    int status;

    printf(condition);
    fgets(stringAux, sizeof(stringAux), stdin);
    length = strlen(stringAux);
    stringAux[length-1]='\0';

    for(int i=0; i<length-1; i++)
    {
        check = stringAux[i];
        if(!(check >= '0' && check <= '9'))
        {
            printf(error);
            system("pause");
            status = -1;
            break;
        }else
        {
            numberCheck = atoi(stringAux);
            if(numberCheck>=rangeMinimum && numberCheck<=rangeMaximum)
            {
                *input = numberCheck;
                status = 1;
                break;
            }else
            {
                printf(error);
                system("pause");
                break;
            }
        }
    }
    return status;
}

////////////////////////////////////////////////////////////////////////////////////
///////////////////////////        getFloat    /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Gets a floating value from the user.
*
*\param float* input a pointer to the number in question.
*\param char condition[] message displaying the valid input conditions to the user
*\param char error[] error message displayed in case of not fulfilling the estated conditions
*\param int rangeMinimum minimum range of value
*\param int rangeMaximum maximum range of value
*\return status -1 if conditions are not fulfilled, 1 if is everything ok
*
*/

int getFloat(float* input, char condition[], char error[], int rangeMinimum, int rangeMaximum)
{
    char stringAux[32001];
    char check;
    int pointCheck=0;
    float numberCheck;
    int length;
    int status;

    printf(condition);
    fgets(stringAux, sizeof(stringAux), stdin);
    length = strlen(stringAux);
    stringAux[length-1]='\0';

    for(int i=0; i<length-1; i++)
    {
        check = stringAux[i];
        if(check=='.')
        {
            pointCheck++;
        }
    }

    for(int i=0; i<length-1; i++)
    {
        check = stringAux[i];
        if(!( (check >= '0' && check <= '9') && pointCheck<=1))
        {
            printf(error);
            system("pause");
            status = -1;
            break;
        }else
        {
            numberCheck = atof(stringAux);
            if(numberCheck>=rangeMinimum && numberCheck<=rangeMaximum)
            {
                *input = numberCheck;
                status = 1;
                break;
            }else
            {
                printf(error);
                system("pause");
            }
        }
    }
    return status;
}

////////////////////////////////////////////////////////////////////////////////////
///////////////////////////        getChar     /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Gets a character from the user.
*
*\param char* input a pointer to the character in question.
*\param char condition[] message displaying the valid input conditions to the user
*\param char error[] error message displayed in case of not fulfilling the estated conditions
*\param int rangeMinimum minimum range of value
*\param int rangeMaximum maximum range of value
*\return status -1 if conditions are not fulfilled, 1 if is everything ok
*
*/

int getChar(char* input, char condition[], char error[], int rangeMinimum, int rangeMaximum)
{
    int status;
    char aux;

    printf(condition);
    aux = getchar();

    if(!(aux>='a' && aux<='z'))
    {
        printf(error);
        system("pause");
        status = -1;
    }else{
        *input = aux;
        status = 1;
    }
    return status;
}


////////////////////////////////////////////////////////////////////////////////////
///////////////////////////        getString     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Gets a string from the user.
*
*\param char input a pointer to the string in question.
*\param char condition[] message displaying the valid input conditions to the user
*\param char error[] error message displayed in case of not fulfilling the estated conditions
*\param int rangeMinimum minimum range of value
*\param int rangeMaximum maximum range of value
*\return status -1 if conditions are not fulfilled, 1 if is everything ok
*
*/

int getString(char input[], char condition[], char error[], int rangeMinimum, int rangeMaximum)
{
    char stringAux[32001];
    int length, status;

    printf(condition);
    fgets(stringAux, sizeof(stringAux), stdin);
    length = strlen(stringAux);

    if(length>=rangeMaximum || length<rangeMinimum || strcmp(stringAux, "\n\0")==0)
    {
        printf(error);
        system("pause");
        status = -1;
    }else{
        stringAux[length-1]='\0';
        strcpy(input, stringAux);
        status = 1;
    }
    return status;
}
