#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Insaurralde.Barbara.Validaciones.h"
#include"Insaurralde.Barbara.Juegos.h"
#include"Insaurralde.Barbara.Clientes.h"
#include"Insaurralde.Barbara.Alquileres.h"
#include"Insaurralde.Barbara.1G.Informes.h"

#define TAM 20
#define OCUPADO 0
#define VACIO 1



int menu()
{
    int opcion;
    char opcionAux[6];

    system("cls");
    printf("\n*****       ABM:  MENU DE OPCIONES   ***\n");
    printf("\n  *** CLIENTES ***\n");
    printf(" 1- Alta de clientes\n");
    printf(" 2- Modificar clientes \n");
    printf(" 3- Baja de clientes\n");
    printf(" 4- Listar clientes\n\n");
    printf("\n  *** JUEGOS ***\n");
    printf(" 5- Alta de Juegos\n");
    printf(" 6- Modificar juegos \n");
    printf(" 7- Baja de juegos\n");
    printf(" 8- Listar juegos\n\n");
    printf("\n  *** ALQUILERES ***\n");
    printf(" 9-  Alta alquileres\n");
    printf(" 10- Modificar alquileres\n");
    printf(" 11- Baja alquileres\n");
    printf(" 12- Listar Alquileres\n\n");
    printf("\n    *** INFORMES ***\n");
    printf(" 13- Informes\n\n");
    printf("\n 15- Salir\n\n");


    while(!getStringNumeros("Ingrese opcion:  ",opcionAux));

    opcion=atoi(opcionAux);
    printf("%d", opcion);

    if(opcion< 1 || opcion> 15)
    {
        printf("\n Error! Ingrese opcion correcta.\n\n");
        system("pause");
        fflush(stdin);
    }


    return opcion;
}


/** \brief inicializa todos los elementos del array en vacio 1
 *
 * \param los elementod del array.
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void inicializarClientes (sCliente clientes[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        clientes[i].isEmpty = 1;
    }
}

/** \brief busca el primer espacio vacio.
 *
 * \param los elementos del array.
 * \param el tamaño.
 * \return retorna el indice que se encuetra vacio.
 *
 */

int buscarEspacioClientes(sCliente clientes[], int tam)
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

/** \brief de da de alta un cliente.
 *
 * \param cod de cliente que se da de alta.
 * \param -
 * \return los datos del cliente dado de alta.
 *
 */

sCliente altacliente (int codigoCliente)
{

    sCliente unCliente;

    char nombreAux [51];
    char sexoAux [10];
    char telefonoAux[21];




    system("cls");

    printf("\n ****  ALTA DE CLIENTES  **** \n\n");

    printf("Codigo cliente: %d \n",codigoCliente );


    while(!getStringLetras("\nIngrese nombre del cliente :  ",nombreAux));

    function_continueform("\nIngrese sexo del cliente  f o m :  ", sexoAux);

    strcpy(unCliente.sexo,sexoAux) ;

    while(!getStringtelefono("\nIngrese telefono del cliente:   ",telefonoAux ));


    strcpy(unCliente.nombre,nombreAux) ;
    strcpy(unCliente.telefono,telefonoAux);

    return unCliente;

}


/** \brief se da de alta un cliente vailendo que haya un espacio vacio.
 *
 * \param el array a analizar.
 * \param el tamaño.
 * \return el cod de cliente a dar de alta.
 *
 */

void altaClientes ( sCliente clientes [], int tam, int codCliente)

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
        clientes[indice].codCliente= codCliente;
        clientes[indice].isEmpty=OCUPADO;

        system("pause");

    }

}

/** \brief muestra los datos de un cliente.
 *
 * \param el array de clientes.
 * \param
 * \return no tiene retorno.
 *
 */


void listarUnCliente (sCliente  clientes)

{

    printf("%10d              %10s          %10s            %10s\n",clientes.codCliente,clientes.nombre,clientes.sexo,clientes.telefono);

}

/** \brief mustra el total de clientes del array.
 *
 * \param el array analizar-
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void listarClientes (sCliente clientes [], int tam)
{
    system("cls");
    printf("\n  ******  LISTA DE CLIENTES  ****** \n");
    printf("\n       COD.CLIENTE           NOMBRE                SEXO            TELEFONO\n");

    for (int i=0; i<tam ; i++)
    {

        if( clientes[i].isEmpty == 0)
        {
            listarUnCliente(clientes[i]);

        }

    }

}

/** \brief Bs por id el cliente a modificar.
 *
 * \param el array a analizar.
 * \param el tamaño.
 * \param el codigo de cliente a buscar.
 * \return el indice a modificar.
 *
 */

int buscarclienteporCodCliente( sCliente clientes [], int tam, int codigoCliente)

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

