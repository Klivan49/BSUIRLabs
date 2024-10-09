#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "LibForMe.h"



int main()
{
	char* locale = setlocale(LC_ALL, "");
	system("chcp 1251");
	system("cls");

	while (mainMenu());
}

int mainMenu()
{

	int n;
	printf("Что вы хотите сделать?\n");
	printf("1 -- Поиграться с двумерным массивом массивом\n");
	printf("2 -- Ещё раз поиграться с двумерным массивом\n");
	printf("3 -- Выйти\n");
	n = inputNatural();
	system("cls");
	switch (n)
	{
	case 1:
		sqrMassive();
		break;
	case 2:
		maxSqrMassive();
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
	int lines, counter, sum = 0, diagsum = 0, ediagsum = 0, temp1, temp2;

	printf("Введите разрядность матрицы: ");
	lines = inputNatural();
	massive = (int **)calloc(lines, sizeof(int*));
	for (int i = 0; i < lines; i++) massive[i] = (int*)calloc(lines, sizeof(int));
	printf("Введите элементы массива:\n"); //Введение элементов массива
	for (int i = 0; i < lines; i++)
	{
		counter = 0;
		for (int j = 0; j < lines; j++)
		{
			printf("a[%d][%d] = ", i + 1, j + 1);
			massive[i][j] = inputInteger();
			sum = sum + massive[i][j];
			if (massive[i][j] < 0) counter++;
		}
		if (counter > 0) sum = 0;
		else printf("В строке %d нет отрицательных элементов и её сумма равна %d \n", i + 1, sum);
	}

	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < lines; j++) printf("%d ", massive[i][j]);
		printf("\n");
	}

	sum = massive[0][lines - 1];
	for (int i = 1; i < lines; i++)
	{
		temp1 = temp2 = 0;
		for (int j = 0; j < lines - i; j++)
		{
			temp1 += massive[i + j][j];
			temp2 += massive[j][i + j];
		}
		if (temp1 < sum) sum = temp1;
		if (temp2 < sum) sum = temp2;
	}
	printf("Минимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы: %d", sum);
	printf("\n");
	free(massive);
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	mainMenu();
}

int maxSqrMassive()
{
	int massive[4][4]; //Создание указателя на массив
	int counter, sum = 0, max, row, line;

	printf("Введите элементы массива:\n"); //Введение элементов массива
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("a[%d][%d] = ", i + 1, j + 1);
			massive[i][j] = inputInteger();
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) printf("%d ", massive[i][j]);
		printf("\n");
	}
	printf("\n");

	max = massive[0][0];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (max < massive[i][j])
			{
				max = massive[i][j];
				line = i;
			}
	for (int i = 0; i < 4; i++)
		sum += massive[0][i];
	if (max == sum) swapRows(massive, 0, line);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) printf("%d ", massive[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	mainMenu();
}

swapRows(int matrix[4][4], int row1, int row2) {
	for (int i = 0; i < 4; i++) {
		int temp = matrix[row1][i];
		matrix[row1][i] = matrix[row2][i];
		matrix[row2][i] = temp;
	}
}

int inputNatural()
{
	char* input;
	int inputLength;
	char buff[100];
	int n = 0;

	fgets(buff, sizeof(buff), stdin);
	inputLength = strlen(buff) - 1;
	input = (char*)malloc(inputLength * sizeof(char));
	for (int i = 0; i < inputLength; i++) input[i] = buff[i];
	memset(buff, 0, sizeof(buff));
	if (isNatural(input, inputLength) == true) {
		sscanf_s(input, "%d", &n); free(input);  return n;
	}
	else mainMenu();
}


int inputInteger()
{
	char* input;
	int inputLength;
	char buff[100];
	int n = 0;

	fgets(buff, sizeof(buff), stdin);
	inputLength = strlen(buff) - 1;
	input = (char*)malloc(inputLength * sizeof(char));
	for (int i = 0; i < inputLength; i++) input[i] = buff[i];
	memset(buff, 0, sizeof(buff));
	if (isInteger(input, inputLength) == true) {
		sscanf_s(input, "%d", &n); free(input); return n;
	}
	else mainMenu();
}