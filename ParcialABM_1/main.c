#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Insaurralde.Barbara.Validaciones.h"
#include"Insaurralde.Barbara.Juegos.h"
#include"Insaurralde.Barbara.Clientes.h"
#include"Insaurralde.Barbara.Alquileres.h"
#include"Insaurralde.Barbara.1G.Informes.h"

#define TAMC 30
#define TAMA 50
#define TAM 25
#define OCUPADO 0
#define VACIO 1


int main()
{
    sCliente clientes [TAMC];
    sAlquiler alquiler [TAMA];
    eJuego juegos[TAM];
    eCategoria categoria [5];
    sFecha fecha[TAM];
    int codigoCliente=11;
    int codAlq=111;
    int codJuegos=1011;

    int banderaClientes=0;
    int banderaJuegos=0;
    int banderaAlquileres=0;
    char seguir='s';
    int opcion;

    inicializarClientes( clientes,  TAMC);
    inicializarJuegos(juegos,TAM);
    inicializarAlquileres(alquiler, TAMA);

    cargarClientes(clientes);
    cargarCategorias(categoria);
    cargarJuegos(juegos);
    cargarAlquileres(alquiler);

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");

            listarClientes(clientes,TAMC);
            //altaClientes( clientes,TAM, codigoCliente);
            codigoCliente++;
            banderaClientes=1;
            system("\n\n  pause \n\n");

            break;
        case 2:
            system("cls");
            if (banderaClientes==0)
            {
                printf("\nNo hay clientes activos! . Ingrese ALTA de cliente. \n\n");
            }
            else
            {
                modificarCliente(clientes,TAMC );
            }
            system("\n\n  pause \n\n");
            break;
        case 3:
            system("cls");
            if (banderaClientes==0)
            {
                printf("\nNo hay clientes activos! . Ingrese ALTA de cliente. \n\n");
            }
            else
            {
                bajadeCliente(clientes,TAMC);
            }
            system("\n\n  pause \n\n");
            break;
        case 4:
            system("cls");
            printf("\n ****** LISTADO DE CLIENTES ****** \n\n");

            if (banderaClientes==0)
            {
                printf("\nNo hay clientes activos! . Ingrese ALTA de cliente. \n\n");
            }
            else
            {
                listarClientes(clientes,TAMC);
                printf("\n\n  ******  LISTA DE CLIENTES ORDENADOS  ****** \n\n");
                listarClientesOrdenados(clientes,TAMC);
            }

            system("\n\n  pause \n\n");
            break;
        case 5:
            system("cls");
            printf("\n ****** ALTA DE JUEGO ****** \n\n");

            listarJuegos(juegos,TAM,categoria,5);
            //altadeJuegos(juegos,TAM,codJuegos,categoria,5);
            codJuegos++;
            banderaJuegos=1;
            system("\n\n  pause \n\n");
            break;
        case 6:
            system("cls");
            if (banderaJuegos==0)
            {
                printf("\nNo hay juegos activos! . Ingrese ALTA de juegos. \n\n");
            }
            else
            {
                modificarJuegos(juegos,TAM,categoria,5);
            }
            system("\n\n  pause \n\n");
            break;
        case 7:
            system("cls");
            if (banderaJuegos==0)
            {
                printf("\nNo hay juegos activos! . Ingrese ALTA de juegos. \n\n");
            }
            else
            {
                bajaJuegos(juegos,TAM,categoria,5);
            }
            system("\n\n  pause \n\n");
            break;
        case 8:
            system("cls");
            if (banderaJuegos==0)
            {
                printf("\nNo hay juegos activos! . Ingrese ALTA de juegos. \n\n");
            }
            else
            {
                listarJuegos(juegos,TAM,categoria,5);
            }
            system("\n\n  pause \n\n");
            break;
        case 9:
            system("cls");
            printf("\n ****** ALTA DE ALQUILERES ****** \n\n");

            if (banderaClientes==0 || banderaJuegos==0 )
            {
                printf("\nNo hay clientes o juegos activos! . Ingrese ALTA de cliente. \n\n");
            }
            else
            {
                listarAlquileresDetallados(alquiler,TAMA,clientes,TAMC,juegos,TAM);
                //altaAlquiler(juegos,TAM, clientes,TAM,alquiler, TAM,codAlq,categoria,5);
                codAlq++;
                banderaAlquileres=1;
            }
            system("\n\n  pause \n\n");

            break;
        case 10:
            system("cls");
            printf("\n ****** MODIFICAR DE ALQUILERES ****** \n\n");

            if (banderaAlquileres==0)
            {
                printf("\nNo hay alquileres activos! . Ingrese ALTA de alquileres. \n\n");
            }
            else
            {
                modificarAlquileres(alquiler,TAMA,clientes,TAMC,juegos,TAM,categoria,5);
            }
            system("\n\n  pause \n\n");

            break;
        case 11:
            system("cls");
            printf("\n ****** MODIFICAR DE ALQUILERES ****** \n\n");

            if (banderaAlquileres==0)
            {
                printf("\nNo hay alquileres activos! . Ingrese ALTA de alquileres. \n\n");
            }
            else
            {
                bajaAlquileres(alquiler, TAMA, clientes, TAMC, juegos, TAM );
            }
            system("\n\n  pause \n\n");

            break;
        case 12:
            system("cls");
            printf("\n ****** LISTADO DE ALQUILERES ****** \n\n");

            if (banderaAlquileres==0 )
            {
                printf("\nNo hay alquileres activos! . Ingrese ALTA de alquileres. \n\n");
            }
            else
            {
                listarAlquileresDetallados(alquiler,TAMA,clientes,TAMC, juegos,TAM);
            }
            system("\n\n  pause \n\n");

            break;
        case 13:
            system("cls");
            if (banderaClientes==0 || banderaJuegos==0 || banderaAlquileres==0)
            {
                printf("\n** INFORMES **");
                printf("\n\n No hay informes para mostrar. Verifique Alta de Cliente,Juegos y Alquileres.\n\n");
                system("\n\n  pause \n\n");
            }
            else
            {
                do
                {
                    system("cls");

                    printf("\n** INFORMES **\n\n");
                    printf("1- Mostrar Juegos x Categoria\n");
                    printf("2- Mostrar Juegos x Categoria Mesa\n");
                    printf("3- Total Importes Pagados Por Cliente Seleccionado\n");
                    printf("4- Listar Clientes Que No ALquilaron Juegos\n");
                    printf("5- Listar Juegos Que No Han Sido Alquilados\n");
                    printf("6- Telefonos De Clientes Que Alquilaron En Una Determinada Fecha\n");
                    printf("7- Listar Los Juegos Alquilados Por Mujeres\n");
                    printf("8- Mostrar El o Los Juegos Alquilados Por Hombre\n");
                    printf("9- Mostrar Los Clientes Que Alquilaron Un Determinado Juego\n");
                    printf("10- Mostrar La Recaudacion De Una Fecha En Particular \n");



                    printf("15- Salir\n");


                    printf("\n Ingrese opcion: ");
                    scanf("%d", &opcion);


                    switch(opcion)
                    {

                    case 1:
                        mostrarJuegosxCategoria ( juegos,TAM, categoria, 5  );
                        system("\n\n  pause \n\n");
                        break;
                    case 2:
                        mostrarJuegosxCategoriaMesa ( juegos,TAM, categoria, 5  );
                        system("\n\n  pause \n\n");
                        break;
                    case 3:
                        totalImportesPagadosPorClienteSeleccionado(alquiler,TAMA,juegos,TAM,clientes, TAMC);
                        system("\n\n  pause \n\n");
                        break;
                    case 4:
                        listarClientesQueNoALquilaronJuegos(alquiler,TAMA,juegos,TAM,clientes, TAMC);
                        system("\n\n  pause \n\n");
                        break;
                    case 5:
                        listarJuegosQueNoHanSidoAlquilados(alquiler,TAMA,juegos,TAM,clientes, TAMC,categoria,5);
                        system("\n\n  pause \n\n");
                        break;
                    case 6:
                        telefonosDeClientesQueAlquilaronEnUnaDeterminadaFecha(clientes,TAMC,alquiler,TAMA,fecha,TAM, juegos,TAM);
                        system("\n\n  pause \n\n");
                        break;
                    case 7:
                        listarLosJuegosAlquiladosPorMujeres(alquiler,TAMA,clientes,TAMC,juegos,TAM);
                        system("\n\n  pause \n\n");
                        break;
                    case 8:
                        mostrarEloLosJuegosAlquiladosPorHombre(alquiler,TAMA,clientes,TAMC,juegos,TAM,categoria,5);
                        system("\n\n  pause \n\n");
                        break;
                    case 9:
                        mostrarLosClientesQueAlquilaronUnDeterminadoJuego(alquiler,TAMA,clientes,TAMC,juegos,TAM,categoria,5);
                        system("\n\n  pause \n\n");
                        break;
                    case 10:
                        mostrarLaRecaudacionDeUnaFechaEnParticular(alquiler,TAMA,juegos,TAM,clientes,TAMC);
                        system("\n\n  pause \n\n");
                        break;
                    case 15:
                        printf("Salir");
                        break;


                    }

                }
                while(opcion>15);
            }
            break;
        case 15:
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




