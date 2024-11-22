#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

int isNumber(char input[], int length)
{

	int n, i, counter = 0;
	n = length;
	for (i = 0; i < n; i++)
		if (input[i] >= '0'
			&& input[i] <= '9'
			|| input[i] == '+'
			|| input[i] == '-'
			|| input[i] == '.'
			|| input[i] == ',') counter++;
	if (counter == n) return true;
	else
	{
		return false;
	}
}

int isNatural(char arr[], int length)
{
	int nat, i, n, errors = 0;
	n = length;
	if (isNumber(arr, n) == true)
	{
		for (i = 0; i < n; i++)
			if (arr[i] == '-' || arr[i] == '+') errors++;

		for (i = 0; i < n; i++)
			if (arr[i] == ',' || arr[i] == '.') errors++;

		for (i = 0; i < n; i++)
			if ((arr[0] == '0'
				|| arr[i] < '0'
				|| arr[i] > '9')
				&& arr[i] != ' ') errors++;

		if (errors != 0)
		{
			return false;
		}
		return true;
	}
	else return false;
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
		sorting();
		return -1;
	}
}

int main()
{
	char* locale = setlocale(LC_ALL, "");
	system("chcp 1251");
	system("cls");
	while (sorting());
}

int sorting()
{
	int count;
	int length; char** massive; char* temp; printf("Введите количество символов в строках: "); 
	length = inputNatural(); printf("Введите количество строк: "); count = inputNatural(); // Выделение памяти под массив строк 
	massive = (char**)malloc(count * sizeof(char*)); 
	for (int i = 0; i < count; i++) 
		massive[i] = (char*)malloc((length + 1) * sizeof(char)); // +1 для символа конца строки 
	printf("Введите строки, которые надо отсортировать:\n"); 
	for (int i = 0; i < count; i++) 
	{ 
		fgets(massive[i], length + 1, stdin); 
		massive[i][strcspn(massive[i], "\n")] = '\0'; // Удаляем символ новой строки 
	} 
	printf("Исходные строки:\n"); 
	for (int i = 0; i < count; i++) 
		puts(massive[i]); 
	// Выделение памяти для temp 
	temp = (char*)malloc((length + 1) * sizeof(char)); 
	// Сортировка строк 
	for (int i = 0; i < count - 1; i++) 
		for (int j = i + 1; j < count; j++) 
			if (strcmp(massive[i], massive[j]) > 0) 
			{ 
				strcpy(temp, massive[i]); 
				strcpy(massive[i], massive[j]); 
				strcpy(massive[j], temp); 
			}
	printf("Отсортированные строки:\n"); 
	for (int i = 0; i < count; i++)
		puts(massive[i]); 
	free(temp); 
	for (int i = 0; i < count; i++) 
		free(massive[i]);
	free(massive); 
	printf("На этом всё или хотите ещё что-то отсортировать?(Хочу - 1/Нет - 2)");
	int n = inputNatural();
	if (n == 1)
	{
		system("cls");
		return 1;
	}
	else if (n == 2)
		return 0;
	else
	{
		printf("Вы что-то не то ввели, завершаем программу....");
		return 0;
	}
}
