#include "lab3.1.h"
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

char arr[100];
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
    char choice;
    system("cls");
    printf(
    "1 -- ������� �������� � �����\n"
    "2 -- ������� �����\n"
    "3 -- ������� �����\n"
    "4 -- �����\n"
    );
    choice = _getch();
    if ((choice == '2' || choice == '3') && stackIsExist == 0)
    {
        printf("������ ���, ������ ������ �� :3\n");
        system("pause");
        choice = '\n';
    }
    switch (choice)
    {
    case '1':
        printf("������� ������ (��� ����� ������� �� ������� � �������������� �� ������)\n");
        fgets(arr, 100, stdin);
        int length = strlen(arr);
        if (arr[length - 1] == '\n') arr[length - 1] = '\0'; // ������� ������ ����� ������
        enterStacks(stack1, stack2, arr, length);
        stackIsExist = 1;
        break;
    case '2': 
        printStacks(*stack1, *stack2);
        break;
    case '3':
        stackDelete(*stack1);
        stackDelete(*stack2);
        stackIsExist = 0;
        printf("����� �������\n");
        system("pause");
        break;
    case '4': 
        printf("��������� ���������\n");
        return 0;
    default:
        break;
    }
    return 1;
}