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

void inicializarAlquileres (sAlquileres alquiler[], int tam)
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

int buscarLibreAlquileres(sAlquileres alquiler[], int tam)
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

void altaAlquiler (eJuegos juego[], sClientes clientes[], int tamclientes, sAlquileres alquileres [], int tamalq, int codAlq)

{


    char clientesAux[10];
    char codJuegosAux [10];
    sFecha fecha;

    sAlquileres altaAlquiler;
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
        listarClientesOrdenados(clientes,tamclientes);
        while(!getStringNumeros("\n Ingrese codigo del cliente que alquilara:  ",clientesAux));

        altaAlquiler.codClientes=atoi(clientesAux);

        listarJuegos(juego);
        while(!getStringNumeros("Ingrese codigo de juego: " , codJuegosAux ));

        altaAlquiler.codJuegos=atoi(codJuegosAux);


        printf("\n\n Ingrese fecha de alquiler. \n\n Ingrese dia: ");
        scanf("%d", &fecha.dia);

        printf("Ingrese mes: ");
        scanf("%d", &fecha.mes );

        printf("Ingrese anio: ");
        scanf("%d", &fecha.anio );


        altaAlquiler.fecha=fecha;

        altaAlquiler.isEmpty = 0;

        alquileres[indice] = altaAlquiler;

        codAlq++;

        printf("\n\n ALQUILER CARGADO CON EXITO!! \n\n");


    }
}





/** \brief muestra el detalle de un alquiler dado de alta.
 *
 * \param el array analizar.
 * \param
 * \return no tiene retorno.
 *
 */

void listarUnAlquiler (sAlquileres  alquileres)

{
    printf("\n %10d          %10d              %10d        %10d/%d/%d \n ",alquileres.codAlquiler,alquileres.codClientes, alquileres.codJuegos, alquileres.fecha.dia, alquileres.fecha.mes,alquileres.fecha.anio  );

}


/** \brief muestra todos los elementos del array con estado activo
 *
 * \param el array analizar.
 * \param el tamaño.
 * \return no tiene retorno.
 *
 */

void listarAlquileres (sAlquileres alquileres [], int tam)
{
    system("cls");
    printf("\n  ******  LISTA DE ALQUILERES ****** \n\n");

    printf("\n  COD. DE ALQUIER          COD. DE CLIENTE        COD. DE JUEGO            FECHA  \n");

    for (int i=0; i<tam ; i++)

    {


        if( alquileres[i].isEmpty == OCUPADO)
        {
            listarUnAlquiler(alquileres[i]);
        }

    }
    system("pause");
}



