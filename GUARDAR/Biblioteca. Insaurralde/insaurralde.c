#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "insaurralde.h"
#define OCUPADO 0
#define VACIO 1

/*

    FUNCIONES

    * Menu.
    * Validacion:
            1- De un numero entero dentro de un rango y validado.
            2- De un numero flotante dentro de un rango.
            3- getInt
            4- getChar
            5- getFloat
            6- getStringLetras(char msj[],char input[])
            7- getStringNumeros(char mensaje[],char input[])


    * Estructuras :
            *--------------- ALTA -----------
            1- case----
            2- init--inicia estado
            3- buscar libre
            4- sEmployee altaempleado (int idAut)
            5- void addEmployees ( sEmployee empleados [], int tam, int idAut) // alta por sistema
            *------------LISTAR-----------------
            1- void mostrarEmpleado (sEmployee  empleado)
            2- void printEmployeess (sEmployee empleados [], int tam)
            *-----------MODIFICAR---------------------
            1- int findEmployeeById( sEmployee empleados [], int tam, int idAuto)
            2-void modifyEmployee (sEmployee empleados [], int tam )
            *-----------BAJA-----------------------------
            1-removeEmployee (sEmployee empleados [], int tam)


            *------------ORDENAMIENTO-------------------
            1-listarjuegosOrdenados (sJuegos juego [], int tam)

    * Calculos: (tp calculadora)

            1- float ingresarOperando1 ( float operando1)
            2- float ingresarOperando2 ( float operando2)
            3- float suma( float operando1, float operando2)
            4- float resta(float operando1, float operando2)
            5- float division(float operando1, float operando2)
            6- float multiplicacion(float operando1, float operando2)
            7- float factorialUno (float operando1)





*/
/**< ---------------------------------------------------------    MENU   -------------------------------------------------------------------- */

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
    printf("\n ***** MENU DE OPCIONES : ALTA DE JUEGOS *****\n\n");
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

/**< ---------------------------------------------------SWICHT----------------------------------------------------------------------------------------------- */

  /*  sEmployee empleados[TAM];
    //int idAut=1;
    int bandera=0;
    char continuar='s';


    initEmployees(empleados,TAM);

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
                modifyEmployee(empleados,TAM);
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
                removeEmployee (empleados,TAM);
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
                sortEmployees(empleados,TAM);
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

*/


/**< ---------------------------------------------------ESTRUCTURA--------------   ALTA------------------------------------------------------------------------ */


/** \brief inicializa todas el array 1 que indica ESTADO vacio.
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

/** \brief busca el indice vacio donde cargar un empleado.
 *
 * \param la estrutura empleado
 * \param el tamaño de la estrutura-
 * \return el indice se que encuentea vacio.
 *
 */

