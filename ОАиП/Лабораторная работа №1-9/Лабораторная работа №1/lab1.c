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

	printf("Что вы ходите сделать?\n");
	printf("1 -- Вычислить параметры конуса\n");
	printf("2 -- посчитать площать треугольника\n");
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
		printf("Ну я же попросил 1 или 2 ввести(\n");
		break;
	}
	}
}


int cone(void)
{
	float v, s1, s2, h, r, l;

	printf("Введите длинну ребра конуса\n");
	l = inputDigit();
	printf("Введите радиус основания конуса\n");
	r = inputDigit();
	printf("Введите высоту конуса\n");
	h = inputDigit();
	if (l <= 0 || r <= 0 || h <= 0)
	{
		printf("Вы что-то не то ввели!\n");
		return 0;
	}
	s1 = 2 * M_PI * r * l;
	s2 = 2 * M_PI * pow((double)r, 2) + 2 * M_PI * r * l;
	v = ((float)1 / 3) * 2 * M_PI * pow((double)r, 2) * h;

	printf("Площадь боковой поверхности равна %.3f\n", s1);
	printf("Площадь полной поверхности равна %.3f\n", s2);
	printf("Объём равен %.3f\n", v);
}

int sTriangle(void)
{
	float a, b, c, p, s;

	printf("Введите сторону a\n");
	a = inputDigit();
	printf("Введите сторону b\n");
	b = inputDigit();
	printf("Введите сторону c\n");
	c = inputDigit();
	if (a <= 0 || b <= 0 || c <= 0)
	{
		printf("Вы что-то не то ввели!\n");
		return 0;
	}
	if (a >= b + c) printf("Такого треугольника не существует\n");
	else if (b >= a + c) printf("Такого треугольника не существует\n");
	else if (c >= a + b) printf("Такого треугольника не существует\n");
	else
	{
		p = ((a + b + c) / 2.);
		s = (float)sqrt((p * (p - a) * (p - b) * (p - c)));
		printf("Площадь треугольника равна %f\n", s);
	}
}