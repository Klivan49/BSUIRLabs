#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>


int mainMenu(void);
int isDigit(void);
int luckyTick();
int geometrickProgression();
int age();

int main()
{
	char *locale = setlocale(LC_ALL, "");

	while (mainMenu());
}

int isDigit()
{
	int n = 0;
	char input[100];
	fgets(input, sizeof(input), stdin);
	for (int i = 0; input[i] != '\0'; i++) if (input[i] < '0' || input[i] > '9') n++;
	if (n > 1)
	{
		printf("Явно вы ввели что-то не то\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
		mainMenu();
	}
	else
	{
		sscanf_s(input, "%d", &n);
		return n;
	}
	return 0;
}
int mainMenu()
{

	int n;
	printf("Что вы ходите сделать?\n");
	printf("1 -- Найти сумму геометрической прогрессии\n");
	printf("2 -- Узнать, счастливый ли у вас билет\n");
	printf("3 -- Узнать свой возраст\n");
	printf("4 -- Выход\n");
	n = isDigit();
	system("cls");
	switch (n)
	{
	case 1:
		geometrickProgression();
		break;
	case 2:
		luckyTick();
		break;
	case 3:
		age();
		break;

	case 4:
		return 0;
	default:
	{
		printf("Некоректный ввод\n");
		printf("Press any key to continue...\n");
		_getch();
		system("cls");
	}
	}
	return 1;
}

int luckyTick()
{
	int num, a, b, c, d;

	printf("Введите номер билета(четырёхзначный): \n");
	num = isDigit();
	if (num < 1000 || num > 9999)
		printf("У билета номер четырёхзначный!\n");
	else
	{
		a = num / 1000;
		d = num % 1000;
		b = d / 100;
		d = d % 100;
		c = d / 10;
		d = d % 10;
		if (a + b == c + d)
			printf("У вас СЧАСТЛИВЫЙ БИЛЕТ!\n");
		else
			printf("Повезёт в следующий раз\n");
	}
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
	return 0;
}

int geometrickProgression()
{
	int b, q, n;
	double sum;

	printf("Введите первый член геометрической прогрессии\n");
	b = isDigit();
	printf("Введите знаменатель прогрессии\n");
	q = isDigit();
	if (q == 1)
		printf("Знаменатель не может быть равен 1!\n");
	else
	{
		printf("Введите количесво членов прогрессии\n");
		n = isDigit();
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
	int K, n;

	printf("Введите свой возраст(от 0 да 9): ");
	K = isDigit();
	if (K == 0 || (K > 4 && K <= 9)) n = 1;
	else if (K > 0 && K <= 4) n = 2;
	else n = 3;
	switch (n)
	{
	case 1:
	{
		printf("Мне %d лет:\n", K);
		break;
	}
	case 2:
	{
		printf("Мне %d год\n", K);
		break;
	}
	case 3:
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