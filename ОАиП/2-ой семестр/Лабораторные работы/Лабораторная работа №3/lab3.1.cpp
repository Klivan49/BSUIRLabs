#include "lab3.h"
#include <iostream>
#include <locale.h>
#include <conio.h>;

ListNodePtr start = nullptr; // Начало списка

int main()
{
    char* locale = setlocale(LC_ALL, "");
    while (mainMenu());
}

int mainMenu() 
{
    int elem;
    char choice;
    instructions(); // Вывод меню
    choice = _getch();
    system("cls");

    switch (choice) {
    case '1': // Вставка элемента
        std::cout << "Введите число: ";
        elem = (int)_getch() - 48;
        insert(&start, elem);
        printList(start);
        break;
    case '2': // Удаление всех вхождений
        if (!isEmpty(start)) {
            std::cout << "Введите, что хотите удалить: ";
            std::cin >> elem;
            deleteAllOccurrences(&start, elem);
            printList(start);
        }
        else {
            std::cout << "List is empty.\n";
        }
        break;
    case '3': // Удаление дубликатов
        deleteDuplicates(&start);
        printList(start);
        break;
    case '4': // Показать количество, минимум и максимум
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