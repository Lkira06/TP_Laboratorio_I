#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* pFile;
    pFile = fopen(path,"r");
    if(parser_EmployeeFromText(pFile , pArrayListEmployee) == 0)
    {
        printf("Se cargaron los datos correctamente.\n");
        retorno = 0;
    }else{
        printf("No se pudieron cargar los datos.");
        }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path, "rb");
    if(pFile != NULL && parser_EmployeeFromBinary(pFile, pArrayListEmployee) == 0)
    {
        printf("Se cargaron los datos correctamente.\n");
        retorno = 0;
    }
    else
    {
        printf("No se pudieron cargar los datos.");
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_cargarEmployee(pArrayListEmployee) == 0)
    {
        printf("El nuevo empleado ha sido agregado correctamente.");
        retorno = 0;
    }else{
            printf("El nuevo empleado no ha podido ser agregado correctamente.");
        }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_modificarEmployee(pArrayListEmployee) == 0)
    {
        printf("El empleado se ha modificado exitosamente.\n");
        retorno = 0;
    }
    else{
            printf("El empleado no ha podido ser modificado correctamente.\n");
        }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno =- 1;
    if(employee_borrarEmployee(pArrayListEmployee) == 0)
    {
        printf("El empleado se ha borrado correctamente.\n");
        retorno=0;
    }
    else
    {
        printf("El empleado no se ha podido borrar correctamente.\n");
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int auxId;
    char auxNombre[1024];
    int auxHorasTrabajadas;
    int auxSueldo;
    int size;
    int retorno = -1;
    size = ll_len(pArrayListEmployee);
    Employee* auxEmployee;
    if(size > 0)
    {
        for(i=0; i < size; i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            if( employee_getId(auxEmployee, &auxId) == 0 &&
                employee_getNombre(auxEmployee, auxNombre) == 0 &&
                employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas) == 0 &&
                employee_getSueldo(auxEmployee, &auxSueldo) == 0)
            {
                printf("ID: %.02d   Nombre: %10s   Horas Trabajadas: %4d   Sueldo: %6d \n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
                retorno = 0;
            }
            else
            {
                printf("\nNo se pudo mostrar la lista.\n");
            }
        }
         printf("\nLa cantidad de empleados es: %d.\n", size);
    }
    else
    {
        printf("\nNo se encuentra la lista cargada.\n");
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int seguir = 1;
    if(pArrayListEmployee != NULL)
    {
        do{
            switch(menuSort())
            {
                case 1:
                        printf("\nEspere un momento...\n\n");
                        ll_sort(pArrayListEmployee, employee_SortId, 0);
                        break;
                case 2:
                        printf("\nEspere un momento...\n\n");
                        ll_sort(pArrayListEmployee, employee_SortNombre, 0);
                        break;
                case 3:
                        printf("\nEspere un momento...\n\n");
                        ll_sort(pArrayListEmployee, employee_SortHoras, 0);
                        break;
                case 4:
                        printf("\nEspere un momento...\n\n");
                        ll_sort(pArrayListEmployee, employee_SortSalario, 0);
                        break;
                case 5:
                        seguir = 0;
                        break;
                default:
                        printf("\n\n Debe ingresar un numero del 1 al 5.\n\n");
                        system("pause");
                        break;
            }
        printf("\nLos empleados han sido ordenados exitosamente.\n\n");
        system("pause");
        system("cls");
        }while(seguir);
    retorno = 0;
    }else{
            printf("Los empleados no han podido ser ordenados como corresponde.");
        }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_guardarDatosenTexto(pArrayListEmployee, path) == 0)
    {
        printf("Los datos han sido guardados correctamente.");
        retorno = 0;
    }else{
            printf("Los datos no se han guardaron, intente nuevamente.");
        }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee) //revisar copia fiel
{
    FILE* pFile = fopen(path, "wb");
    Employee* pEmployeeAux;
    int retorno = -1;
    int listLen = ll_len(pArrayListEmployee);
    int i;

    if(pFile == NULL)
        {
            printf("Error al guardar\n");
            return retorno;
        }
    if(pArrayListEmployee!=NULL)
        {
            for(i = 0; i < listLen; i++)
                {
                    pEmployeeAux = (Employee*)ll_get(pArrayListEmployee, i);
                    fwrite(pEmployeeAux,sizeof(Employee), 1, pFile);
                }
            printf("Archivo binario guardado.\n");
            retorno = 0;
        }
    fclose(pFile);
    return retorno;
}

