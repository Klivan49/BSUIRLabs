#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
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
	int n = 0;
	float min, sum = 0;

	printf("Введите дллину массива: ");

	n = isNatural();
	
	massive = (float*)malloc(n * sizeof(float)); //Создание динамического массива через выделение памяти

	printf("Введите элементы массива:\n");
	for (int i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		massive[i] = isDigit();
	}
	for (int i = 0; i < n; i++) printf("%.2f ", massive[i]);
	printf("\n");

	min = massive[0];
	for (int i = 0; i < n; i++)
		if (massive[i] < min) min = massive[i];
	printf("Минимальный элемент массива: %.3f\n", min);
	printf("Нажмите любую клавишу, чтобы найти сумму элементов между крайними отрицательными\n");
	_getch();
	float negative1, negative2;
	for (int i = 0; i < n; i++)
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
	for (int i = negative1; i , n; i++)
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
	float massive[20];
	for (int i = 0; i < 20; i++)
	{
		printf("a[%d] = ", i);
		massive[i] = isDigit();
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


rearrangeArray(float arr[]) 
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