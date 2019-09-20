#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    int A=0;
    int B=0;
    int AValido=0;
    int BValido=0;
    int opcionElegida;
    int suma;
    int resta;
    int multiplicacion;
    int factorialnumA;
    int factorialnumB;
    float division;
    int dividirPorCero=0;

    do {
        menuCalculadora(A,B);
        if (!getNumero(&opcionElegida,"\nIngresar opcion: ","Error, la opcion ingresada no es valida.",1,5,5))
            {
                switch(opcionElegida)
                {
                    case 1: system("cls");
                            getNumero(&A,"Digite un numero entre 0 y 150: ","Error, el numero ingresado no es valido, reintente: ",0,150,5);
                            AValido=1;
                            system("cls");
                            break;
                    case 2: system("cls");
                            getNumero(&B,"Digite un numero entre 0 y 150: ","Error, el numero ingresado no es valido, reintente: ",0,150,5);
                            BValido=1;
                            system("cls");
                            break;
                    case 3: if(AValido==1 && BValido==1)
                            {
                            sumar(A,B,&suma);
                            restar(A,B,&resta);
                            multiplicar(A,B,&multiplicacion);
                            dividirPorCero=dividir(A,B,&division);
                            factorial(A,&factorialnumA);
                            if(A==0)
                            {
                                factorialnumA=1;
                            }
                            factorial(B,&factorialnumB);
                            if(B==0)
                            {
                                factorialnumB=1;
                            }
                            printf("\nLos calculos fueron realizados exitosamente!!\n\n");
                            }
                            else
                            {
                                printf("Faltan valores, debe ingresarlos: ");
                            }
                            break;
                    case 4: if(AValido==1 && BValido==1)
                            {
                                informarResultados(suma,resta,dividirPorCero,division,multiplicacion,factorialnumA,factorialnumB);
                            }
                            else
                            {
                                printf("Faltan valores, debe ingresarlos: ");
                            }
                            break;
                    case 5: opcionElegida=5;
                            break;

                }
            }
        }while(opcionElegida!=5);

    return 0;
}
