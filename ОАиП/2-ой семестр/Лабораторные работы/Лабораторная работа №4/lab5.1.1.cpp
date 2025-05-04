#include <stdio.h>
#include "lab5.1.h"
#include <locale.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdlib>

int main()
{
    setlocale(LC_ALL, "");
    system("chcp 1251");
    system("cls");
    while (mainMenu());
    return 0;
}

extern int mainMenu()
{
    char n = '0';
    int numberOfJobs = -1;
    std::cout << "Что вы хотите сделать?"
        "\n1 -- Добавить работу"
        "\n2 -- Отсортировать работы"
        "\n3 -- Произвести поиск работы по заданному параметру"
        "\n4 -- Изменить данные работы"
        "\n5 -- Удалить работу из списка"
        "\n6 -- Вывести на экран список работ"
        "\n7 -- Удалить файл(если была ошибка при его создании)"
        "\n8 -- Выйти\n";
    while (n < '1' || n > '8')
        n = _getch();
    system("cls");

    if (n > '1' && n < '7')
    {
        std::ifstream inFile("numberOfJobs.txt");
        if (inFile) {
            inFile >> numberOfJobs;
            inFile.close();
        }
        if (numberOfJobs <= 0) {
            std::cout << "В базе нет информации ни об одной работе(\n"
                << "Нажмите любую клавишу для продолжения...";
            system("pause");
            system("cls");
            return 1;
        }
    }

    switch (n)
    {
    case '1':
        inputStruct();
        break;
    case '2':
        sorting();
        break;
    case '3':
        finder();
        break;
    case '4':
        remaking();
        break;
    case '5':
        deleting();
        break;
    case '6':
        outputStruct(0, 0);
        break;
    case '7':
        deleteFile();
        break;
    case '8':
        return 0;
    default:
        std::cerr << "Неправильный выбор...\n"
            << "Нажмите любую клавишу для продолжения...\n";
        system("pause");
        system("cls");
        return 1;
    }

    system("pause");
    system("cls");
    return 1;
}
