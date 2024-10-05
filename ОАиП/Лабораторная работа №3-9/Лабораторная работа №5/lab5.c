#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "LibForMe.h"


int main()
{
	char* locale = setlocale(LC_ALL, "");

	while (mainMenu());
}

int mainMenu()
{

	int n;
	printf("Что вы хотите сделать?\n");
	printf("1 -- Поиграться с массивом\n");
	printf("2 -- Ещё раз поиграться с массивом\n");
	printf("3 -- Выйти\n");
	n = isNatural();
	system("cls");
	switch (n)
	{
	case 1:
		sqrMassive();
		break;
	case 2:
		break;
	case 3:
		return 0;
	default:
	{
		printf("Неверный ввод\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
	}
	}
	return 1;
}

int sqrMassive()
{
	int **massive; //Создание указателя на массив
	int lines, rows;
	float min, sum = 0;

	printf("Введите кол-во строк массива: ");
	lines = isNatural();
	printf("Введите кол-во cтолбцов массива: ");
	rows = isNatural();
	massive = (int **)calloc(lines, sizeof(int*));
	for (int i = 0; i < lines; i++) massive[i] = (int*)calloc(rows, sizeof(int));
	printf("Введите элементы массива:\n"); //Введение элементов массива
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < rows; j++) 
		{
			printf("a[%d][%d] = ", i, j);
			massive[i][j] = isNatural();
		}
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < rows; j++) printf("%d ", massive[i][j]);
		printf("\n");
	}
	printf("\n");
	free(massive);
}
