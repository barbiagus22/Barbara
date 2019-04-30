#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define VACIO 1
#define OCUPADO 0

/** \brief es un menu de opcion.
 *
 * \param no recibe paramertros.
 * \param no recibe paramertros.
 * \return la opcion eleigda-
 *
 */

int menu()
{
    int opcion;
    char opcionAux[6];

    system("cls");
    printf("\n ***** MENU DE OPCIONES : Nomina Empleados *****\n\n");
    printf(" 1- Alta\n");
    printf(" 2- Modificar\n");
    printf(" 3- Baja\n");
    printf(" 4- Informes \n");
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

/** \brief inicializa todas el array 1 que indica vacio.
 *
 * \param estructura de empleados.
 * \param cantidad de datos del sistema.
 * \return no retorna valor.
 *
 */

void initEmployees ( sEmployee empleados [], int tam)
{
    for (int i=0 ; i< tam; i++)
    {
        empleados[i].isEmpty= VACIO;
    }
}

/** \brief muestra un empleados
 *
 * \param la estrutura empleado.
 * \param ///
 * \return no retorna valor.
 *
 */

void mostrarEmpleado (sEmployee  empleado, sSector sec [], int tams)

{
    char descripcion [51];

    obtenerSector(sec,tams,empleado.sector,descripcion);

    printf("\t\%d\t\t\%s\t\t\%s\t\t\%2.0f\t\t\%s\t\t\n ", empleado.id,empleado.name, empleado.lastname, empleado.salary, descripcion );

}

/** \brief para mostrar todos los empleados del la estrutura.
 *
 * \param la estrutura empleado.
 * \param cantidad de datos del sistema, tamaño.
 * \return no retorna valor.
 *
 */

void printEmployeess (sEmployee empleados [], int tam, sSector sec [], int tams)
{
    system("cls");
    printf("\n  ******  DETALLLE DE EMPLEADOS  ****** \n\n");

    printf("\n\t\ID\t\t\NOMBRE\t\t\APELLIDO\t\SALARIO\t\t\SECTOR\n ");

    for (int i=0; i<tam ; i++)
    {

        if( empleados[i].isEmpty == OCUPADO)
        {
            mostrarEmpleado(empleados[i],sec,tams);
        }

    }
    system("pause");
}

/** \brief busca el indice vacio donde cargar un empleado.
 *
 * \param la estrutura empleado
 * \param el tamaño de la estrutura-
 * \return el indice se que encuentea vacio.
 *
 */

int buscarLibre( sEmployee empleados [], int tam)

{
    int indice= -1;

    for (int i= 0 ; i<tam; i ++)
    {
        if (empleados[i].isEmpty== VACIO)
        {
            indice=i;
        }
    }
    return indice;
}

/** \brief busca el indice donde se encuentra un  empleado por numero de id.
 *
 * \param la estructura empleados.
 * \param tamaño de la estructura.
 * \param id de los empledos. autoincremental.
 * \return el indice donde se encuentra ese id de empleado.
 *
 */

int findEmployeeById( sEmployee empleados [], int tam, int idAuto)

{
    int indice= -1 ;

    for (int i=0 ; i<tam ; i++)
    {
        if ( empleados[i].id ==idAuto && empleados[i].isEmpty== OCUPADO)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

/** \brief alta de un empleado.
 *
 * \param la estructura empleados.
 * \param tamaño de la estructura.
 * \param id de los empledos. autoincremental.
 * \return no tiene retorno.
 *
 */


void addEmployees ( sEmployee empleados [], int tam, int idAut)

{

    int indice;

    system("cls");
    printf(" **** ALTA DE EMPLEADOS **** \n\n");

    indice = buscarLibre(empleados, tam);

    if (indice == -1 )
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }

    else
    {
        empleados[indice] = altaempleado(idAut);
        empleados[indice].id= idAut;
        empleados[indice].isEmpty=OCUPADO;
        system("pause");

    }

}
/** \brief alta de emleados. solicita ingreso de datos.
 *
 * \param recibe el id donde cargar ese empleado
 * \param //
 * \return el empleado cargado en ese id-
 *
 */

sEmployee altaempleado (int idAut)

{

    sEmployee empleado;

    char nameAux [25];
    char lastNameAux [25];
    char salarioAux[11];
    char sectorAux[11];

    system("cls");

    printf("\n ****  ALTA DE EMPLEADOS  **** \n\n");

    printf("ID Empleado: %d \n",idAut );

    while(!getStringLetras("\n Ingrese nombre del empleado: ",nameAux));

    while(!getStringLetras("\nIngrese apellido del empleado: ",lastNameAux));

    while(!getStringNumeros("\nIngrese salario del empleado: ",salarioAux));
    empleado.salary=atof(salarioAux);

    while(empleado.salary<=0 )// VALLIDAR QUE SEA MAYOR A UN NUMERO Y COPIARLO EN EL VALOR DE LA ESTRUCTURA.

    {
        printf("\n El importe debe ser mayor a 0 \n");
        while(!getStringNumeros("\nInsegre nuevo salario:  ",salarioAux));
        if (empleado.salary<=0)
        {
            empleado.salary=atof(salarioAux);
            break;
        }
    }

    printf("\n\n1. RRHH");
    printf("\n2. Sistemas");
    printf("\n3. Marketing");
    while(!getStringNumeros("\nIngrese sector del empleado: ",sectorAux));


    strcpy(empleado.name,nameAux) ;
    strcpy(empleado.lastname,lastNameAux);
    empleado.sector=atoi(sectorAux);


    return empleado;
}
/** \brief modifica datos de un empleado.
 *
  * \param la estructura empleados.
 * \param tamaño de la estructura.
 * \return no tiene retorno.
 *
 */

void modifyEmployee (sEmployee empleados [], int tam , sSector sec[], int tams)
{
    int idAut;
    int indice;
    int opcion;
    char confirma;
    char nameAux [25];
    char lastNameAux [25];
    char salarioAux[11];
    char sectorAux[11];
    char idAux[10];

    system("cls");
    printf("\n ******  MODIFICACION EMPLEADOS  ****** \n");

    while(!getStringNumeros("\n Ingrese ID de empleado:  ", idAux));

    idAut= atoi(idAux);

    indice = findEmployeeById(empleados, tam, idAut);
    if( indice == -1)
    {
        printf("ERROR, No hay empleado con el ID:  %d \n\n", idAut);
        system("pause");
    }
    else
    {
        printf("\n\t\ID\t\t\NOMBRE\t\t\APELLIDO\t\SALARIO\t\t\SECTOR\n ");
        mostrarEmpleado(empleados[indice],sec, tams);
        printf(" \n\n");

        confirma =getChar("\n Desea MODIFICAR ? s=SI  n= NO :  ");
        while (confirma!= 's' || confirma != 'm')                                     ///valida que sea s o no
        {
            confirma =getChar("\n Error! Ingrese s=SI  n= NO  para modificar :  ");
            if (confirma == 's' || confirma== 'n')
            {
                break;
            }

        }

        if (confirma== 's')
        {
            printf(" \n Que desea modificar ? \n\n");
            printf("1. Nombre \n\n");
            printf("2. Apellido \n\n");
            printf("3. Salario \n\n");
            printf("4. Sector \n\n");
            printf("Ingrese opcion: ");
            scanf("%d", &opcion);

            switch (opcion)
            {

            case 1:
                system("cls");

                while( !getStringLetras("\nInsegre nuevo nombre: \n",nameAux));
                strcpy(empleados[indice].name,nameAux);
                printf("\nModificacion Realizada\n\n");
                break;
            case 2:
                system("cls");
                while(!getStringLetras("\nInsegre nuevo apellido: \n", lastNameAux));
                strcpy(empleados[indice].lastname,lastNameAux);
                printf("\nModificacion Realizada\n\n");
                break;
            case 3:
                system("cls");

                while(!getStringNumeros("\nInsegre nuevo salario: \n", salarioAux));
                empleados[indice].salary= atof(salarioAux);

                while(empleados[indice].salary<=0 )// VALLIDAR QUE SEA MAYOR A UN NUMERO Y COPIARLO EN EL VALOR DE LA ESTRUCTURA.

                {
                    printf("\n El importe debe ser mayor a 0 \n");
                    while(!getStringNumeros("\nInsegre nuevo salario:  ",salarioAux));
                    if (empleados[indice].salary<=0)
                    {
                        empleados[indice].salary =atof(salarioAux);
                        break;
                    }
                }
                printf("Modificacion Realizada\n\n");
                break;
            case 4:
                system("cls");
                printf("\n ******  MODIFICACION EMPLEADOS  ****** \n\n");
                while(!getStringNumeros("\nInsegre nuevo Sector: \n", sectorAux));
                empleados[indice].sector=atoi(sectorAux);
                printf("Modificacion Realizada\n\n");
                break;
            default:
                printf("No es una opcion valida.");
                break;
            }
        }
        else
        {
            printf("\n\n Modificacion Cancelada\n\n");
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

void removeEmployee (sEmployee empleados [], int tam, sSector sec [], int tams)
{

    int idAut;
    int indice;
    char confirma;
    char idAux[20];

    system("cls");
    printf("\n ******  BAJA DE EMPLEADOS  ****** \n");

    while(!getStringNumeros("\n Ingrese ID a dar de BAJA :  ", idAux) );
    idAut= atoi(idAux);

    indice = findEmployeeById(empleados, tam, idAut);
    if( indice == -1)
    {
        printf("\n ERROR, No hay empleado con el ID:  %d \n\n", idAut);
        system("pause");
    }
    else
    {
        printf(" \n\n   ID         NOMBRE         APELLIDO          SALARIO           SECTOR   \n\n");
        mostrarEmpleado(empleados[indice],sec, tams);
        printf(" \n\n");

        confirma =getChar("\n Confirma la BAJA ? s=SI  n= NO :  ");
        while (confirma!= 's' || confirma != 'm')                                     ///valida que sea s o no
        {
            confirma =getChar("\n Error! Ingrese s=SI  n= NO dar de baja:  ");
            if (confirma == 's' || confirma== 'n')
            {

                break;
            }

        }

        if (confirma== 's')
        {
            empleados[indice].isEmpty = 1;
            printf(" \n\n Baja efectuada \n\n");
        }
        else
        {
            printf("\n\n Baja cancelada\n\n");
        }
    }
}
/** \brief realiza un informe sobre datos ordenamiento y suma se sueldos.
 *
 * \param la estructura empleados.
 * \param el tamaño de la estructura.
 * \return no tiene retorno.
 *
 */


void sortEmployees (sEmployee empleados [], int tam, sSector sec[] , int tams)

{

    int opcion;
    int ordenar;
    int ordenarAscendente;
    int ordenarDecendente;


    system("cls");
    printf("\n ******  LISTADO DE EMPLEADOS  ****** \n");
    printf("\n\t\ID\t\t\NOMBRE\t\t\APELLIDO\t\SALARIO\t\t\SECTOR\n ");
      for (int i=0; i<tam ; i++)
    {

        if( empleados[i].isEmpty == OCUPADO)
        {
            mostrarEmpleado(empleados[i], sec, tams);
        }

    }
    printf("\n\n QUE DESEA MOSTRAR ? :   \n\n");
    printf("\n1. Empleados ordenados alfabeticamente por Apellido y Sector. \n");
    printf("\n2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.  \n\n\n");
    printf("\n Ingrese una opcion :  ");
    scanf("%d", &opcion);


    switch(opcion)
    {
    case 1:
        system("cls");
        printf("\n ******  INFOMES EMPLEADOS  ****** \n\n");
        printf("\nA. Orden Ascendente \n");
        printf("\nB. Orden Descendente \n\n\n");
        printf("\n Ingrese una opcion : ");
        scanf("%d", &ordenar);
        {
            switch(ordenar)
            {
            case 1:
                system("cls");
                printf("\n ******  INFOMES EMPLEADOS  ****** \n\n");
                printf("\n1. Por apellido \n");
                printf("\n2. Por sector \n\n");
                printf("\n Ingrese una opcion :  ");
                scanf("%d", &ordenarAscendente);

                {
                    switch (ordenarAscendente)
                    {
                    case 1:
                        ordenarPorApellidoAscendente(empleados, tam);
                        printEmployeess(empleados,tam, sec,tams);
                        system("pause");
                        break;
                    case 2:
                        ordenarPorSectorAscendente(empleados,tam);
                        printEmployeess(empleados,tam,sec,tams);
                        system("pause");
                        break;
                    }

                }
                break;


            case 2:
                system("cls");
                printf("\n ******  INFOMES EMPLEADOS  ****** \n\n");
                printf("\n1. Por apellido \n");
                printf("\n2. Por sector \n\n");
                printf("\n Ingrese una opcion :  ");
                scanf("%d", &ordenarDecendente);
                {
                    switch (ordenarDecendente)
                    {
                    case 1:
                        ordenarPorApellidoDescendente(empleados, tam);
                        printEmployeess(empleados,tam,sec,tams);
                        system("pause");
                        break;
                    case 2:
                        ordenarPorSectorDecendente(empleados,tam);
                        printEmployeess(empleados,tam,sec,tams);
                        system("pause");
                        printf("falta por sector");
                        break;
                    }

                }
                break;
            }
        }
    case 2:
        salariosEmpleados(empleados, tam);
        break;
    }
}

/** \brief ordena de forma ascendete los apellido
 *
 * \param estructura empleado.
 * \param tamaña de la estructura.
 * \return no tiene retorno.
 *
 */
void ordenarPorApellidoAscendente(sEmployee empleados [], int tam )

{
    sEmployee auxEmpleado;

    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if (strcmp(empleados[j].lastname,empleados[i].lastname )< 0 && empleados[j].isEmpty==0 && empleados[i].isEmpty==0)
            {
                auxEmpleado=empleados[i];
                empleados[i]=empleados[j];
                empleados[j]=auxEmpleado;
            }
            else if (strcmp(empleados[j].lastname,empleados[i].lastname)== 0 && empleados[i].isEmpty==0 && empleados[j].isEmpty==0)
            {
                if (strcmp(empleados[j].name,empleados[i].name)>0)
                {
                    auxEmpleado=empleados[i];
                    empleados[i]=empleados[j];
                    empleados[j]=auxEmpleado;
                }
            }
        }
    }

    printf("\n\n El orden  ASCENDENTEMENTE de empleados por apellido fue efecuado.\n\n");
    system("\n\npause\n\n");

}

/** \brief ordena de forma decendente los apellido
 *
 * \param estructura empleado.
 * \param tamaña de la estructura.
 * \return no tiene retorno.
 *
 */

void ordenarPorApellidoDescendente(sEmployee empleados [], int tam )

{
    sEmployee auxEmpleado;

    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if (strcmp(empleados[j].lastname,empleados[i].lastname )> 0 && empleados[j].isEmpty==0 && empleados[i].isEmpty==0)
            {
                auxEmpleado=empleados[i];
                empleados[i]=empleados[j];
                empleados[j]=auxEmpleado;
            }
            else if (strcmp(empleados[j].lastname,empleados[i].lastname)== 0 && empleados[i].isEmpty==0 && empleados[j].isEmpty==0)
            {
                if (strcmp(empleados[j].name,empleados[i].name)>0)
                {
                    auxEmpleado=empleados[i];
                    empleados[i]=empleados[j];
                    empleados[j]=auxEmpleado;
                }
            }
        }
    }

    printf("\n\n El orden  DESCENDENTE de empleados por apellido fue efecuado.\n\n");
    system("\n\npause\n\n");

}

/** \brief ordena por sector de manera alfabetica ascendente y sin son iguales los ordena por apellido.
 *
 * \param estructura empleado.
 * \param tamaña de la estructura.
 * \return no tiene retorno.
 *
 */

void ordenarPorSectorAscendente(sEmployee empleados [], int tam )

{
    sEmployee auxEmpleado;

    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if ((empleados[j].sector<empleados[i].sector ) && empleados[j].isEmpty==0 && empleados[i].isEmpty==0)
            {
                auxEmpleado=empleados[i];
                empleados[i]=empleados[j];
                empleados[j]=auxEmpleado;
            }
            else if ((empleados[j].sector==empleados[i].sector) && empleados[i].isEmpty==0 && empleados[j].isEmpty==0)
            {
                if (strcmp(empleados[j].lastname,empleados[i].lastname)>0)
                {
                    auxEmpleado=empleados[i];
                    empleados[i]=empleados[j];
                    empleados[j]=auxEmpleado;
                }
            }
        }
    }

    printf("\n\n El orden  ASCENDENTEMENTE de empleados por sector fue efecuado.\n\n");
    system("\n\npause\n\n");


}
/** \brief ordena por sector de manera alfabetica decendente y sin son iguales los ordena por apellido.
 *
 * \param estructura empleado.
 * \param tamaña de la estructura.
 * \return no tiene retorno.
 *
 */

