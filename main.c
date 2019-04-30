#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 10
#define VACIO 1
#define OCUPADO 0



int main()


{
    sEmployee empleados[TAM];
    sSector sector[3];
    int idAut=3;
    int bandera=0;
    char continuar='s';


    initEmployees(empleados,TAM);
    harcodearSector(sector);
    harcodearEmpleados(empleados);

    system("cls");

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            addEmployees(empleados, TAM, idAut);
            idAut++;
            bandera=1;
            break;
        case 2:
            system("cls");
            if ( bandera==0 )
            {
                printf("\nNo se ingresaron datos!\n\nIngrese a ALTA de empleado. \n\n");
            }
            else
            {
                modifyEmployee(empleados,TAM,sector,3);
            }
            system("\n\n  pause \n\n");

            break;
        case 3:
            system("cls");
            if ( bandera==0 )
            {
                printf("\nNo se ingresaron datos!\n\n Ingrese ALTA de empleado.  \n\n");
            }
            else
            {
                removeEmployee (empleados,TAM,sector,3);
            }
            system("\n\n  pause \n\n");
            break;
        case 4:
            system("cls");
            if ( bandera==0 )
            {
                printf("\nNo se ingresaron datos!\n\nIngrese ALTA de empleado. \n\n");
            }
            else
            {

                sortEmployees(empleados,TAM,sector,3);
            }
             system("\n\n  pause \n\n");
            break;
        case 5:
            system("cls");
            printf("\n\n Cerrando sistema ...\n\n");
            continuar='n';
            break;
        }

    }
    while(continuar== 's');


    return 0;
}

