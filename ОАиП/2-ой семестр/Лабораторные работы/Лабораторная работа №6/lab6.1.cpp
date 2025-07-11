#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <stdio.h>
#include "lab6.h"
#include <time.h>
#include <Windows.h>

int main() 
{
    system("chcp 65001");
    system("cls");
    SetConsoleOutputCP(65001);
    char* locale = setlocale(LC_ALL, "");
    srand(time(NULL));
    struct tree* root = NULL;
    char choice = '0';
    int value, sum;

    while (choice != 6) {
        std::cout << "1. Добавить элементы в дерево\n"
                  << "2. Рассчитать максимальную сумму пути \n"
                  << "3. Удалить элемент из дерева \n"
                  << "4. Вывести дерево\n"
                  << "5. Вывести элементы в порядке возрастания\n"
                  << "6. Выход\n"
                  << "7. Балансировщик дерева\n"
                  << "8. Найти второй минимальный элемент в дереве\n"
                  << "9. Добавить 1 к каждому листу и вычесть 1 из каждого узла\n"
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
            } while (random != 'r' && random != 'R'
                && random != 'к' && random != 'К'
                && random != 'p' && random != 'P'
                && random != 'з' && random != 'З');

            switch (random)
            {
            case 'r':
            case 'R':
            {
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
            case 'p':
            case 'P':
            {
                std::cout << "Сколько элементов хотите добавить?\n";
                int amount = inputInteger();
                std::cout << "Вводите элементы\n";
                for (int i = 0; i < amount; i++)
                {
                    value = inputInteger();
                    root = treeNewElement(root, value);
                }
                system("cls");
                break;
            }
            }
            break;
        }
         case '2':
            sum = findMaxSumPath(root);
            std::cout << "Максимальная сумма пути = " << sum << std::endl;
            break;
        case '3':
            std::cout << "Какой элемент вы хотите удалить из дерева?: ";
            value = inputInteger();
            root = deleteElement(root, value);
            std::cout << "Элемент удалён " << value;
            break;
        case '4':
            std::cout << "Элементы дерева: " << std::endl;
            printTree(root);
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
            printTree(balanced);
            break;
        }
        case '8':
        {
            int second = findSecondMinimum(root);
            std::cout << "Второй минимальный элемент в дереве: " << second << std::endl;
            break;
        }
        case '9':
        {
            extraLeaves(root);
            printTree(root);
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
