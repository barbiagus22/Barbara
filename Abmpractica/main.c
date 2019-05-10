#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prueba.h"
#include "Validaciones.h"
#include "Libros.h"
#include "Socios.h"
#include "Prestamos.h"

#define TAM 4
#define TAMA 10
#define TAML 10
#define TAMS 10
#define TAMP 30
#define VACIO 0
#define OCUPADO 1


int main()
{
    eAutores autores[TAMA];
    eLibros libros [TAML];
    eSocio socios[TAMS];
    ePrestamo prestamos [TAMP];

    int idAutAutores=5;
    int idAutlibros=4;
    int idAutSocios=5;
    int codigoDePrestamo=1;
    int bandera=0;
    int flagLibros=0;
    int flagSocios=0;
    //int flagPrestamo=0;
    char continuar='s';
    char confirmaP='s';

    initSocios(socios,TAMS);
    initAutores(autores, TAMA);
    initLibros(libros,TAML);
    initPrestamos(prestamos,TAMP);



    cargarAutores(autores,TAM);
    // cargarSocios(socios, TAM);

    system("cls");
    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            //printf("Alta\n");
            addAutor(autores,TAMA,idAutAutores);
            idAutAutores++;
            bandera=1;
            system("\n\n  pause \n\n");
            break;
        case 2:
            system("cls");
            if ( bandera==0 )
            {
                printf("\nNo se ingresaron datos!\n\nIngrese a ALTA de autor. \n\n");
            }
            else
            {
                //printf(" 2- Modificar\n");
                modifyAutores(autores,TAMA);
            }
            system("\n\n  pause \n\n");
            break;
        case 3:
            system("cls");
            if ( bandera==0 )
            {
                printf("\nNo se ingresaron datos!\n\n Ingrese ALTA de autor.  \n\n");
            }
            else
            {
                // printf(" 3- Baja\n");
                removeAutor(autores, TAMA);
            }
            system("\n\n  pause \n\n");
            break;
        case 4:
            system("cls");
            if ( bandera==0 )
            {
                printf("\nNo se ingresaron datos!\n\nIngrese ALTA de autor. \n\n");
            }
            else
            {
                // printf(" 4- Listar\n");
                //printAutores(autores,TAMA);
                listarAutoresOrdenados(autores,TAMA);
            }
            printf("\n\n");
            system("\npause\n\n");
            break;
        case 5:
            system("cls");
            printf("Alta\n");
            cargarLibros(libros,TAM);
            idAutlibros++;
            flagLibros=1;
            system("\n\n  pause \n\n");
            break;
        case 6:
            system("cls");
            if ( flagLibros==0 )
            {
                printf("\nNo se ingresaron datos!\n\nIngrese a ALTA de autor. \n\n");
            }
            else
            {
                //printf(" 2- Modificar\n");
                modifyLibro(libros,TAML, autores,TAMA);
            }
            system("\n\n  pause \n\n");
            break;
        case 7:
            system("cls");
            if ( flagLibros==0 )
            {
                printf("\nNo se ingresaron datos!\n\n Ingrese ALTA de libros.  \n\n");
            }
            else
            {
                // printf(" 3- Baja\n");
                removeLibro(libros, TAML);
            }
            system("\n\n  pause \n\n");
            break;
        case 8:
            system("cls");
            if ( flagLibros==0 )
            {
                printf("\nNo se ingresaron datos!\n\n");
            }
            else
            {
                //printLibros(libros,TAML);
                listarLibrosOrdenadosPorTitulo (libros,TAML);
            }
            printf("\n\n");
            system("\npause\n\n");
            break;
        case 9:
            system("cls");
            printf("Alta\n");
            // addSocio(socios,TAMS,idAutSocios);
            cargarSocios(socios, TAM);
            idAutSocios++;
            flagSocios=1;
            system("\n\n  pause \n\n");
            break;
        case 10:
            system("cls");
            if ( flagSocios==0 )
            {
                printf("\nNo se ingresaron datos!\n\nIngrese a ALTA de socio. \n\n");
            }
            else
            {
                //printf(" 2- Modificar\n");
                modifySocios(socios,TAMS);

            }
            system("\n\n  pause \n\n");
            break;
        case 11:
            system("cls");
            if ( flagSocios==0 )
            {
                printf("\nNo se ingresaron datos!\n\n Ingrese ALTA de autor.  \n\n");
            }
            else
            {
                //printf(" 3- Baja\n");
                removeSocio(socios,TAMS);
            }
            system("\n\n  pause \n\n");
            break;
        case 12:
            system("cls");
            if ( flagSocios==0 )
            {
                printf("\nNo se ingresaron datos!\n\nIngrese ALTA de autor. \n\n");
            }
            else
            {
                //printf(" 4- Listar\n");
                //printSocios(socios,TAMS);
                listarSociosOrdenados(socios,TAMS);
            }
            printf("\n\n");
            system("\npause\n\n");
            break;
        case 13:
            system("cls");
            if ( flagLibros==0 )
            {
                printf("\nNo se ingresaron datos!. Ingrese ALTA de libros. \n\n");
            }
            else
            {
                // printf(" 4- Listar\n");
                //printAutores(autores,TAMA);
                listarLibrosOrdenadosPorTitulo(libros,TAML);
            }
            printf("\n\n");
            system("\npause\n\n");
            break;
        case 14:
            system("cls");
            if ( bandera==0 )
            {
                printf("\nNo se ingresaron datos!.Ingrese ALTA de autores. \n\n");
            }
            else
            {
                //printLibros(libros,TAML);
                listarAutoresOrdenados(autores,TAMA);
            }
            printf("\n\n");
            system("\npause\n\n");
            break;
        case 15:
            do
            {
                switch(menuPrestamo())
                {
                case 1:
                    if (bandera==0 || flagLibros==0 || flagSocios==0)
                    {
                        printf("Faltan ingresar alta de Autores , Libros o Socio");
                    }
                    else
                    {

                        addPrestamo(prestamos,TAMP,codigoDePrestamo,libros,TAML,socios,TAMS );
                        //    flagPrestamo=1;
                        codigoDePrestamo++;
                        printf("\n\n");
                    }


                    break;
                case 2:
                    printf(" 2- Modificar\n");
                    break;
                case 3:
                    printf(" 3- Baja\n");
                    break;
                case 4:

                    printPrestamos(prestamos,TAMP, socios,TAMS);
                    break;
                case 5:
                    system("cls");
                    printf("\n\n Volviendo menu anterior sistema ...\n\n");
                    confirmaP='n';
                    break;
                default:
                    printf(" No es  una opcion valida.\n");

                }
            }
            while(confirmaP=='s');

            break;
        case 16:
            system("cls");
            printf("\n\n Cerrando sistema ...\n\n");
            continuar='n';
            break;
        }
    }
    while(continuar== 's');


















    return 0;
}
