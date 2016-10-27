#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "validaciones.h"

int validaCadena(char* buffer, int maxCadena)
{
    int cadValida = 1;
    if( strlen(buffer)> maxCadena || atoi(buffer)< 0 || atoi(buffer)>0)
        {
            cadValida =0;
        }
    return cadValida;
}

int esNumeroYPositivo(char* numero)
{
    int i;
    int retorno=1;

    for(i=0; i< strlen(numero); i++)
    {
        if(!isdigit(numero[i]) || atoi(numero)<0)
        {
            retorno = 0;
        }
    }
    return retorno;
}

void capturarCadena(char* buffer, char* textoError, int tamDeseado)
{
    fflush(stdin);
    gets(buffer);
     while(!validaCadena(buffer, 50))
        {
            printf("%s",textoError);
            fflush(stdin);
            gets(buffer);
        }
}
