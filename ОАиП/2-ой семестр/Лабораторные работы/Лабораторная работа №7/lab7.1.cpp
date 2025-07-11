#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <stdio.h>
#include "lab7.h"
#include <time.h>
#include <Windows.h>
#include <vector>

int main()
{
    system("chcp 65001");
    system("cls");
    SetConsoleOutputCP(65001);
    char* locale = setlocale(LC_ALL, "");
    srand(time(NULL));
    

    char choice = '0', exercise = '0';
    int value, sum;
    while (exercise != '3') {
        std::cout << "1. Хешировать числа\n"
            << "2. Хешировать структуры \n"
            << "3. Выход\n"
            << "Введите выбор: ";
        exercise = _getch();
        system("cls");
        switch (exercise)
        {
        case '1':
        {
            const int n = 11;
            const int M = 15;

            std::vector<int> arr, table;
            arr.reserve(n);
            while (choice != 5) {
                std::cout << "1. Добавить элементы в таблицу\n"
                    << "2. Найти элемент по ключу \n"
                    << "3. Вывести изначальные значения\n"
                    << "4. Вывести значения(изначальную таблицу)\n"
                    << "5. Выход\n"
                    << "Введите выбор: ";
                while (choice < '1' || choice > '9')
                    choice = _getch();
                system("cls");
                switch (choice) {
                case '1':
                {
                    std::cout << "Сами введёте элементы или рандоимно?(p/r)\n";
                    char random = '0';
                    do {
                        random = _getch();
                    } while (random != 'r' && random != 'R' && random != 'p' && random != 'P');

                    switch (random)
                    {
                    case 'r':
                    case 'R':
                    {
                        for (int i = 0; i < n; ++i) {
                            int x;
                            x = rand() % 29000 + 44000;
                            arr.push_back(x);
                        }
                        break;
                    }
                    case 'p':
                    case 'P':
                    {
                        std::cout << "Введите " << n << " целых чисел в диапазоне [44000..73000]:\n";
                        for (int i = 0; i < n; ++i) {
                            int x;
                            while (true) {
                                x = inputInteger();
                                if (44000 <= x && x <= 73000) {
                                    break;
                                }
                                std::cout << "Число вне диапазона! Пожалуйста, введите значение от 44000 до 73000: ";
                            }
                            arr.push_back(x);
                        }
                    }
                    }
                    table = tableInstantinate(M, arr);
                    break;
                }
                case '2':
                {
                    std::cout << "\nВведите ключ для поиска (в том же диапазоне):\n";
                    int keyToFind;
                    while (true) {
                        keyToFind = inputInteger();
                        if (44000 <= keyToFind && keyToFind <= 73000) {
                            break;
                        }
                        std::cout << "Число вне диапазона! Пожалуйста, введите значение от 44000 до 73000: ";
                    }
                    int pos = searchKey(table, keyToFind);

                    if (pos != -1) {
                        std::cout << "Ключ " << keyToFind << " найден в ячейке " << pos << ".\n";
                    }
                    else {
                        std::cout << "Ключ " << keyToFind << " не найден в таблице.\n";
                    }
                }
                break;
                case '3':
                    printArrayBase(arr);
                    break;
                case '4':
                    printHashTable(table, M);
                    break;
                case '5':
                    break;
                default:
                    std::cout << "Неверный выбор\n";
                }
                system("pause");
                system("cls");
                choice = '0';
            }
            break;
        }
        case '2':
        {
            const int n = 8;
            const int M = 15;
            std::vector<Product> products(n);
            std::vector<Product*> hashTable(M, nullptr);
            while (choice != '4')
            {
                choice = '0';
                std::cout << "1. Добавить структуры в таблицу\n"
                    << "2. Вывести изначальные структуры \n"
                    << "3. Вывести хешированные структуры\n"
                    << "4. Выход\n"
                    << "Введите выбор: ";
                while (choice < '1' || choice > '4')
                    choice = _getch();
                system("cls");
                switch (choice) {
                case '1':
                {
                    inputStructs(n, M, products, hashTable);
                    break;
                }
                case '2':
                {
                    printBaseStruct(products);
                    break;
                }
                case '3':
                    printHashStruct(M, hashTable);
                    break;
                case '4':
                    std::cout << "Ну ладно\n";
                    break;
                default:
                    std::cout << "Неверный выбор\n";
                }
                system("pause");
                system("cls");
                
            }
            break;
        }
        case '3':
        {
            std::cout << "Закончили упражнение";
            break;
        }
        default:
            std::cout << "Неверный выбор\n";
            break;
        }
        system("pause");
        system("cls");
        choice = '0';
    }
    return 0;
}
