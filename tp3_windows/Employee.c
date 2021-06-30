
#include "Employee.h"

Employee* employee_new()
{
	Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));
	    if(nuevoEmpleado != NULL)
	    {
	        nuevoEmpleado->id = 0;
	        strcpy(nuevoEmpleado->nombre, "");
	        nuevoEmpleado->horasTrabajadas = 0;
	        nuevoEmpleado->sueldo = 0;

	    }
	    return nuevoEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* nuevoEmpleado = employee_new();
	    if(nuevoEmpleado != NULL)
	    {
	        if(!(employee_setId(nuevoEmpleado, atoi(idStr)) &&
	           employee_setNombre(nuevoEmpleado, nombreStr)&&
	             employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))&&
	             employee_setSueldo(nuevoEmpleado, atoi(sueldoStr))))
	        {
	          //employee_delete(nuevoEmpleado);
	          nuevoEmpleado = NULL;
	        }
	    }
	    return nuevoEmpleado;
}
void employee_delete(Employee* empleado)
{
	free(empleado);
}

int employee_setId(Employee* this,int id)
{
	int isOk=0;
	    if(this != NULL && id > 0)
	    {
	        this->id = id;
	        isOk=1;
	    }
	    return isOk;
}
int employee_getId(Employee* this,int* id)
{
	int isOk=0;
	if(this != NULL && id != NULL)
	    {
	        *id = this->id;
	        isOk=1;
	    }
	    return isOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int isOk=0;
	    if(this != NULL && nombre != NULL && strlen(nombre) < 128)
	    {
	        strcpy(this->nombre, nombre);
	        isOk= 1;
	    }
	    return isOk;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int isOk=0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
	    isOk=1;
    }
	return isOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int isOk=0;
	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
        isOk=1;
	}
	return isOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int isOk=0;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		isOk=1;
    }
	return isOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int isOk=0;
	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
	    isOk=1;
	}
	return isOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int isOk=0;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
        isOk=1;
	}
	return isOk;
}
int mostrarEmpleado(Employee* empleado)
{
    int isOk=0;
    int legajo;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    if( empleado != NULL && employee_getId(empleado, &legajo)
       && employee_getNombre(empleado, nombre)
       && employee_getHorasTrabajadas(empleado, &horasTrabajadas)
       && employee_getSueldo(empleado, &sueldo))
    {

    printf("%d  %s %d  %d\n",
            legajo,
            nombre,
            horasTrabajadas,
            sueldo);
            isOk = 1;
    }
    return isOk;
}
int mostrarListaEmpleados(LinkedList* vec)
{
    int isOk=0;

    if(vec != NULL)
    {
        printf("Legajo     Nombre    Horas Trabajadas   Sueldo\n");
        for(int i=0; i<ll_len(vec); i++)
        {
            mostrarEmpleado( (Employee*) ll_get(vec, i));
        }
        printf("\n\n");
        isOk = 1;

    }
    return isOk;
}
int buscarMayorId(LinkedList* vec, int* id)
{
	int isOk=0;
	int mayor;
	Employee* auxEmpl = NULL;
	    if(vec != NULL)
	    {
	        for(int i=0; i<ll_len(vec); i++)
	        {
	            auxEmpl = (Employee*) ll_get(vec, i);
	        	if(i == 0 || auxEmpl->id > mayor)
	        	{
	        		mayor = auxEmpl->id;
	        	}
	        }
	        *id = mayor + 1;
	        isOk = 1;

	    }
	    return isOk;
}
int addEmployee(LinkedList* pArrayListEmployee, int* id)
{
	Employee* auxEmpleado = NULL;
	//int cant;
	int isOk = 0;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	if(id != NULL && pArrayListEmployee != NULL)
	{
		auxEmpleado = employee_new();
		if(auxEmpleado != NULL)
		{
			auxEmpleado->id = *id;
			printf("Numero de id: %d\n", auxEmpleado->id);
			printf("Ingrese nombre: ");
			fflush(stdin);
		    gets(nombre);
		    while(!employee_setNombre(auxEmpleado, nombre))
		    {
		    	printf("Error. Ingrese nombre: ");
		        fflush(stdin);
		        gets(nombre);
		    }
		    printf("Ingrese Horas Trabajadas: ");
		    scanf("%d", &horasTrabajadas);
		    while(!employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas))
		    {
		    	printf("Error. Ingrese Horas Trabajadas: ");
		        scanf("%d", &horasTrabajadas);
		    }
			printf("Ingrese sueldo: ");
			scanf("%d", &sueldo);
		    while(!employee_setSueldo(auxEmpleado, sueldo))
		    {
		        printf("Error. Ingrese sueldo: ");
		        scanf("%d", &sueldo);
		    }
		    ll_add(pArrayListEmployee, auxEmpleado);
		    *id = *id + 1;
			isOk=1;
		}
	}
	return isOk;
}
int edit_nameEmployee(Employee* empleado)
{
	int isOk = 0;
	char nuevoNombre[128];
	if(empleado != NULL)
	{
		printf("Ingrese nuevo nombre: ");
		fflush(stdin);
		gets(nuevoNombre);
		while(strlen(nuevoNombre) > 128)
		{
			printf("Nuevo nombre Invalido. Ingrese nombre: ");
			fflush(stdin);
			gets(nuevoNombre);
		}

		strcpy(empleado->nombre, nuevoNombre);
		isOk=1;
	}
	return isOk;
}
int edit_horasTrabajadas(Employee* empleado)
{
	int isOk = 0;
	int nuevasHorasTrabajadas;
	if(empleado != NULL)
	{
		printf("Ingrese nueva cantidad de horas trabajadas: ");
		scanf("%d", &nuevasHorasTrabajadas);
		while(nuevasHorasTrabajadas <= 0)
		{
			printf("cantidad Invalida. Ingrese numero mayor a 0: ");
			scanf("%d", &nuevasHorasTrabajadas);
		}

			empleado->horasTrabajadas =  nuevasHorasTrabajadas;
			isOk=1;
		}
		return isOk;
}
int edit_sueldo(Employee* empleado)
{
	int isOk = 0;
	int sueldo;
	if(empleado != NULL)
	{
		printf("Ingrese nuevo sueldo: ");
		scanf("%d", &sueldo);
		while(sueldo <= 0)
		{
			printf("sueldo Invalido. Ingrese numero mayor a 0: ");
			scanf("%d", &sueldo);
		}

			empleado->sueldo =  sueldo;
			isOk=1;
		}
		return isOk;
}
int bajaEmpleado(LinkedList* listado, int* id)
{
	int isOk = 0;
	if(listado != NULL && id != NULL)
	{
		ll_remove(listado, ((*id)-1));
		isOk=1;
	}
	return isOk;
}
int ordenarEmpleadosNombre(void* nombre1, void* nombre2)
{
	int isOk=0;
	Employee* emp1;
	Employee* emp2;
	if(nombre1 != NULL && nombre2 != NULL)
	{
		emp1 = (Employee*) nombre1;
		emp2 = (Employee*) nombre2;

		isOk = strcmp(emp1->nombre, emp2->nombre);

	}
	return isOk;
}
int ordenarEmpleadosHorasTrabajadas(void* horas1, void* horas2)
{
	int isOk=0;
	Employee* emp1;
	Employee* emp2;
	if(horas1 != NULL && horas2 != NULL)
	{
		emp1 = (Employee*) horas1;
		emp2 = (Employee*) horas2;

		if(emp1->horasTrabajadas > emp2->horasTrabajadas)
		{
			isOk=1;
		}
		if(emp1->horasTrabajadas < emp2->horasTrabajadas)
		{
			isOk=-1;
		}
	}
	return isOk;
}
int ordenarEmpleadosSueldo(void* sueldo1, void* sueldo2)
{
	int isOk=0;
	Employee* emp1;
	Employee* emp2;
	if(sueldo1 != NULL && sueldo2 != NULL)
	{
		emp1 = (Employee*) sueldo1;
		emp2 = (Employee*) sueldo2;

		if(emp1->sueldo > emp2->sueldo)
		{
			isOk=1;
		}
		if(emp1->sueldo < emp2->sueldo)
		{
			isOk=-1;
		}
	}
	return isOk;
}
