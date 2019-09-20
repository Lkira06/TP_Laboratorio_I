#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

/**
* \brief muestra el menu de la calculadora
* \param A el primer entero que reemplaza a "x"
* \param B el segundo entero que reemplaza a "y"
* \return Si todo salio bien [0] si no [-1]
*/
int menuCalculadora(int x,int y)
{
    printf("---> MENU CALCULADORA <---\n");
    printf("\n1. Ingresar 1er operando (A=%d) \n2. Ingresar 2do operando (B=%d) \n3. Calcular todas las operaciones \n4. Informar resultados \n5. Salir\n",x,y);
    return 0;
}

/**
* \brief toma el ingreso por consola de un char y lo transforma en un entero
* \param pResultado donde se guarda el numero entero
* \return Si todo salio bien [0] si no [-1]
*/
int getInt(int *pResultado)
{
    char buffer[64];
    scanf("%s",buffer);

    *pResultado = atoi(buffer);
    return 0;
}

/**
* \brief Pedir un numero, validar si esta entre los parametros, de caso contrario muestra mensaje de error, y tiene cantidad de reintentos.
* \param pResultado donde se guardara el numero entero
* \param const char mensaje el mensaje a ser mostrado
* \param const char mensaje el mensaje de error a ser mostrado
* \param minimo numero minimo aceptado
* \param maximo numero maximo aceptado
* \param reintentos cantidad de veces a reintentar
* \return Si todo salio bien [0] si no [-1]
*/
int getNumero(int* pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    int num;

    while (reintentos>0)
    {
        printf("%s",mensaje);
        if (getInt(&num)==0)
        {
            if (num<=maximo && num>=minimo)
            {
                break;
            }
        }
                fflush(stdin);
                reintentos--;
                printf("%s\n",mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }else
        {
            ret=0;
            *pResultado = num;
        }
    return ret;
}

/**
* \brief suma a+b
* \param A el primer entero a sumar
* \param B el segundo entero a sumar
* \return Si obtuvo el numero [0] si no [-1]
*/
int sumar(int A,int B,int* r)
{
    *r=A+B;
    return 0;
}

/**
* \brief resta a-b
* \param A el primer entero a restar
* \param B el segundo entero a restar
* \return Si obtuvo el numero [0] si no [-1]
*/
int restar(int A,int B,int* r)
{
    *r=A-B;
    return 0;
}

/**
* \brief multiplica a*b
* \param A el primer entero a multiplicar
* \param B el segundo entero a multiplicar
* \return Si obtuvo el numero [0] si no [-1]
*/
int multiplicar(int A,int B,int* r)
{
    *r=A*B;
    return 0;
}

/**
* \brief divide a/b
* \param A el primer flotante a dividir
* \param B el segundo flotante a dividir
* \return Si obtuvo el numero [0] si no [-1]
*/
int dividir(int A,int B,float* r)
{
    int retorno =-1;
    if(B==0)
    {
        retorno=-1;

    }
    else
    {
       *r=(float)A/B;
       retorno=0;
    }

    return retorno;
}

/**
* \brief obtiene el factorial de A
* \param A el entero a sacar factorial
* \return Si obtuvo el numero [0] si no [-1]
*/
int factorial(int A,int *r)
{
    int i;
    *r=A;
    A--;
    for (i=1;i<A;A--)
    {
        *r = *r * A;
    }
    return 0;
}

/**
* \brief informa los resultados obtenidos de las operaciones
* \param resultado de la suma
* \param resultado de la resta
* \param si se dividio por cero
* \param resultado de la division
* \param resultado de la multiplicacion
* \param resultado del factorial del entero A
* \param resultado del factorial del entero B
* \return Si obtuvo el numero [0] si no [-1]
*/
int informarResultados(int suma,int resta,int dividirPorCero,float division,int multiplicacion,int factorialnumA,int factorialnumB)
{
    printf("\nEl resultado de A+B es: %d",suma);
    printf("\nEl resultado de A-B es: %d",resta);
    if(dividirPorCero)
    {
       printf("\nNo es posible dividir por cero");
    }
    else
    {
       printf("\nEl resultado de A/B es: %.2f\n",division);
    }
    printf("El resultado de A*B es: %d",multiplicacion);
    printf("\nEl factorial de A es: %d y El factorial de B es: %d\n\n",factorialnumA,factorialnumB);
    return 0;
}
