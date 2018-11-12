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


/** \brief inicializa todos los elementos del array en vacio 1
 *
 * \param los elementod del array.
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void inicializarAlquileres (sAlquiler alquiler[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        alquiler[i].isEmpty = 1;
    }
}


/** \brief busca el primer espacio vacio.
 *
 * \param los elementos del array.
 * \param el tamaño.
 * \return retorna el indice que se encuetra vacio.
 *
 */

int buscarLibreAlquileres(sAlquiler alquiler[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( alquiler[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


/** \brief se da de alta un alquiler validando que haya un espacio vacio.
 *
 * \param el array a analizar.
 * \param el tamaño.
 * \return el cod de cliente a dar de alta.
 *
 */

void altaAlquiler (eJuego juego[], int tam, sCliente clientes[], int tamclientes, sAlquiler alquileres [], int tamalq, int codAlq, eCategoria categoria [], int tamc)

{


    char clientesAux[10];
    //char codJuegosAux [10];
    int codJuegoAux;
    sFecha fecha;


    sAlquiler altaAlquiler;
    int indice;

    indice = buscarLibreAlquileres(alquileres, tamalq);

    if(indice == -1)
    {
        printf("No se pueden cargar mas alquileres\n\n");
    }
    else
    {
        altaAlquiler.codAlquiler= codAlq;

        printf("\n COD.CLIENTE            NOMBRE              SEXO              TELEFONO\n");
        //listarClientesCargados(clientes);
        listarClientes(clientes,tamclientes);

        while(!getStringNumeros("\n Ingrese codigo del CLIENTE que alquilara:  ",clientesAux));
        altaAlquiler.codClientes=atoi(clientesAux);


        listarJuegos(juego,tam,categoria,tamc);
        //while(!getStringNumeros("Ingrese codigo de juego: " , codJuegosAux ));

        //altaAlquiler.codJuegos=atoi(codJuegosAux);
        codJuegoAux=getValidoInt("\n Ingrese codigo del JUEGO que alquilara:  ", "Error, o se encuentra dentro de los cod validos.", 1001, 1050);
        altaAlquiler.codJuegos=codJuegoAux;

        printf("\n\n Ingrese fecha de alquiler. \n\n Ingrese dia: ");
        scanf("%d", &fecha.dia);

        printf("Ingrese mes: ");
        scanf("%d", &fecha.mes );

        printf("Ingrese anio: ");
        scanf("%d", &fecha.anio );


        altaAlquiler.fecha=fecha;

        altaAlquiler.isEmpty = 0;

        alquileres[indice] = altaAlquiler;

        printf("\n\n ALQUILER CARGADO CON EXITO!! \n\n");


    }
}

/** \brief muestra todos los elementos del array con estado activo
 *
 * \param el array analizar.
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void listarAlquileresDetallados(sAlquiler alquileres [], int tam, sCliente clientes[], int tamc, eJuego juego [], int tamj)
{
    system("cls");
    printf("\n  ******  LISTA DE ALQUILERES ****** \n\n");
    printf("COD. DE ALQUILER             CLIENTE           JUEGO                  FECHA\n");

    for (int i=0; i<tam; i++)
    {
        if (alquileres[i].isEmpty== OCUPADO)
        {
            listarUnAlquilerDetallado(alquileres[i],clientes,tamc,juego,tamj);
        }

    }

}


void listarUnAlquilerDetallado (sAlquiler  alquileres, sCliente cliente [], int tamc, eJuego juego [], int tamj)

{
    char nombre[25];
    char nombreJuego [25];

    obtenerCliente(cliente,tamc, alquileres.codClientes , nombre);
    obtenerJuego (juego,tamj,alquileres.codJuegos,nombreJuego );

    printf("    %5d               %13s        %10s     %10d/%d/%d\n", alquileres.codAlquiler,nombre, nombreJuego, alquileres.fecha.dia, alquileres.fecha.mes,alquileres.fecha.anio);

}



/** \brief se reliza la modificacion de los datos de cliente.
 *
 * \param el array de clientes.
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void modificarAlquileres (sAlquiler alquileres [], int tam, sCliente cliente [], int tamc,  eJuego juego [], int tamj, eCategoria categorias [],int tamcg)
{
    int codAlquiler;

    int indice;
    int opcion;

    char codAlquilerAux [20];
    char codClienteAux [20];
    char codJuegoAux[20];

    char diaAux[10];
    char mesAux[10];
    char anioAux[10];

    system("cls");
    printf("\n ******  MODIFICACION DE ALQUILERES  ****** \n");

    listarAlquileresDetallados(alquileres, tam, cliente,tamc,juego,tamj);

    while(!getStringNumeros("\n Ingrese Cod. de alquiler a modificar:  ", codAlquilerAux));

    codAlquiler=atoi(codAlquilerAux);

    indice = buscarAlquilerPorCodigodeAlquiler(alquileres, tam, codAlquiler);
    if( indice == -1)
    {
        printf("ERROR, No hay alquiler con ese codigo:  %d \n\n", codAlquiler);
        system("pause");
    }
    else
    {
        system("cls");
        do
        {
            printf("\n ******  MODIFICACION DE ALQUILERES  ****** \n");
            printf("\n  COD. DE ALQUILER             CLIENTE                      JUEGO                     FECHA  \n");
            listarUnAlquilerDetallado(alquileres[indice],cliente,tamc,juego,tamj);
            printf(" \n\n");


            printf(" \n Que desea modificar ? \n\n");
            printf("1. Cliente \n");
            printf("2. Juego \n");
            printf("3. Fecha \n");
            printf("4. Cancelar \n");

            printf("Ingrese opcion: ");
            scanf("%d", &opcion);


            switch (opcion)
            {
            case 1:
                listarClientes(cliente,tamc);
                while(!getStringNumeros("\n Ingrese cod. de cliente correcto: ", codClienteAux));
                alquileres[indice].codClientes= atoi(codClienteAux);
                printf("\n\nModificacion Realizada con Exito!!!\n\n");

                break;
            case 2:
                listarJuegos(juego,tamj,categorias,tamcg);
                while(!getStringNumeros("\n Ingrese cod. de cliente que correcto: ", codJuegoAux));
                alquileres[indice].codJuegos= atoi(codJuegoAux);
                printf("\n\nModificacion Realizada con Exito!!!\n\n");
                break;
            case 3:
                while(!getStringNumeros("\nIngrese nueva fecha.\n Ingrese Dia:   \n", diaAux));
                while(!getStringNumeros("Ingrese Mes:   \n", mesAux));
                while(!getStringNumeros("Ingrese Anio:   \n", anioAux));

                alquileres[indice].fecha.dia= atoi(diaAux);
                alquileres[indice].fecha.mes= atoi(mesAux);
                alquileres[indice].fecha.anio= atoi(anioAux);

                printf("\n\n Modificacion Realizada con Exito !!!\n\n");
                break;

            case 4:
                printf("\n\n Modificacion Cancelada.\n\n");
                break;
            }
        }
        while (opcion>4);

    }
}

/** \brief Busca  cod de alquileres a modificar.
 *
 * \param el array a analizar.
 * \param el tamaño.
 * \param el codigo de alquiler a buscar.
 * \return el indice a modificar.
 *
 */

int buscarAlquilerPorCodigodeAlquiler( sAlquiler alquiler [], int tam, int codAlquiler)

{
    int indice= -1 ;

    for (int i=0 ; i<tam ; i++)
    {
        if ( alquiler[i].codAlquiler ==codAlquiler && alquiler[i].isEmpty== OCUPADO)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

/** \brief se reliza la baja de alquiler por cod de alquiler.
 *
 * \param el array de clientes.
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void bajaAlquileres (sAlquiler alquileres [], int tam, sCliente cliente [], int tamc, eJuego juego [], int tamj)
{
    int codAlquiler;
    int indice;
    char codAlqAux[20];

    system("cls");
    printf("\n ******  BAJA DE ALQUILERES  ****** \n");

    listarAlquileresDetallados(alquileres,tam,cliente,tamc,juego, tamj);

    while(!getStringNumeros("\n Ingrese CODIGO DE ALQUILER a dar de BAJA :  ", codAlqAux) );
    codAlquiler= atoi(codAlqAux);

    indice = buscarAlquilerPorCodigodeAlquiler(alquileres,tam,codAlquiler);
    if( indice == -1)
    {
        printf("\n ERROR, No hay alquiler con ese codigo:  %d \n\n", codAlquiler);
        system("pause");
    }
    else
    {
        printf(" \n\n");
        alquileres[indice].isEmpty = 1;
        printf(" \n\n BAJA EFECTUADA CON EXITO\n\n");
    }

}

/** \brief Re realiza el harcodeo de la categoria alquiler.
 *
 * \param los elecmentos de la estructura.
 * \param -
 * \return no tiene retorno.
 *
 */
void cargarAlquileres(sAlquiler alquileres[])
{
    sAlquiler alquiler[]=
    {
        {101, 1001, 3,  {01,11,18}, 0},
        {102, 1009, 5,  {01,11,18}, 0},
        {103, 1006, 3,  {10,11,18}, 0},
        {104, 1004, 9,  {12,11,18}, 0},
        {105, 1005, 6,  {13,11,18}, 0},
        {106, 1003, 6,  {14,11,18}, 0},
        {107, 1006, 10, {11,11,18}, 0},
        {108, 1009, 8,  {11,11,18}, 0},
        {109, 1009, 10, {11,11,18}, 0},
        {110, 1010, 7 , {11,11,18}, 0},

    };

    for(int i=0; i < 10; i++)
    {
        alquileres[i] = alquiler[i];
    }
}


/** \brief compara dos fechas
 *
 * \param fecha del arra alquileres
 * \param fecha ingresada por teclado.
 * \return no tiene retorno.
 *
 */

int compararFecha (sFecha fecha1, sFecha fecha2)
{

    int igual=0;

    if (fecha1.dia== fecha2.dia && fecha1.mes==fecha2.mes && fecha1.anio==fecha2.anio )
    {
        igual=1;
    }

    return igual;


}





