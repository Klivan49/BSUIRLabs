#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include "LibForMe.h"

struct kino
{
	char name[100];
	int session;
	float cost;
	int numbOfVisitors;
}*data;

struct kino temp;

FILE* f;

int numberOfFilms;

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
		free(input);
		return temp;
	}
	else { free(input); mainMenu(); return -1; }
}

int main()
{
	char* locale = setlocale(LC_ALL, "");
	system("cls");
	system("chcp 1251");
	while (mainMenu());
}

mainMenu()
{
	int n;
	system("cls");
	printf("�������� ������:\n");
	printf("1 -- \"���������� � �������\"\n");
	printf("2 -- \"��������� ���������\"\n");
	printf("3 -- �����\n");
	n = inputNatural();
	switch (n)
	{
	case 1:
		break;
	case 2:
		system("cls");
		while (cinema());
		break;
	case 3:
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
	if (sizeof(data) == 0 && n > 1 && n < 8)
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
	fopen_s(&f, "numberOfFilms.bin", "wb");
	if (f == 0) { printf("������ �������� �����(\n"); return 0; }
	printf("������� ���-�� �������\n");
	numberOfFilms = inputInteger();
	fwrite(&numberOfFilms, sizeof(int), 1, f);
	fclose(f);
	fopen_s(&f, "kino.bin", "wb");
	if (f == 0) { printf("������ �������� �����(\n"); return 0; }
	data = malloc(numberOfFilms * (2 * sizeof(int) + sizeof(float) + 100 * sizeof(char)));
	for (int i = 0; i < numberOfFilms; i++)
	{
		printf("������� �������� ������ �%d: ", i + 1);
		fgets(data[i].name, 100, stdin);

		printf("������� ����� ������: ");
		data[i].session = inputNatural();

		printf("������� ��������� ������: ");
		data[i].cost = inputDigit();

		printf("������� ���������� ��������: ");
		data[i].numbOfVisitors = inputNatural();
		printf("\n");
	}
	fwrite(data, sizeof(data), numberOfFilms, f);
	fclose(f);
	free(data);
	printf("������ ������� ������!\n");
}

sorting()
{
	printf("��� ������ �� ������ ������������� ������?\n1 -- � ���������� ������� �� ��������\n2 -- �� ������ ������\n3 -- �� ��������� ������\n4 -- �� ���������� ��������\n5 -- �����\n");
	int n = inputNatural();
	switch (n)
	{
	case 1:
	{
		fopen_s(&f, "kino.bin", "r+b");
		for (int i = 0; i < numberOfFilms - 1; i++)
			for (int j = i + 1; j < numberOfFilms; j++)
				if (strcmp(data[i].name, data[j].name) > 0)
				{
					fread(&data[i], sizeof(data), numberOfFilms, f);
					fread(&data[j], sizeof(data), numberOfFilms, f);
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
					fread(&data[i], sizeof(data), numberOfFilms, f);
					fread(&data[j], sizeof(data), numberOfFilms, f);
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
					fread(&data[i], sizeof(data), numberOfFilms, f);
					fread(&data[j], sizeof(data), numberOfFilms, f);
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
					fread(&data[i], sizeof(data), numberOfFilms, f);
					fread(&data[j], sizeof(data), numberOfFilms, f);
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
		char input[100];
		int counter = 0;
		printf("������� ��������(��� ��� ������ �����): ");
		fgets(input, 100, stdin);
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
		fgets(data[num].name, 100, stdin);
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
	fopen_s(&f, "numberOfFilms.bin", "rb");
	fread(&numberOfFilms, sizeof(int), 1, f);
	fclose(f);
	fopen_s(&f, "kino.bin", "rb");
	fread(data, sizeof(data), numberOfFilms, f);
	if (f == 0) { printf("������ �������� �����(\n"); return 0; }
	if (n == 0)
	{
		for(int i = 0; i < numberOfFilms; i++)
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
	fclose(f);
}

