#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "milibreria.h"


int main()
{
    int menu=5,banderaA=0,banderaB=0;
    float numeroA=0,numeroB=0;
    float Calculo1=0, Calculo2=0, Calculo3=0, Calculo4=0, Calculo5=0, Calculo6=0;


    do
    {
        system("cls");
        printf(" \n >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  CALCULADORA  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

        if (banderaA==1 )
        {
            printf(" 1 . Ingrese 1er operando ( A = %0.2f ) \n\n ", numeroA);
        }
        else
        {
            printf(" 1 . Ingrese 1er operando ( A = x ) \n\n ");
        }

        if (banderaB==1 )
        {
            printf("2 . Ingrese 2do operando ( B = %0.2f ) \n\n ", numeroB);
        }
        else
        {
            printf("2 . Ingrese 2do operando ( B = y ) \n\n ");
        }

        printf("3 . Calcule  (+ , - , * , / , n! ) \n\n");
        printf(" 4 . Resultados   \n\n");
        printf(" 5 . Salir  \n\n");
        printf("\n  >>>>>>>>>>>>>>>>>>>>>> Ingrese una opcion del MENU >>>>>>>>>>>>>>>>>>>>>>>> \n\n ");
        scanf ("%d", &menu);

        switch (menu)
        {
        case 1:
            system("cls");
            numeroA=ingresarOperando1(numeroA);
            banderaA=1;
            break;
        case 2:
            system("cls");
            numeroB= ingresarOperando2(numeroB);
            banderaB=1;
            break;
        case 3:
            if  (banderaA ==1 && banderaB==1)
            {
                Calculo1=suma(numeroA,numeroB);
                Calculo2=resta(numeroA,numeroB);
                Calculo3=division(numeroA,numeroB);
                Calculo4=multiplicacion(numeroA,numeroB);
                Calculo5=factorialUno(numeroA);
                Calculo6=factorialDos(numeroB);

                system("cls");
                printf( "\n\n Calculando operaciones. . \n\n\n\n ");
                system("\n Pause");
                system("cls");
            }
            else if (banderaA ==0 || banderaB==0 )
            {
                system("cls");
                printf("\n Falta ingresar un operando. \n\n\n");
                system("\n\n Pause");
            }
            break;
        case 4:
            if  (banderaA ==1 && banderaB==1)
            {
                system("cls");
                printf ("\n Resultado de ( A + B ) es : %0.2f \n\n",Calculo1);
                printf (" Resultado de ( A - B ) es : %0.2f \n\n",Calculo2);
                if(numeroB==0)
                {
                    printf(" Resultado de ( A / B ) es : No se puede dividir por Cero \n\n");
                }
                else
                {
                    printf(" Resultado de ( A / B ) es : %0.2f    \n\n",Calculo3);
                }

                printf (" Resultado de ( A * B ) es : %0.2f \n\n",Calculo4);
                printf (" El factorial de A es: %0.2f y El factorial de B es: %0.2f  \n\n\n",Calculo5, Calculo6);
                system("\n Pause");
                system("cls");
            }
            else if (banderaA ==0 || banderaB==0 )
            {
                system("cls");
                printf("\n Falta ingresar un operando. \n\n\n");
                system("\n\n Pause");
            }
            break;
        case 5:
            system("cls");
            printf(" \n Saliendo . . . \n\n");
            system(" Pause");
            break;
        default:
            system("cls");
            printf ("\n No es una opcion de valida.\n\n Ingrese una opcion de MENU: \n\n\n\n");
            system("\n Pause");
            break;
        }

    }
    while (menu != 5);

    return 0;

}


