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

FILE* f;

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
		return -1.1;
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
			free(input);
			return -1;
		}
		else
		{
			free(input);
			return temp;
		}
	}
	else { free(input); return -1; }
}

struct kino
{
	char name[100];
	int session;
	float cost;
	int numbOfVisitors;
};

struct kino film;

struct kino* arrOfFilms;

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
	printf("1 -- \"файлики\"\n");
	printf("2 -- \"Вкаченный кинотеатр\"\n");
	printf("3 -- Выход\n");
	n = inputNatural();
	system("cls");
	switch (n)
	{
	case 1:
	{
		break;
	}
	case 2:
		while (cinema());
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

cinema()
{
	printf("Что вы хотите сделать?\n1 -- Добавить структуру\n2 -- Отсортировать массив структур\n3 -- Произвести поиск в массиве структур по заданному параметру\n4 -- Изменить заданную структуру\n5 -- Удалить структуру из массива\n6 -- Вывести на экран массив структур\n7 -- Удалить файл(если была ошибка при его создании)\n8 -- Выйти\n");
	int n = inputNatural();
	system("cls");
	if (n > 1 && n < 7)
	{
		if (fopen_s(&f, "numberOfFilms.bin", "r+b") != 0) {
			printf("В базе нет информации ни об одном фильме(\n");
			printf("Press any key to continue...\n");
			_getch();
			system("cls");
			return 1;
		}
		else fclose(f);
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
		remaking();
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
		deleteFile();
		break;
	}
	case 8:
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
	int numberOfFilms, buff = 0;
	if (fopen_s(&f, "numberOfFilms.bin", "rb") != 0)
	{
		if (fopen_s(&f, "numberOfFilms.bin", "w+b") != 0)
		{
			printf("Ошибка создания файла(\n");
			return 0;
		}
		printf("Введите кол-во фильмов\n");
		numberOfFilms = inputNatural();
		if (numberOfFilms == -1)
		{
			printf("Вы ввели что-то не то...\nPress any key to continue...\n");
			fclose(f);
			_getch();
			return 0;
		}
		fwrite(&numberOfFilms, sizeof(int), 1, f);
		fclose(f);
	}
	else
	{
		fread(&numberOfFilms, sizeof(int), 1, f);
		fclose(f);
		if (fopen_s(&f, "numberOfFilms.bin", "w+b") != 0)
		{
			printf("Ошибка создания файла(\n");
			fclose(f);
			return 0;
		}
		printf("Введите кол-во фильмов\n");
		int addFilms = inputNatural();
		if (addFilms == -1)
		{
			printf("Вы ввели что-то не то...\nPress any key to continue...\n");
			fclose(f);
			_getch();
			return 0;
		}
		buff = numberOfFilms;
		numberOfFilms += addFilms;
		fwrite(&numberOfFilms, sizeof(int), 1, f);
		fclose(f);
	}
	
	if (fopen_s(&f, "kino.bin", "a+b") != 0)
	{
		if (fopen_s(&f, "kino.bin", "w+b") != 0)
		{
			printf("Ошибка создания файла(\n");
			return 0;
		}
	}
	for (int i = buff; i < numberOfFilms; i++)
	{
		printf("Введите название фильма №%d: ", i + 1);
		fgets(film.name, 100, stdin);

		printf("Введите номер сеанса: ");
		film.session = inputNatural();

		printf("Введите стоимость билета: ");
		film.cost = inputDigit();

		printf("Введите количество зрителей: ");
		film.numbOfVisitors = inputNatural();

		if (film.session == -1 || film.cost == -1.1 || film.numbOfVisitors == -1)
		{
			printf("Вы ввели что-то не то...\nPress any key to continue...\n");
			deleteFile();
			_getch();
			fclose(f);
			return 0;
		}

		fwrite(&film, sizeof(film), 1, f);
		printf("\n");
	}
	printf("Список успешно создан!\n");
	fclose(f);
}

sorting()
{
	printf("Как именно вы хотите отсортировать фильмы?\n1 -- В алфавитном порядке по названию\n2 -- По номеру сеанса\n3 -- По стоимости билета\n4 -- По количеству зрителей\n5 -- Выход\n");

	int numberOfFilms, n = inputNatural();

	if (fopen_s(&f, "numberOfFilms.bin", "rb") != 0)
	{
		printf("Ошибка открытия файла(\n");
		return 0;
	}
	fread(&numberOfFilms, sizeof(int), 1, f);
	fclose(f);

	arrOfFilms = malloc(numberOfFilms *(sizeof(char) * 100 + sizeof(int) * 2 + sizeof(float)));

	if (fopen_s(&f, "kino.bin", "rb") != 0)
	{
		printf("Ошибка открытия файла(\n");
		return 0;
	}
	for (int i = 0; i < numberOfFilms; i++) 
		fread(&arrOfFilms[i], sizeof(film), 1, f);

	switch (n)
	{
	case 1:
	{

		for (int i = 0; i < numberOfFilms - 1; i++)
			for (int j = i + 1; j < numberOfFilms; j++)
				if (strcmp(arrOfFilms[i].name, arrOfFilms[j].name) > 0)
				{
					film = arrOfFilms[i];
					arrOfFilms[i] = arrOfFilms[j];
					arrOfFilms[j] = film;
				}
		break;
	}
	case 2:
	{
		for (int i = 0; i < numberOfFilms - 1; i++)
			for (int j = i + 1; j < numberOfFilms; j++)
				if (arrOfFilms[i].session > arrOfFilms[j].session)
				{
					film = arrOfFilms[i];
					arrOfFilms[i] = arrOfFilms[j];
					arrOfFilms[j] = film;
				}
		break;
	}
	case 3:
	{

		for (int i = 0; i < numberOfFilms - 1; i++)
			for (int j = i + 1; j < numberOfFilms; j++)
				if (arrOfFilms[i].cost > arrOfFilms[j].cost)
				{
					film = arrOfFilms[i];
					arrOfFilms[i] = arrOfFilms[j];
					arrOfFilms[j] = film;
				}
		break;
	}

	case 4:
	{
		for (int i = 0; i < numberOfFilms - 1; i++)
			for (int j = i + 1; j < numberOfFilms; j++)
				if (arrOfFilms[i].numbOfVisitors > arrOfFilms[j].numbOfVisitors)
				{
					film = arrOfFilms[i];
					arrOfFilms[i] = arrOfFilms[j];
					arrOfFilms[j] = film;
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
	fclose(f);
	if (fopen_s(&f, "kino.bin", "wb") != 0)
	{
		printf("Ошибка открытия файла(\n");
		return 0;
	}
	for (int i = 0; i < numberOfFilms; i++)
	{
		film = arrOfFilms[i];
		fwrite(&film, sizeof(film), 1, f);
	}
	fclose(f);
	free(arrOfFilms);
}

finder()
{
	printf("По какому параметру вы будете проводить поиск?\n1 -- По названию\n2 -- По номеру сеанса\n3 -- По стоимости билета\n4 -- По количеству зрителей\n5 -- Выход\n");
	int numberOfFilms, n = inputNatural();

	if (fopen_s(&f, "numberOfFilms.bin", "rb") != 0)
	{
		printf("Ошибка открытия файла(\n");
		return 0;
	}
	fread(&numberOfFilms, sizeof(int), 1, f);
	fclose(f);

	arrOfFilms = malloc(numberOfFilms * (sizeof(char) * 100 + sizeof(int) * 2 + sizeof(float)));

	if (fopen_s(&f, "kino.bin", "rb") != 0)
	{
		printf("Ошибка открытия файла(\n");
		return 0;
	}
	for (int i = 0; i < numberOfFilms; i++)
		fread(&arrOfFilms[i], sizeof(film), 1, f);

	switch (n)
	{
	case 1:
	{
		char input[100];
		int counter = 0;
		printf("Введите название: ");
		fgets(input, 100, stdin);
		for (int i = 0; i < numberOfFilms; i++)
			if (strcmp(arrOfFilms[i].name, input) == 0)
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
		if (session == -1)
		{
			printf("Вы ввели что-то не то...\nPress any key to continue...\n");
			fclose(f);
			_getch();
			return 0;
		}
		for (int i = 0; i < numberOfFilms; i++)
			if (arrOfFilms[i].session == session)
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
		if (cost == -1.1)
		{
			printf("Вы ввели что-то не то...\nPress any key to continue...\n");
			fclose(f);
			_getch();
			return 0;
		}
		for (int i = 0; i < numberOfFilms; i++)
			if (arrOfFilms[i].cost <= cost)
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
		if (numbOfVisitors == -1)
		{
			printf("Вы ввели что-то не то...\nPress any key to continue...\n");
			fclose(f);
			_getch();
			return 0;
		}
		for (int i = 0; i < numberOfFilms; i++)
			if (arrOfFilms[i].numbOfVisitors >= numbOfVisitors)
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
	fclose(f);
	free(arrOfFilms);
}

remaking()
{
	int numberOfFilms, par, num;

	if (fopen_s(&f, "numberOfFilms.bin", "rb") != 0)
	{
		printf("Ошибка открытия файла(\n");
		return 0;
	}
	fread(&numberOfFilms, sizeof(int), 1, f);
	fclose(f);

	arrOfFilms = malloc(numberOfFilms * (sizeof(char) * 100 + sizeof(int) * 2 + sizeof(float)));

	if (fopen_s(&f, "kino.bin", "rb") != 0)
	{
		printf("Ошибка открытия файла(\n");
		return 0;
	}
	for (int i = 0; i < numberOfFilms; i++)
		fread(&arrOfFilms[i], sizeof(film), 1, f);

	printf("Информацию о каком фильме вы хотите изменить?\n");
	for (int i = 0; i < numberOfFilms; i++)
		printf("%d -- %s", i + 1, arrOfFilms[i].name);
	num = inputNatural() - 1;
	if (num >= numberOfFilms) {
		printf("Такого фильма нет");
		return 0;
	}
	printf("Что именно вы хотите изменить?\n1 -- Название\n2 -- Сеанс\n3 -- Стоимость билета\n4 -- Количество зрителей\n");
	par = inputNatural();
	switch (par)
	{
	case 1:
	{
		printf("Старое значение: %s\n", arrOfFilms[num].name);
		printf("Введите новое значение: ");
		fgets(arrOfFilms[num].name, 100, stdin);
		printf("Новое значение: %s\n", arrOfFilms[num].name);
		break;
	}
	case 2:
	{
		printf("Старое значение: %d\n", arrOfFilms[num].session);
		printf("Введите новое значение: ");
		arrOfFilms[num].session = inputNatural();
		if (arrOfFilms[num].session == -1)
		{
			printf("Вы ввели что-то не то...\nPress any key to continue...\n");
			fclose(f);
			_getch();
			return 0;
		}
	}
	case 3:
	{
		printf("Старое значение: %.2f\n", arrOfFilms[num].cost);
		printf("Введите новое значение: ");
		arrOfFilms[num].cost = inputDigit();
		if (arrOfFilms[num].cost == -1.1)
		{
			printf("Вы ввели что-то не то...\nPress any key to continue...\n");
			fclose(f);
			_getch();
			return 0;
		}
		printf("Новое значение: %.2f\n", arrOfFilms[num].cost);
		break;
	}
	case 4:
	{
		printf("Старое значение: %d\n", arrOfFilms[num].numbOfVisitors);
		printf("Введите новое значение: ");
		arrOfFilms[num].numbOfVisitors = inputNatural();
		if (arrOfFilms[num].numbOfVisitors == -1)
		{
			printf("Вы ввели что-то не то...\nPress any key to continue...\n");
			fclose(f);
			_getch();
			return 0;
		}
		printf("Новое значение: %d\n", arrOfFilms[num].numbOfVisitors);
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
	fclose(f);
	if (fopen_s(&f, "kino.bin", "wb") != 0)
	{
		printf("Ошибка открытия файла(\n");
		return 0;
	}
	for (int i = 0; i < numberOfFilms; i++)
	{
		film = arrOfFilms[i];
		fwrite(&film, sizeof(film), 1, f);
	}
	fclose(f);
	free(arrOfFilms);
}

deleting()
{
	int numberOfFilms, par, num;

	if (fopen_s(&f, "numberOfFilms.bin", "rb") != 0)
	{
		printf("Ошибка открытия файла(\n");
		return 0;
	}
	fread(&numberOfFilms, sizeof(int), 1, f);
	fclose(f);

	arrOfFilms = malloc(numberOfFilms * (sizeof(char) * 100 + sizeof(int) * 2 + sizeof(float)));

	if (fopen_s(&f, "kino.bin", "rb") != 0)
	{
		printf("Ошибка открытия файла(\n");
		return 0;
	}
	for (int i = 0; i < numberOfFilms; i++)
		fread(&arrOfFilms[i], sizeof(film), 1, f);
	fclose(f);

	printf("Информацию о каком фильме вы хотите удалить?\n");
	for (int i = 0; i < numberOfFilms; i++)
		printf("%d -- %s", i + 1, arrOfFilms[i].name);
	num = inputNatural() - 1;
	if (num == -2)
	{
		printf("Вы ввели что-то не то...\nPress any key to continue...\n");
		fclose(f);
		_getch();
		return 0;
	}
	if (num < numberOfFilms)
	{
		numberOfFilms--;
		if (fopen_s(&f, "numberOfFilms.bin", "r+b") != 0)
		{
			printf("Ошибка открытия файла(\n");
			return 0;
		}
		fwrite(&numberOfFilms, sizeof(int), 1, f);
		fclose(f);
		for (int i = num; i < numberOfFilms; i++)
			arrOfFilms[i] = arrOfFilms[i + 1];
		if (fopen_s(&f, "kino.bin", "wb") != 0)
		{
			printf("Ошибка открытия файла(\n");
			return 0;
		}
		for (int i = 0; i < numberOfFilms; i++)
		{
			film = arrOfFilms[i];
			fwrite(&film, sizeof(film), 1, f);
		}
		fclose(f);
		free(arrOfFilms);
	}
	else 
	{
		printf("Такого фильма в списке нет\n");
		free(arrOfFilms);
	}
}

outputStruct(int n, int num)
{
	int numberOfFilms;
	if (fopen_s(&f, "numberOfFilms.bin", "rb") != 0)
	{
		printf("Ошибка открытия файла(\n");
		return 0;
	}
	fread(&numberOfFilms, sizeof(int), 1, f);
	fclose(f);
	if (fopen_s(&f, "kino.bin", "rb") != 0)
	{
		printf("Ошибка открытия файла 2(\n");
		return 0;
	}
	if (n == 0)
	{
		for (int i = 0; i < numberOfFilms; i++)
		{
			fread(&film, sizeof(film), 1, f);
			printf("Название фильма: %s", film.name);
			printf("Номер сеанса: %d\n", film.session);
			printf("Стоимость билета: %.2f\n", film.cost);
			printf("Количество зрителей: %d\n", film.numbOfVisitors);
			printf("\n");
		}
	}
	if (n == 1)
	{
		fseek(f, sizeof(struct kino) * num, SEEK_SET);
		fread(&film, sizeof(film), 1, f);
		printf("Название фильма: %s", film.name);
		printf("Номер сеанса: %d\n", film.session);
		printf("Стоимость билета: %.2f\n", film.cost);
		printf("Количество зрителей: %d\n", film.numbOfVisitors);
		printf("\n");
	}
	fclose(f);
}

deleteFile()
{
	if(remove("numberOfFilms.bin")) printf("Ошибка удаления\n");
	if(remove("kino.bin")) printf("Ошибка удаления\n");
}