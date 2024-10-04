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
		superMassive();
		break;
	case 2:
		massiveXYZ();
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

superMassive()
{
	float* massive; //�������� ��������� �� ������
	int n = 0;
	float min, sum = 0;

	printf("������� ������ �������: ");

	n = isNatural();
	
	massive = (float*)malloc(n * sizeof(float)); //�������� ������������� ������� ����� ��������� ������

	printf("������� �������� �������:\n");
	for (int i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		massive[i] = isDigit();
	}
	for (int i = 0; i < n; i++) printf("%.2f ", massive[i]);
	printf("\n");

	min = massive[0];
	for (int i = 0; i < n; i++)
		if (massive[i] < min) min = massive[i];
	printf("����������� ������� �������: %.3f\n", min);
	printf("������� ����� �������, ����� ����� ����� ��������� ����� �������� ��������������\n");
	_getch();
	float negative1, negative2;
	for (int i = 0; i < n; i++)
		if (massive[i] < 0)
		{
			negative1 = i + 1;
			break;
		}
		else 
		{
			free(massive);
			printf("� ������� ��� ������������� ���������\n");
			printf("Press any key to continue...\n");
			_getch();
			system("cls");
			mainMenu();
		}
	for (int i = negative1; i , n; i++)
		if (massive[i] < 0)
		{
			negative2 = i - 1;
			break;
		}
	if (negative1 == negative2) printf("� ������� ������ 1 ������������� �����");
	else
	{
		for (int i = negative1; i < negative2-1; i++)
		{
			sum += massive[i];
		}
		printf("����� ��������� ����� ������ � ��������� ������������� ����������: %.3f\n", sum);
	}
	free(massive);
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
}


int massiveXYZ() 
{
	float massive[20];
	for (int i = 0; i < 20; i++)
	{
		printf("a[%d] = ", i);
		massive[i] = isDigit();
	}
	printf("�������� ������:\n");
	for (int i = 0; i < 20; i++) printf("%.2f ", massive[i]);
	printf("\n");

	rearrangeArray(massive);

	printf("������ ����� ����������� ������������� ��������� � �����:\n");
	for (int i = 0; i < 20; i++) printf("%.2f ", massive[i]);

	printf("������ � �������� �������:\n");
	for (int i = 19; i >= 0; i--) printf("%.2f ", massive[i]);
	printf("\n");

	return 0;
}


rearrangeArray(float arr[]) 
{
	int temp[20];
	int j = 0;

	// �������� ��� ��������������� �������� � temp
	for (int i = 0; i < 20; i++) {
		if (arr[i] >= 0) {
			temp[j++] = arr[i];
		}
	}

	// �������� ��� ������������� �������� � temp
	for (int i = 0; i < 20; i++) {
		if (arr[i] < 0) {
			temp[j++] = arr[i];
		}
	}

	// �������� temp ������� � arr
	for (int i = 0; i < 20; i++) {
		arr[i] = temp[i];
	}
}