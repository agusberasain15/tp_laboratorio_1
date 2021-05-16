/*
============================================================================
 Name        : tp_laboratorio_1
 Author      : Agustin Berasain Ruffo
 Notas		 : No logre que muestre los resultados correctos.
============================================================================
*/

#include <stdlib.h>
#include "funciones.h"


int main(void)
{
	int opcion;
	int enteroNumeroA;
	int enteroNumeroB;
	int numeroAEs;
	int numeroBEs;
	int flagA;
	int flagB;
	int i;
	int enteroSuma;
	int enteroResta;
	int enteroProducto;
	float division;
	float decimalNumeroA;
	float decimalNumeroB;
	float decimalSuma;
	float decimalResta;
	float decimalProducto;
	char stringNumA[T];
	char stringNumB[T];
	int factorialA;
	int factorialB;


	setbuf(stdout, NULL);

	flagA = 0;
	flagB = 0;
	do
	{
		MostrarMenu();
		fflush(stdin);
		opcion = ValidarOpcion(1,5);
		switch(opcion)
		{
		case 1:
			printf("Ingrese un número: ");
			fflush(stdin);
			gets(stringNumA);
			/*while(isalpha(stringNumA[i])!=0)
			{
				printf("\nERROR! Debe ingresar un número: ");    //NO LOGRE QUE FUNCIONE CORRECTAMENTE
				fflush(stdin);
				gets(stringNumA);
			}*/
			for(i=0; i<T; i++ )
			{
				if(stringNumA[i] == '.' || stringNumA[i] == ',')
				{
					decimalNumeroA = atof(stringNumA);
					numeroAEs = decimal;
				}else
				{
					enteroNumeroA = atoi(stringNumA);
					numeroAEs = entero;
				}
			}

			flagA = 1;
			printf("\nValor cargado exitosamente!\n\n");
			//MostrarMenu();
			//fflush(stdin);
			//opcion = ValidarOpcion(1,5);
			break;

		case 2:
			printf("Ingrese un número: ");
			fflush(stdin);
			gets(stringNumB);
			/*while(isalpha(stringNumB)!=0)
			{
				printf("\nERROR! Debe ingresar un número: ");	//NO LOGRE QUE FUNCIONE CORRECTAMENTE
				fflush(stdin);
				gets(stringNumB);
			}*/
			for(i=0; i<T; i++ )
			{
				if(stringNumB[i] == '.' || stringNumB[i] == ',' )
				{
					decimalNumeroB = atof(stringNumB);
					numeroBEs = decimal;
				}else
				{
					enteroNumeroB = atoi(stringNumB);
					numeroBEs = entero;
				}
			}

			flagB = 1;
			printf("\nValor cargado exitosamente!\n\n");
			//MostrarMenu();
			//fflush(stdin);
			//opcion = ValidarOpcion(1,5);
			break;


		case 3:
			if(flagA == 1 && flagB == 1 )
			{
				if(numeroAEs == entero && numeroBEs == entero)
				{
					enteroSuma = SumarEnteros(enteroNumeroA,enteroNumeroB);
					enteroResta = RestarEnteros(enteroNumeroA,enteroNumeroB);
					enteroProducto = MultiplicarEnteros(enteroNumeroA,enteroNumeroB);
					if(enteroNumeroB!=0)
					{
						division = DividirEnteros(enteroNumeroA,enteroNumeroB);
					}
					if(enteroNumeroA>0)
					{
						factorialA = FactorizarNumeros(enteroNumeroA);
					}
					if(enteroNumeroB>0)
					{
						factorialB = FactorizarNumeros(enteroNumeroB);
					}
				}else
				{
					if(numeroAEs == decimal && numeroBEs == decimal)
					{
						decimalSuma = SumarFlotantes(decimalNumeroA,decimalNumeroB);
						decimalResta = RestarFlotantes(decimalNumeroA,decimalNumeroB);
						decimalProducto = MultiplicarFlotantes(decimalNumeroA,decimalNumeroB);
						if(decimalNumeroB!=0)
						{
							division = DividirFlotantes(decimalNumeroA,decimalNumeroB);
						}
					}else
					{
						if(numeroAEs == entero && numeroBEs == decimal)
						{
							decimalSuma = SumarEnteroFlotante(enteroNumeroA,decimalNumeroB);
							decimalResta = RestarEnteroFlotante(enteroNumeroA,decimalNumeroB);
							decimalProducto = MultiplicarEnteroFlotante(enteroNumeroA,decimalNumeroB);
							if(decimalNumeroB!=0)
							{
								division = DividirEnteroFlotante(enteroNumeroA,decimalNumeroB);
							}
							if(enteroNumeroA>0)
							{
								factorialA = FactorizarNumeros(enteroNumeroA);
							}
						}else
						{
							if(numeroAEs == decimal && numeroBEs == entero)
							{
								decimalSuma = SumarEnteroFlotante(enteroNumeroB,decimalNumeroA);
								decimalResta = RestarFlotanteEntero(decimalNumeroA,enteroNumeroB);
								decimalProducto = MultiplicarEnteroFlotante(enteroNumeroB,decimalNumeroA);
								if(enteroNumeroB!=0)
								{
									division = DividirFlotanteEntero(decimalNumeroA,enteroNumeroB);
								}
								if(enteroNumeroB>0)
								{
									factorialB = FactorizarNumeros(enteroNumeroB);
								}
							}
						}
					}
				}


			}else
			{
				printf("Para realizar esta operacion debe cargar ambos operando con un valor.\n");
			}
			printf("\nCalculos realizados con exito!\n\n");
			//MostrarMenu();
			//fflush(stdin);
			//opcion = ValidarOpcion(1,5);
			break;

		case 4:
			if(numeroAEs == entero && numeroBEs == entero)
			{
				printf("a) El resultado de %s + %s es: %d\n",stringNumA,stringNumB,enteroSuma);
				printf("b) El resultado de %s - %s es: %d\n",stringNumA,stringNumB,enteroResta);
				if(enteroNumeroB==0)
				{
					printf("c) No es posible dividir por 0.\n");
				}else
				{
					printf("c) El resultado de %s / %s es: %f\n",stringNumA,stringNumB,division);
				}

				printf("d) El resultado de %s * %s es: %d\n",stringNumA,stringNumB,enteroProducto);
				printf("e) El factorial de %s es: %d y el factorial de %s es: %d\n\n",stringNumA,factorialA,stringNumB,factorialB);
			}else
			{
				printf("a) El resultado de %s + %s es: %f\n",stringNumA,stringNumB,decimalSuma);
				printf("b) El resultado de %s - %s es: %f\n",stringNumA,stringNumB,decimalResta);
				if(enteroNumeroB==0 || decimalNumeroB ==0)
				{
					printf("c) No es posible dividir por 0.\n");
				}else
				{
					printf("c) El resultado de %s / %s es: %f\n",stringNumA,stringNumB,division);
				}
				printf("d) El resultado de %s * %s es: %f\n",stringNumA,stringNumB,decimalProducto);
				if(enteroNumeroA>0)
				{
					printf("e) El factorial de %s es: %d y el factorial de %s no es posible de calcular.\n\n",stringNumA,factorialA,stringNumB);
				}else
				{
					if(enteroNumeroB>0)
					{
						printf("e) El factorial de %s no es posible de calcular y el factorial de %s es: %d.\n\n",stringNumA,stringNumB,factorialB);
					}else
					{
						printf("e) El factorial de %s no es posible de calcular y el factorial de %s tampoco es posible de calcular.\n\n",stringNumA,stringNumB);
					}
				}
			}
			flagA = 0;
			flagB = 0;
			//MostrarMenu();
			//fflush(stdin);
			//opcion = ValidarOpcion(1,5);
			break;
		}

	}while(opcion != 5);

	printf("Gracias por utilizar esta calculadora. Adios!");
	system("pause");
}
