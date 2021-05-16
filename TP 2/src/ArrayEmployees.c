/*
 * ArrayEmployees.c
 *
 *  Created on: 14 may. 2021
 *      Author: agust
 */

#include "ArrayEmployees.h"

void InitEmployees(eEmployee list[],int len) //INICIALIZA EL ARRAY DE EMPLEADOS EN EMPTY.
{
	int i;
	for(i=0; i<len; i++)
	{
		list[i].isEmpty = EMPTY;
	}
}

int SearchEmpty(eEmployee list[], int len) //BUSCA UNA POSICION DE ARRAY QUE SE ENCUENTRE VACÍA.
{
	int i;
	int index;

	index = -1;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty==EMPTY)
		{
			index = i;
			break;
		}
	}
	return index;
}

int SearchOccupied(eEmployee list[], int len) //BUSCA UNA POSICION DE ARRAY QUE SE ENCUENTRE OCUPADA.
{
	int i;
	int index;

	index = EMPTY;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty==OCCUPIED)
		{
			index = i;
			break;
		}
	}
	return index;
}


int GenerateId(eEmployee list[], int len) //GENERA ID AUTOMATICAMENTE PARA LA CARGA DE EMPLEADOS
{
	int id;
	int i;
	int maxId;

	maxId = 0;

	if(SearchOccupied(list,len) == EMPTY)
	{
		id = 1;
	}
	else
	{
		for(i=0; i<len; i++)
		{
		   if(list[i].id>maxId && list[i].isEmpty == OCCUPIED)
		   {
			   maxId = list[i].id;
		   }
		}
		id = maxId+1;
	}
	return id;
}

int ValidateName(char string[]) //VALIDA STRING PARA VERIFICAR QUE NO HAYA CARACTERES NUMERICOS
{
	int index;
	int i;
	index = 1;
	for(i=0; i<strlen(string); i++)
	{
		if(!isalpha(string[i]) && !isspace(string[i]))
		{
			index = 0;
			break;
		}
	}
	return index;
}

eEmployee RequestData(eEmployee list[], int len) //PIDE LOS DATOS Y LOS DEVUELVE EN FORMA DE VARIABLE.
{
	eEmployee enteredEmployee;
	int i;

	enteredEmployee.id = GenerateId(list,len);

	GetString(enteredEmployee.name,"\nEnter the name: ");
	while(ValidateName(enteredEmployee.name)== 0)
	{
		GetString(enteredEmployee.name,"\nERROR! Enter the name correctly: ");
	}
	strlwr(enteredEmployee.name);
	enteredEmployee.name[0] = toupper(enteredEmployee.name[0]);
	for(i=0; i<strlen(enteredEmployee.name); i++)
	{
		if(isspace(enteredEmployee.name[i] != 0)) // It's a space
		{
			enteredEmployee.name[i+1] = toupper(enteredEmployee.name[i+1]);
		}
	}
	GetString(enteredEmployee.lastName,"\nEnter the last name: ");
	while(ValidateName(enteredEmployee.lastName)== 0)
	{
		GetString(enteredEmployee.lastName,"\nERROR! Enter the last name correctly: ");
	}
	strlwr(enteredEmployee.lastName);
	enteredEmployee.lastName[0] = toupper(enteredEmployee.lastName[0]);
	for(i=0; i<strlen(enteredEmployee.lastName); i++)
	{
		if(isspace(enteredEmployee.lastName[i] != 0)) // It's a space
		{
			enteredEmployee.lastName[i+1] = toupper(enteredEmployee.lastName[i+1]);
		}
	}

	enteredEmployee.salary = GetFloat("\nEnter salary[800-10000]: ",800,10000,"\nERROR! Enter salary correctly[800-10000]: ");
	enteredEmployee.sector = GetInt("\nIndicate sector number[1-5]: ",1,5,"\nERROR! Indicate sector number correctly[1-5]: ");
	enteredEmployee.isEmpty = OCCUPIED;

	return enteredEmployee;
}

int AddEmployee(eEmployee list[],int len) //AÑADE UN EMPLEADO AL ARRAY
{
	int i;
	i = SearchEmpty(list, len);
	if(i != -1)
	{
		 list[i] = RequestData(list,len);
	}
	return i;
}

int FindEmployeeById(eEmployee list[], int len, int idEntered) //BUSCA UN EMPLEADO EN EL ARRAY A TRAVES DE UN ID
{
	int i;
	int index;

	index = -1;
	for(i=0; i<len; i++)
	{
		if(list[i].id == idEntered)
		{
			index = i;
			break;
		}
	}
	return index;
}

int ConfirmAction() //PIDE CONFIRMACION PARA REALIZAR X ACCIÓN.
{
	int index;
	char answer;
	index = -1;
	printf("\nAre you sure to make this change?[y/n]: ");
	fflush(stdin);
	scanf("%c",&answer);
	while(answer != 'y' && answer != 'n')
	{
		printf("\nAre you sure to make this change?[y/n]: ");
		fflush(stdin);
		scanf("%c",&answer);
	}
	if(answer == 'y')
	{
		index = 1;
	}
	return index;
}

