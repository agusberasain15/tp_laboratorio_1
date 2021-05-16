/*
 * ArrayEmployees.h
 *
 *  Created on: 14 may. 2021
 *      Author: agust
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include "Inputs.h"
#define MAX_EMPLOYEES 1000
#define MAX_BUFFER 51
#define EMPTY -1
#define OCCUPIED 0

typedef struct
{
	int id;
	char name[MAX_BUFFER];
	char lastName[MAX_BUFFER];
	float salary;
	int sector;
	int isEmpty;
}eEmployee;

eEmployee arrayEmployees[MAX_EMPLOYEES];

void InitEmployees(eEmployee list[],int len);
int SearchEmpty(eEmployee list[], int len);
int SearchOccupied(eEmployee list[], int len);
int GenerateId(eEmployee list[], int len);
int ValidateName(char string[]);
int FindEmployeeById(eEmployee list[], int len, int idEntered);
int ConfirmAction();
int ChangeName(char name[]);
int ChangeSalary(float salary);
int ChangeSector(int number);
eEmployee RequestData(eEmployee list[], int len);
int AddEmployee(eEmployee list[],int len);
int RemoveEmployee(eEmployee list[],int len, int id);
void SortEmployees(eEmployee list[],int len, int order);
void PrintEmployees(eEmployee list[],int len);
float SalaryAccumulator(eEmployee list[],int len);
int CountEmployees(eEmployee list[],int len);
int CountEmployeesSalaryAverage(eEmployee list[],int len, float average);
#endif /* ARRAYEMPLOYEES_H_ */
