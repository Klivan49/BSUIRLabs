#include "lab5.h"
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

short unsigned int stackIsExist = 0;

int main()
{
    system("chcp 1251");
    PtrToStack stack1 = stackInstantinate();
    PtrToStack stack2 = stackInstantinate();
    char* locale = setlocale(LC_ALL, "");
    while (mainMenu(&stack1, &stack2));
    return 0;
}

int mainMenu(PtrToStack *stack1, PtrToStack *stack2)
{
    char choice = '0';
    system("cls");
    printf(
    "1 -- Вводить элементы в стеки\n"
    "2 -- Вывести стеки\n"
    "3 -- Удалить стеки\n"
    "4 -- Выйти\n"
    );
    while(choice < '1' || choice > '4')
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
        printf("Введите длину стека");
        int length = -1;
        char* arr;
        scanf_s("%d", &length);
        getchar();
        arr = malloc((length+1)*sizeof(char));
        printf("Введите строку (она будет разбита на символы и рассортирована по стекам)\n");
        fgets(arr, length+1, stdin);
        if (arr[length - 1] == '\n') arr[length - 1] = '\0'; // Удаляем символ новой строки
        enterStacks(stack1, stack2, arr, length);
        stackIsExist = 1;
        length = -1;
        free(arr);
        break;
    case '2': 
        printStacks(*stack1, *stack2);
        break;
    case '3':
        stackDelete(*stack1);
        stackDelete(*stack2);
        stackIsExist = 0;
        printf("Стеки удалены\n");
        system("pause");
        break;
    case '4': 
        printf("Закончили упражение\n");
        return 0;
    default:
        break;
    }
    return 1;
}