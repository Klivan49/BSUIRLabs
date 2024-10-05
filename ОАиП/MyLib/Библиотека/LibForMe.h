#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

int isNatural(void)
{
	char* input;
	int n = 0, nat = 0, i, counter = 0;
	char buff[100];
	fgets(buff, sizeof(buff), stdin);
	n = strlen(buff) - 1;
	input = (char*)malloc(n * sizeof(char));
	for (i = 0; i < n; i++) input[i] = buff[i];
	memset(buff, 0, sizeof(buff));
	for (i = 0; i < n; i++) if (input[i] < '0' || input[i] > '9') counter++;
	if (counter > 0)
	{
		printf("Вы явно ввели что-то не то\n");
		printf("Press any key to continue...\n");
		_getch();
		free(input);
		isNatural();
	}
	else
	{
		sscanf_s(input, "%d", &nat);
		free(input);
		return nat;
	}
}

float isDigit(void)
{
	char* input;
	int n = 0, i, counter = 0;
	float dig = 0;
	char buff[100];
	fgets(buff, sizeof(buff), stdin);
	n = strlen(buff) - 1;
	input = (char*)malloc(n * sizeof(char));
	for (i = 0; i < n; i++) input[i] = buff[i];
	memset(buff, 0, sizeof(buff));
	for (i = 0; i < n; i++) if ((input[i] >= '0' && input[i] <= '9') || input[i] == ',' || input[0] == '-') counter++;
	if (n != counter)
	{
		printf("Вы явно ввели что-то не то\n");
		printf("Press any key to continue...\n");
		_getch();
		free(input);
		isDigit();
	}
	else
	{
		sscanf_s(input, "%f", &dig);
		free(input);
		return dig;
	}
}