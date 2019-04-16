#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployee.h"
#define TAM 3
#define VACIO 0
#define OCUPADO 1




int main()
{

    eEmployee employee[TAM];
    int idAut=4;
    initEmployees(employee,TAM);

    hardCodearEmpleado(employee, TAM);

    char continuar= 's';



    switch(menu())
    {
        do{

        case 1:
        system("cls");
        printf("Opcion alta\n ");

        break;
        case 2:
        system("cls");
        printf("Opcion Modificar.");
        break;
        case 3:
        system("cls");
        printf("Opcion Baja.");
        break;
        case 4:
        system("cls");
        printf("Opcion Informes");
        break;
        case 5:
        system("cls");
        printEmployees(employee, TAM);
        break;
        case 6:
        system("cls");
        continuar='n';
        printf("Cerrando");
        break;

        }while(continuar== 's');



    }



    return 0;
}

/*int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{




 return -1;
}*/

int findEmployeeById(Employee[] list, int len,int id)
{
    int index=-1;

    for ( int i=0; i<len ; i++)
    {
        //if (list)

    }



 return index;
}

