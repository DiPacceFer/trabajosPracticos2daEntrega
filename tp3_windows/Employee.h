#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

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
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int mostrarListaEmpleados(LinkedList* vec);
int mostrarEmpleado(Employee* empleado);

int buscarMayorId(LinkedList* vec, int* id);
int addEmployee(LinkedList* pArrayListEmployee, int* id);
int edit_nameEmployee(Employee* empleado);
int edit_horasTrabajadas(Employee* empleado);
int edit_sueldo(Employee* empleado);
int bajaEmpleado(LinkedList* listado, int* id);

int ordenarEmpleadosNombre(void* nombre1, void* nombre2);
int ordenarEmpleadosHorasTrabajadas(void* horas1, void* horas2);
int ordenarEmpleadosSueldo(void* sueldo1, void* sueldo2);


#endif // employee_H_INCLUDED
