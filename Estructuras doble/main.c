#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"estrutura.h"
#define TAM 4
#define OCUPADO 0
#define VACIO 1






void inicializarAlquileres (sAlquileres alquiler[], int tam);
int buscarLibreAlquileres(sAlquileres alquiler[], int tam);


int main()
{
    char seguir='s';

    sJuegos juegos[TAM];
    int codJuegos=100;
    int bandera=0;

    sClientes clientes [TAM];
    int codigoCliente=1;
    int banderaClientes=0;

    sAlquileres alquileres [TAM];
    sFecha fecha[TAM];
    int codAlq=1000;

    inicializarJuegos (juegos, TAM);
    inicializarClientes ( clientes,  TAM);
    inicializarAlquileres (alquileres, TAM);



    do
    {

        switch(menu())
        {

        case 1:
            system("cls");
            altadeJuegos (juegos, TAM, codJuegos);
            codJuegos++;
            bandera=1;
            break;
        case 2:
            system("cls");
            if ( bandera==0 )
            {
                printf("\nNo hay juegos dados de alta!\n Ingrese ALTA de juegos. \n\n");
            }
            else
            {
                modificarJuegos (juegos,  TAM);
            }
            system("\n\n  pause \n\n");

            break;
        case 3:
            system("cls");

            if ( bandera==0 )
            {
                printf("\nNo hay juegos dados de alta!\n Ingrese ALTA de juegos. \n\n");
            }
            else
            {
                bajadeJuego(juegos, TAM);
            }
            system("\n\n  pause \n\n");
            break;

        case 4:
            system("cls");

            if ( bandera==0 )
            {
                printf("\nNo hay juegos dados de alta!\n Ingrese ALTA de juegos. \n\n");
            }
            else
            {
                listarjuegosOrdenados(juegos, TAM);
            }
            system("\n\n  pause \n\n");
            break;
        case 5:
            system("cls");
            altaClientes ( clientes,  TAM, codigoCliente);
            codigoCliente++;
            banderaClientes=1;
            system("\n\n  pause \n\n");
            break;
        case 6:
            system("cls");
            if (banderaClientes==0)
            {

                printf("\nNo hay clientes dados de alta!\n Ingrese ALTA de cliente. \n\n");
            }
            else
            {
                modificarCliente (clientes,TAM );
            }
            system("\n\n  pause \n\n");
            break;
        case 7:
            system("cls");
            if (banderaClientes==0)
            {

                printf("\nNo hay clientes dados de alta!\n Ingrese ALTA de cliente. \n\n");
            }
            else
            {
                bajadeCliente(clientes,TAM );
            }
            system("\n\n  pause \n\n");
            break;
        case 8:
            system("cls");
            printf("\n ****** LISTA DE CLIENTE ****** \n\n");
            if (banderaClientes==0)
            {

                printf("\nNo hay clientes dados de alta!\n Ingrese ALTA de cliente. \n\n");
            }
            else
            {
                listarClientesOrdenados(clientes,TAM);
            }
            system("\n\n  pause \n\n");
            break;
        case 9:
            altaAlquiler(juegos,TAM, clientes,TAM,alquileres, TAM,codAlq);
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

void inicializarAlquileres (sAlquileres alquiler[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        alquiler[i].isEmpty = 1;
    }
}

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






void altaAlquiler (sJuegos juegos [], int tamjuegos, sClientes clientes[] , int tamclientes, sAlquileres alquileres [], int tamalq, int codAlq)

{


    int clientesAux;
    int juegosAux;
    int fecha;
    int indice;

    indice = buscarLibreAlquileres(alquileres, tamalq);

    if(indice == -1)
    {
        printf("No se pueden cargar mas alquileres\n\n");
    }
    else
    {
        sAlquileres.codAlquiler = codAlq;

        listarClientesOrdenados(clientes, tamclientes);

        printf("Ingrese codigo de cliente: ");
        scanf("%d", &clientesAux);

        alquileres.clientes


        listarjuegosOrdenados(juegos,tamjuegos);
        printf("Ingrese juego: ");
        scanf("%d", &alquileres.juegos);


        printf("\nIngrese dia: ");
        scanf("%d", &fecha.dia);

        printf("Ingrese mes: ");
        scanf("%d", &fecha.mes );

        printf("Ingrese anio: ");
        scanf("%d", &fecha.anio );

        alquileres.fecha = fecha;

        alquileres.isEmpty = 0;

        alquileres[indice] = alquileres;

        codAlq++;
    }










}
