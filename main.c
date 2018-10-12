#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Insaurralde.Barbara.Validaciones.h"
#include"Insaurralde.Barbara.Juegos.h"
#include"Insaurralde.Barbara.Clientes.h"
#include"Insaurralde.Barbara.Alquileres.h"
#include"Insaurralde.Barbara.1G.Informes.h"

#define TAM 10
#define OCUPADO 0
#define VACIO 1

int main()
{


    sClientes clientes [10];
    int codigoCliente=1;

    int banderaClientes=0;
    char seguir='s';

    sAlquileres alquiler [TAM];
    sFecha fecha[TAM];
    int codAlq=1000;

    eJuegos juegos[10];
    eCategoria categoria [5];

    cargarCategorias(categoria);
    //listarCategorias(categoria);
    cargarJuegos(juegos);
    //listarJuegos(juegos);
    cargarClientes(clientes);


    inicializarClientes( clientes,  TAM);
    inicializarAlquileres(alquiler, TAM);


    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            //listarClientesCargados(clientes);
            altaClientes( clientes,TAM, codigoCliente);
            codigoCliente++;
            banderaClientes=1;
            system("\n\n  pause \n\n");
            break;
        case 2:
            system("cls");
            if (banderaClientes==0)
            {
                printf("\nNo hay clientes dados de alta!\n Ingrese ALTA de cliente. \n\n");
            }
            else
            {
                modificarCliente(clientes,TAM );
            }
            system("\n\n  pause \n\n");
            break;
        case 3:
            system("cls");
            if (banderaClientes==0)
            {

                printf("\nNo hay clientes dados de alta!\n Ingrese ALTA de cliente. \n\n");
            }
            else
            {
                bajadeCliente(clientes,TAM);
            }
            system("\n\n  pause \n\n");
            break;
        case 4:
            system("cls");
            printf("\n ****** LISTADO DE CLIENTES ****** \n\n");

            if (banderaClientes==0)
            {
                printf("\nNo hay clientes dados de alta!\n Ingrese ALTA de cliente. \n\n");
            }
            else
            {
                listarClientes(clientes,TAM);
                printf("\n\n\n  ******  LISTA DE CLIENTES ORDENADOS  ****** \n\n");
                listarClientesOrdenados(clientes, TAM);
            }

            system("\n\n  pause \n\n");
            break;
        case 5:
            system("cls");
            printf("\n ****** ALTA DE ALQUILERES ****** \n\n");

            if (banderaClientes==0)
            {
                printf("\nNo hay clientes dados de alta!\n Ingrese ALTA de cliente. \n\n");
            }
            else
            {
                altaAlquiler(juegos, clientes,TAM,alquiler, TAM,codAlq);
            }
            system("\n\n  pause \n\n");

            break;
        case 6:
            system("cls");
            printf("\n ****** LISTADO DE ALQUILERES ****** \n\n");

            if (banderaClientes==0)
            {
                printf("\nNo hay clientes dados de alta!\n Ingrese ALTA de cliente. \n\n");
            }
            else
            {
                listarAlquileres(alquiler, TAM);
            }
            system("\n\n  pause \n\n");

            break;
        case 7:
            printf("informes a realizar");
            break;
        case 10:
            system("cls");
            printf("\n\n Cerrando sistema ...\n\n");
            seguir='n';
            system("\n\n  pause \n\n");
            break;
        }
    }
    while(seguir== 's');

    return 0;
}


