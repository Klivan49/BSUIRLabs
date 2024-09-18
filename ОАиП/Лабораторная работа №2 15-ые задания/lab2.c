#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>



int main()
{
	char* locale = setlocale(LC_ALL, "");
	hello();
}

hello(void)
{
	int n;
	printf("Что вы ходите сделать?\n");
	printf("1 -- Найти сумму геометрической прогрессии\n");
	printf("2 -- Узнать, счастливый ли у вас билет\n");
	printf("3 -- Узнать свой возраст\n");
	printf("4 -- Выход\n");
	n = _getch();
	if (n > 57 || n < 48)
	{
		printf("Некоректный ввод\n");
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
				printf("Некоректный ввод\n");
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

	printf("Введите номер билета(четырёхзначный): \n");
	scanf_s("%d", &num);
	if (num < 1000 || num > 9999) printf("У билета номер четырёхзначный!\n");
	else
	{
		a = num / 1000;
		d = num % 1000;
		b = d / 100;
		d = d % 100;
		c = d / 10;
		d = d % 10;
		if (a + b == c + d) printf("У вас СЧАСТЛИВЫЙ БИЛЕТ!\n");
		else printf("Повезёт в следующий раз\n");
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

	printf("Введите первый член геометрической прогрессии\n");
	scanf_s("%d", &b);
	printf("Введите знаменатель прогрессии\n");
	scanf_s("%d", &q);
	if (q == 1) printf("Знаменатель не может быть равен 1!\n");
	else
	{
		printf("Введите количесво членов прогрессии\n");
		scanf_s("%d", &n);
		sum = (double)(b * (1 - pow((double)q, n)) / (1. - q));
		printf("Сумма вашей геометрической прогрессии равна %.3f\n", sum);
	}

	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	return 0;
}


int age()
{
	int K;
	 
	printf("Введите свой возраст(от 0 да 9): ");
	scanf_s("%d", &K); 
	switch (K)
	{
	case 0: 
	{
		printf("Мне %d лет:\n", K);
		break;
	}
	case 1:
	{
		printf("Мне %d год\n", K);
		break;
	}
	case 2:
	{
		printf("Мне %d года\n", K);
		break;
	}
	case 3:
	{
		printf("Мне %d года\n", K);
		break;
	}
	case 4:
	{
		printf("Мне %d года\n", K);
		break;
	}
	case 5:
	{
		printf("Мне %d лет\n", K);
		break;
	}
	case 6:
	{
		printf("Мне %d лет\n", K);
		break;
	}
	case 7:
	{
		printf("Мне %d лет\n", K);
		break;
	}
	case 8:
	{
		printf("Мне %d лет\n", K);
		break;
	}
	case 9:
	{
		printf("Мне %d лет\n", K);
		break;
	}
	default:
	{
		printf("Ну просили же от 0 до 9\n");
		break;
	}
	}

	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	return 0;
}