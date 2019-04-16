#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployee.h"
#define TAM 3
#define VACIO 0
#define OCUPADO 1


/** \brief solicita mje al usuario para el ingrese de un dato tipo flotante..
 *
 * \param Mensaje a ser mostrado al usuario.
 * \param //
 * \return el numero ingresado por el usuario.
 *
 */


float getFloat(char msj[])
{
    float aux;
    printf("%s",msj);
    scanf("%f",&aux);
    return aux;
}

/** \brief solicita mje al usuario para el ingrese de un dato tipo entero.
 *
 * \param Mensaje a ser mostrado al usuario.
 * \param //
 * \return el numero ingresado por el usuario.
 *
 */

int getInt(char msj[] )
{
    int resultado;
    printf("%s",msj);
    scanf("%d",&resultado);
    return resultado;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */

char getChar(char msj[])
{
    char aux;
    printf("%s",msj);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */


int soloNumero(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9')&&(str[i]!='.')&&(str[i]!=',')&&(str[i]!=NULL)&&(str[i]!=' '))
            return 0;
        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int soloLetras(char str[])
{
    int i=0;
    int retorno = 1;
    if(str[i] == '\0')
        retorno = 0;
    else
    {
        while(str[i] != '\0')
        {
            if(  (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return no tiene retorno.
 */

void getString (char msj[],char input[])
{
    printf("%s",msj);
    fflush(stdin) ;
    gets(input) ;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */

int getStringLetras(char msj[],char input[])
{
    char aux[256];
    getString(msj,aux);
    if(soloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0 ;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */

int getStringNumeros(char msj[],char input[])
{
    char aux[256];
    getString(msj,aux);
    if(soloNumero(aux))
    {
        strcpy(input,aux);

        return 1;
    }
    return 0;
}

int menu()
{
    int opcion;
    char opcionAux[5];

    system("cls");
    printf("\n ***** MENU DE OPCIONES : Nomina Empleados *****\n\n");
    printf(" 1- Alta\n");
    printf(" 2- Modificar\n");
    printf(" 3- Baja\n");
    printf(" 4- Informes \n");
    printf(" 5- Listar \n");
    printf(" 6- Salir\n\n");

    while(!getStringNumeros("Ingrese una opcion: ", opcionAux))

    {
            printf("Error! Ingrese una opcion correcta.\n\n");
            system("pause");
            fflush(stdin);
    }
    opcion=atoi(opcionAux);
    if(opcion<1 || opcion>6)
    {
        printf("Error! Ingrese una opcion correcta.\n\n");
        system("pause");
        fflush(stdin);
    }
    return opcion;

}


/** \brief inicializa todas el array 1 que indica vacio.
 *
 * \param estructura de empleados.
 * \param cantidad de datos del sistema.
 * \return no retorna valor.
 *
 */

void initEmployees ( eEmployee employee [], int len)
{
    for (int i=0 ; i< len; i++)
    {
        employee[i].isEmpty= VACIO;
    }
}



void hardCodearEmpleado ( eEmployee employee[], int len  )
{

    eEmployee employee1[]= {
        {1, "Juan"  , "Perez"  , 30000, 3,1 },
        {2, "Maria", "Esquivel", 10000, 3,1 },
        {3, "Pedro", "Martinez", 15000, 2,1 },
    };

     for (int i=0; i<len; i++ )
     {
         employee[i]=employee1[i];

     }


}


void printOneEmployee ( eEmployee employee)
{

   printf( " %d      %s          %s          %0.2f        %d\n  ", employee.id, employee.name, employee.lastName, employee.salary, employee.sector );

}


int printEmployees ( eEmployee employee [] , int len)
{

    printf( "LEGAJO      NOMBRE       APELLIDO     SALRIO     SECTOR \n ");
    for (int i=0; i < len; i++)
    {
       if (employee[i].isEmpty== OCUPADO)
        {
             printOneEmployee(employee[i]);
        }

    }

}


