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
        std::cout << "1. Вставить элемент в дерево\n"
                  << "2. Определить максимальную сумму пути \n"
                  << "3. Удалить элемент из дерева \n"
                  << "4. Вывести все элементы дерева\n"
                  << "5. Вывести элементы в порядке возрастания\n"
                  << "6. Выйти из программы\n"
                  << "7. Балансировщик дерева\n"
                  << "Введите выбор: ";
        while (choice < '1' || choice > '7')
            choice = _getch();
        system("cls");
        switch (choice) {
        case '1':
        {
            std::cout << "Сами введёте элементы или хотите рандомно?(p/r)";
            char random = '0';
            do {
                random = _getch();
            } while (random != 'r' && random != 'R'
                && random != 'к' && random != 'К'
                && random != 'r' && random != 'R'
                && random != 'к' && random != 'К');
            switch (random)
            {
            case 'r' || 'R' || 'к' || 'К':
                std::cout << "Сколько элементов хотите добавить?\n";
                int amount = inputInteger();
                for (int i = 0; i < amount; i++)
                {
                    value = rand() % 100;
                    root = treeNewElement(root, value);
                }
                system("cls");
                break;
            }
            case 'p' || 'P' || 'з' || 'З':
            {
                    std::cout << "Введите значение для вставки: ";
                    value = inputInteger();
                    root = treeNewElement(root, value);
                    system("cls");
                    break;
            }
            return 0;
        }
        case '2':
            sum = findMaxSumPath(root);
            std::cout << "Максимальная сумма пути = " << sum;
            break;
        case '3':
            std::cout << "Введите значение для удаления: ";
            value = inputInteger();
            root = deleteElement(root, value);
            std::cout << "удален элемент %d\n", value;
            break;
        case '4':
            std::cout << "Элементы дерева: " << std::endl;
            printTree(root, 1);
            std::cout << std::endl;
            break;
        case '5':
            std::cout << "Элементы в порядке возрастания: " << std::endl;
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
            std::cout << "Неверный выбор\n";
        }
        system("pause");
        system("cls");
        choice = '0';
    }
    return 0;
}
