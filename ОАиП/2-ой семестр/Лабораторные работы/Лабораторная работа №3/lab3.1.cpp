#include "lab3.h"
#include <iostream>
#include <locale.h>
#include <conio.h>;

ListNodePtr start = nullptr; // ������ ������

int main()
{
    char* locale = setlocale(LC_ALL, "");
    while (mainMenu());
}

int mainMenu() 
{
    int elem;
    char choice;
    instructions(); // ����� ����
    choice = _getch();
    system("cls");

    switch (choice) {
    case '1': // ������� ��������
        std::cout << "������� �����: ";
        elem = (int)_getch() - 48;
        insert(&start, elem);
        printList(start);
        break;
    case '2': // �������� ���� ���������
        if (!isEmpty(start)) {
            std::cout << "�������, ��� ������ �������: ";
            std::cin >> elem;
            deleteAllOccurrences(&start, elem);
            printList(start);
        }
        else {
            std::cout << "List is empty.\n";
        }
        break;
    case '3': // �������� ����������
        deleteDuplicates(&start);
        printList(start);
        break;
    case '4': // �������� ����������, ������� � ��������
        std::cout << "Number of elements: " << countList(start) << "\n";
        if (!isEmpty(start)) {
            std::cout << "Min: " << findMin(start) << "\n";
            std::cout << "Max: " << findMax(start) << "\n";
        }
        break;
    case '5':
        std::cout << "End of run.\n";
        return 0;
    default:
        std::cout << "Invalid choice.\n";
        instructions();
        break;
    }
}