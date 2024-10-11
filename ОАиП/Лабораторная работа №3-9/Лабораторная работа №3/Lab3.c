#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include "LibForMe.h"


int main()
{
	char* locale = setlocale(LC_ALL, "");
	system("chcp 1251"); //кодировка
	system("cls"); //очистка конслоли

	while (mainMenu());
}

int mainMenu()
{

	int n;
	printf("Что вы ходите сделать?\n");
	printf("1 -- Загрузить кучу коробок\n");
	printf("2 -- Узнать, простое ли ваше число\n");
	printf("3 -- Узнать, сколько простых чисел в вашем диапозоне\n");
	printf("4 -- Узнать, какое простое число стоит под номером n\n");
	printf("5 -- Выйти\n");
	n = inputNatural();
	switch (n)
	{
	case 1:
		gruzhchik();
		break;
	case 2:
		s1mple1();
		break;
	case 3:
		s1mple2();
		break;
	case 4:
		s1mple3();
		break;
	case 5:
		return 0;
		break;
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
				if (i * Box1 + j * Box2 == loadCapacity)
				{
					printf("Потребовалось %d коробок массой %d и %d коробок массой %d\n", i, Box1, j, Box2);
					n++;
				}
		if (n >= 1) printf("Вы классный грузчик(всё влезло)!\n");
		else printf("Никак не впихнуть(\n");
	}
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	mainMenu();
}

s1mple1()
{
	int K, n = 0, buf;
	printf("Введите своё число(Натуральное): \n");
	K = inputNatural();
	if (K == 1) printf("Простая ли эта единица...?\n");
	for (int i = 1; i <= K; i++)
		if (K % i == 0) n++;
	if (n == 2) printf("Ваше число простое!\n");
	else printf("Не такое уж оно и простое...\n");
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	mainMenu();
}

s1mple2()
{
	int n = 0, el1, eln, counter = 0;
	printf("Введите первый элемент диапазона: \n");
	el1 = inputNatural();
	if (el1 == 1) 
	{ 
		printf("Единица не должна быть в диапазоне, иначе вселенная схлопнется!\n"); 
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
		mainMenu(); 
	}
	printf("Введите последний элемент диапазона: \n");
	eln = inputNatural();
	if (el1 >= eln) 
	{ 
		printf("А что это за диапазон такой? Мы такого не знаем!\n"); 
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
		mainMenu(); 
	}
	printf("Простые числа в вашем диапазоне: ");
	for (int i = el1; i <= eln; i++)
	{
		for (int j = 2; j < i; j++)
			if (i % j == 0)
				n++;
		if (n == 0) { printf("%d ", i); counter++; }
		n = 0;
	}
	if (counter == 0) printf("Их нет(");
	else printf("\nВсего простых чисел в вашем диапазоне: %d\n", counter);

	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	mainMenu();
}

s1mple3()
{
	int temp, n = 0, counter = 0, buf = 0;
	printf("Введите номер простого числа, которое вы хотите узнать: \n");
	n = inputNatural();
	temp = 2;
	while (counter != n)
	{
		for (int i = 1; i <= temp; i++)
			if (temp % i == 0) buf++;
		if (buf == 2) 
		{
			counter++; 
		}
		buf = 0;
		temp++;
	}
	printf("Ваше простое число: %d\n", temp-1);
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	mainMenu();
}

int inputNatural()
{
	char* input; //создание указателя на массив
	int inputLength;
	char buff[100]; //буферный массив, который мы потом обнулим
	int n = 0;

	fgets(buff, sizeof(buff), stdin); //получает строку из из консоли как массив символов
	inputLength = strlen(buff) - 1;
	input = (char*)malloc(inputLength * sizeof(char)); //выделяет память из стэка в 
	for (int i = 0; i < inputLength; i++) input[i] = buff[i];
	memset(buff, 0, sizeof(buff)); //"Обнуляет" массив buff
	if (isNatural(input, inputLength) == true) 
	{
		sscanf_s(input, "%d", &n); 
		free(input);  
		return n;
	}
	else mainMenu();
}
