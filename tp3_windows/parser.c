#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int isOk = 0;
	char auxCad[100];
	char buffer[4][128];
	Employee* auxEmpleado = NULL;
	int cant=4;
	int flag;
	char confirma = 'n';

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		if(ll_len(pArrayListEmployee) > 0)
		{
			printf("Se van a sobrescribir los empleados!! Confirma?: s/n\n");
			fflush(stdin);
			scanf("%c", &confirma);
		}
		if(ll_len(pArrayListEmployee) == 0 || confirma == 's')
		{
			ll_clear(pArrayListEmployee);
			fscanf(pFile, "%[^\n]\n", auxCad);//para saltar encabezado
			while(!feof(pFile))//iterar sobre cada linea del archivo
			{
				//leo y parseo una fila del archivo
				cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
	            //printf("%s", buffer[0]);
				if(cant == 4)//si leyo todo bien creo un empleado con un constructor
	            {
	            	auxEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
	                if(auxEmpleado != NULL)
	                {
	                    ll_add(pArrayListEmployee, auxEmpleado);
	                    auxEmpleado = NULL;
	                    flag = 0;
	                }
	                else
	                {
	                    flag = 1;// 1 = problema para cargar empleado
	                    break;
	                }
	            }
	            else
	            {
	                flag = 2;// 2 = problema para leer empleado
	                break;
	            }
	        }
	    }
	    if(flag == 0)
	    {
	        printf("Empleados cargados correctamente!!!\n");
	        isOk =1;
	    }
	    else if(flag == 1)
	    {
	        printf("problema para cargar empleado!!!\n");
	    }
	    else if(flag == 2)
	    {
	        printf("problema para leer empleado!!!\n");
	        printf("cant: %d\n", cant);
	    }
	}
    return isOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int isOk = 0;
	Employee* auxEmpleado = NULL;
	char confirma = 'n';
	int flag = 1;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		if(ll_len(pArrayListEmployee) > 0)
		{
			printf("Se van a sobrescribir los empleados!! Confirma?: s/n\n");
			fflush(stdin);
			scanf("%c", &confirma);
		}
		if(ll_len(pArrayListEmployee) == 0 || confirma == 's')
		{
			ll_clear(pArrayListEmployee);
			while(!feof(pFile))//iterar sobre cada linea del archivo
			{
				auxEmpleado = employee_new();
		        if(auxEmpleado != NULL)
		        {
		        	if(fread(auxEmpleado, sizeof(Employee), 1, pFile) == 1)
		        	{
		            	ll_add(pArrayListEmployee, auxEmpleado);
		            	auxEmpleado = NULL;
		            	flag = 0;
			        }
	                else
	                {
		                break;
	                }

		        }
		    }
		}
		if(flag == 0)
		{
			printf("Empleados cargados correctamente!!!\n");
	        isOk =1;
		}
		else if(flag == 1)
		{
			printf("problema para cargar empleado!!!\n");
	    }
	}
    return isOk;
}
int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int isOk = 0;
	Employee* auxEmp = NULL;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		for(int i=0;i< ll_len(pArrayListEmployee);i++)
		{
			auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
			fprintf(pFile, "%d,%s,%d,%d\n", auxEmp->id, auxEmp->nombre, auxEmp->horasTrabajadas, auxEmp->sueldo);
		}
	}
	else if(pFile != NULL)
	{
		printf("problemas con pFile\n");
	}
	else if(pArrayListEmployee)
	{
		printf("problemas con el listado\n");
	}

	return isOk;
}
int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int isOk = 0;
	Employee* auxEmp = NULL;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		for(int i=0;i< ll_len(pArrayListEmployee);i++)
		{
			auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(auxEmp, sizeof(Employee), 1, pFile);
		}
	}
	return isOk;
}
