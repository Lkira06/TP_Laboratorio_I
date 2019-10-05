#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}typedef Employee;

typedef struct{
    int id;
    char descripcion[31];
}eSector;


/** \brief Muestra el menu raiz de opciones.
 * \return Devuelve la opcion elegida.
 */
int menuIndex();

/** \brief Muestra el subMenu de informes.
 * \return Devuelve la opcion elegida.
 */
int menuInformar();

/** \brief Inicializa todo el array en Empty.
* \param list array empleados.
* \param len longitud del array.
* \return
*
*/
void initEmployees(Employee list[], int len);

/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera (isEmpty) en TRUE en todas las posiciones del array.
* \param list array empleados.
* \param len longitud del array.
* \return indice -1 error, 0 correcto.
*
*/
int buscarLibre(Employee list[], int len);

/** \brief carga los sectores existentes ya definidos.
* \param sectores array sectores.
* \return
*
*/
void cargarSectores(eSector sectores[]);

/** \brief recorre el array, y muestras los sectores.
* \param sectores array sectores.
* \param len longitud del array.
* \return
*
*/
void listarSectores(eSector sectores[], int len);

/** \brief Agrega en un array de empleados existente los valores recibidos como parámetro en la primer posición libre.
* \param list array empleados.
* \param len longitud del array empleado.
* \param sectores array sectores.
* \param lenSector longitud del array sector.
* \return flag -1 error, 0 correcto.
*
*/
int addEmployee(Employee list[], int len, eSector sectores[], int lenSector);

/** \brief busca un empleado por su id.
* \param list array empleados.
* \param len longitud del array empleado.
* \param legajo id del empleado.
* \return indice -1 error, 0 correcto.
*
*/
int findEmployeeById(Employee list[], int len, int legajo);

/** \brief obtiene la descripcion del id sector.
* \param sectores array sectores.
* \param len longitud del array sectores.
* \param idSector del sector.
* \param cadena array destino de la descripcion del sector.
* \return
*
*/
void obtenerSector(eSector sectores[], int len, int idSector, char cadena[]);

/** \brief Muestra el nombre,apellido,salario y descripcion del sector de un empleado.
* \param list array empleados.
* \param sectores array de sectores.
* \param lanSector longitud del array.
* \return
*
*/
void showEmployee(Employee list, eSector sectores[], int lenSector);

/** \brief Busca si hay empleados.
* \param list array empleados.
* \param len longitud del array.
* \return indice -1 error, 0 correcto.
*
*/
int empleadoExiste(Employee list[], int len);

/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
* \param list array empleados.
* \param len longitud del array empleado.
* \param legajo id del empleado.
* \return flag -1 error, 0 correcto.
*
*/
int findEmployeeById(Employee list[], int len, int legajo);

/** \brief Muestra el menu de modificacion.
* \param list array empleados.
* \param indice posicion del empleado en el array.
* \param sectores array de sectores.
* \param lenSector longitud del array sectores.
* \return flag -1 error, 0 correcto.
*
*/
int menuModificarEmpleado(Employee list[], int indice, eSector sectores[], int lenSector);

/** \brief Modifica el nombre,apellido,salario y sector.
* \param list array empleados.
* \param len longitud del array empleados.
* \param legajo puntero a legajo.
* \param sectores array de sectores.
* \param lenSector longitud del array sectores.
* \return flag -1 error, 0 correcto.
*
*/
int ModificarEmpleado(Employee list[], int len, int *legajo, eSector sectores[], int lenSector);

/** \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
* \param list array empleados.
* \param len longitud del array empleado.
* \param legajo id del empleado.
* \param sectores array sectores.
* \param lenSector longitud del array sector.
* \return flag -1 error, 0 correcto.
*
*/
int removeEmployee(Employee list[], int len, int legajo, eSector sectores[], int lenSector);

/** \brief Ordena alfabeticamente de manera descendente.
* \param list array empleados.
* \param len longitud del array empleado.
* \return
*
*/
void ordenarApellido(Employee list[], int len);

