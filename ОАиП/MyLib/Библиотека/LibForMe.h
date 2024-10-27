#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
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
		printf("Вы явно ввели не число\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
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
			printf("Вы явно ввели что-то не то\n");
			printf("Press any key to continue...\n");
			_getch();
			system("cls");
			return false;
		}
		return true;
	}
	else return false;
}

int isInteger(char arr[], int length)
{
	int i, n, errors = 0;
	n = length;
	if (isNumber(arr, n) == true)
	{
		for (i = 0; i < n; i++)
			if (arr[i] == ',' || arr[i] == '.') errors++;

		for (i = 0; i < n; i++)
			if (arr[i] != ' '
				&& arr[i] != '+'
				&& arr[i] != '-'
				&& (arr[i] < '0'
					|| arr[i] > '9')) errors++;

		if (errors != 0)
		{
			printf("Вы явно ввели что-то не то\n");
			printf("Press any key to continue...\n");
			_getch();
			system("cls");
			return false;
		}
		return true;
	}
	else return false;
}

int isDigit(char arr[], int length)
{
	int i, n, errors = 0;
	n = length;
	if (isNumber(arr, n) == true)
	{
		for (i = 0; i < n; i++)
			if ((arr[i] < '0'
				|| arr[i] > '9')
				&& arr[i] != ' '
				&& arr[i] != '+ '
				&& arr[i] != '-'
				&& arr[i] != '.'
				&& arr[i] != ',') errors++;
		int pointCounter = 0;
		for (i = 0; i < n; i++)
		{
			if (arr[i] == ',' || arr[i] == '.')
			{
				if (arr[i] == '.')
				{
					arr[i] = ',';
					pointCounter++;
				}
			}
		}
		if (pointCounter > 1) errors++;

		if (errors != 0)
		{
			printf("Вы явно ввели что-то не то\n");
			printf("Press any key to continue...\n");
			_getch();
			system("cls");
			return false;
		}
		return true;
	}
	else return false;
}