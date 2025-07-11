#include "lab3.0.h"
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <cstring>
#include <sstream>
#include <string>

List* start = nullptr; // ������ ������

int main()
{
    char* locale = setlocale(LC_ALL, "");
    while (mainMenu());
    return 0;
}

int mainMenu() 
{
    int elem;
    char choice = '0';
    instructions(); // ����� ����
    while(choice < '1' || choice > '6')
        choice = _getch();
    system("cls");
    std::string input;
    switch (choice)
    {
    case '1':
    {   // ������� ��������
        std::cout << "������� �������� ������� ����� ������ (Enter -- ����� �������)" << std::endl;
        std::getline(std::cin, input);
        std::istringstream iss(input);
        int value;
        while (iss >> value) {
            insert(&start, value);
        }
        if (iss.fail() && !iss.eof()) {
            std::cerr << "������ �����: ������������ �������� � �������" << std::endl;
        }
        printList(start);
        break;
    }
    case '2': // �������� ���� ���������
        if (!isEmpty(start)) {
            std::cout << "�������, ���������� � ����� ����� �� ������� �����������: ";
            std::cin >> elem;
            deleteAllOccurrences(&start, elem);
            printList(start);
        }
        else {
            std::cout << "������ ����.\n";
        }
        break;
    case '3': // �������� ����������
        deleteDuplicates(&start);
        printList(start);
        break;
    case '4': // �������� ����������, ������� � ��������
        std::cout << "���������� ���������: " << countList(start) << "\n";
        if (!isEmpty(start)) {
            std::cout << "Min: " << findMin(start) << "\n";
            std::cout << "Max: " << findMax(start) << "\n";
        }
        break;
    case '5':
        printList(start);
        break;
    case '6':
        std::cout << "��������� ���������\n";
        return 0;
    default:
        std::cout << "�������� �����\n";
        break;
    }
}