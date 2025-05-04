#include <stdio.h>
#include "lab5.1.h"
#include <locale.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdlib>

int main()
{
    setlocale(LC_ALL, "");
    system("chcp 1251");
    system("cls");
    while (mainMenu());
    return 0;
}

extern int mainMenu()
{
    char n = '0';
    int numberOfJobs = -1;
    std::cout << "��� �� ������ �������?"
        "\n1 -- �������� ������"
        "\n2 -- ������������� ������"
        "\n3 -- ���������� ����� ������ �� ��������� ���������"
        "\n4 -- �������� ������ ������"
        "\n5 -- ������� ������ �� ������"
        "\n6 -- ������� �� ����� ������ �����"
        "\n7 -- ������� ����(���� ���� ������ ��� ��� ��������)"
        "\n8 -- �����\n";
    while (n < '1' || n > '8')
        n = _getch();
    system("cls");

    if (n > '1' && n < '7')
    {
        std::ifstream inFile("numberOfJobs.txt");
        if (inFile) {
            inFile >> numberOfJobs;
            inFile.close();
        }
        if (numberOfJobs <= 0) {
            std::cout << "� ���� ��� ���������� �� �� ����� ������(\n"
                << "������� ����� ������� ��� �����������...";
            system("pause");
            system("cls");
            return 1;
        }
    }

    switch (n)
    {
    case '1':
        inputStruct();
        break;
    case '2':
        sorting();
        break;
    case '3':
        finder();
        break;
    case '4':
        remaking();
        break;
    case '5':
        deleting();
        break;
    case '6':
        outputStruct(0, 0);
        break;
    case '7':
        deleteFile();
        break;
    case '8':
        return 0;
    default:
        std::cerr << "������������ �����...\n"
            << "������� ����� ������� ��� �����������...\n";
        system("pause");
        system("cls");
        return 1;
    }

    system("pause");
    system("cls");
    return 1;
}
