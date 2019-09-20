#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

int menuCalculadora(int x,int y);
int getInt(int *pResultado);
int getNumero(int* pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos);
int sumar(int A,int B,int* r);
int restar(int A,int B,int* r);
int multiplicar(int A,int B,int* r);
int dividir(int A,int B,float* r);
int factorial(int A,int *r);
int informarResultados(int suma,int resta,int dividirPorCero,float division,int multiplicacion,int factorialnumA,int factorialnumB);

#endif // BIBLIOTECA_H_INCLUDED
