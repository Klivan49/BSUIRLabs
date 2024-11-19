#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "LibForMe.h"
#include <time.h>
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
	system("cls");
	printf("Выберите задачу:\n");
	printf("1 -- \"Запрет уникальности\"\n");
	printf("2 -- \"Дешифратор\"\n");
	printf("3 -- Выход\n");
	n = inputNatural();
	switch (n)
	{
	case 1:
		inclusiviness();
		break;
	case 2:
		decryptor();
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

inclusiviness()
{
	float** massive;
	int lines = 0, rows = 0, counter = 0, numb = 0, n = 0;
	float prodOfNegatives = 1., sum = 0.;
	char* input;
	int inputLength;
	char buff[100];

	srand(time(NULL));

	printf("Введите кол-во строк матрицы: ");

	lines = inputNatural();

	printf("Введите кол-во столбцов матрицы: ");

	rows = inputNatural();

	massive = (float**)calloc(lines, sizeof(float*));
	for (int i = 0; i < lines; i++) massive[i] = (float*)calloc(rows, sizeof(float));

	printf("Введёте всё сами или доверитесь судьбе?(1/2): ");
	n = inputNatural();
	switch (n)
	{
	case 1:
	{
		system("cls");
		printf("Введите элементы матрицы:\n");
		for (int i = 0; i < lines; i++)
			for (int j = 0; j < rows; j++)
			{
				printf("a[%d][%d] = ", i + 1, j + 1);
				massive[i][j] = inputDigit();
			}
		break;
	}
	case 2:
	{
		for (int i = 0; i < lines; i++)
			for (int j = 0; j < rows; j++)
				massive[i][j] = rand() % 20 - 10;
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

	printf("Исходный массив: \n");
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < rows; j++)
			printf("%.2f ", massive[i][j]);
		printf("\n");
	}


	removeRowsWithoutRepeats(massive, &lines, rows);

	printf("Массив без уникальностей: \n");
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < rows; j++)
			printf("%.2f ", massive[i][j]);
		printf("\n");
	}
	free(massive);
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	return 0;
}

bool hasRepeatingElements(int* arr, int m) {
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			if (arr[i] == arr[j]) {
				return true;
			}
		}
	}
	return false;
}

removeRowsWithoutRepeats(int** arr, int* lines, int rows) {
	for (int i = 0; i < *lines; ) 
	{
		if (!hasRepeatingElements(arr[i], rows)) 
		{
			for (int j = i; j < *lines - 1; j++)
				arr[j] = arr[j + 1];
			(*lines)--;
		}
		else i++;
	}
}

int decryptor()
{
	char* massive;
	int length;

	printf("Введите кол-во символов в строке: ");

	length = inputNatural();

	massive = (char*)calloc(length, sizeof(char));

	puts("Введите сообщение, которое надо расшифровать: ");
	fgets(massive, length+1, stdin);
	printf("Исходное сообщение: ");
	puts(massive);
	decryptMessage(massive);
	printf("Дешифрованное сообщение: ");
	puts(massive);
	printf("Press any key to continue...");
	_getch();
	system("cls");
}
	
reverseWord(char* start, char* end) {
	while (start < end) 
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

decryptMessage(char* massive) {
	char* wordStart = massive;
	char* wordEnd = massive;

	while (*wordEnd) {
		wordEnd++;
		if (*wordEnd == ' ' 
			|| *wordEnd == '\0' 
			|| *wordEnd == ',' 
			|| *wordEnd == '?' 
			|| *wordEnd == '!' 
			|| *wordEnd == '.') 
		{
			reverseWord(wordStart, wordEnd - 1);
			wordStart = wordEnd + 1;
		}
	}
}