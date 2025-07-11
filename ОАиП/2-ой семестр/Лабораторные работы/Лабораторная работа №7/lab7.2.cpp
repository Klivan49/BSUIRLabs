#include <iostream>
#include <vector>
#include <limits>
#include "lab7.h"
#include <string>
#include <iomanip>
#include <time.h>
#include <conio.h>

// Функции безопасного ввода
int inputInteger()
{
    int value;
    while (true) {
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nНеверный ввод. Пожалуйста, введите целое число: ";
        }
    }
}

float inputDigit() {
    float value;
    while (true) {
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный ввод. Пожалуйста, введите число: ";
        }
    }
}

const int EMPTY = std::numeric_limits<int>::min();  // маркер пустой ячейки

// Хеш-функция: остаток от деления (учитываем отрицательные)
int hashFunc(int key, int M) {
    return (key % M + M) % M;
}

// Вставка с линейным пробированием
void insertKey(std::vector<int>& table, int key) {
    int M = (int)(table.size());
    int idx = hashFunc(key, M);
    while (table[idx] != EMPTY) {
        idx = (idx + 1) % M;
    }
    table[idx] = key;
}

// Поиск ключа; возвращает индекс или -1, если не найден
int searchKey(const std::vector<int>& table, int key) {
    int M = (int)(table.size());
    int idx = hashFunc(key, M);
    int start = idx;
    while (table[idx] != EMPTY) {
        if (table[idx] == key)
            return idx;
        idx = (idx + 1) % M;
        if (idx == start)
            break;  // обошли всю таблицу
    }
    return -1;
}

std::vector<int> tableInstantinate(int M, std::vector<int> arr)  // Инициализируем хеш-таблицу
{
    std::vector<int> table(M, EMPTY);
    for (int key : arr) {
        insertKey(table, key);
    }
    return table;
}

void printArrayBase(std::vector<int> arr)// Вывод исходного массива
{
    std::cout << "Исходный массив:\n";
    for (int x : arr) {
        std::cout << x << ' ';
    }
    std::cout << "\n";
}

void printHashTable(std::vector<int> table, int M)
{
    // Вывод хеш-таблицы
    std::cout << "\nХеш-таблица (размер " << M << "):\n";
    for (int i = 0; i < M; ++i) {
        if (table[i] == EMPTY) {
            std::cout << i << ": [EMPTY]\n";
        }
        else {
            std::cout << i << ": " << table[i] << '\n';
        }
    }
}

// Вставка с квадратичным пробированием
bool insertProduct(std::vector<Product*>& table, Product* item, int M) {
    int key = item->release_day;
    int idx = hashFunc(key, M);
    int i = 0;
    while (i < M) {
        int probe = (idx + i * i) % M;
        if (table[probe] == nullptr) {
            table[probe] = item;
            return true;
        }
        i++;
    }
    return false; // Таблица заполнена
}

Product* searchProduct(const std::vector<Product*>& table, int key, int M) {
    int idx = hashFunc(key, M);
    int i = 0;
    while (i < M) {
        int probe = (idx + i * i) % M;
        if (table[probe] == nullptr) {
            return nullptr;
        }
        if (table[probe]->release_day == key) {
            return table[probe];
        }
        i++;
    }
    return nullptr;
}

void inputStructs(int n, int M, std::vector<Product>& products, std::vector<Product*>& hashTable)
{
    const std::vector<std::string> prefixes = {
        "Iphone", "Samsung", "Xiaomi", "Nokia", "Blackberry", "Huawei", "Honor", "Lenovo"
    };
    const std::vector<std::string> suffixes = {
        "One", "Note", "Pro", "Plus", "Max", "Ultra", "Neo", "Elite"
    };
    srand(time(NULL));
    char choice = '0';
    int rand1, rand2;
    std::string name;
    std::cout << "Сами введёте " << n << " структур?(Y/N)";
    while(choice != 'Y' && choice != 'N' && choice != 'y' && choice != 'n')
        choice = _getch();
    switch (choice)
    {
    case 'N':
    case 'n':
    {
        for (int i = 0; i < n; ++i) 
        {
            rand1 = rand() % 8;
            rand2 = rand() % 8;
            name = prefixes[rand1] + "_" + suffixes[rand2];
            products[i].name = name;
            products[i].price = rand() % 1000 + 10;
            products[i].release_day = rand() % 100 + 1;
            insertProduct(hashTable, &products[i], M);
        }
        break;
    }
    case 'Y':
    case 'y':
    {
        std::cout << "Введите данные для " << n << " товаров:\n";
        for (int i = 0; i < n; ++i) {
            std::cout << "\nТовар " << i + 1 << ":\n";
            std::cout << "Наименование: ";
            std::getline(std::cin, products[i].name);
            std::cout << "Цена: ";
            products[i].price = inputDigit();
            std::cout << "День выпуска: ";
            products[i].release_day = inputInteger();
            insertProduct(hashTable, &products[i], M);
        }
        break;
    }
    }
}


void printBaseStruct(const std::vector<Product>& products)
{
    // Заголовок таблицы
    std::cout << std::left
        << std::setw(1) << "№ "
        << std::setw(48) << "Наименование"
        << std::setw(14) << "Цена"
        << std::setw(12) << "День выпуска"
        << '\n';

    // Разделительная линия
    std::cout << std::setfill('-')
        << std::setw(2) << ""
        << std::setw(50) << ""
        << std::setw(14) << ""
        << std::setw(12) << ""
        << std::setfill(' ') << '\n';

    // Данные
    for (size_t i = 0; i < products.size(); ++i) {
        const auto& p = products[i];
        std::cout << std::left
            << std::setw(2) << (i + 1)
            << std::setw(36) << p.name.substr(0, 35)  // обрезаем, если слишком длинное
            << std::setw(10) << std::fixed << std::setprecision(2) << p.price
            << std::setw(12) << p.release_day
            << '\n';
    }

    std::cout << std::endl;
}

void printHashStruct(int M, const std::vector<Product*>& hashTable)
{
    std::cout << std::left
        << std::setw(4) << "Яч. "
        << std::setw(51) << "Наименование"
        << std::setw(16) << "День выпуска"
        << '\n';

    std::cout << std::setfill('-')
        << std::setw(4) << ""
        << std::setw(50) << ""
        << std::setw(12) << ""
        << std::setfill(' ') << '\n';

    for (int i = 0; i < M; ++i) {
        std::cout << std::left
            << std::setw(4) << i;
        if (hashTable[i]) {
            std::cout << std::setw(39) << hashTable[i]->name.substr(0, 38)
                << std::setw(12) << hashTable[i]->release_day;
        }
        else {
            std::cout << std::setw(44) << "[пусто]"
                << std::setw(12) << "-";
        }
        std::cout << '\n';
    }

    std::cout << std::endl;
}
