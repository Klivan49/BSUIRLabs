﻿#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "LibForMe.h"

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
	if (isNatural(input, inputLength) == true)
	{
		sscanf_s(input, "%d", &n);
		free(input);
		return n;
	}
	else
	{
		printf("Вы ввели что-то не то...\nPress any key to continue...\n");
		_getch();
		free(input);
		mainMenu();
		return -1;
	}
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
	else
	{
		printf("Вы ввели что-то не то...\nPress any key to continue...\n");
		_getch();
		free(input);
		mainMenu();
		return -1;
	}
}

float inputDigit()
{
	char* input;
	int inputLength;
	char buff[100];
	float temp = 0;

	fgets(buff, sizeof(buff), stdin);
	inputLength = strlen(buff) - 1;
	input = (char*)malloc(inputLength * sizeof(char));
	for (int i = 0; i < inputLength; i++) input[i] = buff[i];
	memset(buff, 0, sizeof(buff));
	if (isDigit(input, inputLength) == true)
	{
		for (int i = 0; i < inputLength; i++) if (input[i] == '.') { input[i] = ','; }
		sscanf_s(input, "%f", &temp);
		free(input);
		return temp;
	}
	else 
	{ 
		printf("Вы ввели что-то не то...\nPress any key to continue...\n");
		_getch();
		free(input); 
		mainMenu(); 
		return -1; 
	}
}

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
	printf("1 -- Поиграться с массивом\n");
	printf("2 -- Ещё раз поиграться с массивом\n");
	printf("3 -- Выйти\n");
	n = inputNatural();
	switch (n)
	{
	case 1:
		superMassive();
		break;
	case 2:
		massiveXYZ();
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

superMassive()
{
	float* massive; //Создание указателя на массив
	int length = 0, counter = 0, numb = 0;
	float prodOfNegatives = 1., sum = 0.;
	char* input;
	int inputLength;
	char buff[100];

	printf("Введите длину массива: ");

	length = inputNatural();
	

	massive = (float*)malloc(length * sizeof(float)); //Динамическое выделение памяти для массива

	printf("Введите элементы массива:\n"); //Введение элементов массива
	for (int i = 0; i < length; i++)
	{
		printf("a[%d] = ", i+1);
		massive[i] = inputDigit();
	}
	for (int i = 0; i < length; i++) printf("%.2f ", massive[i]);
	printf("\n");
	float max = massive[0];

	for (int i = 0; i < length; i++)
	{
		if (massive[i] < 0)
		{
			prodOfNegatives *= massive[i];
			counter++;
		}
		if (massive[i] > max)
		{
			max > massive[i];
			numb = i;
		}
	}

	for (int i = 0; i < numb; i++)
		if (massive[i] > 0) sum += massive[i];
	if (counter == 0) printf("В массиве нет отрицательных элементов\n");
	else printf("Произведение отрицательных элементов равно %.2f\n", prodOfNegatives);
	printf("Сумма положительных элементов, расположенных до максимального элемента равна %.2f\n", sum);
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	return 0;
}

int massiveXYZ()
{
	int** massive; //Создание указателя на массив
	int lines, rows, counter2 = 0, row;

	printf("Введите кол-во строк матрицы: ");
	lines = inputNatural();
	printf("Введите кол-во строк столбцов: ");
	rows = inputNatural();

	massive = (int**)calloc(lines, sizeof(int*));
	for (int i = 0; i < lines; i++) massive[i] = (int*)calloc(rows, sizeof(int));
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < rows; j++)
			massive[i][j] = rand() % 10;
	}
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < lines; j++) printf("%d ", massive[i][j]);
		printf("\n");
	}

	for (int i = 0; i < rows; i++) {
		int counter = 1; 
		for (int j = 1; j < lines; j++) 
		{ 
			if (massive[j][i] == massive[j - 1][i]) 
				counter++;
			else 
			{ 
				if (counter > counter2) 
				{ 
					counter2 = counter; 
					row = i; 
				} 
				counter = 1; 
			} 
		} 
		if (counter > counter2)
		{
			counter2 = counter;
			row = i;
		}
	}
	printf("Номер столбца с максимальным количеством плвторяющихся элементов: %d\n", row+1);
			
}
