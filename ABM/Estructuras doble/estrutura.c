#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"estrutura.h"
#define TAM 4
#define OCUPADO 0
#define VACIO 1


int menu()
{
    int opcion;
    char opcionAux[6];

    system("cls");
    printf("\n ***** MENU DE OPCIONES : ALTA DE JUEGOS *****\n\n");
    printf(" 1- Alta\n");
    printf(" 2- Modificar\n");
    printf(" 3- Baja\n");
    printf(" 4- Listar\n");
    printf(" 5- Salir\n\n");


    while(!getStringNumeros("Ingrese opcion: ",opcionAux));

    opcion=atoi(opcionAux);
    printf("%d", opcion);

    if(opcion< 1 || opcion> 5)
    {
        printf("\n Error! Ingrese opcion correcta.\n\n");
        system("pause");
        fflush(stdin);
    }

    return opcion;
}


void inicializarJuegos (sJuegos juegos[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        juegos[i].isEmpty = 1;
    }
}

int buscarLibre(sJuegos juegos[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( juegos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


sJuegos altaUnJuego (int codJuegos)

{
    sJuegos altaJuego;

    char descripcionAux [51];
    char importeAux[30];


    system("cls");

    printf("\n ****  ALTA DE JUEGOS  **** \n\n");

    printf("Codigo de Juego : %d \n",codJuegos );

    while(!getStringLetras("\n Ingrese nombre del juego:  ",descripcionAux));
    while(!getStringNumeros("\nIngrese importe del juego:  ",importeAux));

    strcpy( altaJuego.descripcion,descripcionAux) ;

    altaJuego.importe =atof(importeAux);

    while(altaJuego.importe<=0 )

    {
        printf("\n El importe debe ser mayor a 0 \n");
        while(!getStringNumeros("\nIngrese importe del juego:  ",importeAux));
        if (altaJuego.importe<=0)
        {
            altaJuego.importe =atof(importeAux);
            break;
        }
    }


    return altaJuego;


}


void altadeJuegos ( sJuegos juego [], int tam, int codJuegos)

{

    int indice;

    system("cls");
    printf(" **** ALTA DE JUEGOS **** \n\n");

    indice = buscarLibre(juego, tam);

    if (indice == -1 )
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }

    else
    {
        juego[indice] = altaUnJuego(codJuegos);
        juego[indice].codJuegos= codJuegos;
        juego[indice].isEmpty=OCUPADO;
        system("pause");

    }

}

void listarUnjuego (sJuegos  juego)

{
    printf("\n\t\%d\t\t\t\%s\t\t\t\%2.f\t\t\t\n ", juego.codJuegos,juego.descripcion, juego.importe);

}

void listarjuegos (sJuegos juego [], int tam)
{
    system("cls");
    printf("\n  ******  LISTA DE JUEGOS  ****** \n\n");

    printf("\n\t\COD. DE JUEGO\t\t\ NOMBRE\t\t\t\ IMPORTE\t\t\t\n");

    for (int i=0; i<tam ; i++)
    {

        if( juego[i].isEmpty == OCUPADO)
        {
            listarUnjuego(juego[i]);
        }

    }
    system("pause");
}

int buscarJuego( sJuegos juego [], int tam, int codJuegos)

{
    int indice= -1 ;

    for (int i=0 ; i<tam ; i++)
    {
        if ( juego[i].codJuegos ==codJuegos && juego[i].isEmpty== OCUPADO)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void bajadeJuego (sJuegos juego [], int tam)
{

    int codJuegos;
    int indice;
    char confirma;
    char codJuegosAux[20];

    system("cls");
    printf("\n ******  BAJA DE JUEGOS  ****** \n");

    while(!getStringNumeros("\n Ingrese CODIGO DE JUEGO a dar de BAJA :  ", codJuegosAux) );
    codJuegos= atoi(codJuegosAux);

    indice = buscarJuego(juego, tam, codJuegos);
    if( indice == -1)
    {
        printf("\n ERROR, No hay juego con ese codigo:  %d \n\n", codJuegos);
        system("pause");
    }
    else
    {
        printf("\n\t\COD. DE JUEGO\t\t\ NOMBRE\t\t\t\ IMPORTE\t\t\t\n");
        listarUnjuego(juego[indice]);
        printf(" \n\n");

        printf("\n Confirma la BAJA ? s=SI n = NO :  \n\n");
        fflush (stdin);
        scanf("%c", &confirma);

        if (confirma== 's')
        {
            juego[indice].isEmpty = 1;
            printf(" \n\n BAJA EFECTUADA \n\n");
        }
        else
        {
            printf("\n\n BAJA CANCELADA \n\n");
        }
    }
}


void modificarJuegos (sJuegos juego [], int tam)
{
    int codJuego;
    int indice;
    int opcion;
    char confirma;
    char descripionAux[51];
    char importeAux[30];
    char codJuegoAux[10];

    system("cls");
    printf("\n ******  MODIFICACION DE JUEGOS  ****** \n");

    while(!getStringNumeros("\n Ingrese CODIGO DE JUEGO a modificar:  ", codJuegoAux));

    codJuego= atoi(codJuegoAux);

    indice = buscarJuego(juego, tam, codJuego);
    if( indice == -1)
    {
        printf("ERROR, No hay juego con ese codigo:  %d \n\n", codJuego);
        system("pause");
    }
    else
    {
        printf("\n\t\COD. DE JUEGO\t\t\ NOMBRE\t\t\t\ IMPORTE\t\t\t\n");
        listarUnjuego(juego[indice]);
        printf(" \n\n");

        confirma =getChar("\n Desea MODIFICAR ? s=SI  n= NO :  ");
        while (confirma!= 's' || confirma != 'm')                                     ///valida que sea s o no
        {
            confirma =getChar("\n Error! Ingrese s=SI  n= NO  para modificar :  ");
            if (confirma == 's' || confirma== 'n')
            {
                break;
            }

        }

        if (confirma== 's')
        {
            printf(" \n Que desea modificar ? \n\n");
            printf("1. Nombre del juego \n\n");
            printf("2. Importe del juego \n\n");
            //printf("3. Salario \n\n");
            //printf("4. Sector \n\n");
            printf("Ingrese opcion: ");
            scanf("%d", &opcion);

            switch (opcion)
            {

            case 1:
                system("cls");

                while( !getStringLetras("\nInsegre nuevo nombre: \n",descripionAux));
                strcpy(juego[indice].descripcion,descripionAux);
                printf("\nModificacion Realizada\n\n");
                break;
            case 2:
                system("cls");

                while(!getStringNumeros ("\nIngrese nuevo importe: \n", importeAux));
                juego[indice].importe= atof(importeAux);

                while(juego[indice].importe<=0 )// VALLIDAR QUE SEA MAYOR A UN NUMERO Y COPIARLO EN EL VALOR DE LA ESTRUCTURA.

                {
                    printf("\n El importe debe ser mayor a 0 \n");
                    while(!getStringNumeros("\nIngrese importe del juego:  ",importeAux));
                    if (juego[indice].importe<=0)
                    {
                        juego[indice].importe =atof(importeAux);
                        break;
                    }
                }

                printf("Modificacion Realizada\n\n");
                break;
            default:
                printf("No es una opcion valida");
                break;
            }
        }
        else
        {
            printf("\n\n Modificacion Cancelada\n\n");
        }


    }

}


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
    while(str[i] != '\0' || str[i]!= NULL )
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





