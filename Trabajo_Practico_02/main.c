#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define TAMe 1000
#define TAMs 5

int main()
{
    Employee empleados[TAMe];
    eSector sector[5];
    cargarSectores(sector);
    initEmployees(empleados,TAMe);
    int legajo;
    int control;
    int seguir = 1;
    float totalSalario;
    float promSalario;
        do{
            switch(menuIndex())
                {
                    case 1:
                            addEmployee(empleados,TAMe,sector,TAMs);
                            break;
                    case 2:
                            control = empleadoExiste(empleados,TAMe);
                            if(control== -1)
                            {
                                printf("\nNo se puede modificar. Primero debe dar de alta al menos 1 empleado\n\n");
                                system("pause");
                            }else{
                                    printEmployees(empleados,TAMe,sector,TAMs);
                                    system("pause");
                                    control= ModificarEmpleado(empleados,TAMe,&legajo,sector,TAMs);
                                    if(control ==-1)
                                        {
                                            printf("No hay ningun empleado con legajo: %d",legajo);
                                        }else if(control == 0)
                                            {
                                            printf("Modificacion cancelada.\n\n");
                                            system("pause");
                                            }else{
                                                printf("Modificacion exitosa!!\n\n");
                                                system("pause");
                                                    }
                                }
                            break;
                    case 3:
                            control = empleadoExiste(empleados,TAMe);
                            if(control== -1)
                            {
                                printf("\nNo se puede dar de baja. Primero debe dar de alta al menos 1 empleado\n\n");
                                system("pause");
                            }else{
                                    control= removeEmployee(empleados,TAMe,legajo,sector,TAMs);
                                    if(control ==-1)
                                        {
                                            printf("No hay ningun empleado con legajo: %d",legajo);
                                        }else if(control == 0)
                                            {
                                            printf("Baja cancelada.\n\n");
                                            system("pause");
                                            }else{
                                                printf("Baja realizada con exito.\n\n");
                                                system("pause");
                                                    }
                                 }
                            break;
                    case 4:
                            control = empleadoExiste(empleados, TAMe);
                            if(control == -1)
                                {
                                printf("\nNo se puede ingresar al menu de informes. Primero debe dar de alta al menos 1 empleado\n\n");
                                system("pause");
                                }else{
                                    int continuar = 1;
                                    do{
                                        switch(menuInformar())
                                            {
                                            case 1:
                                                    sortEmployess(empleados,TAMe);
                                                    printEmployees(empleados,TAMe,sector,TAMs);
                                                    system("pause");
                                                    break;
                                            case 2:
                                                    totalSalario = totalSalary(empleados,TAMe);
                                                    promSalario = promSalary(empleados,TAMe);
                                                    printf("\n    TOTAL Y PROMEDIO DE LOS SALARIOS\n\n");;
                                                    printf("Total de salarios: %.2f \n\n",totalSalario);
                                                    printf("Promedio salario: %.2f \n\n",promSalario);
                                                    printf("Empleados que superan el promedio: \n\n");
                                                    EmployeesExceedSalary(empleados,TAMe,promSalario);
                                                    system("pause");
                                                    break;
                                            case 3:
                                                    continuar = 0 ;
                                                    break;
                                            default:
                                                    printf("\n\n Debe ingresar un numero del 1 al 3.\n\n");
                                                    system("pause");
                                                    break;
                                            }
                                    }while(continuar);
                                    }
                            break;
                    case 5:
                            seguir = 0 ;
                            break;
                    default:
                            printf("\n\n Debe ingresar un numero del 1 al 5.\n\n");
                            system("pause");
                            break;
                }
        }while(seguir);
        return 0;
}
