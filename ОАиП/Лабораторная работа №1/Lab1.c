#include <stdio.h>
#include <locale.h>
#include <math.h>
#define M_PI 3.14159265358979323846

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
	scanf_s("%f", &l);
	printf("������� ������ ��������� ������\n");
	scanf_s("%f", &r);
	printf("������� ������ ������\n");
	scanf_s("%f", &h);
	s1 = 2 * M_PI * r * l;
	s2 = 2 * M_PI * pow((double)r, 2) + 2 * M_PI * r * l;
	v = ((float)1 / 3) * 2 * M_PI * pow((double)r, 2)*h;
	
	printf("������� ������� ����������� ����� %.3f\n", s1);
	printf("������� ������ ����������� ����� %.3f\n", s2);
	printf("����� ����� %.3f\n", v);
}

int sTriangle(void)
{
	float a, b, c, p, s;

	printf("������� ������� a\n");
	scanf_s("%f", &a);
	printf("������� ������� b\n");
	scanf_s("%f", &b);
	printf("������� ������� c\n");
	scanf_s("%f", &c);
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