#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "LibForMe.h"
#include <stdbool.h>

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
		if (temp <= 0)
		{
			printf("Билет не может столько стоить!\n");
			printf("Press any key to continue...");
			free(input);
			_getch();
			system("cls");
			cinema();
			return -1;
		}
		else
		{
			free(input);
			return temp;
		}
	}
	else 
	{ 
		free(input); 
		printf("Вы ввели что-то не то...\nPress any key to continue...\n");
		_getch(); 
		mainMenu(); 
		return -1; 
	}
}

struct kino
{
	char name[30];
	int session;
	float cost;
	int numbOfVisitors;
}*data;

struct kino temp;

int numberOfFilms = 0;

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
	system("cls");
	printf("Выберите задачу:\n");
	printf("1 -- \"Кинотеатр\"\n");
	printf("2 -- Выход\n");
	n = inputNatural();
	switch (n)
	{
	case 1:
		system("cls");
		while (cinema());
		break;
	case 2:
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

cinema()
{
	printf("Что вы хотите сделать?\n1 -- Ввести массив структур\n2 -- Отсортировать массив структур\n3 -- Произвести поиск в массиве структур по заданному параметру\n4 -- Изменить заданную структуру\n5 -- Удалить структуру из массива\n6 -- Вывести на экран массив структур\n7 -- Выйти\n");
	int n = inputNatural();
	system("cls");
	if (numberOfFilms == 0 && n > 1 && n < 8)
	{
		printf("В базе нет информации ни об одном фильме(\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
		return 1;

	}
	switch (n)
	{
	case 1:
	{
		inputStruct();
		break;
	}
	case 2:
	{
		sorting();
		break;
	}
	case 3:
	{
		finder();
		break;
	}
	case 4:
	{
		remaking(data);
		break;
	}
	case 5:
	{
		deleting();
		break;
	}
	case 6:
	{
		outputStruct(0, NULL);
		break;
	}
	case 7:
	{
		return 0;
	}
	default:
	{
		printf("Вы явно ввели что-то не то...\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
		mainMenu();
		break;
	}
	}

	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	return 1;
}

inputStruct()
{
	printf("Введите кол-во фильмов\n");
	numberOfFilms = inputInteger();
	data = malloc(numberOfFilms * (2 * sizeof(int) + sizeof(float) + 30 * sizeof(char)));
	for (int i = 0; i < numberOfFilms; i++)
	{
		printf("Введите название фильма №%d: ", i + 1);
		fgets(data[i].name, 30, stdin);

		printf("Введите номер сеанса: ");
		data[i].session = inputNatural();

		printf("Введите стоимость билета: ");
		data[i].cost = inputDigit();

		printf("Введите количество зрителей: ");
		data[i].numbOfVisitors = inputNatural();
		printf("\n");
	}
}

sorting()
{
	printf("Как именно вы хотите отсортировать фильмы?\n1 -- В алфавитном порядке по названию\n2 -- По номеру сеанса\n3 -- По стоимости билета\n4 -- По количеству зрителей\n5 -- Выход\n");
	int n = inputNatural();
	switch (n)
	{
	case 1:
	{

		for (int i = 0; i < numberOfFilms - 1; i++)
			for (int j = i + 1; j < numberOfFilms; j++)
				if (strcmp(data[i].name, data[j].name) > 0)
				{
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
		break;
	}
	case 2:
	{
		for (int i = 0; i < numberOfFilms - 1; i++)
			for (int j = i + 1; j < numberOfFilms; j++)
				if (data[i].session > data[j].session)
				{
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
		break;
	}
	case 3:
	{

		for (int i = 0; i < numberOfFilms - 1; i++)
			for (int j = i + 1; j < numberOfFilms; j++)
				if (data[i].cost > data[j].cost)
				{
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
		break;
	}

	case 4:
	{
		for (int i = 0; i < numberOfFilms - 1; i++)
			for (int j = i + 1; j < numberOfFilms; j++)
				if (data[i].numbOfVisitors > data[j].numbOfVisitors)
				{
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
		break;
	}
	case 5:
	{
		return 0;
	}
	default:
	{
		printf("Вы явно ввели что-то не то...\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
		mainMenu();
		break;
	}
	}
}

finder()
{
	printf("По какому параметру вы будете проводить поиск?\n1 -- По названию\n2 -- По номеру сеанса\n3 -- По стоимости билета\n4 -- По количеству зрителей\n5 -- Выход\n");
	int n = inputNatural();
	switch (n)
	{
	case 1:
	{
		char input[30];
		int counter = 0;
		printf("Введите название: ");
		fgets(input, 30, stdin);
		for (int i = 0; i < numberOfFilms; i++)
			if (strcmp(data[i].name, input) == 0)
			{
				outputStruct(1, i);
				counter++;
			}
		if (counter == 0) printf("Нет фильмов с таким названием(\n");
		break;
	}
	case 2:
	{
		int counter = 0;
		printf("Введите номер сеанса: ");
		int session = inputNatural();
		for (int i = 0; i < numberOfFilms; i++)
			if (data[i].session == session)
			{
				outputStruct(1, i);
				counter++;
			}
		if (counter == 0) printf("На этот сеанс нет фильмов(\n");
		break;
	}
	case 3:
	{

		int counter = 0;
		printf("Введите ваш бюджет: ");
		int cost = inputDigit();
		for (int i = 0; i < numberOfFilms; i++)
			if (data[i].cost <= cost)
			{
				outputStruct(1, i);
				counter++;
			}
		if (counter == 0) printf("С таким бюджетом кино вам не по карману(\n");
		break;
	}
	case 4:
	{
		int counter = 0;
		printf("Насколько популярен должен быть фильм?(минимум зрителей): ");
		int numbOfVisitors = inputNatural();
		for (int i = 0; i < numberOfFilms; i++)
			if (data[i].numbOfVisitors >= numbOfVisitors)
			{
				outputStruct(1, i);
				counter++;
			}
		if (counter == 0) printf("Настолько популярных фильмов в прокате сейчас нет(\n");
		break;
	}
	case 5:
	{
		return 0;
	}
	default:
	{
		printf("Вы явно ввели что-то не то...\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
		mainMenu();
		break;
	}
	}
}

remaking(struct kino* data)
{
	printf("Информацию о каком фильме вы хотите изменить?\n");
	for (int i = 0; i < numberOfFilms; i++)
		printf("%d -- %s", i + 1, data[i].name);
	int num = inputNatural() - 1;
	if (num >= numberOfFilms) {
		printf("Такого фильма нет"); 
		return 0; 
	}
	printf("Что именно вы хотите изменить?\n1 -- Название\n2 -- Сеанс\n3 -- Стоимость билета\n4 -- Количество зрителей\n");
	int par = inputNatural();
	switch (par)
	{
	case 1:
	{
		printf("Старое значение: %s\n", data[num].name);
		printf("Введите новое значение: ");
		fgets(data[num].name, 30, stdin);
		printf("Новое значение: %s\n", data[num].name);
		break;
	}
	case 2:
	{
		printf("Старое значение: %d\n", data[num].session);
		printf("Введите новое значение: ");
		data[num].session = inputNatural();
		printf("Новое значение: %d\n", data[num].session);
		break;
	}
	case 3:
	{
		printf("Старое значение: %f\n", data[num].cost);
		printf("Введите новое значение: ");
		data[num].cost = inputDigit();
		printf("Новое значение: %f\n", data[num].cost);
		break;
	}
	case 4:
	{
		printf("Старое значение: %d\n", data[num].numbOfVisitors);
		printf("Введите новое значение: ");
		data[num].numbOfVisitors = inputNatural();
		printf("Новое значение: %d\n", data[num].numbOfVisitors);
		break;
	}
	default:
	{
		printf("Вы явно ввели что-то не то...\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
		mainMenu();
		break;
	}
	}

}

deleting()
{
	printf("Информацию о каком фильме вы хотите удалить?\n");
	for (int i = 0; i < numberOfFilms; i++)
		printf("%d -- %s", i + 1, data[i].name);
	int num = inputNatural() - 1;
	if (num <= numberOfFilms)
	{
		for (int i = num; i < numberOfFilms; i++)
			data[i] = data[i + 1];
		numberOfFilms--;
	}
	else printf("Такого фильма в списке нет\n");
}

outputStruct(int n, int num)
{
	if (n == 0)
	{
		for (int i = 0; i < numberOfFilms; i++)
		{
			printf("Название фильма: %s", data[i].name);
			printf("Номер сеанса: %d\n", data[i].session);
			printf("Стоимость билета: %.2f\n", data[i].cost);
			printf("Количество зрителей: %d\n", data[i].numbOfVisitors);
			printf("\n");
		}
	}
	if (n == 1)
	{
		printf("Название фильма: %s", data[num].name);
		printf("Номер сеанса: %d\n", data[num].session);
		printf("Стоимость билета: %.2f\n", data[num].cost);
		printf("Количество зрителей: %d\n", data[num].numbOfVisitors);
		printf("\n");
	}
}