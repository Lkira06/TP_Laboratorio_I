#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define OCUPADO 0
#define EMPTY 1

int menuIndex()
{
    char auxOption[2];
    int option;
    system("cls") ;
    printf("\n    MENU DE OPCIONES\n\n");
    printf("1- Altas\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Informar\n");
    printf("5- Salir\n\n");
    while(!function_getStringNumeros("Ingresar opcion: ",auxOption))
    {
        printf("\nDebe ingresar un numero del 1 al 5. \n") ;
        system("pause") ;

    }
    option = atoi(auxOption) ;
    return option;
}

void initEmployees(Employee list[], int len)
{
    int i;
    for(i=0; i < len; i++)
    {
        list[i].isEmpty = EMPTY;
    }
}

int buscarLibre(Employee list[], int len)
{
    int indice = -1;
    int contador;
    for(contador=0; contador < len; contador++){
        if( list[contador].isEmpty == 1){
            indice = contador;
            break;
        }
    }
    return indice;
}

void cargarSectores(eSector sectores[])
{
    eSector sectoresExistentes[]=
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };

    for(int i=0; i < 5; i++)
    {
        sectores[i] = sectoresExistentes[i];
    }
}

void listarSectores(eSector sectores[], int len)
{
  printf("\nId de Sector   Descripcion\n\n");
    for(int i=0; i< len; i++){
      printf("      %d         %10s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\n");
}

int addEmployee(Employee list[], int len, eSector sectores[], int lenSector)
{
    int indice;
    int control;
    char seguir;
    int flag=0;
    Employee nuevoEmpleado;

    indice = buscarLibre(list, len);
    system("cls");
    printf("\n    ALTA EMPLEADO\n\n");
    if(indice == -1)
        {
            control = -1;
        }else{
            nuevoEmpleado.id = indice + 1;
            control = getString(nuevoEmpleado.name, "Ingrese Nombre: ", "Error, el nombre solo puede contener letras: ",3,51,3);
            if(control == 0)
                {
                printf("No se logro ingresar el nombre correctamente.\n");
                }else{
                    control = getString(nuevoEmpleado.lastName, "Ingrese Apellido: ", "Error, el Apellido solo puede contener letras: ",3,51,3);
                    if(control == 0)
                    {
                    printf("No se logro ingresar el Apellido correctamente.\n");
                    }else{
                        control = getFloat(&nuevoEmpleado.salary, "Ingrese sueldo: ", "Error, sueldo solo puede contener numeros y estar entre 4.000 y 35.000 : ", 4000.00,35000.00,3);
                        if(control == 0)
                        {
                        printf("No se logro ingresar el Sueldo correctamente.\n");
                        }else{
                            listarSectores(sectores, lenSector);
                            control = getInt(&nuevoEmpleado.sector, "Ingrese sector: ", "Error, ingrear solo numeros entre 1 y 5: ",1,5,3);
                            if(control == 0)
                            {
                            printf("No se logro ingresar el Sector correctamente.\n");
                            }else{
                                    printf("\nConfima el alta? s/n: ");
                                    fflush(stdin);
                                    scanf("%c", &seguir);
                                    if(seguir == 'n')
                                    {
                                        printf("Alta cancelada\n\n");
                                    }else{
                                                nuevoEmpleado.isEmpty = OCUPADO;
                                                list[indice] = nuevoEmpleado;
                                                printf("\nEl empleado ha sido registrado con exito!\n\n");
                                                flag=1;
                                            }
                                            system("pause");
                                }
                }
            }
        }
    }
    return flag;
}

int findEmployeeById(Employee list[], int len, int legajo)
{
    int indice = -1;
    int contador;
    for(contador=0; contador < len; contador++){
        if( list[contador].id == legajo && list[contador].isEmpty == OCUPADO){
            indice = contador;
            break;
        }
    }
    return indice;
}

void obtenerSector(eSector sectores[], int len, int idSector, char cadena[])
{
    for(int contador=0; contador < len; contador++){
        if( sectores[contador].id == idSector){
            strcpy(cadena, sectores[contador].descripcion);
        }
    }
}

void showEmployee(Employee list, eSector sectores[], int lenSector)
{
    char descSector[31];
    obtenerSector(sectores,lenSector, list.sector, descSector);
    printf("%4d %10s %10s     %6.2f %10s\n", list.id, list.name, list.lastName, list.salary, descSector);
}

int empleadoExiste(Employee list[], int len)
{
    int flag = -1;
    int contador;
    for(contador=0; contador < len; contador++)
        {
            if( list[contador].isEmpty == OCUPADO)
            {
                flag = contador;
                break;
            }
    }
    return flag;
}

int menuModificarEmpleado(Employee list[], int indice, eSector sectores[], int lenSector)
{
    int opcion;
    int nuevoSector;
    int control;
    char nuevoNombre[51];
    char nuevoApellido[51];
    float nuevoSueldo;
    system("cls");
    printf("\nQue desea modificar?\n\n");
    printf(" 1- Nombre\n");
    printf(" 2- Apellido\n");
    printf(" 3- Salario\n");
    printf(" 4- Sector\n\n");
    control = getInt(&opcion, "Ingrese opcion: ", "Debe ingresar un numero del 1 al 4.",1,4,3);
    switch(opcion)
        {
            case 1:
                control = getString(nuevoNombre,"\n\nIngrese nuevo nombre: ","Error, el Nombre solo puede contener letras: ",3,19,3);
                strcpy(list[indice].name, nuevoNombre);
                break;
            case 2:
                control = getString(nuevoApellido, "\n\nIngrese nuevo apellido: ", "\nError, el Apellido solo puede contener letras: ",3,19,3);
                strcpy(list[indice].lastName, nuevoApellido);
                break;
            case 3:
                control = getFloat(&nuevoSueldo, "\n\nIngrese nuevo sueldo: ", "\nError, salario solo puede contener numeros y estar entre 4.000 y 35.000 : ",4000.00,35000.00,3);
                list[indice].salary = nuevoSueldo;
                break;
            case 4:
                listarSectores(sectores, lenSector);
                control = getInt(&nuevoSector, "\nIngrese nuevo sector: ", "Error, ingrear solo numeros entre 1 y 5: ",1,5,3);
                list[indice].sector = nuevoSector;
                break;
    }
    return control;
}

int ModificarEmpleado(Employee list[], int len, int *legajo, eSector sectores[], int lenSector)
{
    int indice;
    int control;
    int flag;
    char seguir;

    printf("\n    MODIFICAR EMPLEADO\n\n");
    control = getInt(legajo, "\nIngrese legajo: ", "Error, ingrese solo numeros entre 1 y 1000: ",1,1000,3);
    if(control != 1)
        {
            flag = 0;
            printf("No se obtuvo el numero de legajo.");
            system("pause");
        }else{
            indice = findEmployeeById(list, len, *legajo);
            if(indice == -1){
            flag = -1;
            }else{
                printf("Legajo   Nombre   Apellido     Sueldo     Sector\n");
                showEmployee(list[indice], sectores, lenSector);
                printf("\nDesea modificar algun campo? s/n: ");
                fflush(stdin);
                scanf("%c", &seguir);
            while(!(seguir == 'n' || seguir == 's'))
            {
                printf("Error, solo debe ingresar 's' o 'n': ");
                fflush(stdin);
                scanf("%c", &seguir);
            }
            if(seguir == 'n' || seguir == 'N')
            {
                flag = 0;
            }else{
                flag = menuModificarEmpleado(list, indice, sectores, lenSector);
            }
        }
    }
    return flag;
}

int removeEmployee(Employee list[], int len, int legajo, eSector sectores[], int lenSector)
{
    int indice;
    int control;
    int flag;
    char seguir;

    system("cls");
    printf("\n    BAJA EMPLEADO\n\n");
    control = getInt(&legajo, "Ingrese legajo: ", "Error, el legajo solo puede contener numeros y estar entre 1 y 1000: ",1,1000,3);
     if(control != 1)
        {
            flag = 0;
            printf("No se pudo ingresar el numero de legajo.");
        }else{
            indice = findEmployeeById(list,len,legajo);
            if( indice == -1)
            {
                flag = -1;
            }else{
                    printf("Legajo  Nombre   Apellido    Sueldo     Sector\n");
                    showEmployee(list[indice], sectores, lenSector);
                    printf("\nConfima baja? s/n: ");
                    fflush(stdin);
                    scanf("%c", &seguir);
                    while(!(seguir == 'n' || seguir == 's' || seguir == 'N' || seguir == 'S')){
                        printf("Error, solo debe ingresar 's' o 'n', reingrese: ");
                        fflush(stdin);
                        scanf("%c", &seguir);
                    }
                    if(seguir == 'n' || seguir == 'N'){
                        flag = 0;
                    }else{
                        list[indice].isEmpty = 1;
                        flag = 1;
                        }
                }
    }
    return flag;
}

int getFloat(float *x, char ing[], char err[], float inf, float sup, int chances)
{
    int control;
    int flag = 0;
    float aux;
    printf("%s", ing);
    control = scanf("%f", &aux);
    chances--;
    while((control != 1 || aux < inf || aux > sup) && chances>=1)
        {
            printf("%s", err);
            fflush(stdin);
            control = scanf("%f", &aux);
            chances--;
        }
    if(control == 1)
        {
            flag = 1;
            *x = aux;
        }
    return flag;
}

int getInt(int *x, char ing[], char err[], int inf, int sup, int chances)
{
    int control;
    int flag = 0;
    int aux;
    printf("%s", ing);
    control = scanf("%d", &aux);
    chances--;
    while((control != 1 || aux < inf || aux > sup) && chances>=1)
        {
            printf("%s", err);
            fflush(stdin);
            control = scanf("%d", &aux);
            chances--;
        }
    if(control == 1)
        {
            flag = 1;
            *x = aux;
        }
    return flag;
}

void function_getString (char msj[],char input[])
{
    printf("%s",msj);
    fflush(stdin) ;
    gets(input) ;
}

int validStrArray(char string[])
{
    int aux;
    int contador;
    for(contador = 0; contador < strlen(string); contador++)// recorre el array.
        {
        if(!(isalpha(string[contador]))) //isalpha Indica si un carácter es alfabético.
            {
                aux = 0; //Algún caracter no es letra.
                break;
            }
            aux = 1; //Todos los caracteres son letras.
        }
    return aux;
}

int menuInformar()
{
    char auxOption[2];
    int option;
    system("cls") ;
    printf("\n    MENU DE INFORMES\n\n");
    printf("1- Listado de los empleados\n");
    printf("2- Total y promedio de los salarios, empleados superan el salario promedio.\n");
    printf("3- Salir\n\n");
    while(!function_getStringNumeros("Ingresar opcion: ",auxOption))
    {
        printf("\nDebe ingresar un numero del 1 al 3. \n") ;
        system("pause") ;

    }
    option = atoi(auxOption) ;
    return option;
}

void ordenarApellido(Employee list[], int len)
{
    int i;
    int j;
    Employee auxEmpleado;

    for(i=0; i<len-1; i++)
    {
        for (j=i+1; j<len; j++)
        {
            if(strcmp(list[i].lastName,list[j].lastName)>0)
            {
                auxEmpleado=list[i];
                list[i]=list[j];
                list[j]=auxEmpleado;
            }
        }
    }
}

void printEmployees(Employee list[], int len, eSector sectores[], int lenSector)
{
    system("cls");
    printf("\n    LISTA DE EMPLEADOS\n\n");
    printf("Legajo   Nombre   Apellido      Sueldo      Sector\n\n");
    for(int contador=0; contador < len; contador++){
        if( list[contador].isEmpty == 0){
            showEmployee(list[contador], sectores, lenSector);
        }
    }
    printf("\n");
}

void sortEmployess(Employee list[], int len)
{
    int i;
    int j;
    Employee aux;
    for(i=0; i<len-1; i++){
        for(j=i+1; j<len; j++){
            if(list[i].sector > list[j].sector){
                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }else{
                if((list[i].sector == list[j].sector) && strncmp(list[i].lastName, list[j].lastName, 6) > 0){
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
    }
}

float totalSalary(Employee list[], int len)
{

    int i;
    float acumuladorS=0;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            acumuladorS=acumuladorS + list[i].salary;
        }
    }
    return acumuladorS;
}

int lenEmpleados(Employee list[], int len)
{

    int cantidadEmpleados=0;
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            cantidadEmpleados++;
        }
    }

    return cantidadEmpleados;
}

