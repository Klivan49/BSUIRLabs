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
	printf("�������� ������:\n");
	printf("1 -- \"�������\"\n");
	printf("2 -- \"��������� ���������\"\n");
	printf("3 -- �����\n");
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
	printf("��� �� ������ �������?\n1 -- �������� ���������\n2 -- ������������� ������ ��������\n3 -- ���������� ����� � ������� �������� �� ��������� ���������\n4 -- �������� �������� ���������\n5 -- ������� ��������� �� �������\n6 -- ������� �� ����� ������ ��������\n7 -- ������� ����(���� ���� ������ ��� ��� ��������)\n8 -- �����\n");
	int n = inputNatural();
	system("cls");
	if (n > 1 && n < 7)
	{
		if (fopen_s(&f, "numberOfFilms.bin", "r+b") != 0) {
			printf("� ���� ��� ���������� �� �� ����� ������(\n");
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
	int numberOfFilms, buff = 0;
	if (fopen_s(&f, "numberOfFilms.bin", "rb") != 0)
	{
		if (fopen_s(&f, "numberOfFilms.bin", "w+b") != 0)
		{
			printf("������ �������� �����(\n");
			return 0;
		}
		printf("������� ���-�� �������\n");
		numberOfFilms = inputNatural();
		if (numberOfFilms == -1)
		{
			printf("�� ����� ���-�� �� ��...\nPress any key to continue...\n");
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
			printf("������ �������� �����(\n");
			fclose(f);
			return 0;
		}
		printf("������� ���-�� �������\n");
		int addFilms = inputNatural();
		if (addFilms == -1)
		{
			printf("�� ����� ���-�� �� ��...\nPress any key to continue...\n");
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
			printf("������ �������� �����(\n");
			return 0;
		}
	}
	for (int i = buff; i < numberOfFilms; i++)
	{
		printf("������� �������� ������ �%d: ", i + 1);
		fgets(film.name, 100, stdin);

		printf("������� ����� ������: ");
		film.session = inputNatural();

		printf("������� ��������� ������: ");
		film.cost = inputDigit();

		printf("������� ���������� ��������: ");
		film.numbOfVisitors = inputNatural();

		if (film.session == -1 || film.cost == -1.1 || film.numbOfVisitors == -1)
		{
			printf("�� ����� ���-�� �� ��...\nPress any key to continue...\n");
			deleteFile();
			_getch();
			fclose(f);
			return 0;
		}

		fwrite(&film, sizeof(film), 1, f);
		printf("\n");
	}
	printf("������ ������� ������!\n");
	fclose(f);
}

sorting()
{
	printf("��� ������ �� ������ ������������� ������?\n1 -- � ���������� ������� �� ��������\n2 -- �� ������ ������\n3 -- �� ��������� ������\n4 -- �� ���������� ��������\n5 -- �����\n");

	int numberOfFilms, n = inputNatural();

	if (fopen_s(&f, "numberOfFilms.bin", "rb") != 0)
	{
		printf("������ �������� �����(\n");
		return 0;
	}
	fread(&numberOfFilms, sizeof(int), 1, f);
	fclose(f);

	arrOfFilms = malloc(numberOfFilms *(sizeof(char) * 100 + sizeof(int) * 2 + sizeof(float)));

	if (fopen_s(&f, "kino.bin", "rb") != 0)
	{
		printf("������ �������� �����(\n");
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
		printf("�� ���� ����� ���-�� �� ��...\n");
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
		printf("������ �������� �����(\n");
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
	printf("�� ������ ��������� �� ������ ��������� �����?\n1 -- �� ��������\n2 -- �� ������ ������\n3 -- �� ��������� ������\n4 -- �� ���������� ��������\n5 -- �����\n");
	int numberOfFilms, n = inputNatural();

	if (fopen_s(&f, "numberOfFilms.bin", "rb") != 0)
	{
		printf("������ �������� �����(\n");
		return 0;
	}
	fread(&numberOfFilms, sizeof(int), 1, f);
	fclose(f);

	arrOfFilms = malloc(numberOfFilms * (sizeof(char) * 100 + sizeof(int) * 2 + sizeof(float)));

	if (fopen_s(&f, "kino.bin", "rb") != 0)
	{
		printf("������ �������� �����(\n");
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
		printf("������� ��������: ");
		fgets(input, 100, stdin);
		for (int i = 0; i < numberOfFilms; i++)
			if (strcmp(arrOfFilms[i].name, input) == 0)
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
		if (session == -1)
		{
			printf("�� ����� ���-�� �� ��...\nPress any key to continue...\n");
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
		if (counter == 0) printf("�� ���� ����� ��� �������(\n");
		break;
	}
	case 3:
	{

		int counter = 0;
		printf("������� ��� ������: ");
		int cost = inputDigit();
		if (cost == -1.1)
		{
			printf("�� ����� ���-�� �� ��...\nPress any key to continue...\n");
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
		if (counter == 0) printf("� ����� �������� ���� ��� �� �� �������(\n");
		break;
	}
	case 4:
	{
		int counter = 0;
		printf("��������� ��������� ������ ���� �����?(������� ��������): ");
		int numbOfVisitors = inputNatural();
		if (numbOfVisitors == -1)
		{
			printf("�� ����� ���-�� �� ��...\nPress any key to continue...\n");
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
	fclose(f);
	free(arrOfFilms);
}

remaking()
{
	int numberOfFilms, par, num;

	if (fopen_s(&f, "numberOfFilms.bin", "rb") != 0)
	{
		printf("������ �������� �����(\n");
		return 0;
	}
	fread(&numberOfFilms, sizeof(int), 1, f);
	fclose(f);

	arrOfFilms = malloc(numberOfFilms * (sizeof(char) * 100 + sizeof(int) * 2 + sizeof(float)));

	if (fopen_s(&f, "kino.bin", "rb") != 0)
	{
		printf("������ �������� �����(\n");
		return 0;
	}
	for (int i = 0; i < numberOfFilms; i++)
		fread(&arrOfFilms[i], sizeof(film), 1, f);

	printf("���������� � ����� ������ �� ������ ��������?\n");
	for (int i = 0; i < numberOfFilms; i++)
		printf("%d -- %s", i + 1, arrOfFilms[i].name);
	num = inputNatural() - 1;
	if (num >= numberOfFilms) {
		printf("������ ������ ���");
		return 0;
	}
	printf("��� ������ �� ������ ��������?\n1 -- ��������\n2 -- �����\n3 -- ��������� ������\n4 -- ���������� ��������\n");
	par = inputNatural();
	switch (par)
	{
	case 1:
	{
		printf("������ ��������: %s\n", arrOfFilms[num].name);
		printf("������� ����� ��������: ");
		fgets(arrOfFilms[num].name, 100, stdin);
		printf("����� ��������: %s\n", arrOfFilms[num].name);
		break;
	}
	case 2:
	{
		printf("������ ��������: %d\n", arrOfFilms[num].session);
		printf("������� ����� ��������: ");
		arrOfFilms[num].session = inputNatural();
		if (arrOfFilms[num].session == -1)
		{
			printf("�� ����� ���-�� �� ��...\nPress any key to continue...\n");
			fclose(f);
			_getch();
			return 0;
		}
	}
	case 3:
	{
		printf("������ ��������: %.2f\n", arrOfFilms[num].cost);
		printf("������� ����� ��������: ");
		arrOfFilms[num].cost = inputDigit();
		if (arrOfFilms[num].cost == -1.1)
		{
			printf("�� ����� ���-�� �� ��...\nPress any key to continue...\n");
			fclose(f);
			_getch();
			return 0;
		}
		printf("����� ��������: %.2f\n", arrOfFilms[num].cost);
		break;
	}
	case 4:
	{
		printf("������ ��������: %d\n", arrOfFilms[num].numbOfVisitors);
		printf("������� ����� ��������: ");
		arrOfFilms[num].numbOfVisitors = inputNatural();
		if (arrOfFilms[num].numbOfVisitors == -1)
		{
			printf("�� ����� ���-�� �� ��...\nPress any key to continue...\n");
			fclose(f);
			_getch();
			return 0;
		}
		printf("����� ��������: %d\n", arrOfFilms[num].numbOfVisitors);
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
	fclose(f);
	if (fopen_s(&f, "kino.bin", "wb") != 0)
	{
		printf("������ �������� �����(\n");
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
		printf("������ �������� �����(\n");
		return 0;
	}
	fread(&numberOfFilms, sizeof(int), 1, f);
	fclose(f);

	arrOfFilms = malloc(numberOfFilms * (sizeof(char) * 100 + sizeof(int) * 2 + sizeof(float)));

	if (fopen_s(&f, "kino.bin", "rb") != 0)
	{
		printf("������ �������� �����(\n");
		return 0;
	}
	for (int i = 0; i < numberOfFilms; i++)
		fread(&arrOfFilms[i], sizeof(film), 1, f);
	fclose(f);

	printf("���������� � ����� ������ �� ������ �������?\n");
	for (int i = 0; i < numberOfFilms; i++)
		printf("%d -- %s", i + 1, arrOfFilms[i].name);
	num = inputNatural() - 1;
	if (num == -2)
	{
		printf("�� ����� ���-�� �� ��...\nPress any key to continue...\n");
		fclose(f);
		_getch();
		return 0;
	}
	if (num < numberOfFilms)
	{
		numberOfFilms--;
		if (fopen_s(&f, "numberOfFilms.bin", "r+b") != 0)
		{
			printf("������ �������� �����(\n");
			return 0;
		}
		fwrite(&numberOfFilms, sizeof(int), 1, f);
		fclose(f);
		for (int i = num; i < numberOfFilms; i++)
			arrOfFilms[i] = arrOfFilms[i + 1];
		if (fopen_s(&f, "kino.bin", "wb") != 0)
		{
			printf("������ �������� �����(\n");
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
		printf("������ ������ � ������ ���\n");
		free(arrOfFilms);
	}
}

outputStruct(int n, int num)
{
	int numberOfFilms;
	if (fopen_s(&f, "numberOfFilms.bin", "rb") != 0)
	{
		printf("������ �������� �����(\n");
		return 0;
	}
	fread(&numberOfFilms, sizeof(int), 1, f);
	fclose(f);
	if (fopen_s(&f, "kino.bin", "rb") != 0)
	{
		printf("������ �������� ����� 2(\n");
		return 0;
	}
	if (n == 0)
	{
		for (int i = 0; i < numberOfFilms; i++)
		{
			fread(&film, sizeof(film), 1, f);
			printf("�������� ������: %s", film.name);
			printf("����� ������: %d\n", film.session);
			printf("��������� ������: %.2f\n", film.cost);
			printf("���������� ��������: %d\n", film.numbOfVisitors);
			printf("\n");
		}
	}
	if (n == 1)
	{
		fseek(f, sizeof(struct kino) * num, SEEK_SET);
		fread(&film, sizeof(film), 1, f);
		printf("�������� ������: %s", film.name);
		printf("����� ������: %d\n", film.session);
		printf("��������� ������: %.2f\n", film.cost);
		printf("���������� ��������: %d\n", film.numbOfVisitors);
		printf("\n");
	}
	fclose(f);
}

deleteFile()
{
	if(remove("numberOfFilms.bin")) printf("������ ��������\n");
	if(remove("kino.bin")) printf("������ ��������\n");
}