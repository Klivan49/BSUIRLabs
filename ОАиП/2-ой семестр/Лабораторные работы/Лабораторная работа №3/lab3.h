#pragma once
#ifndef LIST_H
#define LIST_H

struct ListNode {
    int number;         // Значение узла (целое число)
    ListNode* next;     // Указатель на следующий узел
};

typedef ListNode* ListNodePtr;

// Прототипы функций
int mainMenu();                                     // Главное меню
void insert(ListNodePtr* s, int value);             // Вставка элемента
void deleteAllOccurrences(ListNodePtr* s, int value); // Удаление всех вхождений
void deleteDuplicates(ListNodePtr* s);              // Удаление дубликатов
int countList(ListNodePtr s);                       // Подсчет элементов
int findMin(ListNodePtr s);                         // Поиск минимального значения
int findMax(ListNodePtr s);                         // Поиск максимального значения
void printList(ListNodePtr current);                // Печать списка
bool isEmpty(ListNodePtr s);                        // Проверка на пустоту
void instructions();                                // Вывод подменю
#endif