int ChangeName(char name[]) //SE ENCARGA DE MODIFICAR UN NOMBRE O APELLIDO EXISTENTE DE UN EMPLEADO POR UNO NUEVO.
{
	char nameEntered[MAX_BUFFER];
	int i;
	int index;

	index = -1;
	GetString(nameEntered,"\nEnter the name/last name: ");
	while(ValidateName(nameEntered)== 0)
	{
		GetString(nameEntered,"\nERROR! Enter the name/last name correctly: ");
	}
	strlwr(nameEntered);
	nameEntered[0] = toupper(nameEntered[0]);
	for(i=0; i<strlen(nameEntered); i++)
	{
		if(isspace(nameEntered[i] != 0)) // It's a space
		{
			nameEntered[i+1] = toupper(nameEntered[i+1]);
		}
	}
	if(ConfirmAction()==1)
	{
		strcpy(name,nameEntered);
		index = i;
	}
	return index;
}

int ChangeSalary(float salary) //SE ENCARGA DE MODIFICAR EL SALARIO EXISTENTE DE UN EMPLEADO POR UNO NUEVO.
{
	int index;
	float newSalary;

	newSalary = GetFloat("\nEnter new salary[800-10000]: ",800,10000,"\nERROR! Enter new salary correctly[800-10000]: ");
	if(ConfirmAction()==1)
	{
		salary = newSalary;
		index = 1;
	}
	return index;
}

int ChangeSector(int sector) //SE ENCARGA DE MODIFICAR EL SECTOR DE UN EMPLEADO.
{
	int index;
	int newSector;

	index = -1;
	newSector = GetInt("\nIndicate new sector number[1-5]: ",1,5,"\nERROR! Indicate new sector number correctly[1-5]: ");
	if(ConfirmAction()==1)
	{
		sector = newSector;
		index = 1;
	}
	return index;
}

int RemoveEmployee(eEmployee list[],int len, int id) //SE ENCARGA DE REALIZAR LA BAJA LÓGICA DEL EMPLEADO.
{
	int index;
	int i;

	index = -1;
	i = FindEmployeeById(list,len,id);
	if(i!=-1)
	{
		if(ConfirmAction()==1)
		{
			list[i].isEmpty = EMPTY;
			index = i;
		}else
		{
			index = -2;
		}

	}
	return index;
}

void SortEmployees(eEmployee list[],int len, int order)  //NO LOGRÉ QUE FUNCIONE DE FORMA CORRECTA. ESTA FUNCIÓN SE DEBIA ENCARGAR DE ORDENAR
{                                                        //EL ARRAY POR APELLIDO Y SECTOR.
	int i;
	int j;
	eEmployee aux;

	if(order==1)
	{
		for(i=0; i>len-1;i++)
		{
			for(j=i+1; j<len;j++)
			{
				if(strcmp(list[i].lastName,list[j].lastName)>0 && list[i].isEmpty == OCCUPIED && list[j].isEmpty == OCCUPIED)
				{
					aux = list[j];
					list[j] = list[i];
					list[i] = aux;
				}
			}
		}
	}else
	{

	}
}

void PrintEmployees(eEmployee list[],int len) //SE ENCARGA DE MOSTRAR EL ARRAY DE EMPLEADOS JUNTO SUS DATOS.
{
	int i;

	puts("\n LAST NAME  -----  NAME  -----  SECTOR  -----  SALARY  -----  ID \n\n");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCCUPIED)
		{
			printf(" %s  -----  %s  -----  %d  -----  $%.2f  -----  %d  \n",list[i].lastName
																		  ,list[i].name
																		  ,list[i].sector
																		  ,list[i].salary
																		  ,list[i].id);
		}
	}
}

float SalaryAccumulator(eEmployee list[],int len) //SE ENCARGA DE ACUMULAR EL SALARIO DE LOS EMPLEADOS CARGADOS.
{
	int i;
	float salaryAccumulator;

	salaryAccumulator = 0;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCCUPIED)
		{
			salaryAccumulator = salaryAccumulator + list[i].salary;
		}
	}
	return salaryAccumulator;
}

int CountEmployees(eEmployee list[],int len) //SE ENCARGA DE CONTAR LA CANTIDAD DE EMPLEADO YA CARGADOS.
{
	int i;
	int totalEmployees;

	totalEmployees = 0;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCCUPIED)
		{
			totalEmployees++;
		}
	}
	return totalEmployees;
}

int CountEmployeesSalaryAverage(eEmployee list[],int len, float average) //SE ENCARGAR DE CONTAR LA CANTIDAD DE EMPLEADOS QUE TIENEN
{																		//UN SALARIO SUPERIOR AL SALARIO PROMEDIO.
	int i;
	int accountant;

	accountant = 0;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCCUPIED && list[i].salary > average )
		{
			accountant++;
		}
	}
	return accountant;
}
