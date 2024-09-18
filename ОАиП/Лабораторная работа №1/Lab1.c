#include <stdio.h>
#include <locale.h>
#include <math.h>
#define M_PI 3.14159265358979323846

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
	scanf_s("%f", &l);
	printf("Введите радиус основания конуса\n");
	scanf_s("%f", &r);
	printf("Введите высоту конуса\n");
	scanf_s("%f", &h);
	s1 = 2 * M_PI * r * l;
	s2 = 2 * M_PI * pow((double)r, 2) + 2 * M_PI * r * l;
	v = ((float)1 / 3) * 2 * M_PI * pow((double)r, 2)*h;
	
	printf("Площадь боковой поверхности равна %.3f\n", s1);
	printf("Площадь полной поверхности равна %.3f\n", s2);
	printf("Объём равен %.3f\n", v);
}

int sTriangle(void)
{
	float a, b, c, p, s;

	printf("Введите сторону a\n");
	scanf_s("%f", &a);
	printf("Введите сторону b\n");
	scanf_s("%f", &b);
	printf("Введите сторону c\n");
	scanf_s("%f", &c);
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