/** \brief Imprime el array de empleados de forma encolumnada.
* \param list array empleados.
* \param len longitud del array empleado.
* \param legajo id del empleado.
* \param sectores array sectores.
* \param lenSector longitud del array sector.
* \return
*
*/
void printEmployees(Employee list[], int len, eSector sectores[], int lenSector);

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
* \param list array empleados.
* \param len longitud del array empleado.
* \return
*
*/
void sortEmployess(Employee list[], int len);

/** \brief Recorre el array y guarda los salarios de los empleados.
* \param list array empleados.
* \param len longitud del array empleado.
* \return acumuladorS sumatoria de los salarios.
*
*/
float totalSalary(Employee list[], int len);

/** \brief Recorre el array y cuenta la cantidad de empleados.
* \param list array empleados.
* \param len longitud del array empleado.
* \return cantidadEmpleados cantidad de empleados dados de alta.
*
*/
int lenEmpleados(Employee list[], int len);

/** \brief Calcula el promedio del salario total de empleados.
* \param list array empleados.
* \param len longitud del array empleado.
* \return promSalario promedio.
*
*/
float promSalary(Employee list[], int len);

/** \brief Imprime los empleados que superan el promedio de salario.
* \param list array empleados.
* \param len longitud del array empleado.
* \param promSalarios promedio.
* \return
*
*/
void EmployeesExceedSalary(Employee list[] , int len, float promSalarios);



















        //-------VALIDACIONES-------//


/** \brief Pide y valida el ingreso de un entero.
 * \param *x es el puntero a empleado para pasar el input por referencia.
 * \param Ing es el mensaje del input.
 * \param Err es el mensaje de error.
 * \param Inf es limite menor
 * \param Sup es el limite mayor
 * \param Chances es la cantidad de oportunidades disponibles para cargar el número.
 * \return flag (-1) si no cargó el número; Uno (1) si cargó el número.
 */
int getInt(int *x, char ing[], char err[], int inf, int sup, int chances);

/** \brief Toma por input y valida un caracter, excluyendo letras y simbolos.
 * \param *x es el puntero a empleado para pasar el input por referencia.
 * \param Ing es el mensaje del input.
 * \param Err es el mensaje de error.
 * \param Inf es limite menor
 * \param Sup es el limite mayor
 * \param Chances es la cantidad de oportunidades disponibles para cargar el número.
 * \return flag (-1) si no cargó el número; Uno (1) si cargó el número.
 */
int getFloat(float *x, char ing[], char err[], float inf, float sup, int chances);

/** \brief Pide y valida un array de char.
 * \param String es el array en cuestion.
 * \param input Array donde se cargará el texto ingresado.
 * \return
 */
void function_getString (char msj[],char input[]);

/** \brief Valida que sea un numero.
 * \param String es el array en cuestion.
 * \return 0 si valido 1 si no.
 */
int function_esNum(char str[]);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param input Array donde se cargará el texto ingresado.
 * \return 1 si el texto contiene solo números.
 */
int function_getStringNumeros(char msj[],char input[]);

/** \brief Pide y valida un array de char.
 * \param String es el array en cuestion.
 * \param Ing es el mensaje.
 * \param Err es el mensaje de error.
 * \param Inf es limite menor
 * \param Sup es el limite mayor
 * \param Chances es la cantidad de oportunidades disponibles para cargar el array.
 * \return La cantidad de chances: Cero (0) si no cargó el array; Mayor o igual a Uno(>=1) si cargó el array.
 */
int getString(char string[], char ing[], char err[], int inf, int sup, int chances);

/** \brief Recorre el array buscando validar(en letras) los caracteres.
 * \param string es el array.
 * \return Retorna cero (0) si algún caracter del array NO es letra sino (1).
 */
int validStrArray(char string[]);

#endif // ARRAYEMPLOYEES_H_INCLUDED
