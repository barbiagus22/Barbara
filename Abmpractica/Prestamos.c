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


/** \brief creacion de funcion basica menu.
 *
 * \param
 * \param
 * \return
 *
 */

int menuPrestamo()
{
    int opcion;
    char opcionAux[6];

    system("cls");
    printf("\n ***** MENU DE OPCIONES : PRESTAMOS *****\n\n");
    printf("\n ***** ABM: PRESTAMOS *****\n");
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


/** \brief inicializa todas el array 1 que indica ESTADO vacio.
 *
 * \param estructura de empleados.
 * \param cantidad de datos del sistema.
 * \return no retorna valor.
 *
 */

void initPrestamos ( ePrestamo prestamos  [], int tam)
{
    for (int i=0 ; i< tam; i++)
    {
        prestamos[i].isEmpty = VACIO;
    }

}

/** \brief busca el indice vacio donde cargar un empleado.
 *
 * \param la estrutura empleado
 * \param el tamaño de la estrutura-
 * \return el indice se que encuentea vacio.
 *
 */

int buscarLibrePrestamos (ePrestamo prestamo[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( prestamo[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


/** \brief alta de emleados. solicita ingreso de un solo empleado .
 *
 * \param recibe el id donde cargar ese empleado
 * \param //
 * \return el empleado cargado en ese id-
 *
 */

ePrestamo altaPrestamo (int idAut, eLibros libros[], int taml, eSocio socios [], int tams )

{

    ePrestamo unPrestamo;

    char codigoDeLibroAux[10];
    char codigoDeSocioAux[10];
    char diaAux[5];
    char mesAux[5];
    char anioAux[5];


    system("cls");

    printf("\n ****  ALTA DE AUTOR  **** \n\n");

    printf("Codigo de Prestamo: %d \n",idAut );

    printLibros(libros,taml);
    while(!getStringNumeros("\n\nIngrese codigo de Libro:  ", codigoDeLibroAux));

    printSocios(socios,tams);
    while(!getStringNumeros("\n\nIngrese codigo de Socio:  ", codigoDeSocioAux));

    while(!getStringNumeros("\nIngrese fecha de prestamo.\nIngrese Dia:  ", diaAux));
    while(!getStringNumeros("\nIngrese Mes:  ", mesAux));
    while(!getStringNumeros("\nIngrese Anio: ", anioAux));


    unPrestamo.codigoDeLibro=atoi(codigoDeLibroAux);
    unPrestamo.codigoDeSocio=atoi(codigoDeSocioAux);
    unPrestamo.fecha.dia=atoi(diaAux);
    unPrestamo.fecha.mes=atoi(mesAux);
    unPrestamo.fecha.anio=atoi(anioAux);


    return unPrestamo;
}



/** \brief Realiza el alta por sistema
 *
 * \param la estructura empleados.
 * \param tamaño de la estructura.
 * \param id de los empledos. autoincremental.
 * \return no tiene retorno.
 *
 */


void addPrestamo ( ePrestamo prestamos [], int tam, int idAut, eLibros libros [], int taml, eSocio socios [], int tams)

{

    int indice;

    system("cls");
    printf(" **** ALTA DE AUTOR **** \n\n");

    indice = buscarLibrePrestamos(prestamos, tam);

    if (indice == -1 )
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }

    else
    {
        prestamos[indice] = altaPrestamo(idAut,libros,taml,socios,tams);
        prestamos[indice].codigoDePrestamo= idAut;
        prestamos[indice].isEmpty=OCUPADO;
        printf(" \n\n Alta efectuada \n\n");

    }

}


/** \brief muestra un autor
 *
 * \param la estrutura autores.
 * \param ///
 * \return no retorna valor.
 *
 */

void mostrarPrestamo (ePrestamo prestamo, eSocio socio[], int tams )

{

    char descripcionSocio [30];

    obtenerSocio(socio,tams,prestamo.codigoDeSocio,descripcionSocio);

    printf("\n\t%d\t\t%d\t\t%20s\t\t\t%d/%d/%d ", prestamo.codigoDePrestamo,prestamo.codigoDeLibro, descripcionSocio, prestamo.fecha.dia,prestamo.fecha.mes,prestamo.fecha.anio );

}


/** \brief Muestra por pantalla el array completo
 *
 * \param recibe la estructura
 * \param el atamaño
 * \return no tiene retorno.
 *
 */

void printPrestamos (ePrestamo prestamos[], int tam, eSocio socio [], int tams)
{
    //system("cls");
    printf("\n  ******  DETALLLE DE PRESTAMOS  ****** \n\n");

    printf("\nCODIGO DE PRESTAMO\tCODIGO DE LIBRO\t\tSOCIO\t\t\tFECHA  ");

    for (int i=0; i<tam ; i++)
    {

        if( prestamos[i].isEmpty == OCUPADO)
        {
            mostrarPrestamo(prestamos[i],socio,tams);
        }

    }
    printf("\n\n");
    system("\npause\n");

}

