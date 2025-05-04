#pragma once

struct List {           // Список
    int number;         // Значение элемента
    List* next;         // Указатель на следующий узел
};


// Прототипы функций
int inputInteger();                               //Ввод/проверка числа
int mainMenu();                                   // Главное меню
void insert(List** start, int value);               // Вставка элемента
void deleteAllOccurrences(List** start, int value); // Удаление всех вхождений
void deleteDuplicates(List** start);                // Удаление дубликатов
int countList(List* s);                         // Подсчет элементов
int findMin(List* s);                           // Поиск минимального значения
int findMax(List* s);                           // Поиск максимального значения
void printList(List* current);                  // Печать списка
bool isEmpty(List* s);                          // Проверка на пустоту
void instructions();                              // Вывод подменю