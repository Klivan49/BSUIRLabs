#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "LibForMe.h"

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
		printf("�� ����� ���-�� �� ��...\nPress any key to continue...\n");
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
	int length; char** massive; char* temp; printf("������� ���������� �������� � �������: "); 
	length = inputNatural(); printf("������� ���������� �����: "); count = inputNatural();
	massive = (char**)malloc(count * sizeof(char*)); 
	for (int i = 0; i < count; i++) 
		massive[i] = (char*)malloc((length + 1) * sizeof(char));
	printf("������� ������, ������� ���� �������������:\n"); 
	for (int i = 0; i < count; i++) 
	{ 
		fgets(massive[i], length + 1, stdin); 
		massive[i][strcspn(massive[i], "\n")] = '\0';
	} 
	printf("�������� ������:\n"); 
	for (int i = 0; i < count; i++) 
		puts(massive[i]); 
	temp = (char*)malloc((length + 1) * sizeof(char)); 
	for (int i = 0; i < count - 1; i++) 
		for (int j = i + 1; j < count; j++) 
			if (strcmp(massive[i], massive[j]) > 0) 
			{ 
				strcpy(temp, massive[i]); 
				strcpy(massive[i], massive[j]); 
				strcpy(massive[j], temp); 
			}
	printf("��������������� ������:\n"); 
	for (int i = 0; i < count; i++)
		puts(massive[i]); 
	free(temp); 
	for (int i = 0; i < count; i++) 
		free(massive[i]);
	free(massive); 
	printf("�� ���� �� ��� ������ ��� ���-�� �������������?(���� - 1/��� - 2)");
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
		printf("�� ���-�� �� �� �����, ��������� ���������....");
		return 0;
	}
}
