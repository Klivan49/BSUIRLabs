#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <stdint.h>
#include "LibForMe.h"

int main()
{
	char* locale = setlocale(LC_ALL, "");

	while (mainMenu());
}

int mainMenu()
{

	int n;
	printf("Что вы ходите сделать?\n");
	printf("1 -- Поиграться с массивом\n");
	printf("2 -- Узнать, насколько всё просто с этими числами\n");
	printf("3 -- Выйти\n");
	n = isDigit();
	system("cls");
	switch (n)
	{
	case 1:
		superMassive();
		break;
	case 2:
		s1mple();
		break;
	case 3:
		return 0;
	default:
	{
		printf("Некоректный ввод\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
	}
	}
	return 1;
}

superMassive()
{
	int size, Box2, loadCapacity, x, y, n = 0;
	printf("Введите кол-во элементов массива \n");
	size = isNatural();
	if (size == NULL) mainMenu();

	printf("Press any key to continue...\n");
	_getch();
	system("cls");
}

s1mple()
{
	int K, n = 0;
	printf("Введите своё число(Натуральное): \n");
	K = isDigit();
	if (K == 1) printf("Простая ли эта единица...?\n");
	if (K == 0) printf("НАТУРАЛЬНОЕ!\n");
	for (int i = 1; i <= K; i++) if (K % i == 0) n++;
	if (n == 2) printf("Ваше число простое!\n");
	else printf("Не такое уж оно и простое...\n");
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
}