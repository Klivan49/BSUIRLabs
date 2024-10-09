#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
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
	printf("Что вы ходите сделать?\n");
	printf("1 -- Загрузить кучу коробок\n");
	printf("2 -- Узнать, насколько всё просто с этими числами\n");
	printf("3 -- Выйти\n");
	n = inputNatural();
	switch (n)
	{
	case 1:
		gruzhchik();
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

gruzhchik()
{
	int Box1, Box2, loadCapacity, x, y, n = 0, buf;
	printf("Введите массу первой коробки: \n");
	Box1 = inputNatural();
	printf("Введите массу второй коробки: \n");
	Box2 = inputNatural();
	printf("Введите грузоподъёмность грузовика: \n");
	loadCapacity = inputNatural();
	if (Box1 == 0 || Box2 == 0 || loadCapacity == 0) printf("Вы забыли ввести какое-то значение\n");
	else
	{
		for (int i = 0; i < loadCapacity / Box1; i++)
			for (int j = 0; j < loadCapacity / Box2; j++)
				if (i * Box1 + j * Box2 == loadCapacity) n++;
		if (n >= 1) printf("Вы классный грузчик(всё влезло)!\n");
		else printf("Никак не впихнуть(\n");
	}
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
}

s1mple()
{
	int K, n = 0, buf;
	printf("Введите своё число(Натуральное): \n");
	K = inputNatural();
	if (K == 1) printf("Простая ли эта единица...?\n");
	for (int i = 1; i <= K; i++) if (K % i == 0) n++;
	if (n == 2) printf("Ваше число простое!\n");
	else printf("Не такое уж оно и простое...\n");
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
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
