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

int menu()
{
    int opcion;
    char opcionAux[6];

    system("cls");
    printf("\n ***** MENU DE OPCIONES : BIBLIOTECA *****\n\n");
    printf("\n ***** ABM: AUTORES *****\n");
    printf(" 1- Alta\n");
    printf(" 2- Modificar\n");
    printf(" 3- Baja\n");
    printf(" 4- Listar\n");
    printf("\n***** ABM: LIBROS *****\n");
    printf(" 5- Alta\n");
    printf(" 6- Modificar\n");
    printf(" 7- Baja\n");
    printf(" 8- Listar\n");
    printf("\n***** ABM: SOCIOS *****\n");
    printf(" 9- Alta\n");
    printf(" 10- Modificar\n");
    printf(" 11- Baja\n");
    printf(" 12- Listar\n");
    printf(" 13- Listar Libros\n");
    printf(" 14- Listar Autores\n");
    printf(" 15- Prestamos\n");

    printf(" 16- Salir\n\n");


    while(!getStringNumeros("Ingrese opcion: ",opcionAux));

    opcion=atoi(opcionAux);
    printf("%d", opcion);

    if(opcion< 1 || opcion> 16)
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

void initAutores ( eAutores autores  [], int tam)
{
    for (int i=0 ; i< tam; i++)
    {
        autores[i].isEmpty = VACIO;
    }

}


/** \brief busca el indice vacio donde cargar un empleado.
 *
 * \param la estrutura empleado
 * \param el tamaño de la estrutura-
 * \return el indice se que encuentea vacio.
 *
 */

int buscarLibre(eAutores autores[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( autores[i].isEmpty == VACIO)
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

eAutores altaAutor (int idAut)

{

    eAutores autor;

    char nameAux [31];
    char lastNameAux [31];


    system("cls");

    printf("\n ****  ALTA DE AUTOR  **** \n\n");

    printf("ID AUTOR: %d \n",idAut );

    while(!getStringLetras("\n Ingrese nombre del autor: ",nameAux));

    while(!getStringLetras("\nIngrese apellido del autor: ",lastNameAux));

    strcpy(autor.name,nameAux) ;
    strcpy(autor.lastname,lastNameAux);

    return autor;
}


/** \brief Realiza el alta por sistema
 *
 * \param la estructura empleados.
 * \param tamaño de la estructura.
 * \param id de los empledos. autoincremental.
 * \return no tiene retorno.
 *
 */


void addAutor ( eAutores autores [], int tam, int idAut)

{

    int indice;

    system("cls");
    printf(" **** ALTA DE AUTOR **** \n\n");

    indice = buscarLibre(autores, tam);

    if (indice == -1 )
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }

    else
    {
        autores[indice] = altaAutor(idAut);
        autores[indice].id= idAut;
        autores[indice].isEmpty=OCUPADO;
        printf(" \n\n Alta efectuada \n\n");

    }

}


/** \brief Re realiza el harcodeo de la categoria juegos.
 *
 * \param los elecmentos de la estructura.
 * \param -
 * \return no tiene retorno.
 *
 */
void cargarAutores(eAutores autores[], int tam)
{
    eAutores a[]=
    {

        {1,"Jose","Sanchez", 1},
        {2,"Domingo","Larroque", 1},
        {3,"Lucas", "Martinez",1},
        {4,"Mario","Lopez",1},


    };

    for(int i=0; i < tam; i++)
    {
        autores[i] = a[i];
    }
}

/** \brief muestra un autor
 *
 * \param la estrutura autores.
 * \param ///
 * \return no retorna valor.
 *
 */

void mostrarAutor (eAutores  autor)

{
    printf("\n\t\%d\t\t\%s\t\t\%s ", autor.id,autor.name, autor.lastname);

}



/** \brief Muestra por pantalla el array completo
 *
 * \param recibe la estructura
 * \param el atamaño
 * \return no tiene retorno.
 *
 */

void printAutores (eAutores autores [], int tam)
{
    //system("cls");
    printf("\n  ******  DETALLLE DE AUTORES  ****** \n\n");

    printf("\n\tID\t\tNOMBRE\t\tAPELLIDO ");

    for (int i=0; i<tam ; i++)
    {

        if( autores[i].isEmpty == OCUPADO)
        {
            mostrarAutor(autores[i]);
        }

    }
    //system("\npause\n");

}


/** \brief busca el indice donde se encuentra un  empleado por numero de id.
 *
 * \param la estructura empleados.
 * \param tamaño de la estructura.
 * \param id de los empledos. autoincremental.
 * \return el indice donde se encuentra ese id de empleado.
 *
 */

int findAutores( eAutores autores [], int tam, int idAuto)

{
    int indice= -1 ;

    for (int i=0 ; i<tam ; i++)
    {
        if ( autores[i].id ==idAuto && autores[i].isEmpty== OCUPADO)
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

void modifyAutores (eAutores autores [], int tam )
{
    int idAut;
    int indice;
    int opcion;
    char nameAux [31];
    char lastNameAux [31];
    char idAux[10];

    system("cls");
    printf("\n ******  MODIFICACION AUTORES  ****** \n");

    printAutores(autores,tam);

    while(!getStringNumeros("\n\n Ingrese ID del autor que desea modificar:  ", idAux));

    idAut= atoi(idAux);

    indice = findAutores(autores, tam, idAut);
    if( indice == -1)
    {
        printf("ERROR, No hay autor con el ID:  %d \n\n", idAut);
        system("pause");
    }
    else
    {
        //mostrarAutor(autores[indice]);
        printf(" \n\n");
        printf("Que desea modificar? \n");
        printf("1. Nombre \n");
        printf("2. Apellido \n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {

        case 1:
            while( !getStringLetras("\nInsegre nuevo nombre: ",nameAux));
            strcpy(autores[indice].name,nameAux);
            printf("\nModificacion Realizada\n\n");
            break;
        case 2:
            while(!getStringLetras("\nInsegre nuevo apellido: ", lastNameAux));
            strcpy(autores[indice].lastname,lastNameAux);
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

void removeAutor (eAutores autores [], int tam)
{

    int idAut;
    int indice;
    char idAux[20];

    system("cls");
    printf("\n ******  BAJA DE AUTORES  ****** \n");
    printAutores(autores,tam);
    printf(" \n\n");
    while(!getStringNumeros("\n\n  Ingrese ID a dar de BAJA :  ", idAux) );
    idAut= atoi(idAux);

    indice = findAutores(autores, tam, idAut);
    if( indice == -1)
    {
        printf("\n ERROR, No hay autor con el ID:  %d \n\n", idAut);
        system("pause");
    }
    else
    {
        //mostrarEmpleado(empleados[indice]);
        autores[indice].isEmpty = VACIO;
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

void listarAutoresOrdenados (eAutores autores [], int tam)

{
    eAutores autoresAux;

    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if ( strcmp(autores[j].lastname,autores[i].lastname)<0 && autores[j].isEmpty==OCUPADO && autores[i].isEmpty==OCUPADO)
            {
                autoresAux=autores[i];
                autores[i]=autores[j];
                autores[j]=autoresAux;
            }
            else if ( strcmp(autores[j].lastname,autores[i].lastname)==0  && autores[j].isEmpty==OCUPADO && autores[i].isEmpty==OCUPADO)
            {
                if (strcmp(autores[j].name,autores[i].name)>0)
                {
                    autoresAux=autores[i];
                    autores[i]=autores[j];
                    autores[j]=autoresAux;
                }
            }
        }
    }

    printf("\n  ******  DETALLLE DE AUTORES  ****** \n\n");
    printf("\n\tID\t\tNOMBRE\t\tAPELLIDO ");

    for (int i=0; i<tam ; i++)
    {

        if( autores[i].isEmpty == OCUPADO)
        {
            mostrarAutor(autores[i]);
        }

    }



}
