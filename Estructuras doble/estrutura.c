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
    char opcionAux[10];

    system("cls");
    printf("\n ***** MENU DE OPCIONES *****\n\n");
    printf(" 1- Alta de juegos\n");
    printf(" 2- Modificar juegos \n");
    printf(" 3- Baja de juegos \n");
    printf(" 4- Listar juegos \n\n");
    printf(" 5- Alta de clientes\n");
    printf(" 6- Modificar clientes\n");
    printf(" 7- Baja de clientes\n");
    printf(" 8- Listar Clientes\n");
    printf(" 9- Alta Alquileres\n");
    printf(" 10- Salir\n\n");


    while(!getStringNumeros("Ingrese opcion: ",opcionAux));

    opcion=atoi(opcionAux);
    printf("%d", opcion);

    if(opcion< 1 || opcion> 10)
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

        confirma =getChar("\n Confirma la BAJA ? s=SI  n= NO :  ");
        while (confirma!= 's' || confirma != 'm')                                     ///valida que sea s o no
        {
            confirma =getChar("\n Error! Ingrese s=SI  n= NO dar de baja:  ");
            if (confirma == 's' || confirma== 'n')
            {

                break;
            }

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



void listarjuegosOrdenados (sJuegos juego [], int tam)

{
    sJuegos juegoAux;

    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if ( (juego[j].importe > juego[i].importe) && juego[j].isEmpty==0 && juego[i].isEmpty==0)
            {
                juegoAux=juego[i];
                juego[i]=juego[j];
                juego[j]=juegoAux;
            }
            else if ( (juego[j].importe == juego[i].importe) && juego[i].isEmpty==0 && juego[j].isEmpty==0)
            {
                if (strcmp(juego[j].descripcion,juego[i].descripcion)>0)
                {
                    juegoAux=juego[i];
                    juego[i]=juego[j];
                    juego[j]=juegoAux;
                }
            }
        }
    }


    for (int i=0; i<tam ; i++)
    {

        if( juego[i].isEmpty == OCUPADO)
        {
            listarUnjuego(juego[i]);
        }

    }



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
    char lastNameAux [51];
    char telefonoAux[21];

    char calle[21];
    char numero[20];


    system("cls");

    printf("\n ****  ALTA DE CLIENTES  **** \n\n");

    printf("Codigo cliente: %d \n",codigoCliente );

    while(!getStringLetras("\nIngrese nombre del cliente :  ",nameAux));

    while(!getStringLetras("\nIngrese apellido del cliente : ",lastNameAux));

    while(!getStringLetras("\nIngrese domicilio del cliente:\n Ingrese calle :  ",calle));

    while(!getStringNumeros(" n:  ",numero));

    while(!getStringNumeros("\nIngrese telefono del cliente:   ",telefonoAux));

    strcpy(unCliente.nombre,nameAux) ;
    strcpy(unCliente.apellido,lastNameAux);
    strcpy(unCliente.domicilio,strcat(calle, numero));
    strcpy(unCliente.telefono,telefonoAux);

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
        clientes[indice].codigoCliente= codCliente;
        clientes[indice].isEmpty=OCUPADO;
        system("pause");

    }

}

void listarUnCliente (sClientes  clientes)

{
    printf("\n  %10d   %10s   %10s   %10s   %10s \n ",clientes.codigoCliente,clientes.nombre,clientes.apellido, clientes.domicilio,clientes.telefono );

}

void listarClientes (sClientes clientes [], int tam)
{
    system("cls");
    printf("\n  ******  LISTA DE CLIENTES  ****** \n\n");

    printf("\n COD.CLIENTE       NOMBRE      APELLIDO       DOMICILIO      TELEFONO\n");

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
        if ( clientes[i].codigoCliente ==codigoCliente && clientes[i].isEmpty== OCUPADO)
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
    char lastNameAux [51];
    char domicilioAux[51];
    char telefonoAux[21];

    char codClienteAux[10];

    system("cls");
    printf("\n ******  MODIFICACION DE CLIENTES  ****** \n");

    while(!getStringNumeros("\n Ingrese Cod. de cliente:  ", codClienteAux));

    codCliente= atoi(codClienteAux);

    indice = buscarclienteporCodCliente(clientes, tam, codCliente);
    if( indice == -1)
    {
        printf("ERROR, No hay cliente con ese codigo:  %d \n\n", codCliente);
        system("pause");
    }
    else
    {
        printf("\n\COD.CLIENTE \t\ NOMBRE \t\  APELLIDO \t\DOMICILIO\t\TELEFONO\n");
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
            printf("2. Apellido \n\n");
            printf("3. Domicilio \n\n");
            printf("4. Telefono \n\n");
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
                while(!getStringLetras("\nInsegre nuevo apellido: \n", lastNameAux));
                strcpy(clientes[indice].apellido,lastNameAux);
                printf("\nModificacion Realizada\n\n");
                break;
            case 3:
                system("cls");
                printf("\nIngrese domicilio del cliente:  ");
                scanf ("%s", domicilioAux);
                while (!esAlfaNumerico(domicilioAux))
                {
                    printf("\nNo hay caracteres validos, ingre calle y numero de casa \n");
                    if (esAlfaNumerico(domicilioAux))
                    {
                        break;
                    }
                }
                strcpy(clientes[indice].domicilio,domicilioAux);
                printf("Modificacion Realizada\n\n");
                break;
            case 4:
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
        printf("\n ERROR, No hay juego con ese codigo:  %d \n\n", codigoCliente);
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
            if (strcmp(clientes[j].apellido,clientes[i].apellido)>0 && clientes[j].isEmpty==0 && clientes[i].isEmpty==0)
            {
                clienteAux=clientes[i];
                clientes[i]=clientes[j];
                clientes[j]=clienteAux;
            }
            else if (strcmp(clientes[j].apellido, clientes[i].apellido)==0 && clientes[i].isEmpty==0 && clientes[j].isEmpty==0)
            {
                if (strcmp(clientes[j].nombre,clientes[i].nombre)>0)
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


