/** \brief se reliza la modificacion de los datos de cliente.
 *
 * \param el array de clientes.
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void modificarCliente (sCliente clientes [], int tam )
{
    int codCliente;
    int indice;
    int opcion;

    char nombreAux [51];
    char sexoAux [10];
    char telefonoAux[21];
    char codClienteAux[10];


    printf("\n ******  MODIFICACION DE CLIENTES  ****** \n");

    listarClientes(clientes,tam);
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
        system("cls");
        do
        {
            printf("\n ******  MODIFICACION DE CLIENTES  ****** \n");
            printf("\n COD.CLIENTE                NOMBRE                  SEXO              TELEFONO\n");
            listarUnCliente(clientes[indice]);
            printf(" \n\n");

            printf(" \n Que desea modificar ? \n\n");
            printf("1. Nombre \n");
            printf("2. Sexo \n");
            printf("3. Telefono \n");
            printf("4. Cancelar \n");

            printf("Ingrese opcion: ");
            scanf("%d", &opcion);

            switch (opcion)
            {
            case 1:
                while( !getStringLetras("\nIngrese nuevo NOMBRE:  ",nombreAux));
                strcpy(clientes[indice].nombre,nombreAux);
                printf("\n\nModificacion Realizada con Exito!!!\n\n");
                break;
            case 2:
                function_continueform("\nIngrese SEXO  f o m :  ", sexoAux);
                strcpy(clientes[indice].sexo,sexoAux);
                printf("\n\nModificacion Realizada con Exito!!!\n\n");
                break;
            case 3:
                while(!getStringtelefono("\nIngrese TELEFONO del cliente:   ", telefonoAux));
                strcpy(clientes[indice].telefono, telefonoAux);
                printf("\n\nModificacion Realizada con Exito!!!\n\n");
                break;
            case 4:
                printf("\n\n Modificacion Cancelada.\n\n");
                break;
            }

        }
        while (opcion>4);

    }
}

/** \brief Ordena por nombre los clientes ingresados y en caso de ser el mismo por sex
 *
 * \param el array analizar.
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void listarClientesOrdenados (sCliente clientes [], int tam)

{
    sCliente clienteAux;

    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if (strcmp(clientes[j].nombre,clientes[i].nombre)<0 && clientes[j].isEmpty==0 && clientes[i].isEmpty==0)
            {
                clienteAux=clientes[i];
                clientes[i]=clientes[j];
                clientes[j]=clienteAux;
            }
            else if (strcmp(clientes[j].nombre, clientes[i].nombre)==0 && clientes[i].isEmpty==0 && clientes[j].isEmpty==0)
            {
                if (strcmp(clientes[j].sexo,clientes[i].sexo)<0)
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

/** \brief se reliza la baja de los datos de cliente por cod de cliente.
 *
 * \param el array de clientes.
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void bajadeCliente (sCliente clientes [], int tam)
{

    int codigoCliente;
    int indice;
    char codClienteAux[20];

    system("cls");
    printf("\n ******  BAJA DE CLIENTE  ****** \n");

    listarClientes(clientes,tam);

    while(!getStringNumeros("\n Ingrese CODIGO DE CLIENTE a dar de BAJA :  ", codClienteAux) );
    codigoCliente= atoi(codClienteAux);

    indice = buscarclienteporCodCliente(clientes, tam, codigoCliente);
    if( indice == -1)
    {
        system("cls");
        printf("\n ERROR, No hay cliente con ese codigo:  %d \n\n", codigoCliente);
        system("pause");
    }
    else
    {
        printf(" \n\n");
        clientes[indice].isEmpty = 1;
        printf(" \n\n BAJA EFECTUADA CON EXITO\n\n");
    }
}

/** \brief harcodeo de estrucuta clientes
 *
 * \param el array de clientes cliente
 * \param
 * \return no tiene retorno
 *
 */

void cargarClientes( sCliente clientes [])
{
    sCliente cl[]=
    {

        {1, "marianela", "f", "2456-6543", 0 },
        {2, "gabriel", "m", "4296-7774", 0 },
        {3, "mariano","m", "1595-7965", 0 },
        {4, "gonzalo", "m", "4296-3333",0},
        {5, "analia", "f", "8972-2222",0},
        {6, "magali", "f", "1596-8987", 0 },
        {7, "lucas", "m", "1598-6712",0},
        {8, "tomas","m","4897-9258",0},
        {9,"emiliano","m","1523-0488",0},
        {10,"alejandro","m","1569-0073",0},

    };

    for(int i=0; i < 10; i++)
    {
        clientes[i] = cl[i];
    }
}


/** \brief busca e tel de un cliente pasandole el numero de id.cliente.
 *
 * \param array de clientes.
 * \param tamaño.
 * \param id de cliente.
 * \param caddena donde e copiana el telefono del cliente.
 * \return no tiene retorno.
 *
 */


void obtenerTefono ( sCliente clientes [], int tamc,int id, char cadena [] )


{
    for(int i=0; i < tamc; i++)
    {

        if( clientes[i].codCliente == id)
        {
            strcpy(cadena, clientes[i].telefono);
        }
    }



}

/** \brief valida que sea hombre.
 *
 * \param array de cliente.
 * \param tamaño del array.
 * \param id a validar
 * \return retorno si es hombre.
 *
 */


int esHombre (sCliente clientes [],int tam, int idCliente )
{
    int hombre=0;


    for ( int i=0; i<tam ; i++)
    {
        if (clientes[i].codCliente== idCliente)
        {
            if (strcmp(clientes[i].sexo,"m")==0)
            {
                hombre=1;
            }
            break;
        }



    }


    return hombre;

}


/** \brief valida que sea hombre.
 *
 * \param array de cliente.
 * \param tamaño del array.
 * \param id a validar
 * \return retorno si es hombre.
 *
 */


int esMujer (sCliente clientes [],int tam, int idCliente )
{
    int mujer=0;


    for ( int i=0; i<tam ; i++)
    {
        if (clientes[i].codCliente== idCliente)
        {
            if (strcmp(clientes[i].sexo,"f")==0)
            {
                mujer=1;
            }
            break;
        }



    }


    return mujer;

}


void obtenerCliente ( sCliente clientes [], int tam,int id, char cadena [] )

{
    for(int i=0; i < tam; i++)
    {

        if( clientes[i].codCliente == id)
        {
            strcpy (cadena,clientes[i].nombre);
        }
    }

}


