#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
/*
 * parser.h
 *
 *  Created on: 16 jun. 2021
 *      Author: Fernando
 */

#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee);