void ordenarPorSectorDecendente(sEmployee empleados [], int tam )

{
    sEmployee auxEmpleado;

    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if ((empleados[j].sector>empleados[i].sector ) && empleados[j].isEmpty==0 && empleados[i].isEmpty==0)
            {
                auxEmpleado=empleados[i];
                empleados[i]=empleados[j];
                empleados[j]=auxEmpleado;
            }
            else if ((empleados[j].sector==empleados[i].sector) && empleados[i].isEmpty==0 && empleados[j].isEmpty==0)
            {
                if (strcmp(empleados[j].lastname,empleados[i].lastname)>0)
                {
                    auxEmpleado=empleados[i];
                    empleados[i]=empleados[j];
                    empleados[j]=auxEmpleado;
                }
            }
        }
    }

    printf("\n\n El orden  DESCENDENTE de empleados por sector fue efecuado.\n\n");
    system("\n\npause\n\n");


}

void salariosEmpleados (sEmployee empleados [], int tam)
{


    float totalSalary=0;
    int totalempleados=0;
    float promedioSalary=0;
    int contadordeSalaryMayoralamedia=0;

    for (int i=0; i<tam ; i++)
    {
        if (empleados[i].isEmpty==0)
        {
            totalSalary= empleados[i].salary + totalSalary;
            totalempleados++;

        }

    }

    promedioSalary= totalSalary/totalempleados;


    for (int i=0; i<tam ; i++)
    {
        if (empleados[i].salary > promedioSalary  && empleados[i].isEmpty== 0)

        {
            contadordeSalaryMayoralamedia++;
        }
    }

    system("cls\n");
    printf("\n - El total de salarios es : %.2f\n", totalSalary );
    printf("\n - EL promedios de salario es de :  %.2f\n", promedioSalary);
    printf("\n - Empleados que superan el salario promedio : %d\n\n", contadordeSalaryMayoralamedia);
    system("pause");
}


