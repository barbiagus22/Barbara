#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Insaurralde.Barbara.Validaciones.h"
#include"Insaurralde.Barbara.Juegos.h"
#include"Insaurralde.Barbara.Clientes.h"
#include"Insaurralde.Barbara.Alquileres.h"
#include"Insaurralde.Barbara.1G.Informes.h"

#define TAM 4
#define OCUPADO 0
#define VACIO 1


int menu()
{
    int opcion;
    char opcionAux[6];

    system("cls");
    printf("\n ******** MENU DE OPCIONES  *******\n\n");
    printf(" 1- Alta de clientes\n");
    printf(" 2- Modificar clientes \n");
    printf(" 3- Baja de clientes\n");
    printf(" 4- Listar clientes\n");
    printf(" 5- Alta alquileres\n");
    printf(" 6- Listar Alquileres\n");
    printf(" 7- Informes\n");
    printf(" 10- Salir\n\n");


    while(!getStringNumeros("Ingrese opcion:  ",opcionAux));

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


/** \brief inicializa todos los elementos del array en vacio 1
 *
 * \param los elementod del array.
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void inicializarClientes (sClientes clientes[], int tam)
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

/** \brief de da de alta un cliente.
 *
 * \param cod de cliente que se da de alta.
 * \param -
 * \return los datos del cliente dado de alta.
 *
 */

sClientes altacliente (int codigoCliente)
{

    sClientes unCliente;

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


void listarUnCliente (sClientes  clientes)

{
    printf("    %d          %10s             %10s            %10s \n ",clientes.codCliente,clientes.nombre,clientes.sexo,clientes.telefono);

}

/** \brief mustra el total de clientes del array.
 *
 * \param el array analizar-
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void listarClientes (sClientes clientes [], int tam)
{
    system("cls");
    printf("\n  ******  LISTA DE CLIENTES  ****** \n\n");

    printf("\n COD.CLIENTE            NOMBRE              SEXO              TELEFONO\n");

    for (int i=0; i<tam ; i++)
    {

        if( clientes[i].isEmpty == OCUPADO)
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

/** \brief se reliza la modificacion de los datos de cliente.
 *
 * \param el array de clientes.
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void modificarCliente (sClientes clientes [], int tam )
{
    int codCliente;
    int indice;
    int opcion;

    char nombreAux [51];
    char sexoAux [10];
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
        printf("\n COD.CLIENTE            NOMBRE              SEXO              TELEFONO\n");
        listarUnCliente(clientes[indice]);
        printf(" \n\n");

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
            while( !getStringLetras("\nIngrese nuevo NOMBRE: \n",nombreAux));
            strcpy(clientes[indice].nombre,nombreAux);
            printf("\nModificacion Realizada\n\n");
            break;
        case 2:
            system("cls");
            function_continueform("\nIngrese SEXO  f o m : \n", sexoAux);
            strcpy(clientes[indice].sexo,sexoAux);
            printf("\nModificacion Realizada\n\n");
            break;
        case 3:
            while(!getStringtelefono("\nIngrese TELEFONO del cliente:   ", telefonoAux));
            strcpy(clientes[indice].telefono, telefonoAux);
            printf("Modificacion Realizada\n\n");
            break;
        default:
            printf("\n\n Modificacion Cancelada.\n\n");
            break;
        }
    }
}

/** \brief Ordena por nombre los clientes ingresados y en caso de ser el mismo por sex
 *
 * \param el array analizar.
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

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

/** \brief se reliza la baja de los datos de cliente por cod de cliente.
 *
 * \param el array de clientes.
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void bajadeCliente (sClientes clientes [], int tam)
{

    int codigoCliente;
    int indice;
    char confirma='s';
    char codClienteAux[20];

    system("cls");
    printf("\n ******  BAJA DE CLIENTE  ****** \n");


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
        printf("\n COD.CLIENTE            NOMBRE              SEXO              TELEFONO\n");
        listarUnCliente(clientes[indice]);
        printf(" \n\n");

        printf("Confirma baja.\n Ingrese  s=si  n=no ?:  ");
        scanf("%s", &confirma);

        while (confirma!= 's' || confirma != 'n')
        {
            confirma =getChar("\n Error! Ingrese s=si  n=no para confirmar baja:  ");
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


void cargarClientes( sClientes clientes [])
{
    sClientes cl[]=
    {

        {10,"pablo","m", "15666"},
        {11,"pedro","m", "42964"},
        {12,"mariano","m", "159965"},
        {13,"gonzalo","m", "42963"},
        {14,"ana","f", "89722"},
        {15,"magali","f","159687" },
        {16,"lucas","m", "1598712"},
        {17,"tomas","m","4897258"},
        {18,"emiliano","m","1523488"},
        {19,"alejandro","m","156973"},

    };

    for(int i=0; i < 10; i++)
    {
        clientes[i] = cl[i];
    }
}

/** \brief Realiza la carga del listado de juegos.
 *
 * \param los elementos del array.
 * \param
 * \return no tiene retorno.
 *
 */

void listarClientesCargados(sClientes clientescargados[])
{


    printf("\n              ******* LISTA DE CLIENTES ********\n\n");
    printf("CODIGO          NOMBRE             SEXO      TELEFONO\n");


    for(int i=0; i < 10; i++)
    {
        printf(" %d        %10s            %s         %s  \n", clientescargados[i].codCliente, clientescargados[i].nombre, clientescargados[i].sexo, clientescargados[i].telefono  );
    }
    printf("\n\n");
}






