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
			printf("����� �� ����� ������� ������!\n");
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
	else { free(input); mainMenu(); return -1; }
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
	printf("�������� ������:\n");
	printf("1 -- \"���������\"\n");
	printf("2 -- �����\n");
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
		printf("�������� ����\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
	}
	}
	return 1;
}

cinema()
{
	printf("��� �� ������ �������?\n1 -- ������ ������ ��������\n2 -- ������������� ������ ��������\n3 -- ���������� ����� � ������� �������� �� ��������� ���������\n4 -- �������� �������� ���������\n5 -- ������� ��������� �� �������\n6 -- ������� �� ����� ������ ��������\n7 -- �����\n");
	int n = inputNatural();
	system("cls");
	if (numberOfFilms == 0 && n > 1 && n < 8)
	{
		printf("� ���� ��� ���������� �� �� ����� ������(\n");
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
		printf("�� ���� ����� ���-�� �� ��...\n");
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
	printf("������� ���-�� �������\n");
	numberOfFilms = inputInteger();
	data = malloc(numberOfFilms * (2 * sizeof(int) + sizeof(float) + 30 * sizeof(char)));
	for (int i = 0; i < numberOfFilms; i++)
	{
		printf("������� �������� ������ �%d: ", i + 1);
		fgets(data[i].name, 30, stdin);

		printf("������� ����� ������: ");
		data[i].session = inputNatural();

		printf("������� ��������� ������: ");
		data[i].cost = inputDigit();

		printf("������� ���������� ��������: ");
		data[i].numbOfVisitors = inputNatural();
		printf("\n");
	}
}

sorting()
{
	printf("��� ������ �� ������ ������������� ������?\n1 -- � ���������� ������� �� ��������\n2 -- �� ������ ������\n3 -- �� ��������� ������\n4 -- �� ���������� ��������\n5 -- �����\n");
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
		printf("�� ���� ����� ���-�� �� ��...\n");
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
	printf("�� ������ ��������� �� ������ ��������� �����?\n1 -- �� ��������\n2 -- �� ������ ������\n3 -- �� ��������� ������\n4 -- �� ���������� ��������\n5 -- �����\n");
	int n = inputNatural();
	switch (n)
	{
	case 1:
	{
		char input[30];
		int counter = 0;
		printf("������� ��������(��� ��� ������ �����): ");
		fgets(input, 30, stdin);
		for (int i = 0; i < numberOfFilms; i++)
			if (strcmp(data[i].name, input) == 0)
			{
				outputStruct(1, i);
				counter++;
			}
		if (counter == 0) printf("��� ������� � ����� ���������(\n");
		break;
	}
	case 2:
	{
		int counter = 0;
		printf("������� ����� ������: ");
		int session = inputNatural();
		for (int i = 0; i < numberOfFilms; i++)
			if (data[i].session == session)
			{
				outputStruct(1, i);
				counter++;
			}
		if (counter == 0) printf("�� ���� ����� ��� �������(\n");
		break;
	}
	case 3:
	{

		int counter = 0;
		printf("������� ��� ������: ");
		int cost = inputNatural();
		for (int i = 0; i < numberOfFilms; i++)
			if (data[i].cost <= cost)
			{
				outputStruct(1, i);
				counter++;
			}
		if (counter == 0) printf("� ����� �������� ���� ��� �� �� �������(\n");
		break;
	}
	case 4:
	{
		int counter = 0;
		printf("��������� ��������� ������ ���� �����?(������� ��������): ");
		int numbOfVisitors = inputNatural();
		for (int i = 0; i < numberOfFilms; i++)
			if (data[i].numbOfVisitors >= numbOfVisitors)
			{
				outputStruct(1, i);
				counter++;
			}
		if (counter == 0) printf("��������� ���������� ������� � ������� ������ ���(\n");
		break;
	}
	case 5:
	{
		return 0;
	}
	default:
	{
		printf("�� ���� ����� ���-�� �� ��...\n");
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
	printf("���������� � ����� ������ �� ������ ��������?\n");
	for (int i = 0; i < numberOfFilms; i++)
		printf("%d -- %s", i + 1, data[i].name);
	int num = inputNatural() - 1;
	if (num > numberOfFilms) {
		printf("������ ������ ���");
		return 0;
	}
	printf("��� ������ �� ������ ��������?\n1 -- ��������\n2 -- �����\n3 -- ��������� ������\n4 -- ���������� ��������\n");
	int par = inputNatural();
	switch (par)
	{
	case 1:
	{
		printf("������ ��������: %s\n", data[num].name);
		printf("������� ����� ��������: ");
		fgets(data[num].name, 30, stdin);
		printf("����� ��������: %s\n", data[num].name);
		break;
	}
	case 2:
	{
		printf("������ ��������: %d\n", data[num].session);
		printf("������� ����� ��������: ");
		data[num].session = inputNatural();
		printf("����� ��������: %s\n", data[num].session);
		break;
	}
	case 3:
	{
		printf("������ ��������: %f\n", data[num].cost);
		printf("������� ����� ��������: ");
		data[num].cost = inputDigit();
		printf("����� ��������: %s\n", data[num].cost);
		break;
	}
	case 4:
	{
		printf("������ ��������: %s\n", data[num].numbOfVisitors);
		printf("������� ����� ��������: ");
		data[num].numbOfVisitors = inputNatural();
		printf("����� ��������: %s\n", data[num].numbOfVisitors);
		break;
	}
	default:
	{
		printf("�� ���� ����� ���-�� �� ��...\n");
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
	printf("���������� � ����� ������ �� ������ �������?\n");
	for (int i = 0; i < numberOfFilms; i++)
		printf("%d -- %s", i + 1, data[i].name);
	int num = inputNatural() - 1;
	if (num <= numberOfFilms)
	{
		for (int i = num; i < numberOfFilms; i++)
			data[i] = data[i + 1];
		numberOfFilms--;
	}
	else printf("������ ������ � ������ ���\n");
}

outputStruct(int n, int num)
{
	if (n == 0)
	{
		for (int i = 0; i < numberOfFilms; i++)
		{
			printf("�������� ������: %s", data[i].name);
			printf("����� ������: %d\n", data[i].session);
			printf("��������� ������: %.2f\n", data[i].cost);
			printf("���������� ��������: %d\n", data[i].numbOfVisitors);
			printf("\n");
		}
	}
	if (n == 1)
	{
		printf("�������� ������: %s", data[num].name);
		printf("����� ������: %d\n", data[num].session);
		printf("��������� ������: %.2f\n", data[num].cost);
		printf("���������� ��������: %d\n", data[num].numbOfVisitors);
		printf("\n");
	}
}