/*
 ============================================================================
 Name        : Trabajo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"


int main(void) {

	setvbuf (stdout, NULL, _IONBF, 0);
	setvbuf (stderr, NULL, _IONBF, 0);

	Employee nomina[1000];
	char salir='n';
	char name[51];
	char lastName[51];
	float salary;
	int id=20000;
	int sector;
	float promedioSalarios;
	int flag= 0;

	initEmployees(nomina, 1000);

	do
	{
		switch(menu() )
		{
		case 1:
			 printf("\n      ALTA EMPLEADO\n\n");
			 pedirCadena(name, 50, "Ingrese nombre: ", "Error en el ingreso.");
			 pedirCadena(lastName, 50, "Ingrese apellido: ", "Error en el ingreso.");
			 pedirFlotante(&salary, "Ingrese sueldo: ", "Ingreso Invalido. ");
			 pedirEntero(&sector, "Ingrese ID del sector: ", "Ingreso Invalido.");
			 addEmployee(nomina, 1000, id, name, lastName, salary, sector);
			 id++;
			 flag = 1;
			break;
		case 2:
			if(flag)
			{
				printf("    MODIFICACION DE DATOS DE EMPLEADOS\n\n");
				pedirEntero(&id, "Ingrese numero de legajo: ", "Error en el ingreso.");
				modifyEmployee(nomina, 1000, id);
				system("pause");
			}
			else
			{
				printf("Primero debe darse de alta un empleado con opcion 1.\n");
				system("pause");
			}
			break;
		case 3:
			if(flag)
			{
				printf("     BAJA DE EMPLEADOS\n\n");
				pedirEntero(&id, "Ingrese numero de legajo: ", "Error en el ingreso.");
				removeEmployee(nomina, 1000, id);
				system("pause");
			}
			else
			{
				printf("Primero debe darse de alta un empleado con opcion 1.\n");
				system("pause");
			}
			break;
		case 4:
			if(flag)
			{
			switch(subMenuInformes())
			{
				case 1:
					sortEmployees(nomina, 1000, pedirOrdenamiento());
					printEmployees(nomina, 1000);
					system("pause");
					break;
				case 2:
					promedioSalarios = calcularPromedioSueldos(nomina, 1000);
					printSalary(promedioSalarios, nomina, 1000);
					system("pause");
					break;
			}
			}
			else
			{
				printf("Primero debe darse de alta un empleado con opcion 1.\n");
				system("pause");
			}
			break;

		case 5:
			salir = 's';
			break;
		}

	}while(salir == 'n');


	return EXIT_SUCCESS;
}
