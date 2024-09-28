#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
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
	printf("1 -- ��������� ���� �������\n");
	printf("2 -- ������, ��������� �� ������ � ����� �������\n");
	printf("3 -- �����\n");
	n = isNatural();
	system("cls");
	switch (n)
	{
	case 1:
		gruzhchik();
		break;
	case 2:
		s1mple();
		break;
	case 3:
		return 0;
	default:
	{
		printf("����������� ����\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
	}
	}
	return 1;
}

gruzhchik()
{
	int Box1, Box2, loadCapacity, x, y, n = 0;
	printf("������� ����� ������ �������: \n");
	Box1 = isNatural();
	if (Box1 == NULL) mainMenu();
	printf("������� ����� ������ �������: \n");
	Box2 = isNatural();
	if (Box2 == NULL) mainMenu();
	printf("������� ���������������� ���������: \n");
	loadCapacity = isNatural();
	if (loadCapacity == NULL) mainMenu();
	for (int i = 0; i < loadCapacity / Box1; i++)
		for (int j = 0; j < loadCapacity / Box2; j++)
			if (i * Box1 + j * Box2 == loadCapacity) n++;
	if (n >= 1) printf("�� �������� �������(�� ������)!\n");
	else printf("����� �� ��������(\n");
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
}

s1mple()
{
	int K, n = 0;
	printf("������� ��� �����(�����������): \n");
	K = isNatural();
	if (K == NULL) mainMenu();
	if (K == 1) printf("������� �� ��� �������...?\n");
	if (K == 0) printf("�����������!\n");
	for (int i = 1; i <= K; i++) if (K % i == 0) n++;
	if (n == 2) printf("���� ����� �������!\n");
	else printf("�� ����� �� ��� � �������...\n");
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
}
