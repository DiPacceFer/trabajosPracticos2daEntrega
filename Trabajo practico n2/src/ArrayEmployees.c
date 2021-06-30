/*
 * ArrayEmployees.c
 *
 *  Created on: 13 may. 2021
 *      Author: Fernando
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"



int initEmployees(Employee* list, int len)
{
	int isOk= -1;

	if(list != NULL && len > 0)
	{
		 for(int i=0; i<len; i++)
		    {
		        list[i].isEmpty = 1;
		    }
		isOk = 0;
	}
	return isOk;
}
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int isOk=-1;

		if(list != NULL && len>0 && len <= 1000)
		{
			   for(int i=0;i<len;i++)
			   {

			    if(list[i].isEmpty)
			    {
			    	strcpy(list[i].name, name);
			    	strcpy(list[i].lastName, lastName);
			    	list[i].id = id;
			    	list[i].salary = salary;
			    	list[i].sector = sector;
			    	list[i].isEmpty = 0;
			        isOk=0;
			        break;
			    }
			   }
		}
	return isOk;
}
int findEmployeeById(Employee* list, int len,int id)
{
	int index=-1;

	if(list != NULL && len>0 && len <= 1000 && id >0)
	{
	    for(int i=0;i<len;i++)
	    {
	        if(list[i].id == id && !list[i].isEmpty)
	        {
	            index=i;
	            break;
	        }
	    }
	}
	return index;
}
int removeEmployee(Employee* list, int len, int id)
{
		int isOk=-1;
	    int indice=-1;
	    char confirmacion = 'n';

	    if(list != NULL && len > 0 && len <= 1000 && id >= 0)
	    indice = findEmployeeById(list, len, id);
	    if(indice == -1)
	    {
	        printf("No se encontro legajo\n");
	    }
	    else
	    {
	        printf("Confirma baja? s/n:  ");
	        fflush(stdin);
	        scanf("%c", &confirmacion);
	        if(confirmacion == 's')
	        {
	            list[indice].isEmpty = 1;
	            isOk=0;
	        }
	        else
	        {
	            printf("Baja cancelada por el usuario\n");
	        }
	    }

	return isOk;
}
int sortEmployees(Employee* list, int len, int order)
{
	Employee auxEmpleado;
	int isOk=-1;
	if(list != NULL && len > 0 && len <= 1000 && !isalpha(order))
	{
	if(order == 1)
	{
	for(int i=0;i<len-1;i++)
	    {
	        for(int j=i+1;j<len;j++)
	        {
	            if((strcmp(list[i].lastName, list[j].lastName) == 1) ||
	            (strcmp(list[i].lastName, list[j].lastName) == 0 &&
	             list[i].sector > list[j].sector))
	            {
	                auxEmpleado=list[i];
	                list[i]=list[j];
	                list[j]=auxEmpleado;

	            }
	        }
	    }
	}
	else if(order == 0)
	{
		for(int i=0;i<len-1;i++)
			    {
			        for(int j=i+1;j<len;j++)
			        {
			            if((strcmp(list[i].lastName, list[j].lastName) == -1) ||
			            (strcmp(list[i].lastName, list[j].lastName) == 0 &&
			             list[i].sector < list[j].sector))
			            {
			                auxEmpleado=list[i];
			                list[i]=list[j];
			                list[j]=auxEmpleado;

			            }
			        }
			    }

	}
	isOk= 0;
	}
	return isOk;
}
int printEmployees(Employee* list, int length)
{
		int flag = 1;
		int isOk = -1;
	    if(list!=NULL && length <=1000 && length > 0 )
	    {
		printf("                        Lista de Empleados   \n");
	    printf("----------------------------------------------------------------\n");
	    printf("Legajo\t        Nombre        apellido      sueldo      sector\n");

	    for(int i=0; i<length; i++)
	    {
	        if(!list[i].isEmpty)
	        {
	            printf("%4d     %10s  %15s      %6.2f       %3d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
	            flag = 0;
	            isOk=1;
	        }
	    }
	    if(flag)
	    {
	        printf("       No hay empleados que mostrar\n\n");
	        isOk=0;
	    }

	    }
	return isOk;
}
int menu()
{
	int opcion=0;

			printf("    *** ABM EMPLEADOS ***\n\n");
	        printf("1. ALTAS\n");
	        printf("2. MODIFICAR\n");
	        printf("3. BAJA\n");
	        printf("4. INFORMAR\n");
	        printf("5. SALIR\n");
	        pedirEntero(&opcion, "Ingrese opcion:", "Ingreso invalido.");

	return opcion;
}
int modifyEmployee(Employee* list, int len, int id)
{
	int isOk=-1;
	int indice;
	char salir = 'n';

	if(list != NULL && len > 0 && len <= 1000)
	{
		indice = findEmployeeById(list, len, id);

		if(indice == -1)
		{
			printf("No se encontro legajo\n");
		}
		else
		{
			do
			{
				switch(subMenuModify())
				{
				case 1:
					pedirCadena(list[indice].name, 50, "Ingrese nuevo nombre: ", "Error en el ingreso.");
					break;
				case 2:
					pedirCadena(list[indice].lastName, 50, "Ingrese nuevo apellido: ", "Error en el ingreso." );
					break;
				case 3:
					pedirFlotante(&list[indice].salary, "Ingrese cambio en el salario: ", "Error en el ingreso");
				break;
				case 4:
					pedirEntero(&list[indice].sector, "Ingreso nuevo sector:", "Ingreso invalido.");
					break;
				case 5:
					salir = 's';
					break;
				default:
					printf("No es un opcion valida\n");
					system("pause");
					break;
				}
			}while(salir == 'n');
		}
		isOk=0;
	}
	return isOk;
}
int  subMenuModify()
{
	int opcion;

		printf("   SUBMENU MODIFICAR:\n");
		printf("----------------------------\n");
		printf("1. Modificar Nombre del empleado.\n");
		printf("2. Modificar Apellido del empleado.\n");
		printf("3. Modificar sueldo del empleado.\n");
		printf("4. Modificar sector del empleado.\n");
		printf("5. Salir.\n");
		pedirEntero(&opcion, "Ingrese opcion:", "Ingreso invalido.");

	return opcion;
}
int subMenuInformes()
{
	int opcion;

			printf("       INFORMES:\n");
			printf("----------------------------\n");
			printf("1. Listado de los empleados ordenados ascendente o descente y por sector.\n");
			printf("2. Total y promedio de los salarios, y cuantos empleados superan el promedio.\n");
			pedirEntero(&opcion, "Ingrese opcion:", "Ingreso invalido.");
	return opcion;
}
int pedirOrdenamiento()
{
	int sistemaDeOrdenamiento;

	pedirEntero(&sistemaDeOrdenamiento, "Indique orden ascendente con 1 o descendente con 0", "Ingreso Invalido");
	while(sistemaDeOrdenamiento != 0 && sistemaDeOrdenamiento != 1)
	{
		printf("Error. Indique orden ascendente con 1 o descendente con 0: ");
		scanf("%d", &sistemaDeOrdenamiento);
	}
	return sistemaDeOrdenamiento;
}
float calcularPromedioSueldos(Employee* list, int len)
{
	float promedios;
	float sumaSueldos=0;
	int contadorEmpleados = 0;


	if(list != NULL && len >0 && len <=1000)
	{
	for(int i=0;i<len;i++)
	{
		if(!list[i].isEmpty)
		{
			sumaSueldos += list[i].salary;
			contadorEmpleados++;
		}
	}
	if(contadorEmpleados != 0)
	{
		promedios = sumaSueldos/contadorEmpleados;
	}
	}
	return promedios;
}
int printSalary(float promedio, Employee* list, int len)
{
	int isOk=-1;
	float sumaSueldos = 0;
	int contadorSuperanPromedio =0;

	if(list != NULL && len > 0 && len <= 1000)
	{
		printf("    ***INFORME TOTAL DE SUELDO Y PROMEDIO***\n");
		printf("---------------------------------------------\n");

		for(int i=0;i<len;i++)
		{
			if(!list[i].isEmpty)
			{
				sumaSueldos += list[i].salary;
				if(list[i].salary > promedio)
				{
					contadorSuperanPromedio++;
					isOk=0;
				}
			}
		}
		printf("El total de sueldos es %.2f: \n", sumaSueldos);
		printf("El promedio de Sueldos es %.2f\n", promedio);
		printf("La cantidad de empleados que superan el promedio es: %d\n", contadorSuperanPromedio);
	}
	return isOk;
}
int pedirEntero(int* numero, char* mensaje, char* mensajeError)
{
	int isOk= -1;
	int num;
	int reintentos=100;

	if(numero != NULL && mensaje != NULL && mensajeError != NULL)
	{
			while(reintentos > 0)
			{
				printf("%s", mensaje);
				if(scanf("%d", &num) == 1)
				{
					break;
				}
				fflush(stdin);
				reintentos--;
				printf("%s", mensajeError);
			}
			if(reintentos == 0)
			{
				isOk=-1;
			}
			else
			{
				*numero = num;
				isOk=0;
			}
	}
	return isOk;
}
int pedirCadena(char* cadena, int tam, char* mensaje, char* mensajeError)
{
	int isOk;
	char chain[51];
	int reintentos=100;
	int error;

		if(cadena != NULL && mensaje != NULL && mensajeError != NULL && tam > 0)
		{
				while(reintentos > 0)
				{
					error = 0;
					printf("%s", mensaje);
					fflush(stdin);
					gets(chain);
					for(int i=0;i<strlen(chain);i++)
					{
						if(!isalpha(chain[i]))
						{
							error++;
						}
					}
					if(error == 0)
					{
						break;
					}
					fflush(stdin);
					reintentos--;
					printf("%s", mensajeError);
				}
				if(reintentos == 0)
				{
					isOk=-1;
				}
				else
				{
					strcpy(cadena, chain);
					isOk=0;
				}
		}
		return isOk;

}
int pedirFlotante(float* numero, char* mensaje, char* mensajeError)
{
	int isOk= -1;
	float num;
	int reintentos=100;
	if(numero != NULL && mensaje != NULL && mensajeError != NULL)
	{
		while(reintentos > 0)
		{
			printf("%s", mensaje);
			if(scanf("%f", &num) == 1)
			{
				break;
			}
			fflush(stdin);
			reintentos--;
			printf("%s", mensajeError);
		}
		if(reintentos == 0)
		{
			isOk=-1;
		}
		else
		{
			*numero = num;
			isOk=0;
		}
	}
		return isOk;
}
