
#include "controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int isOk=0;
	FILE* f = fopen(path, "r");
	if(f == NULL)
    {
		printf("No se pudo abrir el archivo\n");
	    exit(1);
    }
	if(parser_EmployeeFromText(f, pArrayListEmployee))
		{
			isOk=1;
		}

	fclose(f);

    return isOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int isOk=0;
	FILE* f;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path, "rb");
		if(f == NULL)
		{
			printf("No se pudo abrir el archivo o el archivo no existe\n");
		    exit(1);
		}
		if(parser_EmployeeFromBinary(f, pArrayListEmployee))
		{
			isOk=1;
		}

			fclose(f);
	}

    return isOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
    int isOk=0;
    if(pArrayListEmployee != NULL && id != NULL)
    {
    	if(addEmployee(pArrayListEmployee, id))
    	{
    		isOk=1;
    	}
    }
	return isOk;
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
	int isOk=0;
	int id;
	Employee* auxEmpleado = NULL;
	if(pArrayListEmployee != NULL)
	{

		printf("    MODIFICACION DE DATOS DE EMPLEADOS\n\n");
	    printf("Ingrese id del Empleado: ");
	    scanf("%d", &id);
	    auxEmpleado = (Employee*) ll_get(pArrayListEmployee, (id -1));
	    //system("cls");
	    if(auxEmpleado != NULL)
	    {
	        printf("Id\tNombre\tHoras Trabajadas\tsueldo\n");
	        mostrarEmpleado(auxEmpleado);
	        switch(subMenuModificar())
	        {
	        	case 1:
	        		if(edit_nameEmployee(auxEmpleado))
	        		{
	        			printf("Se modifico empleado con exito\n");
	        			isOk=1;
	        		}
	        		break;
	        	case 2:
	        		if(edit_horasTrabajadas(auxEmpleado))
	        		{
	        			printf("Se modifico empleado con exito\n");
	        			isOk=1;
	        		}
	        		break;
	        	case 3:
	        		if(edit_sueldo(auxEmpleado))
	        		{
	        			printf("Se modifico empleado con exito\n");
	        			isOk=1;
	        		}
	        		break;
	        	case 4:
	        		break;
	        }

	    }
	}

	return isOk;
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
	int isOk=0;
	int id;
	Employee* auxEmpleado = NULL;
	char confirmacion = 'n';
	if(pArrayListEmployee != NULL)
	{
		printf("    BAJA DE EMPLEADOS\n\n");
		printf("Ingrese id del Empleado: ");
	    scanf("%d", &id);
	    auxEmpleado = (Employee*) ll_get(pArrayListEmployee, (id -1));
	    //system("cls");
	    if(auxEmpleado != NULL)
	    {
	    	printf("Id\tNombre\tHoras Trabajadas\tsueldo\n");
	    	mostrarEmpleado(auxEmpleado);
	    	printf("Confirma baja del empleado: ");
	    	fflush(stdin);
	   		scanf("%c", &confirmacion);
 			if(confirmacion == 's')
 			{
 				if(bajaEmpleado(pArrayListEmployee, &id))
 				{
 					isOk=1;
 				}
 			}
	  }
	}

	return isOk;
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
    int isOk=0;
    if(pArrayListEmployee != NULL)
    {
    	mostrarListaEmpleados(pArrayListEmployee);
    	isOk=1;
    }
	return isOk;
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
    int isOk=0;
	if(pArrayListEmployee != NULL)
	{
		switch(subMenuOrdenar())
		{
			case 1:
				ll_sort(pArrayListEmployee, ordenarEmpleadosNombre , 1);
				break;
			case 2:
				ll_sort(pArrayListEmployee, ordenarEmpleadosHorasTrabajadas , 1);
				break;
			case 3:
				ll_sort(pArrayListEmployee, ordenarEmpleadosSueldo , 1);
				break;
			case 4:
				break;
		}
		isOk=1;

	}

	return isOk;
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
    int isOk=0;
    FILE* f = NULL;
    char confirmacion = 'n';
    if(path != NULL && pArrayListEmployee)
    {
    	f = fopen(path, "r");
    	if(f == NULL)
    	{
    		printf("No se encontro el archivo, desea crear un nuevo archivo?\n");
    		fflush(stdin);
    		scanf("%c", &confirmacion);
    		if(confirmacion == 's')
    		{
    			fclose(f);
    			f = fopen(path, "w");
    			if(f!= NULL)
    			{
    				parser_EmployeeToText(f, pArrayListEmployee);
    				isOk=1;
    			}
    		}
    		else
    		{
    			exit(1);
    		}
    	}
    	else
    	{
    		fclose(f);
    		printf("Se va a sobrescribir el archivo!!\n");
    		f = fopen(path, "w");
    		if(f != NULL)
    		{
    			parser_EmployeeToText(f, pArrayListEmployee);
    			isOk=1;
    		}
    	}
    	fclose(f);
    }
	return isOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int isOk=0;
	FILE* f = NULL;
    char confirmacion = 's';
    if(path != NULL && pArrayListEmployee)
    {
    	f = fopen(path, "rb");
	   	if(f == NULL)
	   	{
	   		printf("No se encontro el archivo, desea crear un nuevo archivo?\n");
	   		//fflush(stdin);
	   		//scanf("%c", &confirmacion);
	   		if(confirmacion == 's')
    		{
	   			fclose(f);
	    		f = fopen(path, "wb");
	    		printf("Se abrio el archivo para escribir\n");
	    		if(f == NULL)
	    		{
	    			printf("No se pudo abrir archivo\n");
	    			exit(1);
	    		}
	    		parser_EmployeeToBinary(f, pArrayListEmployee);
	   			isOk=1;
	   		}
	   		else
	   		{
	   			exit(1);
	   		}
	   	}
	   	else
    	{
	   		fclose(f);
	    	printf("El archivo ya existe y se va a sobrescribir!!\n");
	    	system("pause");
	   		f = fopen(path, "wb");
	   		if(f!= NULL)
	   		{
	   			parser_EmployeeToBinary(f, pArrayListEmployee);
	   			isOk=1;
	   		}

	   	}
	   	fclose(f);
    }
    return isOk;
}

