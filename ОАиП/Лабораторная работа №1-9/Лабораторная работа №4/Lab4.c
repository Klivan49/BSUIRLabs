#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "LibForMe.h"
#include <time.h>

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
	else { free(input); mainMenu(); return -1; }
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
	printf("1 -- Что-то узнать о массиве\n");
	printf("2 -- Поиграться с его строками\n");
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
		break;
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
	float min, sum = 0;
	char* input;
	int inputLength;
	char buff[100];
	int length;

	printf("Введите длину массива: ");

	length = inputNatural();
	
	massive = (float*)malloc(length * sizeof(float)); //Динамическое выделение памяти для массива


	printf("Введите элементы массива:\n"); //Введение элементов массива
	for (int i = 0; i < length; i++)
	{
		printf("a[%d] = ", i);
		massive[i] = inputDigit();
	}

	for (int i = 0; i < length; i++) printf("%.2f ", massive[i]);
	printf("\n");

	min = massive[0];
	for (int i = 0; i < length; i++)
		if (massive[i] < min) min = massive[i];
	printf("Минимальный элемент массива: %.3f\n", min);
	printf("Нажмите любую клавишу, чтобы найти сумму элементов между крайними отрицательными\n");
	_getch();
	float negative1 = 0, negative2 = 0;
	for (int i = 0; i < length; i++)
		if (massive[i] < 0)
		{
			negative1 = i+1;
			break;
		}
		if (negative1 == 0)
		{
			free(massive);
			printf("В массиве нет отрицательных элементов\n");
			printf("Press any key to continue...\n");
			_getch();
			system("cls");
			mainMenu();
		}
	for (int i = negative1; i < length; i++)
		if (massive[i] < 0)
		{
			negative2 = i;
			break;
		}
	if (negative2 == 0) printf("В массиве только 1 отрицательное число\n");
	else
	{
		for (int i = negative1; i < negative2; i++)
		{
			sum += massive[i];
		}
		printf("Сумма элементов между первыми двумя отрицательным элементами: %.3f\n", sum);
	}
	free(massive);
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
}

massiveXYZ() 
{
	float min, sum = 0;
	float massive[20];
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		massive[i] = -10 + rand() % 20;
	}

	printf("Исходный массив:\n");
	for (int i = 0; i < 20; i++) printf("%.2f ", massive[i]);

	rearrangeArray(massive);

	printf("\nМассив после перемещения отрицательных элементов в конец:\n");
	for (int i = 0; i < 20; i++) printf("%.2f ", massive[i]);

	printf("\nМассив в обратном порядке:\n");
	for (int i = 19; i >= 0; i--) printf("%.2f ", massive[i]);
	printf("\n");

	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	return 0;
}

rearrangeArray(float arr[]) //Функция, перемещающая все отрицательные элементы в конец массива 
{
	int temp[20];
	int j = 0;

	// Копируем все неотрицательные элементы в temp
	for (int i = 0; i < 20; i++) {
		if (arr[i] >= 0) {
			temp[j++] = arr[i];
		}
	}

	// Копируем все отрицательные элементы в temp
	for (int i = 0; i < 20; i++) {
		if (arr[i] < 0) {
			temp[j++] = arr[i];
		}
	}

	// Копируем temp обратно в arr
	for (int i = 0; i < 20; i++) {
		arr[i] = temp[i];
	}
}