int buscarLibre(sJuegos juegos[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( juegos[i].isEmpty == 1)
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

    while(!getStringLetras("\n Ingrese nombre del empleado: \n",nameAux));

    while(!getStringLetras("\nIngrese apellido del empleado: \n",lastNameAux));

    while(!getStringNumeros("\nIngrese salario del empleado: \n",salarioAux));
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

    while(!getStringNumeros("\nIngrese sector del empleado: \n",sectorAux));


    strcpy(empleado.name,nameAux) ;
    strcpy(empleado.lastname,lastNameAux);
    empleado.sector=atoi(sectorAux);


    return empleado;
}


/** \brief Realiza el alta por sistema
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

/**< ----------------------------------------------------------estructura---- LISTAR -------------------------------------------------- */

/** \brief muestra un empleados
 *
 * \param la estrutura empleado.
 * \param ///
 * \return no retorna valor.
 *
 */

void mostrarEmpleado (sEmployee  empleado)

{
    printf("\t\%d\t\t\%s\t\t\%s\t\t\%2.0f\t\t\%d\t\t\n ", empleado.id,empleado.name, empleado.lastname, empleado.salary, empleado.sector );

}



/** \brief Muestra por pantalla el array completo
 *
 * \param recibe la estructura
 * \param el atamaño
 * \return no tiene retorno.
 *
 */

void printEmployeess (sEmployee empleados [], int tam)
{
    system("cls");
    printf("\n  ******  DETALLLE DE EMPLEADOS  ****** \n\n");

    printf("\n\t\ID\t\t\NOMBRE\t\t\APELLIDO\t\SALARIO\t\t\SECTOR\n ");

    for (int i=0; i<tam ; i++)
    {

        if( empleados[i].isEmpty == OCUPADO)
        {
            mostrarEmpleado(empleados[i]);
        }

    }
    system("pause");

}


void listarUnjuego (sJuegos  juego)

{
    printf("\n\t\%d\t\t\t\%s\t\t\t\%2.f\t\t\t\n ", juego.codJuegos,juego.descripcion, juego.importe);

}




/**< ------------------------------------------------------------------MODIFICAR------------------------------------------------------------------- */

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

/** \brief Solicita modificacion de datos del empleado dado de alta.
 *
 * \param la estructura el array
 * \param tamaño del array
 * \return no tiene retorno
 *
 */

void modifyEmployee (sEmployee empleados [], int tam )
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
        mostrarEmpleado(empleados[indice]);
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

/**< ----------------------------------------------------------------BAJA----------------------------------------------------------------------- */

/** \brief dada de baja un empleado solicitando  numero de id-
 *
 * \param estructura empleados.
 * \param tamaño de empleado-
 * \return no tiene retorno-
 *
 */

void removeEmployee (sEmployee empleados [], int tam)
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
        mostrarEmpleado(empleados[indice]);
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



/**< -----------------------------------------------------ORDENAMIENTO------------------------------------------------------------------- */

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




























/**< ------------------------------------------------   VALIDACIONES ------------------------------------------------------------------------- */



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





/**< -------------------------------------------------------        FUNCIONES CALCULOS          ------------------------------------------------------------------------- */








/** 1

\brief Solicita un primer numero.
* \param operando1 es el primer numero a pedir para ejecutar operaciones.
* \return devuelve el valor ingresado  para ejeccion las operaciones necesarias.
*
*/
float ingresarOperando1 ( float operando1)
{
    printf( " \n Ingrese 1er operando ( A = x ):   \n\n ");
    scanf( "%f", &operando1);
    return operando1;

}

/** 2
 \brief Solicita un segundo numero, y se valida que no se igual a 0.
* \param operando1 es el primer numero a pedir para ejecutar operaciones.
* \return Devuelve el valor ingresado  para ejeccion las operaciones necesarias.
*
*/
float ingresarOperando2 ( float operando2)
{
    printf( " \n Ingrese 2do operando ( B = y ):   \n\n ");
    scanf( "%f", &operando2);
    return operando2;

}


/** 3
 \brief Ejecuta la suma de dos numeros.
* \param op1 es el 1er numero a sumar y op2 segundo a sumar.
* \return Devuelve el resultado de la suma.
*
*/
float suma( float operando1, float operando2)
{
    float suma;
    suma= operando1 +operando2;
    return suma;

}

/** 4
\brief Ejecuta la resta de dos numeros.
* \param op1 es el 1er numero a restar y op2 segundo a restar.
* \return Devuelve el resultado de la resta.
*
*/
float resta(float operando1, float operando2)
{
    float resta;
    resta= operando1-operando2;
    return resta;

}

/**5
 \brief Ejecuta la division de dos numeros.
* \param op1 es el 1er numero a dividir y op2 segundo a dividir.
* \return Devuelve el resultado de la division.
*
*/
float division(float operando1, float operando2)
{
    float division=0;
    division= operando1/operando2;
    return division;

}

/**6
\brief Ejecuta la multiplicacion de dos numeros.
* \param op1 es el 1er multiplicaciones y op2 segundo a multiplicar.
* \return Devuelve el resultado de la multiplicacion.
*
*/

float multiplicacion(float operando1, float operando2)
{
    float multiplicacion;
    multiplicacion= operando1*operando2;
    return multiplicacion;
}

/** 7
\brief La funcion calcula el factorial del primer operando ingresado.
 * \param operando1 es el numero ingresado por el usuario a la cual se va ejecutar la funcion.
 * \param x Es la variable creada para ejecutar el bucle for.
 * \return retorna el factorial del primer operando ingresado.
 *
 */

float factorialUno (float operando1)
{
    float x,factorialUno=1;

    for (x = operando1; x>1 ; x--)
    {
        factorialUno*=x;
    }
    return factorialUno;
}

/** \brief La funcion calcula el factorial del segundo operando ingresado.
 * \param operando2 es el numero ingresado por el usuario a la cual se va ejecutar la funcion.
 * \param x Es la variable creada para ejecutar el bucle for.
 * \return retorna el factorial del segundo operando ingresado.
 *
 */

float factorialDos (float operando2)
{
    float x,factorialDos=1;

    for (x = operando2; x>1 ; x--)
    {
        factorialDos*=x;
    }
    return factorialDos;
}



