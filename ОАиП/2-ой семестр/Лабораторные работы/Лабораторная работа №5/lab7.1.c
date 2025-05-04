#include "lab5.h"
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

char arr[100];
short unsigned int stackIsExist = 0;

int main()
{
    system("chcp 1251");
    PtrToStack stack = stackInstantinate();
    char* locale = setlocale(LC_ALL, "");
    while (mainMenu(&stack));
    return 0;
}

int mainMenu(PtrToStack* stack)
{
    char choice = '0';
    system("cls");
    printf(
        "1 -- Ввести обратную польскую запись\n"
        "2 -- Вывести индексную запись"
        "3 -- Вывести стек\n"
        "4 -- Удалить стек\n"
        "5 -- Выйти\n"
    );
    while (choice < '1' || choice > '4')
        choice = _getch();
    if ((choice == '2' || choice == '3') && stackIsExist == 0)
    {
        printf("Стеков нет, сперва создай их :3\n");
        system("pause");
        choice = '\n';
    }
    switch (choice)
    {
    case '1':
        printf("Введите строку (она будет разбита на символы и рассортирована по стекам)\n");
        fgets(arr, 100, stdin);
        int length = strlen(arr);
        if (arr[length - 1] == '\n') arr[length - 1] = '\0'; // Удаляем символ новой строки
        enterStacks(stack, arr, length);
        stackIsExist = 1;
        break;
    case '2':

        break;
    case '3':
        printStacks(*stack);
        system("pause");
        break;
    case '4':
        stackDelete(*stack);
        stackIsExist = 0;
        printf("Стеки удалены\n");
        system("pause");
        break;
    case '5':
        printf("Закончили упражение\n");
        return 0;
    default:
        break;
    }
    return 1;
}