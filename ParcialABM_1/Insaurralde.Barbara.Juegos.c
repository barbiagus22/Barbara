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



void inicializarJuegos (eJuego juegos[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        juegos[i].isEmpty= VACIO;
    }
}

int buscarLibre(eJuego juegos[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( juegos[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


eJuego altaUnJuego (int codJuegos, eCategoria categorias [], int tamc)

{
    eJuego altaJuego;

    char descripcionAux [51];
    char importeAux[20];
    char codCategoriaAux[20];


    system("cls");

    printf("\n ****  ALTA DE JUEGOS  **** \n\n");

    printf("Codigo de Juego : %d \n",codJuegos );

    while(!getStringLetras("\n Ingrese nombre del juego:  ",descripcionAux));
    while(!getStringNumeros("\n Ingrese importe del juego:  ",importeAux));
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

    printf("\n");
    listarCategorias(categorias);
    while(!getStringNumeros("\n Ingrese codigo de categoria:  ", codCategoriaAux ));
    altaJuego.idcategoria= atoi(codCategoriaAux);

    strcpy( altaJuego.descripcion,descripcionAux) ;
    altaJuego.importe =atof(importeAux);


    return altaJuego;
}


void altadeJuegos ( eJuego juego [], int tam, int codJuegos, eCategoria categorias [], int tamc)

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
        juego[indice] = altaUnJuego(codJuegos,categorias,tamc);
        juego[indice].id= codJuegos;
        juego[indice].isEmpty=OCUPADO;

    }

}

/** \brief Re realiza el harcodeo de la categoria juegos.
 *
 * \param los elecmentos de la estructura.
 * \param -
 * \return no tiene retorno.
 *
 */
void cargarJuegos(eJuego juegos[])
{
    eJuego juego[]=
    {

        {1001,"Monopoly",1002, 1,0},
        {1002,"Domino",1000, 1,0},
        {1003,"Bingo", 1000, 2,0},
        {1004,"Cartas",1500, 2,0},
        {1005,"TEG",1000, 3,0},
        {1006,"Ajedrez",1000,3,0 },
        {1007,"Ruleta",2005,4,0 },
        {1008,"Generala",1200,4,0},
        {1009,"Magic Kit",2000,5,0},
        {1010,"Estanciero",1000,5,0},

    };

    for(int i=0; i < 10; i++)
    {
        juegos[i] = juego[i];
    }
}

/** \brief Realiza la carga del listado de juegos.
 *
 * \param los elementos del array.
 * \param
 * \return no tiene retorno.
 *
 */

void listarJuegos(eJuego juegosinfantiles [], int tamj,  eCategoria categoria [], int tamc )
{

    printf("\n              ******* LISTA DE JUEGOS ********\n\n");
    printf("CODIGO            NOMBRE               IMPORTE      CATEGORIA\n");


    for(int i=0; i < tamj; i++)
    {
        if (juegosinfantiles[i].isEmpty== OCUPADO)
        {
            listarUnJuegos(juegosinfantiles[i],categoria,tamc );
        }

    }

}

void listarUnJuegos(eJuego juegosinfantiles, eCategoria categoria [], int tamc )
{
    char descripcionCartegoria [30];

    obtenerCategoria(categoria,tamc, juegosinfantiles.idcategoria,descripcionCartegoria);

    printf(" %d         %10s                  %d    %10s  ", juegosinfantiles.id,juegosinfantiles.descripcion, juegosinfantiles.importe, descripcionCartegoria );

    printf("\n");
}



/** \brief se reliza el harcodeo de las categorias de los juegos
 *
 * \param los elementos del array
 * \param
 * \return no tiene retorno.
 *
 */

void cargarCategorias( eCategoria categorias[])
{
    eCategoria categ[]=
    {

        {1,"Mesa"},
        {2,"Azar"},
        {3,"Estrategia"},
        {4,"Salon"},
        {5,"Magia"}
    };

    for(int i=0; i < 5; i++)
    {
        categorias[i] = categ[i];
    }
}


void listarCategorias (eCategoria categorias[])
{
    printf("\n ***  LISTA DE CATEGORIAS *** \n\n");
    printf("  CODIGO      NOMBRE \n");


    for(int i=0; i < 5; i++)
    {
        printf("  %d     %10s\n",categorias[i].id, categorias[i].descripcion);
    }
    printf("\n\n");
}


void obtenerCategoria (eCategoria categoria[], int tamc, int id, char cadena[] )

{
    for(int i=0; i < tamc; i++)
    {

        if( categoria[i].id == id)
        {
            strcpy(cadena, categoria[i].descripcion);
        }
    }



}

/** \brief se reliza la modificacion de los datos de cliente.
 *
 * \param el array de clientes.
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void modificarJuegos (eJuego juegos [], int tam, eCategoria categorias [], int tamc)
{
    int codJuego;
    int indice;
    int opcion;

    char codJuegoAux[10];
    char nombreAux [51];
    char importeAux [10];
    char categoriaAux[51];



    printf("\n ******  MODIFICACION DE JUEGOS  ****** \n");

    listarJuegos(juegos,tam,categorias,tamc);
    while(!getStringNumeros("\n Ingrese Cod. de juego:  ", codJuegoAux));

    codJuego= atoi(codJuegoAux);

    indice = buscarJuegoPorCodigoJuego(juegos, tam, codJuego);
    if( indice == -1)
    {
        printf("ERROR, No hay juego con ese codigo:  %d \n\n", codJuego);
        system("pause");
    }
    else
    {
        system("cls");
        do
        {
            printf("\n ******  MODIFICACION DE JUEGOS  ****** \n");
            printf("CODIGO            NOMBRE               IMPORTE      CATEGORIA\n");
            listarUnJuegos(juegos[indice],categorias,tamc);
            printf(" \n\n");

            printf(" \n Que desea modificar ? \n\n");
            printf("1. Nombre \n");
            printf("2. Importe \n");
            printf("3. Categoria \n");
            printf("4. Cancelar \n");

            printf("Ingrese opcion: ");
            scanf("%d", &opcion);

            switch (opcion)
            {
            case 1:
                while( !getStringLetras("\nIngrese nuevo nombre:  ",nombreAux));
                strcpy(juegos[indice].descripcion,nombreAux);
                printf("\n\nModificacion Realizada con Exito!!!\n\n");
                break;
            case 2:
                while(!getStringNumeros("\n Ingrese nuevo importe  ", importeAux));
                juegos[indice].importe= atof(importeAux);
                printf("\n\nModificacion Realizada con Exito!!!\n\n");
                break;
            case 3:
                listarCategorias(categorias);
                while(!getStringNumeros("\n Ingrese nueva categoria  ", categoriaAux));
                juegos[indice].idcategoria= atoi(categoriaAux);
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
/** \brief Busca por id el juego a modificar.
 *
 * \param el array a analizar.
 * \param el tamaño.
 * \param el codigo de juego a buscar.
 * \return el indice a modificar.
 *
 */

int buscarJuegoPorCodigoJuego( eJuego juegos [], int tam, int codJuego)

{
    int indice= -1 ;

    for (int i=0 ; i<tam ; i++)
    {
        if ( juegos[i].id ==codJuego && juegos[i].isEmpty== OCUPADO)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


/** \brief se reliza la baja de juegos por cod de juego.
 *
 * \param el array de clientes.
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void bajaJuegos (eJuego juego [], int tamj,eCategoria categoria[], int tamca)
{
    int codJuego;
    int indice;
    char codJuegoAux[20];

    system("cls");
    printf("\n ******  BAJA DE JUEGO  ****** \n");

    listarJuegos(juego,tamj,categoria,tamca);

    while(!getStringNumeros("\n Ingrese CODIGO DE JUEGO a dar de BAJA :  ", codJuegoAux) );
    codJuego= atoi(codJuegoAux);

    indice = buscarJuegoPorCodigoJuego(juego,tamj,codJuego);
    if( indice == -1)
    {
        printf("\n ERROR, No hay juego con ese codigo:  %d \n\n", codJuego);
        system("pause");
    }
    else
    {
        printf(" \n\n");
        juego[indice].isEmpty = 1;
        printf(" \n\n BAJA EFECTUADA CON EXITO\n\n");
    }

}


/** \brief busca e juego de un cliente pasandole el numero de id.cliente.
 *
 * \param array de juego.
 * \param tamaño.
 * \param id de juego.
 * \param caddena donde e copiana el nombe el juego.
 * \return no tiene retorno.
 *
 */

void obtenerJuego ( eJuego juego [], int tamj,int id, char cadena [] )


{
    for(int i=0; i < tamj; i++)
    {

        if( juego[i].id == id)
        {
            strcpy(cadena, juego[i].descripcion);
        }
    }



}

