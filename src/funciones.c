/*
 * funciones.c
 *
 *  Created on: 16 abr. 2021
 *      Author: agust
 */

#include "funciones.h"

void MostrarMenu(void)
{
	printf("BIENVENIDO A MI CALCULADORA!!\n\n");
	printf("1. INGRESAR 1ER OPERANDO (A=x)\n");
	printf("2. INGRESAR 2DO OPERANDO (B=y)\n");
	printf("3. CALCULAR OPERACIONES\n");
	printf("4. MOSTRAR RESULTADOS\n");
	printf("5. SALIR\n\n");
	printf("Ingrese una opcion: ");
}

int ValidarOpcion(int numero1,int numero2)
{
	int opcion;

	scanf("%d", &opcion);
	while(opcion<numero1 || opcion>numero2 || isalpha(opcion)!= 0)
	{
		printf("ERROR.Ingrese una opcion válida: ");
		fflush(stdin);
		scanf("%d", &opcion);
	}
	return opcion;
}
//SUMAS
int SumarEnteros(int numero1,int numero2)
{
	int resultado;
	resultado = numero1 + numero2;
	return resultado;
}

float SumarFlotantes(float numero1,float numero2)
{
	float resultado;
	resultado = numero1 + numero2;
	return resultado;
}

float SumarEnteroFlotante(int numero1,float numero2)
{
	float resultado;
	resultado = numero1 + numero2;
	return resultado;
}


//RESTAS
int RestarEnteros(int numero1,int numero2)
{
	int resultado;
	resultado = numero1 - numero2;
	return resultado;
}

float RestarFlotantes(float numero1,float numero2)
{
	float resultado;
	resultado = numero1 - numero2;
	return resultado;
}

float RestarEnteroFlotante(int numero1,float numero2)
{
	float resultado;
	resultado = numero1 - numero2;
	return resultado;
}

float RestarFlotanteEntero(float numero1, int numero2)
{
	float resultado;
	resultado = numero1 - numero2;
	return resultado;
}


//MULTIPLICACIONES
int MultiplicarEnteros(int numero1,int numero2)
{
	int resultado;
	resultado = numero1 * numero2;
	return resultado;
}

float MultiplicarFlotantes(float numero1,float numero2)
{
	float resultado;
	resultado = numero1 * numero2;
	return resultado;
}

float MultiplicarEnteroFlotante(int numero1,float numero2)
{
	float resultado;
	resultado = numero1 * numero2;
	return resultado;
}


//DIVISIONES
float DividirEnteros(int numero1,int numero2)
{
	float resultado;
	resultado = numero1 / numero2;
	return resultado;
}

float DividirFlotantes(float numero1,float numero2)
{
	float resultado;
	resultado = numero1 / numero2;
	return resultado;
}

float DividirEnteroFlotante(int numero1,float numero2)
{
	float resultado;
	resultado = numero1 / numero2;
	return resultado;
}
float DividirFlotanteEntero(float numero1,int numero2)
{
	float resultado;
	resultado = numero1 / numero2;
	return resultado;
}

//FACTORIZAR
int FactorizarNumeros(int numero1)
{
	int i;
	int valorFactorizado;

	for(i=1; i<=numero1; i++)
		{
			valorFactorizado = valorFactorizado * i;
		}
	return valorFactorizado;
}