/** \brief solicita mje al usuario para el ingrese de un dato tipo flotante..
 *
 * \param Mensaje a ser mostrado al usuario.
 * \param //
 * \return el numero ingresado por el usuario.
 *
 */


float getFloat(char msj[])
{
    float aux;
    printf("%s",msj);
    scanf("%f",&aux);
    return aux;
}

/** \brief solicita mje al usuario para el ingrese de un dato tipo entero.
 *
 * \param Mensaje a ser mostrado al usuario.
 * \param //
 * \return el numero ingresado por el usuario.
 *
 */

int getInt(char msj[] )
{
    int resultado;
    printf("%s",msj);
    scanf("%d",&resultado);
    return resultado;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */

char getChar(char msj[])
{
    char aux;
    printf("%s",msj);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */


int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0' || str[i]!= NULL )
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int soloLetras(char str[])
{
    int i=0;
    int retorno = 1;
    if(str[i] == '\0')
        retorno = 0;
    else
    {
        while(str[i] != '\0'  )
        {
            if(  (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return no tiene retorno.
 */

void getString (char msj[],char input[])
{
    printf("%s",msj);
    fflush(stdin) ;
    gets(input) ;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */

int getStringLetras(char msj[],char input[])
{
    char aux[256];
    getString(msj,aux);

    if (msj != NULL)
    {
        if(soloLetras(aux))
        {
            strcpy(input,aux);
            return 1;
        }
        else
        {
            printf("\nError!, ingrese solo letras.\n");
        }
    }



    return 0 ;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */

int getStringNumeros(char mensaje[],char input[])
{


    char aux[256];
    getString(mensaje,aux);


    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    else
    {
        printf("Error, ingrese solo numeros.");
    }




    return 0;
}


void harcodearEmpleados ( sEmployee empl [])
{
    sEmployee m[]=

    {
      {1,"maria", "perez",2000,1,0},
      {2,"tomas", "irala",5000,2,0},
    };

    for(int i=0; i < 2; i++)
    {
        empl[i] = m[i];
    }
}


void harcodearSector ( sSector sector [])
{
    sSector m[]=

    {
      {1,"RRHH"},
      {2,"Sistemas"},
      {3,"Marketing"},
    };

    for(int i=0; i < 3; i++)
    {
        sector[i] = m[i];
    }
}

void obtenerSector (sSector sec [], int tam, int id, char cadena)
{

    for (int i=0; i<tam; i++)
    {
       if (sec[i].id==id)
        {
            strcpy(cadena, sec[i].descripcion);
        }

    }


}
