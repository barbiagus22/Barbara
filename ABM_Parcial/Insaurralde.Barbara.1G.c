#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define OCUPADO 0
#define VACIO 1
#include "Insaurralde.Barbara.1G.h"



/** \brief creacion de funcion basica menu.
 *
 * \param
 * \param
 * \return
 *
 */

int menu()
{
    int opcion;
    char opcionAux[6];

    system("cls");
    printf("\n ***** MENU DE OPCIONES : ALTA DE CLIENTES *****\n\n");
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


void harcodearJuegos(sJuegos juegos[])
{

    sJuegos x[]=
    {

        {1111, "fifa", 23000,1},
        {2222, "pes", 23000,1},
        {1234, "batalla naval", 23000,1},
        {5643, "juego de la oca", 23000,1},

    };

    for(int i=0; i < 8; i++)
    {

        juegos[i] = x[i];
    }




}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void harcodearCategorias( sCategoria categorias[])
{

    sCategoria x[]=
    {

        {100, "mesa"},
        {101, "azar"},
        {102, "estrategia"},
        {103, "salon"},
        {104, "magia"},


    };

    for(int i=0; i < 8; i++)
    {

        categorias[i] = x[i];
    }




}







void inicializarClientes (sClientes clientes[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        clientes[i].isEmpty = 1;
    }
}


int buscarEspacioClientes(sClientes clientes[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( clientes[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



sClientes altacliente (int codigoCliente)
{

    sClientes unCliente;


    char nameAux [51];
   char sexoAux [10];
   char telefonoAux[21];


    system("cls");

    printf("\n ****  ALTA DE CLIENTES  **** \n\n");

    printf("Codigo cliente: %d \n",codigoCliente );

    printf("INgrese nombre: ");
    scanf("%s", nameAux);

     printf("INgrese sexo: ");
    scanf("%s",sexoAux );

    printf("INgrese telefono: ");
    scanf("%s",telefonoAux );
  //while(!getStringLetras("\nIngrese nombre del cliente :  ",nameAux));
   // while(!getStringLetras("\nIngrese sexo del cliente :  ",sexoAux));
    //while(!getStringNumeros("\n Ingrese telefono del cliente:   ",telefonoAux));

   strcpy(unCliente.telefono, telefonoAux);
    strcpy(unCliente.nombre,nameAux) ;
    strcpy(unCliente.sexo,sexoAux) ;


    return unCliente;
}



void altaClientes ( sClientes clientes [], int tam, int codCliente)

{

    int indice;

    system("cls");
    printf(" **** ALTA DE CLIENTES **** \n\n");

    indice = buscarEspacioClientes(clientes, tam);

    if (indice == -1 )
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }

    else
    {
        clientes[indice] = altacliente(codCliente);
        //clientes[indice].codCliente= codCliente;
        //clientes[indice].isEmpty=0;
        system("pause");

    }

}


/** \brief muestra un empleados
 *
 * \param la estrutura empleado.
 * \param ///
 * \return no retorna valor.
 *
 */

void listarUnCliente (sClientes  cliente)

{
    printf(" %d   %s   %c  % s ", cliente.codCliente ,cliente.nombre,cliente.sexo, cliente.telefono);

}




/** \brief Muestra por pantalla el array completo
 *
 * \param recibe la estructura
 * \param el atamaño
 * \return no tiene retorno.
 *
 */

void listarClientes (sClientes clientes [], int tam)
{
    system("cls");
    printf("\n  ******  LISTADO DE CLIENTES  ****** \n\n");

    printf("\n\t\COD.CLIENTE\t\t\NOMBRE\t\t\SEXO\t\TELEFONO\n ");

    for (int i=0; i<tam ; i++)
    {

        if( clientes[i].isEmpty == OCUPADO)
        {
            listarUnCliente(clientes[i]);
        }

    }
    system("pause");

}



int buscarclienteporCodCliente( sClientes clientes [], int tam, int codigoCliente)

{
    int indice= -1 ;

    for (int i=0 ; i<tam ; i++)
    {
        if ( clientes[i].codCliente ==codigoCliente && clientes[i].isEmpty== OCUPADO)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


void modificarCliente (sClientes clientes [], int tam )
{
    int codCliente;
    int indice;
    int opcion;
    char confirma;

    char nameAux [51];
    char sexoAux[20];
    char telefonoAux[21];

    char codClienteAux[10];

    system("cls");
    printf("\n ******  MODIFICACION DE CLIENTES  ****** \n");

    while(!getStringNumeros("\n Ingrese Cod. de cliente:  ", codClienteAux));

    codCliente= atoi(codClienteAux);

    indice = buscarclienteporCodCliente(clientes, tam, codCliente);
    if( indice != -1)
    {
        printf("ERROR, No hay cliente con ese codigo:  %d \n\n", codCliente);
        system("pause");
    }
    else
    {
        printf("\n\COD.CLIENTE \t\ NOMBRE \t\  SEXO \t\TELEFONO\n");
        listarUnCliente(clientes[indice]);
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
            printf("1. Nombre \n\n");
            printf("2. Sexo \n\n");
            printf("3. Telefono \n\n");

            printf("Ingrese opcion: ");
            scanf("%d", &opcion);

            switch (opcion)
            {

            case 1:
                system("cls");

                while( !getStringLetras("\nInsegre nuevo nombre: \n",nameAux));
                strcpy(clientes[indice].nombre,nameAux);
                printf("\nModificacion Realizada\n\n");
                break;
            case 2:
                system("cls");
                while(!getStringLetras("\nInsegre nuevo sexo: \n", sexoAux));
                strcpy(clientes[indice].sexo,sexoAux);
                printf("\nModificacion Realizada\n\n");
                break;
            case 3:
                while(!getStringNumeros("\n Ingrese telefono del cliente:   ",telefonoAux));
                strcpy(clientes[indice].telefono, telefonoAux);
                printf("Modificacion Realizada\n\n");
                break;
            default:
                printf("No es una opcion valida.");
                break;
            }
        }
        else
        {
            printf("\n\n Modificacion Cancelada\n\n");
        }


    }

}


void bajadeCliente (sClientes clientes [], int tam)
{

    int codigoCliente;
    int indice;
    char confirma;
    char codClienteAux[20];

    system("cls");
    printf("\n ******  BAJA DE CLIENTE  ****** \n");

    while(!getStringNumeros("\n Ingrese CODIGO DE CLIENTE a dar de BAJA :  ", codClienteAux) );
    codigoCliente= atoi(codClienteAux);

    indice = buscarclienteporCodCliente(clientes, tam, codigoCliente);
    if( indice == -1)
    {
        printf("\n ERROR, No hay cliente con ese codigo:  %d \n\n", codigoCliente);
        system("pause");
    }
    else
    {
        printf("\n\COD.CLIENTE \t\ NOMBRE \t\  APELLIDO \t\DOMICILIO\t\TELEFONO\n");
        listarUnCliente(clientes[indice]);
        printf(" \n\n");

        printf("\n Confirma la BAJA ? s=SI n = NO :  \n\n");
        fflush (stdin);
        scanf("%c", &confirma);

        confirma =getChar("\n Confirma la BAJA ? s=SI  n= NO :  ");
        while (confirma!= 's' || confirma != 'm')                                     ///valida que sea s o no
        {
            confirma =getChar("\n Error! Ingrese s=SI  n= NO dar de baja:  ");
            if (confirma == 's' || confirma== 'n')
            {

                break;
            }

        }

        if (confirma== 's')
        {
            clientes[indice].isEmpty = 1;
            printf(" \n\n BAJA EFECTUADA \n\n");
            system("\n\n  pause \n\n");
        }
        else
        {
            printf("\n\n BAJA CANCELADA \n\n");
            system("\n\n  pause \n\n");
        }
    }
}


void listarClientesOrdenados (sClientes clientes [], int tam)

{
    sClientes clienteAux;

    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if (strcmp(clientes[j].nombre,clientes[i].nombre)>0 && clientes[j].isEmpty==0 && clientes[i].isEmpty==0)
            {
                clienteAux=clientes[i];
                clientes[i]=clientes[j];
                clientes[j]=clienteAux;
            }
            else if (strcmp(clientes[j].nombre, clientes[i].nombre)==0 && clientes[i].isEmpty==0 && clientes[j].isEmpty==0)
            {
                if (strcmp(clientes[j].sexo,clientes[i].sexo)>0)
                {
                    clienteAux=clientes[i];
                    clientes[i]=clientes[j];
                    clientes[j]=clienteAux;
                }
            }
        }
    }


    for (int i=0; i<tam ; i++)
    {

        if( clientes[i].isEmpty == OCUPADO)
        {
            listarUnCliente(clientes[i]);
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

