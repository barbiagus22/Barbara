#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prueba.h"
#include "Validaciones.h"
#include "Libros.h"
#include "Socios.h"
#include "Prestamos.h"

#define TAM 10
#define TAMA 10
#define TAML 10
#define TAMS 10
#define VACIO 0
#define OCUPADO 1


/** \brief inicializa todas el array 1 que indica ESTADO vacio.
 *
 * \param estructura de empleados.
 * \param cantidad de datos del sistema.
 * \return no retorna valor.
 *
 */

void initLibros ( eLibros libros  [], int tam)
{
    for (int i=0 ; i< tam; i++)
    {
        libros[i].isEmpty = VACIO;
    }

}


/** \brief busca el indice vacio donde cargar un empleado.
 *
 * \param la estrutura empleado
 * \param el tamaño de la estrutura-
 * \return el indice se que encuentea vacio.
 *
 */


int buscarLibreLibros(eLibros libros[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( libros[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



/** \brief Re realiza el harcodeo de la categoria juegos.
 *
 * \param los elecmentos de la estructura.
 * \param -
 * \return no tiene retorno.
 *
 */
void cargarLibros(eLibros libros[], int tam)
{
    eLibros l[]=
    {

        {1,"El Principito",1, 1},
        {2,"Naranja Mecanica",1 ,1},
        {3,"HArry Poter",2 , 1},


    };

    for(int i=0; i < tam; i++)
    {
        libros[i] = l[i];
    }
}

/** \brief muestra un autor
 *
 * \param la estrutura autores.
 * \param ///
 * \return no retorna valor.
 *
 */

void mostrarUnLibro (eLibros libro)

{
    printf("\n\t%d\t\t%s\t\t%d ", libro.id,libro.titulo, libro.codAutor);

}


/** \brief Muestra por pantalla el array completo
 *
 * \param recibe la estructura
 * \param el atamaño
 * \return no tiene retorno.
 *
 */

void printLibros (eLibros libros [], int tam)
{
    system("cls");
    printf("\n  ******  DETALLLE DE LIBROS  ****** \n\n");
    printf("\nCODIGO DE LIBRO\t\tTITUTO\t\tCODIGO DE AUTOR ");

    for (int i=0; i<tam ; i++)
    {

        if( libros[i].isEmpty == OCUPADO)
        {
            mostrarUnLibro(libros[i]);

        }

    }

}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int findLibros( eLibros libros [], int tam, int idAuto)

{
    int indice= -1 ;

    for (int i=0 ; i<tam ; i++)
    {
        if ( libros[i].id ==idAuto && libros[i].isEmpty== OCUPADO)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


/** \brief Solicita modificacion de datos del empleado dado de alta.
 *
 * \param la estructura el array
 * \param tamaño del array
 * \return no tiene retorno
 *
 */

void modifyLibro ( eLibros libros [], int tam , eAutores autores [],int tama  )
{
    int idAut;
    int indice;
    int opcion;
    char tituloAux [51];
    char codigoAutorAux [51];
    char idAux[10];

    system("cls");
    printf("\n ******  MODIFICACION LIBRO  ****** \n");

    printLibros(libros,tam);

    while(!getStringNumeros("\n\n Ingrese ID del libro que desea modificar:  ", idAux));

    idAut= atoi(idAux);

    indice = findLibros(libros, tam, idAut);
    if( indice == -1)
    {
        printf("ERROR, No hay libro con el ID:  %d \n\n", idAut);
        system("pause");
    }
    else
    {
        //mostrarAutor(autores[indice]);
        printf(" \n\n");
        printf("Que desea modificar? \n");
        printf("1. Titulo \n");
        printf("2. Codigo de Autor \n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {

        case 1:
            while( !getStringLetras("\nInsegre nuevo Titulo: ",tituloAux));
            strcpy(libros[indice].titulo,tituloAux);
            printf("\nModificacion Realizada\n\n");
            break;
        case 2:
            printAutores(autores,tama);
            while(!getStringNumeros("\nInsegre nuevo codigo de autor: \n", codigoAutorAux));
            libros[indice].codAutor= atof(codigoAutorAux);
            printf("\n\nModificacion Realizada\n\n");
            break;
        default:
            printf("No es una opcion valida.");
            break;
        }

    }

}


/** \brief dada de baja un empleado solicitando  numero de id-
 *
 * \param estructura empleados.
 * \param tamaño de empleado-
 * \return no tiene retorno-
 *
 */

void removeLibro (eLibros libro [], int tam)
{

    int idAut;
    int indice;
    char idAux[20];

    system("cls");
    printf("\n ******  BAJA DE LIBROS  ****** \n");
    printLibros(libro, tam);
    printf(" \n\n");
    while(!getStringNumeros("\n\n  Ingrese ID a dar de BAJA :  ", idAux) );
    idAut= atoi(idAux);

    indice = findLibros(libro, tam, idAut);
    if( indice == -1)
    {
        printf("\n ERROR, No hay libro con el ID:  %d \n\n", idAut);
        system("pause");
    }
    else
    {
        //mostrarEmpleado(empleados[indice]);
        libro[indice].isEmpty = VACIO;
        printf(" \n\n Baja efectuada \n\n");
    }
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void listarLibrosOrdenadosPorTitulo (eLibros libros [], int tam)

{
    eLibros librosAux;

    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if ( strcmp(libros[j].titulo,libros[i].titulo)<0 && libros[j].isEmpty==OCUPADO && libros[i].isEmpty==OCUPADO)
            {
                librosAux=libros[i];
                libros[i]=libros[j];
                libros[j]=librosAux;
            }
            else if ( strcmp(libros[j].titulo,libros[i].titulo)==0  && libros[j].isEmpty==OCUPADO && libros[i].isEmpty==OCUPADO)
            {
                if (libros[j].codAutor>libros[i].codAutor)
                {
                    librosAux=libros[i];
                libros[i]=libros[j];
                libros[j]=librosAux;
                }
            }
        }
    }

    printf("\n  ******  DETALLLE DE LIBROS  ****** \n\n");
    printf("\nCODIGO DE LIBRO\t\tTITUTO\t\tCODIGO DE AUTOR ");

    for (int i=0; i<tam ; i++)
    {

        if( libros[i].isEmpty == OCUPADO)
        {
            mostrarUnLibro(libros[i]);
        }

    }



}

