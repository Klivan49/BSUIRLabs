#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include "LibForMe.h"


int main()
{
	char* locale = setlocale(LC_ALL, "");

	while (mainMenu());
}

int mainMenu()
{

	int n;
	printf("��� �� ������ �������?\n");
	printf("1 -- ���������� � ��������\n");
	printf("2 -- ��� ��� ���������� � ��������\n");
	printf("3 -- �����\n");
	n = isNatural();
	system("cls");
	switch (n)
	{
	case 1:
		sqrMassive();
		break;
	case 2:
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

int sqrMassive()
{
	int **massive; //�������� ��������� �� ������
	int lines, rows;
	float min, sum = 0;

	printf("������� ���-�� ����� �������: ");
	lines = isNatural();
	printf("������� ���-�� c������� �������: ");
	rows = isNatural();
	massive = (int **)calloc(lines, sizeof(int*));
	for (int i = 0; i < lines; i++) massive[i] = (int*)calloc(rows, sizeof(int));
	printf("������� �������� �������:\n"); //�������� ��������� �������
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < rows; j++) 
		{
			printf("a[%d][%d] = ", i, j);
			massive[i][j] = isNatural();
		}
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < rows; j++) printf("%d ", massive[i][j]);
		printf("\n");
	}
	printf("\n");
	free(massive);
}
