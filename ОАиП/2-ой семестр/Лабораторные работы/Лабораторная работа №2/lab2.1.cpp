#include "lab2.h"
#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <conio.h>
#include <fstream>

int main()
{
    char* locale = setlocale(LC_ALL, "");
    system("chcp 1251");
    system("cls");
    while (mainMenu());
}

extern int mainMenu()
{
    char n, target;
    std::cout << "��� �� ������ �������?"
        "\n1 -- ������ ������"
        "\n2 -- ������������� ������ ������� ��������"
        "\n3 -- ������������� ������ ������� ������"
        "\n4 -- ������������� ������ ������� �������"
        "\n5 -- ������������� ������ ������� �����"
        "\n6 -- ������������� ������ ������� �����"
        "\n7 -- ������������� ������ ������� �������"
        "\n8 -- �������� �������� ����� � �������� �������"
        "\n9 -- �����\n";
    n = _getch();
    if (array.empty() && n != '1' && n != '8')
    {
        std::cout << "�� �� ����� ������\n";
        system("pause");
        system("cls");
        return 1;
    }
    system("cls");
    
    switch (n)
    {
    case '1':
        inputArray();
        break;
    case '2':
        bubbleSort(array);
        break;
    case '3':
        selectionSort(array);
        break;
    case '4':
        insertionSort(array);
        break;
    case '5':
        shellSort(array);
        break;
    case '6':
        quickSortWrapper(array);
        break;
    case '7':
        mergeSortWrapper(array);
        break;
    case '8':
        std::cout << "������� �������� ��������, ������� �������� ������ ����� � �������: ";
        target = inputInteger();
        linearSearch(array, target);
        break;
    case '9':
        return 0;
    default:
    {
        std::cerr << "�� ���� ����� ���-�� �� ��...\n";
        std::cerr << "Press any key to continue...\n";
        system("pause");
        system("cls");
        mainMenu();
        break;
    }
    }
    system("pause");
    system("cls");
    return 1;
}
