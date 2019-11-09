#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
int employee_delete(Employee* this);
int employee_buscarPorId(LinkedList* pArrayEmployee, int idEmployee);

int employee_borrarEmployee(LinkedList* pArrayEmployee);
int employee_cargarEmployee(LinkedList* pArrayEmployee);

int employee_guardarDatosenTexto(LinkedList* pArrayEmployee, char* path);
int employee_modificarEmployee(LinkedList* pArrayEmployee);

int employee_setId(Employee* this, char* id);
int employee_getId(Employee* this, int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this, char* nombre);

int employee_setHorasTrabajadas(Employee* this, char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);

int employee_setSueldo(Employee* this, char* sueldo);
int employee_getSueldo(Employee* this, int* sueldo);

int employee_SortId(void* employeeA,void* employeeB);
int employee_SortNombre(void* employeeA,void* employeeB);
int employee_SortHoras(void* employeeA,void* employeeB);
int employee_SortSalario(void* employeeA,void* employeeB);
#endif // employee_H_INCLUDED
