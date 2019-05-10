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

/** \brief inicializa todas el array 1 que indica ESTADO vacio.
 *
 * \param estructura de empleados.
 * \param cantidad de datos del sistema.
 * \return no retorna valor.
 *
 */

void initSocios ( eSocio socios  [], int tam)
{
    for (int i=0 ; i< tam; i++)
    {
        socios[i].isEmpty = VACIO;
    }

}



/** \brief busca el indice vacio donde cargar un empleado.
 *
 * \param la estrutura empleado
 * \param el tamaño de la estrutura-
 * \return el indice se que encuentea vacio.
 *
 */


int buscarLibreSocios(eSocio socios [], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( socios[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}




/** \brief de da de alta un cliente.
 *
 * \param cod de cliente que se da de alta.
 * \param -
 * \return los datos del cliente dado de alta.
 *
 */

eSocio altaSocio (int codigoSocio)
{

    eSocio unSocios;

    char lastnameAux[31];
    char nameAux [31];
    char sexoAux [5];
    char telefonoAux[16];
    char mailAux [31];
    char diaAux[5];
    char mesAux[5];
    char anioAux[5];

    system("cls");
    printf("\n ****  ALTA DE SOCIOS  **** \n\n");

    printf("Codigo de socio: %d \n",codigoSocio );

    while(!getStringLetras("\nIngrese apellido del socio :  ",lastnameAux));
    while(!getStringLetras("\nIngrese nombre del socio :  ",nameAux));

    function_continueform("\nIngrese sexo del socio  f o m :  ", sexoAux);
    strcpy(unSocios.sexo,sexoAux) ;

    while(!getStringtelefono("\nIngrese telefono del socio:   ",telefonoAux ));
    while(!getStringLetras("\nIngrese mail del socio :  ",mailAux));

    while(!getStringNumeros("\nIngrese fecha del asociado.\nIngrese Dia:  ", diaAux));
    while(!getStringNumeros("\nIngrese Mes:  ", mesAux));
    while(!getStringNumeros("\nIngrese Anio: ", anioAux));


    strcpy(unSocios.lastname,lastnameAux) ;
    strcpy(unSocios.name,nameAux) ;
    strcpy(unSocios.telefono,telefonoAux);
    unSocios.fecha.dia=atoi(diaAux);
    unSocios.fecha.mes=atoi(mesAux);
    unSocios.fecha.anio=atoi(anioAux);

    return unSocios;

}

/** \brief Realiza el alta por sistema
 *
 * \param la estructura empleados.
 * \param tamaño de la estructura.
 * \param id de los empledos. autoincremental.
 * \return no tiene retorno.
 *
 */


void addSocio ( eSocio socio [], int tam, int idAut)

{

    int indice;

    system("cls");
    printf(" **** ALTA DE SOCIO **** \n\n");

    indice = buscarLibreSocios(socio, tam);

    if (indice == -1 )
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }

    else
    {
        socio[indice] = altaSocio(idAut);
        socio[indice].id= idAut;
        socio[indice].isEmpty=OCUPADO;

        printf(" \n\n Alta efectuada! \n\n");

    }

}




/** \brief Re realiza el harcodeo de la categoria juegos.
 *
 * \param los elecmentos de la estructura.
 * \param -
 * \return no tiene retorno.
 *
 */
void cargarSocios(eSocio socios[], int tam)
{
    eSocio s []=
    {

        {1,"Insaurralde","Barbara","f", "4296-4827 ", "barbi_Agus22@hotmail.com", {7,5,19}, 1},
        {2,"Martinez","Magali","f","4222-6969", "magali@homail.com   ",              {10,5,19},1},
        {3,"Silva   ", "Gonzalo","m","4379-6500", "zalo89@hotmail.com   ",           {7,5,19},1},
        {4,"Dominguez","Pedro","m","2639-5555 ", "pedro_insaurralde@yahoo.com.ar", {1,5,19}, 1},


    };

    for(int i=0; i < tam; i++)
    {
        socios[i] = s[i];
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void listarUnSocio (eSocio socio)

{
    printf("\n\t%d\t%s\t%s\t\t%s\t%s\t%s\t\t%d/%d/%d", socio.id,socio.lastname, socio.name, socio.sexo, socio.telefono, socio.mail,socio.fecha.dia, socio.fecha.mes, socio.fecha.anio);

}

void printSocios (eSocio socios [], int tam)
{
    //system("cls");
    printf("\n  ******  DETALLLE DE SOCIOS  ****** \n\n");

    printf("\n\tID\tAPELLIDO\tNOMBRE\t\tSEXO\tTELEFONO\tMAIL\t\t\t\tFECHA\n\n ");

    for (int i=0; i<tam ; i++)
    {

        if( socios[i].isEmpty == OCUPADO)
        {
            listarUnSocio(socios[i]);
        }

    }
    //system("\npause\n");

}

int findSocios( eSocio socios [], int tam, int idAuto)

{
    int indice= -1 ;

    for (int i=0 ; i<tam ; i++)
    {
        if ( socios[i].id ==idAuto && socios[i].isEmpty== OCUPADO)
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

void modifySocios (eSocio socios [], int tam )
{
    int idAut;
    int indice;
    int opcion;
    char idAux[10];

    char lastnameAux[31];
    char nameAux [31];
    char sexoAux [5];
    char telefonoAux[16];
    char mailAux [31];


    system("cls");
    printf("\n ******  MODIFICACION SOCIOS  ****** \n");

    printSocios(socios,tam);

    while(!getStringNumeros("\n\n Ingrese ID del socio que desea modificar:  ", idAux));

    idAut= atoi(idAux);

    indice = findSocios(socios, tam, idAut);
    if( indice == -1)
    {
        printf("ERROR, No hay socios con el ID:  %d \n\n", idAut);
        system("pause");
    }
    else
    {
        //mostrarAutor(autores[indice]);
        printf(" \n\n");
        printf("Que desea modificar? \n");
        printf("1. Apellido \n");
        printf("2. Nombre \n");
        printf("3. Sexo \n");
        printf("4. Telefono \n");
        printf("5. Mail \n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {

        case 1:
            while( !getStringLetras("\nInsegre nuevo apellido: ",lastnameAux));
            strcpy(socios[indice].lastname,lastnameAux);
            printf("\nModificacion Realizada\n\n");
            break;
        case 2:
            while(!getStringLetras("\nInsegre nuevo nombre: ", nameAux));
            strcpy(socios[indice].name,nameAux);
            printf("\n\nModificacion Realizada\n\n");
            break;
        case 3:
            function_continueform("\nIngrese sexo del socio  f o m :  ", sexoAux);
            strcpy(socios[indice].sexo,sexoAux);
            printf("\n\nModificacion Realizada\n\n");
            break;
        case 4:
            while(!getStringtelefono("\nIngrese telefono del socio:   ",telefonoAux ));
            strcpy(socios[indice].telefono,telefonoAux);
            printf("\n\nModificacion Realizada\n\n");
            break;
        case 5:
            while(!getStringLetras("\nIngrese mail del socio :  ",mailAux));
            strcpy(socios[indice].mail,mailAux);
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

void removeSocio (eSocio socios [], int tam)
{

    int idAut;
    int indice;
    char idAux[20];

    system("cls");
    printf("\n ******  BAJA DE SOCIOS  ****** \n");
    printSocios(socios,tam);
    printf(" \n\n");
    while(!getStringNumeros("\n\n  Ingrese ID a dar de BAJA :  ", idAux) );
    idAut= atoi(idAux);

    indice = findSocios(socios, tam, idAut);
    if( indice == -1)
    {
        printf("\n ERROR, No hay socio con el ID:  %d \n\n", idAut);
        system("pause");
    }
    else
    {
        //mostrarEmpleado(empleados[indice]);
        socios[indice].isEmpty = VACIO;
        printf(" \n\n Baja efectuada\n\n");
    }
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void listarSociosOrdenados (eSocio socios [], int tam)

{
    eSocio sociosAux;

    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if ( strcmp(socios[j].lastname,socios[i].lastname)<0 && socios[j].isEmpty==OCUPADO && socios[i].isEmpty==OCUPADO)
            {
                sociosAux=socios[i];
                socios[i]=socios[j];
                socios[j]=sociosAux;
            }
            else if ( strcmp(socios[j].lastname,socios[i].lastname)==0  && socios[j].isEmpty==OCUPADO && socios[i].isEmpty==OCUPADO)
            {
                if (strcmp(socios[j].name,socios[i].name)>0)
                {
                    sociosAux=socios[i];
                    socios[i]=socios[j];
                    socios[j]=sociosAux;
                }
            }
        }
    }

     printf("\n\tID\tAPELLIDO\tNOMBRE\t\tSEXO\tTELEFONO\tMAIL\t\t\t\tFECHA\n ");

    for (int i=0; i<tam ; i++)
    {

        if( socios[i].isEmpty == OCUPADO)
        {
            listarUnSocio(socios[i]);
        }

    }



}


void obtenerSocio (eSocio socio[], int tams, int id, char cadena[] )

{
    for(int i=0; i < tams; i++)
    {

        if( socio[i].id == id)
        {
            strcpy(cadena, strcat(socio[i].lastname,socio[i].name) );

        }
    }



}





