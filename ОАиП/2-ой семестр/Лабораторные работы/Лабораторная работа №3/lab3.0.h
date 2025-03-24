#pragma once

struct List {           // Список
    int number;         // Значение элемента
    List* next;         // Указатель на следующий узел
};

typedef List* ListPtr;

// Прототипы функций
int inputInteger();                               //Ввод/проверка числа
int mainMenu();                                   // Главное меню
void insert(ListPtr* s, int value);               // Вставка элемента
void deleteAllOccurrences(ListPtr* s, int value); // Удаление всех вхождений
void deleteDuplicates(ListPtr* s);                // Удаление дубликатов
int countList(ListPtr s);                         // Подсчет элементов
int findMin(ListPtr s);                           // Поиск минимального значения
int findMax(ListPtr s);                           // Поиск максимального значения
void printList(ListPtr current);                  // Печать списка
bool isEmpty(ListPtr s);                          // Проверка на пустоту
void instructions();                              // Вывод подменю