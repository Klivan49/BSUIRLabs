#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>


int main() {
	char* locale = setlocale(LC_ALL, "");
	hello();
}

int input()
{
	int n = 0;
	char input[100];
	fgets(input, sizeof(input), stdin);
	for (int i = 0; input[i] != '\0'; i++) if (input[i] < '0' || input[i] > '9') n++;
	if (n > 1)
	{
		printf("���� �� ����� ���-�� �� ��\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
		hello();
	}
	else
	{
		sscanf_s(input, "%d", &n);
		return n;
	}

}
hello(void)
{
	int n;
	printf("��� �� ������ �������?\n");
	printf("1 -- ����� ����� �������������� ����������\n");
	printf("2 -- ������, ���������� �� � ��� �����\n");
	printf("3 -- ������ ���� �������\n");
	printf("4 -- �����\n");
	n = _getch();
	if (n > 57 || n < 48)
	{
		printf("����������� ����\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
		hello();
	}
	else
	{
		n -= 48;
		switch (n)
		{
			case 1:
			{
				system("cls");
				geometrickProgression();
				hello();
				break;
			}
			case 2:
			{
				system("cls");
				luckyTick();
				hello();
				break;
			}
			case 3:
			{
				system("cls");
				age();
				hello();
				break;
			}
			case 4:
			{
				break;
			}
			default:
			{
				printf("����������� ����\n");
				printf("Press any key to continue...\n");
				_getch();
				system("cls");
				hello();
			}
		}
	}
}

int luckyTick()
{
	int num, a, b, c, d;

	printf("������� ����� ������(�������������): \n");
	num = input();
	if (num < 1000 || num > 9999) printf("� ������ ����� �������������!\n");
	else
	{
		a = num / 1000;
		d = num % 1000;
		b = d / 100;
		d = d % 100;
		c = d / 10;
		d = d % 10;
		if (a + b == c + d) printf("� ��� ���������� �����!\n");
		else printf("������ � ��������� ���\n");
	}
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	return 0;
}

int geometrickProgression(void)
{
	int b, q, n;
	double sum;

	printf("������� ������ ���� �������������� ����������\n");
	b = input();
	printf("������� ����������� ����������\n");
	q = input();
	if (q == 1) printf("����������� �� ����� ���� ����� 1!\n");
	else
	{
		printf("������� ��������� ������ ����������\n");
		n = input();
		sum = (double)(b * (1 - pow((double)q, n)) / (1. - q));
		printf("����� ����� �������������� ���������� ����� %.3f\n", sum);
	}

	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	return 0;
}


int age()
{
	int K;
	 
	printf("������� ���� �������(�� 0 �� 9): ");
	K = input();
	switch (K)
	{
	case 0: 
	{
		printf("��� %d ���:\n", K);
		break;
	}
	case 1:
	{
		printf("��� %d ���\n", K);
		break;
	}
	case 2:
	{
		printf("��� %d ����\n", K);
		break;
	}
	case 3:
	{
		printf("��� %d ����\n", K);
		break;
	}
	case 4:
	{
		printf("��� %d ����\n", K);
		break;
	}
	case 5:
	{
		printf("��� %d ���\n", K);
		break;
	}
	case 6:
	{
		printf("��� %d ���\n", K);
		break;
	}
	case 7:
	{
		printf("��� %d ���\n", K);
		break;
	}
	case 8:
	{
		printf("��� %d ���\n", K);
		break;
	}
	case 9:
	{
		printf("��� %d ���\n", K);
		break;
	}
	default:
	{
		printf("�� ������� �� �� 0 �� 9\n");
		break;
	}
	}

	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	return 0;
}