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
    char opcionAux[5];

    system("cls");
    printf("\n ***** MENU DE OPCIONES : Nomina Empleados *****\n\n");
    printf(" 1- Alta\n");
    printf(" 2- Modificar\n");
    printf(" 3- Baja\n");
    printf(" 4- Informes \n");
    printf(" 5- Salir\n\n");

    while(!getStringNumeros("Ingrese opcion: ",opcionAux))
    {
        {
            printf("Error! Ingrese una opcion correcta.\n\n");
            system("pause");
            fflush(stdin);
        }
    }
    opcion=atoi(opcionAux);
    if(opcion<1 || opcion>5)
    {
        printf("Error! Ingrese una opcion correcta.\n\n");
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

void mostrarEmpleado (sEmployee  empleado)

{
    printf(" %10d    %10s     %10s     %10f    %10d     \n\n ", empleado.id,empleado.name, empleado.lastname, empleado.salary, empleado.sector );

}

/** \brief para mostrar todos los empleados del la estrutura.
 *
 * \param la estrutura empleado.
 * \param cantidad de datos del sistema, tamaño.
 * \return no retorna valor.
 *
 */

void printEmployeess (sEmployee empleados [], int tam)
{
    system("cls");
    printf("\n  ******  DETALLLE DE EMPLEADOS  ****** \n\n");

    printf("\n\n         ID       NOMBRE        APELLIDO        SALARIO        SECTOR\n\n");

    for (int i=0; i<tam ; i++)
    {

        if( empleados[i].isEmpty == OCUPADO)
        {
            mostrarEmpleado(empleados[i]);
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

     while(!getStringLetras("\n Ingrese nombre del empleado: \n",nameAux))
            {
                system("cls");
                printf("\n Error! solo debe contener letras.\n");
            }

    while(!getStringLetras("\nIngrese apellido del empleado: \n",lastNameAux))
            {
                system("cls");
                printf("\n Error! solo debe contener letras.\n");
            }

    while(!getStringNumeros("\nIngrese salario del empleado: \n",salarioAux))
            {
                system("cls");
                printf("\nError! solo debe contener letras.\n");
            }

    while(!getStringNumeros("\nIngrese sector del empleado: \n",sectorAux))
            {
                system("cls");
                printf("\nError! solo debe contener letras.\n");
            }

    strcpy(empleado.name,nameAux) ;
    strcpy(empleado.lastname,lastNameAux);
    empleado.sector=atoi(sectorAux);
    empleado.salary=atoi(salarioAux);


    return empleado;

}
/** \brief modifica datos de un empleado.
 *
  * \param la estructura empleados.
 * \param tamaño de la estructura.
 * \return no tiene retorno.
 *
 */

void modifyEmployee (sEmployee empleados [], int tam )
{
    int idAut;
    int indice;
    int opcion;
    char confirma;

    system("cls");

    printf("\n ******  MODIFICACION EMPLEADOS  ****** \n");

    printf("\n Ingrese ID de empleado:  ");
    scanf("%d",&idAut );

    indice = findEmployeeById(empleados, tam, idAut);
    if( indice == -1)
    {
        printf("ERROR, No hay empleado con el ID:  %d \n\n", idAut);
        system("pause");
    }
    else
    {
        printf(" \n\n   ID         NOMBRE         APELLIDO        SALARIO        SECTOR   \n\n");
        mostrarEmpleado(empleados[indice]);
        printf(" \n\n");

        printf("\n Desea MODIFICAR ? s=SI n = NO :  ");
        fflush (stdin);
        scanf("%c", &confirma);

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

                printf("\nInsegre nuevo nombre: \n");
                fflush (stdin);
                gets(empleados[indice].name);
                printf("\nModificacion Realizada\n\n");
                break;
            case 2:
                system("cls");
                printf("\nInsegre nuevo apellido: \n");
                fflush (stdin);
                gets(empleados[indice].lastname);
                printf("\nModificacion Realizada\n\n");
                break;
            case 3:
                system("cls");

                printf("\nInsegre nuevo salario: \n");
                scanf("%f", &empleados[indice].salary);
                printf("Modificacion Realizada\n\n");
                break;
            case 4:
                system("cls");
                printf("\n ******  MODIFICACION EMPLEADOS  ****** \n\n");
                printf("\nInsegre nuevo Sector: \n");
                scanf("%d", &empleados[indice].sector);
                printf("Modificacion Realizada\n\n");
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

void removeEmployee (sEmployee empleados [], int tam)
{

    int idAut;
    int indice;
    char confirma;

    system("cls");
    printf("\n ******  BAJA DE EMPLEADOS  ****** \n");

    printf("\n Ingrese ID a dar de BAJA :  ");
    scanf("%d",&idAut );

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

        printf("\n Confirma la BAJA ? s=SI n = NO :  \n\n");
        fflush (stdin);
        scanf("%c", &confirma);

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
/** \brief realiza un informe sobre datos ingresados.
 *
 * \param la estructura empleados.
 * \param el tamaño de la estructura.
 * \return no tiene retorno.
 *
 */


void sortEmployees (sEmployee empleados [], int tam)

{

    int opcion;

    system("cls");
    printf("\n ******  INFOMES EMPLEADOS  ****** \n\n");
    printf(" Que informe desea ? :   \n\n");
    printf("\n1. Empleados ordenados alfabeticamente por Apellido y Sector. \n");
    printf("\n2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.  \n\n\n");
    printf("\n Ingrese una opcion :  \n");
    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:
        system("cls");
        ordenarPorApellidoySectorAscendente(empleados, tam);
        printEmployeess(empleados,tam);
        break;

    case 2:
        printf("no llegue");
        system("pause");
        break;

    }

}
/** \brief ordena de forma ascendete y decente el apellido y sector.
 *
 * \param estructura empleado.
 * \param tamaña de la estructura.
 * \return no tiene retorno.
 *
 */


void ordenarPorApellidoySectorAscendente (sEmployee empleados [], int tam )

{
    sEmployee auxEmpleado;
    int ordenar;

    system("cls");
    printf("\n ******  INFOMES EMPLEADOS  ****** \n\n");
    printf("\n1. Orden Ascendente \n");
    printf("\n2. Orden Descendente \n\n\n");
    printf("\n Ingrese una opcion :  \n");
    scanf("%d", &ordenar);

    switch(ordenar)
    {
    case 1:
        system("cls");
        printf("\n ****** ORDEN ASCENDETE ****** \n\n");

        for(int i = 0; i < tam-1; i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if(strcmp(empleados[j].lastname, empleados[i].lastname) > 0 && empleados[j].isEmpty == 0 && empleados[i].isEmpty == 0)
                {
                    auxEmpleado = empleados[i];
                    empleados[i] = empleados[j];
                    empleados[j] = auxEmpleado;

                }
                else if(strcmp(empleados[j].lastname, empleados[i].lastname) == 0 && empleados[j].sector > empleados[i].sector  && empleados[j].isEmpty == 0 && empleados[i].isEmpty == 0)
                {
                    auxEmpleado = empleados[i];
                    empleados[i] = empleados[j];
                    empleados[j] = auxEmpleado;

                }
            }
        }
        printf("\n\n El orden  ASCENDENTEMENTE de empleados fue efecuado.\n\n");

        system("\n\npause\n\n");


        break;
    case 2:
        system("cls");
        for(int i = 0; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(strcmp(empleados[j].lastname, empleados[i].lastname) < 0  && empleados[j].isEmpty == 0 && empleados[i].isEmpty == 0)
                {
                    auxEmpleado = empleados[i];
                    empleados[i] = empleados[j];
                    empleados[j] = auxEmpleado;
                }
                else if(strcmp(empleados[j].lastname, empleados[i].lastname) == 0 && empleados[j].sector < empleados[i].sector  && empleados[j].isEmpty == 0 && empleados[i].isEmpty == 0)
                {
                    auxEmpleado = empleados[i];
                    empleados[i] = empleados[j];
                    empleados[j] = auxEmpleado;
                }
            }
        }
        printf("\n\nEl orden  DECENTEMENTE de empleados fue efecuado.  \n \n");

        system("\n\npause\n\n");

        break;
    }
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


int soloNumero(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9')&&(str[i]!='.')&&(str[i]!=',')&&(str[i]!=NULL)&&(str[i]!=' '))
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
        while(str[i] != '\0')
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
    if(soloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0 ;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */

int getStringNumeros(char msj[],char input[])
{
    char aux[256];
    getString(msj,aux);
    if(soloNumero(aux))
    {
        strcpy(input,aux);

        return 1;
    }
    return 0;
}



