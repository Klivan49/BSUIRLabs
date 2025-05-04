#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <stdio.h>
#include "lab6.h"
#include <time.h>

int main() {
    system("chcp 1251");
    char* locale = setlocale(LC_ALL, "");
    srand(time(NULL));
    struct tree* root = NULL;
    char choice = '0';
    int value, sum;

    while (choice != 6) {
        std::cout << "1. �������� ������� � ������\n"
                  << "2. ���������� ������������ ����� ���� \n"
                  << "3. ������� ������� �� ������ \n"
                  << "4. ������� ��� �������� ������\n"
                  << "5. ������� �������� � ������� �����������\n"
                  << "6. ����� �� ���������\n"
                  << "7. ������������� ������\n"
                  << "������� �����: ";
        while (choice < '1' || choice > '7')
            choice = _getch();
        system("cls");
        switch (choice) {
        case '1':
        {
            std::cout << "���� ������ �������� ��� ������ ��������?(p/r)";
            char random = '0';
            do {
                random = _getch();
            } while (random != 'r' && random != 'R'
                && random != '�' && random != '�'
                && random != 'r' && random != 'R'
                && random != '�' && random != '�');
            switch (random)
            {
            case 'r' || 'R' || '�' || '�':
                std::cout << "������� ��������� ������ ��������?\n";
                int amount = inputInteger();
                for (int i = 0; i < amount; i++)
                {
                    value = rand() % 100;
                    root = treeNewElement(root, value);
                }
                system("cls");
                break;
            }
            case 'p' || 'P' || '�' || '�':
            {
                    std::cout << "������� �������� ��� �������: ";
                    value = inputInteger();
                    root = treeNewElement(root, value);
                    system("cls");
                    break;
            }
            return 0;
        }
        case '2':
            sum = findMaxSumPath(root);
            std::cout << "������������ ����� ���� = " << sum;
            break;
        case '3':
            std::cout << "������� �������� ��� ��������: ";
            value = inputInteger();
            root = deleteElement(root, value);
            std::cout << "������ ������� %d\n", value;
            break;
        case '4':
            std::cout << "�������� ������: " << std::endl;
            printTree(root, 1);
            std::cout << std::endl;
            break;
        case '5':
            std::cout << "�������� � ������� �����������: " << std::endl;
            inOrderTraversal(root);
            std::cout << std::endl;
            break;
        case '6':
            free(root); 
            return 0;
        case '7':
        {
            tree* balanced = balanceTree(root);
            printTree(balanced, 1);
            break;
        }
        default:
            std::cout << "�������� �����\n";
        }
        system("pause");
        system("cls");
        choice = '0';
    }
    return 0;
}
