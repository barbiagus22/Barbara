#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"estrutura.h"
#define TAM 4
#define OCUPADO 0
#define VACIO 1







int main()
{
    char seguir='s';
    sJuegos juegos[TAM];
    int codJuegos=100;
    int bandera=0;

    inicializarJuegos (juegos, TAM);



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
            printf("\n\n Cerrando sistema ...\n\n");
            seguir='n';
            break;
        }


    }
    while(seguir== 's');



    return 0;

}

void listarjuegosOrdenados (sJuegos juego [], int tam)

{
    sJuegos juegoAux;

    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if ( (juego[j].importe > juego[i].importe) && juego[j].isEmpty==0 && juego[i].isEmpty==0)
            {
                juegoAux=juego[i];
                juego[i]=juego[j];
                juego[j]=juegoAux;
            }
            else if ( (juego[j].importe == juego[i].importe) && juego[i].isEmpty==0 && juego[j].isEmpty==0)
            {
                if (strcmp(juego[j].descripcion,juego[i].descripcion)>0)
                {
                    juegoAux=juego[i];
                    juego[i]=juego[j];
                    juego[j]=juegoAux;
                }
            }
        }
    }


    for (int i=0; i<tam ; i++)
    {

        if( juego[i].isEmpty == OCUPADO)
        {
            listarUnjuego(juego[i]);
        }

    }



}


