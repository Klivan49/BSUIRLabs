#include "lab2.h"
#include <stdio.h>
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
    int n;
    std::cout << "Что вы хотите сделать?"
        "\n1 -- Ввести массив"
        "\n2 -- Отсортировать массив методом пузырька"
        "\n3 -- Отсортировать массив методом выбора"
        "\n4 -- Отсортировать массив методом вставки"
        "\n5 -- Отсортировать массив методом Шелла"
        "\n6 -- Отсортировать массив методом Хоора"
        "\n7 -- Отсортировать массив методом Слияния"
        "\n8 -- Выйти\n";
    n = inputInteger();
    if (array.empty() && n != 1 && n != 8)
    {
        std::cout << "Вы не ввели массив\n";
        system("pause");
        system("cls");
        return 1;
    }
    system("cls");
    
    switch (n)
    {
    case 1:
    {
        inputArray();
        break;
    }
    case 2:
    {
        bubbleSort(array);
        break;
    }
    case 3:
    {
        selectionSort(array);
        break;
    }
    case 4:
    {
        insertionSort(array);
        break;
    }
    case 5:
    {
        shellSort(array);
        break;
    }
    case 6:
    {
        quickSortWrapper(array);
        break;
    }
    case 7:
    {
        mergeSortWrapper(array);
        break;
    }
    case 8:
    {
        return 0;
    }
    default:
    {
        std::cerr << "Вы явно ввели что-то не то...\n";
        std::cerr << "Press any key to continue...\n";
        system("pause");
        system("cls");
        mainMenu();
        break;
    }
    }

    system("pause");
    system("cls");
    return 1;
}
