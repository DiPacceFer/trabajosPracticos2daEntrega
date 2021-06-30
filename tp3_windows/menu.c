#include "menu.h"
/*
 * menu.c
 *
 *  Created on: 16 jun. 2021
 *      Author: Fernando
 */

int menu()
{
	int opcion;

	//system("cls");
	printf("    ***  Menu ***\n\n");
	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
	printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos de empleado\n");
	printf("5. Baja de empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
	printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
	printf("10. Salir\n");
	printf("\nIngrese opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
int subMenuModificar()
{
	int opcion;

		//system("cls");
		 printf("1. Modificar nombre\n");
		 printf("2. Modificar Horas trabajadas\n");
		 printf("3. modificar sueldo\n");
		 printf("4. Salir\n");
		 printf("\nIngrese opcion: ");
		 scanf("%d", &opcion);

	return opcion;
}
int subMenuOrdenar()
{
	int opcion;

		//system("cls");
		 printf("1. Ordenar por nombre\n");
		 printf("2. Ordenar por Horas trabajadas\n");
		 printf("3. Ordenar por sueldo\n");
		 printf("4. Salir\n");
		 printf("\nIngrese opcion: ");
		 scanf("%d", &opcion);

	return opcion;
}
