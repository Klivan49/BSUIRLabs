#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <stdint.h>
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
	printf("2 -- ������, ��������� �� ������ � ����� �������\n");
	printf("3 -- �����\n");
	n = isDigit();
	system("cls");
	switch (n)
	{
	case 1:
		superMassive();
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

superMassive()
{
	int size, Box2, loadCapacity, x, y, n = 0;
	printf("������� ���-�� ��������� ������� \n");
	size = isNatural();
	if (size == NULL) mainMenu();

	printf("Press any key to continue...\n");
	_getch();
	system("cls");
}

s1mple()
{
	int K, n = 0;
	printf("������� ��� �����(�����������): \n");
	K = isDigit();
	if (K == 1) printf("������� �� ��� �������...?\n");
	if (K == 0) printf("�����������!\n");
	for (int i = 1; i <= K; i++) if (K % i == 0) n++;
	if (n == 2) printf("���� ����� �������!\n");
	else printf("�� ����� �� ��� � �������...\n");
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
}