float promSalary(Employee list[], int len)
{
    float promSalario;
    float totalSalario;
    int cantidadEmpleados;
    cantidadEmpleados=lenEmpleados(list, len);
    totalSalario=totalSalary(list, len);
    promSalario=totalSalario/cantidadEmpleados;
    return promSalario;
}

void EmployeesExceedSalary(Employee list[] , int len, float promSalarios)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == OCUPADO && list[i].salary >= promSalarios)
            {
            printf("Salario: %.2f   ",list[i].salary);
            printf("Empleado: %s %s\n",list[i].lastName,list[i].name);
            }
    }
}

int getString(char string[], char ing[], char err[], int inf, int sup, int chances)
{
    int length;
    int control;
    printf("%s", ing);
    fflush(stdin);
    gets(string);
    control = validStrArray(string);
    length = strlen(string);
    chances--;
    while((length < inf || length > sup || control == 0) && chances >= 1) //validacion de largo de caractares con 3 oportunidades.
        {
            chances--;
            printf("%s", err);
            fflush(stdin);
            gets(string);
            control = validStrArray(string);
        }
    return control;
}

int function_esNum(char str[])
{
    int ret = 1;
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            ret =  0;
        i++;
    }
    return ret;
}

int function_getStringNumeros(char msj[],char input[])
{
    int ret = 0;
    char aux[256];
    function_getString(msj,aux);
    if(function_esNum(aux))
    {
        strcpy(input,aux);
        ret = 1;
    }
    return ret;
}
