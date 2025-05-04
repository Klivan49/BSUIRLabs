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
        "1 -- ������ �������� �������� ������\n"
        "2 -- ������� ��������� ������"
        "3 -- ������� ����\n"
        "4 -- ������� ����\n"
        "5 -- �����\n"
    );
    while (choice < '1' || choice > '4')
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
        printf("����� �������\n");
        system("pause");
        break;
    case '5':
        printf("��������� ���������\n");
        return 0;
    default:
        break;
    }
    return 1;
}