#include "lab3.0.h"
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <cstring>
#include <sstream>
#include <string>

List* start = nullptr; // Начало списка

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
    instructions(); // Вывод меню
    while(choice < '1' || choice > '6')
        choice = _getch();
    system("cls");
    std::string input;
    switch (choice)
    {
    case '1':
    {   // Вставка элемента
        std::cout << "Введите элементы массива через пробел (Enter -- конец массива)" << std::endl;
        std::getline(std::cin, input);
        std::istringstream iss(input);
        int value;
        while (iss >> value) {
            insert(&start, value);
        }
        if (iss.fail() && !iss.eof()) {
            std::cerr << "Ошибка ввода: некорректное значение в массиве" << std::endl;
        }
        printList(start);
        break;
    }
    case '2': // Удаление всех вхождений
        if (!isEmpty(start)) {
            std::cout << "Введите, упоминания о каком числе вы хотиите изничтожить: ";
            std::cin >> elem;
            deleteAllOccurrences(&start, elem);
            printList(start);
        }
        else {
            std::cout << "Список пуст.\n";
        }
        break;
    case '3': // Удаление дубликатов
        deleteDuplicates(&start);
        printList(start);
        break;
    case '4': // Показать количество, минимум и максимум
        std::cout << "Количество элементов: " << countList(start) << "\n";
        if (!isEmpty(start)) {
            std::cout << "Min: " << findMin(start) << "\n";
            std::cout << "Max: " << findMax(start) << "\n";
        }
        break;
    case '5':
        printList(start);
        break;
    case '6':
        std::cout << "Закончили упражение\n";
        return 0;
    default:
        std::cout << "Неверный выбор\n";
        break;
    }
}