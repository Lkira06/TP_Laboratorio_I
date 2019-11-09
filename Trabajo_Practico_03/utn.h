#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int menuSort();

int library_getNombre(char* pNombre, char* msg, char* msgError);
int library_getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo);
int library_getEnteroSinLimites(int* pNum, int reint, char* msg, char* msgError);
int library_getNumeroDecimal(float *pNum, int reint, char* msg, char* msgError,float maximo,float minimo);
int library_getString(char* pBufferString,int limite);
int isInt(char* pBuffer);
int isIntConGuiones(char* pBuffer);
int isLetra(char* pBuffer);
int funcion_esNum(char str[]);
int funcion_getStringNumeros(char msj[],char input[]);
void funcion_getString(char msj[],char input[]);

#endif // UTN_H_INCLUDED
