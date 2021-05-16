/*
 * Inputs.c
 *
 *  Created on: 14 may. 2021
 *      Author: agust
 */

#include "Inputs.h"

int GetInt(char message[],int min, int max,char errorMessage[])
{
	int number;
	printf(message);
	scanf("%d", &number);

	while(number<min || number>max || isalpha(number) != 0)
	{
		printf(errorMessage);
		scanf("%d", &number);
	}
	return number;
}

void GetString(char string[],char message[])
{
	printf(message);
	fflush(stdin);
	gets(string);
}

float GetFloat(char message[],float min,float max,char errorMessage[])
{
	float number;
	printf(message);
	scanf("%f", &number);

	while(number<min || number>max ||isdigit(number) != 0)
	{
		printf(message);
		scanf("%f", &number);
	}
	return number;
}
