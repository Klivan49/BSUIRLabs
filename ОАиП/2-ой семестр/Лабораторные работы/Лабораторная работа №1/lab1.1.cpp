#include <stdio.h>
#include "lab1.h"
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
    int n, numberOfJobs = -1;
    std::cout << "��� �� ������ �������?"
        "\n1 -- �������� ������"
        "\n2 -- ������������� ������"
        "\n3 -- ���������� ����� ������ �� ��������� ���������"
        "\n4 -- �������� ������ ������"
        "\n5 -- ������� ������ �� ������"
        "\n6 -- ������� �� ����� ������ �����"
        "\n7 -- ������� ����(���� ���� ������ ��� ��� ��������)"
        "\n8 -- �����\n";
    n = inputInteger();
    system("cls");

    if (n > 1 && n < 7)
    {
        std::ifstream inFile("numberOfJobs.txt");
        if (inFile) {
            inFile >> numberOfJobs;
            inFile.close();
        }
        if (numberOfJobs == -1) {
            std::cout << "� ���� ��� ���������� �� �� ����� ������(\n"
                      << "Press any key to continue...";
            system("pause");
            system("cls");
            return 1;
        }
    }

    switch (n)
    {
    case 1:
        inputStruct();
        break;
    case 2:
        sorting();
        break;
    case 3:
        finder();
        break;
    case 4:
        remaking();
        break;
    case 5:
        deleting();
        break;
    case 6:
        outputStruct(0, 0);
        break;
    case 7:
        deleteFile();
        break;
    case 8:
        return 0;
    default:
        std::cerr << "�� ���� ����� ���-�� �� ��...\n";
        std::cerr << "Press any key to continue...\n";
        system("pause");
        system("cls");
        mainMenu();
        break;
    }

    system("pause");
    system("cls");
    return 1;
}
