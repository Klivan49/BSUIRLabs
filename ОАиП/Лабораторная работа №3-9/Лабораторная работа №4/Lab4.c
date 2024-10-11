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

	printf("Введите дллину массива: ");

	length = inputNatural();
	
	massive = (float*)malloc(length * sizeof(float)); //Динамическое выделение памяти для массива


	printf("Введите элементы массива:\n"); //Введение элементов массива
	for (int i = 0; i < length; i++)
	{
		printf("a[%d] = ", i);
		fgets(buff, sizeof(buff), stdin);
		inputLength = strlen(buff) - 1;
		input = (char*)malloc(inputLength * sizeof(char));
		for (int i = 0; i < inputLength; i++) input[i] = buff[i];
		memset(buff, 0, sizeof(buff));
		if (isDigit(input, inputLength) == true)
		{
			for (int i = 0; i < inputLength; i++) if (input[i] == '.') { input[i] = ','; }
			sscanf_s(input, "%f", &massive[i]);
		}
		else mainMenu();
		free(input);
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
			negative1 = i + 1;
			break;
		}
		else 
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
			negative2 = i - 1;
			break;
		}
	if (negative1 == negative2) printf("В массиве только 1 отрицательное число");
	else
	{
		for (int i = negative1; i < negative2-1; i++)
		{
			sum += massive[i];
		}
		printf("Сумма элементов между первым и последним отрицательным элементами: %.3f\n", sum);
	}
	free(massive);
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
}


int massiveXYZ() 
{
	float min, sum = 0;
	char* input;
	int inputLength = 20;
	char buff[100];
	float massive[20];
	printf("Введите элеметны массива: \n");
	for (int i = 0; i < 20; i++)
	{
		printf("a[%d] = ", i);
		fgets(buff, sizeof(buff), stdin);
		inputLength = strlen(buff) - 1;
		input = (char*)malloc(inputLength * sizeof(char));
		for (int i = 0; i < inputLength; i++) input[i] = buff[i];
		memset(buff, 0, sizeof(buff));
		if (isDigit(input, inputLength) == true)
		{
			for (int i = 0; i < inputLength; i++) if (input[i] == '.') { input[i] = ','; }
			sscanf_s(input, "%f", &massive[i]);

		}
		else mainMenu();
		free(input);
	}
	printf("Исходный массив:\n");
	for (int i = 0; i < 20; i++) printf("%.2f ", massive[i]);
	printf("\n");

	rearrangeArray(massive);

	printf("Массив после перемещения отрицательных элементов в конец:\n");
	for (int i = 0; i < 20; i++) printf("%.2f ", massive[i]);

	printf("Массив в обратном порядке:\n");
	for (int i = 19; i >= 0; i--) printf("%.2f ", massive[i]);
	printf("\n");

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
