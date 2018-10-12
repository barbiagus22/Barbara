#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Insaurralde.Barbara.Validaciones.h"
#include"Insaurralde.Barbara.Juegos.h"
#include"Insaurralde.Barbara.Clientes.h"
#include"Insaurralde.Barbara.Alquileres.h"
#include"Insaurralde.Barbara.1G.Informes.h"



/** \brief Re realiza el harcodeo de la categoria juegos.
 *
 * \param los elecmentos de la estructura.
 * \param -
 * \return no tiene retorno.
 *
 */
void cargarJuegos(eJuegos juegos[])
{
    eJuegos juego[]=
    {

        {1001,"Monopoly",1000, 1},
        {1002,"Domino",1000, 1},
        {1003,"Bingo", 1000, 2},
        {1004,"Cartas",1500, 2},
        {1005,"TEG",1000, 3},
        {1006,"Ajedrez",1000,3 },
        {1007,"Ruleta",200, 4},
        {1008,"Generala",1200,4},
        {1009,"Magic Kit",2000,5},
        {1010,"Magic",1000,5},

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

void listarJuegos(eJuegos juegosinfantiles[])
{


    printf("\n              ******* LISTA DE JUEGOS ********\n\n");
    printf("CODIGO            NOMBRE               IMPORTE      CATEGORIA\n");


    for(int i=0; i < 10; i++)
    {
        printf(" %d         %10s                  %d    %10d  \n", juegosinfantiles[i].id ,juegosinfantiles[i].descripcion, juegosinfantiles[i].importe , juegosinfantiles[i].idcategoria );
    }
    printf("\n\n");
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
    printf("****** LISTA DE CATEGORIAS ******\n\n");
    printf("CODIGO      NOMBRE \n");


    for(int i=0; i < 5; i++)
    {
        printf(" %d     %10s\n",categorias[i].id, categorias[i].descripcion);
    }
    printf("\n\n");
}







