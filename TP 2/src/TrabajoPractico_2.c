/*
 ============================================================================
 Name        : TrabajoPractico_2.c
 Author      : Agustin Berasain Ruffo. 1°F
 ============================================================================
 */

#include "ArrayEmployees.h"

int main(void)
{
	setbuf(stdout, NULL);
	int option;
	int index;
	int idEntered;
	int order;
	int i;
	float totalSalary;
	int totalEmployees;
	float averageSalary;
	int aboveAverageEmployees;

	InitEmployees(arrayEmployees,MAX_EMPLOYEES);
	do{
		printf("\nWELCOME TO ARRAY EMPLOYEES!\n\n"
				"1. REGISTER\n"
				"2. MODIFY\n"
				"3. UNREGISTER\n"
				"4. REPORT\n"
				"5. EXIT\n");
		option = GetInt("\nChoose an option[1-5]: ",1,5,"\nChoose a valid option[1-5]: ");
		switch(option)
		{
			case 1: //REGISTER
				index = AddEmployee(arrayEmployees,MAX_EMPLOYEES);
				if(index == -1)
				{
					puts("\nERROR! No more employees can be registered.\n");
				}
				else
				{
					puts("\nSuccessful registered employee!\n");
				}
				system("pause");
				break;

			case 2: //MODIFY
				if(SearchOccupied(arrayEmployees, MAX_EMPLOYEES)!= EMPTY)
				{
					PrintEmployees(arrayEmployees,MAX_EMPLOYEES);
					idEntered = GetInt("\nEnter id of the employee to modify[1-1000]: ",1,1000,"\nERROR! Enter valid employee id to modify[1-1000]: ");
					i = FindEmployeeById(arrayEmployees,MAX_EMPLOYEES,idEntered);
					if(i != -1)
					{
						do{
							printf("\nMODIFICATION MENU\n\n"
									"1. CHANGE NAME\n"
									"2. CHANGE LAST NAME\n"
									"3. CHANGE SALARY\n"
									"4. CHANGE SECTOR\n"
									"0. BACK\n");
							option = GetInt("\nChoose an option[1-5]: ",0,4,"\nChoose a valid option[1-5]: ");
							switch(option)
							{
								case 1:
									index = ChangeName(arrayEmployees[i].name);
									if(index == -1)
									{
										puts("\nNo changes have been made.\n");
									}else
									{
										puts("Successful change!");
									}
									break;

								case 2:
									index = ChangeName(arrayEmployees[i].lastName);
									if(index == -1)
									{
										puts("\nNo changes have been made.\n");
									}else
									{
										puts("Successful change!");
									}
									break;

								case 3:
									index = ChangeSalary(arrayEmployees[i].salary);
									if(index == -1)
									{
										puts("\nNo changes have been made.\n");
									}else
									{
										puts("Successful change!");
									}
									break;

								case 4:
									index = ChangeSector(arrayEmployees[i].sector);
									if(index == -1)
									{
										puts("\nNo changes have been made.\n");
									}else
									{
										puts("Successful change!");
									}
									break;
							}
						}while(option!= 0);
					}
					else
					{
						puts("\nERROR! The id entered doesn't match that of any employee.");
					}
				}
				else
				{
					puts("\nERROR! There are no registered employees.\n");
				}
				system("pause");
				break;

			case 3: //UNREGISTER
				if(SearchOccupied(arrayEmployees, MAX_EMPLOYEES)!= EMPTY)
				{
					PrintEmployees(arrayEmployees,MAX_EMPLOYEES);
					idEntered = GetInt("\nEnter id of the employee to remove[1-1000]: ",1,1000,"\nERROR! Enter valid employee id to modify[1-1000]: ");
					index = RemoveEmployee(arrayEmployees,MAX_EMPLOYEES, idEntered);
					if(index > -1 )
					{
						puts("Successful change!");
					}else
					{
						if(index == -1 )
						{
							puts("\nERROR! The id entered doesn't match that of any employee.");
						}else
						{
							if(index == -2)
							{
								puts("\nNo changes have been made.\n");
							}
						}
					}
				}
				else
				{
					puts("\nERROR! There are no registered employees.\n");
				}
				system("pause");
				break;

			case 4: //REPORT
				if(SearchOccupied(arrayEmployees, MAX_EMPLOYEES)!= EMPTY)
				{
					do{
						printf("\nREPORT MENU\n\n"
						"1. LIST OF EMPLOYEES ARRANGED ALPHABETICALLY BY SURNAME AND SECTOR\n"
						"2. TOTAL AND AVERAGE SALARIES, AND HOW MANY EMPLOYEES EXCEED THE AVERAGE SALARY\n"
						"3. BACK\n");
						option = GetInt("\nChoose an option[1-3]: ",1,3,"\nChoose a valid option[1-3]: ");
						switch(option)
						{
							case 1:
								printf("\nOPTIONS\n\n"
								"0. DESCENDING ORDER\n"
								"1. ASCENDING ORDER\n");
								order = GetInt("\nChoose an order[0-1]: ",0,1,"\nChoose a valid order[0-1]: ");
								SortEmployees(arrayEmployees,MAX_EMPLOYEES,order);
								PrintEmployees(arrayEmployees,MAX_EMPLOYEES);
								break;

							case 2:
								totalSalary = SalaryAccumulator(arrayEmployees,MAX_EMPLOYEES);
								totalEmployees = CountEmployees(arrayEmployees,MAX_EMPLOYEES);
								averageSalary = totalSalary / totalEmployees;
								aboveAverageEmployees = CountEmployeesSalaryAverage(arrayEmployees,MAX_EMPLOYEES,averageSalary);
								printf("\nThe total salaries is $%.2f and the average salary is $%.2f. The number of employees above the average salary is %d.",totalSalary
																																							   ,averageSalary
																																							   ,aboveAverageEmployees);
								break;
						}

					}while(option!=3);
				}
				else
				{
					puts("\nERROR! There are no registered employees.\n");
				}
				system("pause");
				break;
		}

	}while(option!=5);
	puts("\nAdios!");
}
