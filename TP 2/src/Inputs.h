/*
 * inputs.h
 *
 *  Created on: 14 may. 2021
 *      Author: agust
 */

#ifndef INPUTS_H_
#define INPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int GetInt(char message[],int minimum, int maximum,char errorMessage[]);
void GetString(char string[],char message[]);
float GetFloat(char message[],float min,float max,char errorMessage[]);

#endif /* INPUTS_H_ */
