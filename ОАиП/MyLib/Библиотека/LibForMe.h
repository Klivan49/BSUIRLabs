#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

int isNatural()
{
	int n = 0;
	char input[100];
	fgets(input, sizeof(input), stdin);
	for (int i = 0; input[i] != '\0'; i++) if (input[i] < '0' || input[i] > '9') n++;
	if (n > 1)
	{
		printf("явно вы ввели что-то не то\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
		return NULL;
	}
	else
	{
		sscanf_s(input, "%d", &n);
		return n;
	}
}

int isDigit()
{
	int n = 0, counter = 0;
	char input[100];
	fgets(input, sizeof(input), stdin);
	for (int i = 0; input[i] != '\0'; i++)
	{
		counter++;
		if ((input[i] >= '0' && input[i] <= '9') || input[i] == '.' || input[i] == '-') n++;
	}
	if (n != counter - 1)
	{
		printf("явно вы ввели что-то не то\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
		return NULL;
	}
	else
	{
		sscanf_s(input, "%d", &n);
		return n;
	}
}