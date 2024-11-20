#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "LibForMe.h"
#define M_PI 3.14159265358979323846

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

int main()
{
	char* locale = setlocale(LC_ALL, "");
	int num;

	printf("��� �� ������ �������?\n");
	printf("1 -- ��������� ��������� ������\n");
	printf("2 -- ��������� ������� ������������\n");
	scanf_s("%d", &num);
	switch (num)
	{
	case 1:
	{
		cone();
		break;
	}
	case 2:
	{
		sTriangle();
		break;
	}
	default:
	{
		printf("�� � �� �������� 1 ��� 2 ������(\n");
		break;
	}
	}
}


int cone(void)
{
	float v, s1, s2, h, r, l;

	printf("������� ������ ����� ������\n");
	l = inputDigit();
	printf("������� ������ ��������� ������\n");
	r = inputDigit();
	printf("������� ������ ������\n");
	h = inputDigit();
	if (l <= 0 || r <= 0 || h <= 0)
	{
		printf("�� ���-�� �� �� �����!\n");
		return 0;
	}
	s1 = 2 * M_PI * r * l;
	s2 = 2 * M_PI * pow((double)r, 2) + 2 * M_PI * r * l;
	v = ((float)1 / 3) * 2 * M_PI * pow((double)r, 2) * h;

	printf("������� ������� ����������� ����� %.3f\n", s1);
	printf("������� ������ ����������� ����� %.3f\n", s2);
	printf("����� ����� %.3f\n", v);
}

int sTriangle(void)
{
	float a, b, c, p, s;

	printf("������� ������� a\n");
	a = inputDigit();
	printf("������� ������� b\n");
	b = inputDigit();
	printf("������� ������� c\n");
	c = inputDigit();
	if (a <= 0 || b <= 0 || c <= 0)
	{
		printf("�� ���-�� �� �� �����!\n");
		return 0;
	}
	if (a >= b + c) printf("������ ������������ �� ����������\n");
	else if (b >= a + c) printf("������ ������������ �� ����������\n");
	else if (c >= a + b) printf("������ ������������ �� ����������\n");
	else
	{
		p = ((a + b + c) / 2.);
		s = (float)sqrt((p * (p - a) * (p - b) * (p - c)));
		printf("������� ������������ ����� %f\n", s);
	}
}