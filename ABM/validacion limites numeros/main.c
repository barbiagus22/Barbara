#include <stdio.h>
#include <stdlib.h>

int getStringNumeros_limites(int numero, int limm, int limmax);




int main()
{



     while(!getStringNumeros_limites("\nIngrese salario del empleado: \n",0,100000000000));






    return 0;
}
/*
int getStringNumeros(char mensaje[],char input[])
{


    char aux[256];
    getString(mensaje,aux);


    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    else
    {
        printf("Error, ingrese solo numeros.");
    }




    return 0;
}*/


int getStringNumeros_limites(int numero, int limm, int limmax)
{
    if(numero<=0)
    {
        printf("El importe debe ser mayot a 0");
    }


    return 0;
}




