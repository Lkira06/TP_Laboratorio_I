#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int flagCargaArchivos = 0;
    int flagCargaModoTexto;
    int flagCargaModoBinario;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        printf("--MENU DE CONTROL DE EMPLEADOS--\n\n1.Cargar datos del archivo data.csv(modo texto)\n2.Cargar datos del archivo data.csv(modo binario)\n3.Alta de empleado\n4.Modificar empleado\n5.Baja de empleado\n6.Listar empleados\n7.Ordenar empleados\n8.Guardar datos en el archivo data.csv (modo texto)\n9.Guardar los datos en el archivo data.csv (modo binario)\n10.Salir\n\nIngrese una opcion: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: if(flagCargaArchivos == 0)
                    {
                        flagCargaModoTexto = controller_loadFromText("data.csv",listaEmpleados);
                        if(flagCargaModoTexto == 0)
                        {
                            flagCargaArchivos = 1;
                        }else{
                                printf("\nError al cargar la lista de texto.\n");
                            }
                    }else{
                            printf("\nLa lista ya fue cargada anteriormente.\n");
                        }
                    break;
            case 2: if(flagCargaArchivos == 0)
                        {
                           flagCargaModoBinario = controller_loadFromBinary("data.bin",listaEmpleados);
                           if(flagCargaModoBinario == 0)
                           {
                               flagCargaArchivos = 1;
                           }else{
                                   printf("\nError al cargar la lista binaria.\n");
                                }
                        }else{
                               printf("\nLa lista ya fue cargada anteriormente\n");
                            }
                    break;
            case 3: if(flagCargaArchivos == 1)
                        {
                            controller_addEmployee(listaEmpleados);
                        }else{
                                printf("\nSe debe cargar la lista de empleados para poder dar un alta.\n");
                        }
                    break;
            case 4: if(flagCargaArchivos == 1)
                        {
                            controller_ListEmployee(listaEmpleados);
                            controller_editEmployee(listaEmpleados);
                        }else{
                                printf("\nSe debe cargar la lista de empleados para poder modificar.\n");
                        }
                    break;
            case 5: if(flagCargaArchivos == 1)
                        {
                            controller_ListEmployee(listaEmpleados);
                            controller_removeEmployee(listaEmpleados);
                        }else{
                                printf("\nSe debe cargar la lista de empleados para poder dar un alta.\n");
                        }
                    break;
            case 6: if(flagCargaArchivos == 1)
                        {
                            controller_ListEmployee(listaEmpleados);
                        }else{
                                printf("\nSe debe cargar la lista de empleados para poder dar una baja.\n");
                            }
                    break;
            case 7: if(flagCargaArchivos == 1)
                        {
                            controller_sortEmployee(listaEmpleados);
                        }else{
                               printf("\nSe debe cargar la lista de empleados para poder ordenar.\n");
                            }
                    break;
            case 8: controller_saveAsText("data.csv",listaEmpleados);
                    break;
            case 9: controller_saveAsBinary("data.bin",listaEmpleados);
                    break;
        }
    system("pause");
    system("cls");
    }while(option != 10);
    return 0;
}
