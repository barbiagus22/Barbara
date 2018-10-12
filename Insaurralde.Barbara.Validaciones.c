#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Insaurralde.Barbara.Validaciones.h"
#include"Insaurralde.Barbara.Juegos.h"
#include"Insaurralde.Barbara.Clientes.h"
#include"Insaurralde.Barbara.Alquileres.h"
#include"Insaurralde.Barbara.1G.Informes.h"



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


int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
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
        while(str[i] != '\0'  )
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

    if (msj != NULL)
    {
        if(soloLetras(aux))
        {
            strcpy(input,aux);
            return 1;
        }
        else
        {
            printf("\nError!, ingrese solo letras.\n");
        }
    }
    return 0 ;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */

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
}

/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */

int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if( (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }

    return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */

int validarTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1)
        return 1;

    return 0;
}

/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */

int getStringtelefono(char mensaje[],char input[])
{
    char aux[256];

    getString(mensaje,aux);
    if(validarTelefono(aux))
    {

        strcpy(input,aux);
        return 1;
    }




    return 0;
}

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int validarNumeroFlotante(char str[])
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
*/

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(validarNumeroFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/** \brief funcio que valida el ingreso de sexo f o m
 *
 * \param el mensaje al usuario
 * \param donde se copiara el dato
 * \return no tiene retrono.
 *
 */


void function_continueform(char msj[],char input[])
{
    do
    {
        if(!function_getStringLetras(msj,input))

        {
            printf("*** ERROR *** Debe ingresar la letra F o M");
            system("pause");
            system("cls");
        }

    }
    while(!(input[0] == 'f' || input[0] == 'm' || input[0] == 'F' || input[0] == 'M'));

}

/** \brief se validad que se ingresen solo letras
 *
 * \param el mensaje al usuario
 * \param donde se copiara el dato.
 * \return retorna si es solo letras 1 sino 0.
 *
 */


int function_getStringLetras(char msj[],char input[])
{
    int ret = 0;
    char aux[256];
    getString(msj,aux);
    if(function_esSoloLetras(aux))
    {
        strcpy(input,aux);
        ret = 1;
    }
    return ret ;
}

/** \brief se ingresa un texto y valida que todos los elementos sean letras.
 *
 * \param
 * \param
 * \return retorno 1 o 0 sino se valido correcta o incorrectamente.
 *
 */

int function_esSoloLetras(char str[])
{
    int ret = 1;
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))

            ret = 0;
        i++;
    }
    return ret;
}



