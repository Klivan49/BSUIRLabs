#include "lab3.h"
#include <iostream>
#include <cstdlib>

void insert(ListNodePtr* s, int value) {
    ListNodePtr newP = new ListNode;
    if (newP != nullptr) {
        newP->number = value;
        newP->next = nullptr;
        ListNodePtr previous = nullptr;
        ListNodePtr current = *s;
        // Поиск позиции для вставки (сортировка по возрастанию)
        while (current != nullptr && value > current->number) {
            previous = current;
            current = current->next;
        }
        if (previous == nullptr) { // Вставка в начало
            newP->next = *s;
            *s = newP;
        }
        else { // Вставка в середину или конец
            previous->next = newP;
            newP->next = current;
        }
    }
    else {
        std::cout << value << " не хватило памяти.\n";
    }
}

void deleteAllOccurrences(ListNodePtr* s, int value) {
    ListNodePtr previous = nullptr;
    ListNodePtr current = *s;
    while (current != nullptr) {
        if (current->number == value) {
            ListNodePtr temp = current;
            if (previous == nullptr) { // Удаление первого элемента
                *s = current->next;
            }
            else { // Удаление из середины или конца
                previous->next = current->next;
            }
            current = current->next;
            delete temp;
        }
        else {
            previous = current;
            current = current->next;
        }
    }
}

void deleteDuplicates(ListNodePtr* s) {
    ListNodePtr current = *s;
    while (current != nullptr && current->next != nullptr) {
        if (current->number == current->next->number) {
            ListNodePtr temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}

int countList(ListNodePtr s) {
    int count = 0;
    while (s != nullptr) {
        count++;
        s = s->next;
    }
    return count;
}

int findMin(ListNodePtr s) {
    if (s == nullptr) {
        std::cout << "Список пуст.\n";
        return -1; // Значение по умолчанию для пустого списка
    }
    return s->number; // Первый элемент — минимальный (список отсортирован)
}

int findMax(ListNodePtr s) {
    if (s == nullptr) {
        std::cout << "Список пуст.\n";
        return -1; // Значение по умолчанию для пустого списка
    }
    while (s->next != nullptr) { // Последний элемент — максимальный
        s = s->next;
    }
    return s->number;
}

void printList(ListNodePtr current) {
    if (current == nullptr) {
        std::cout << "Список пуст.\n";
    }
    else {
        std::cout << "Список:\n";
        while (current != nullptr) {
            std::cout << current->number << " --> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }
}

bool isEmpty(ListNodePtr s) {
    return s == nullptr;
}

void instructions() {
    std::cout << "Выберите вариант:\n"
        << "1 -- Вставить элемент в список.\n"
        << "2 -- Удалить конкретный элемент.\n"
        << "3 -- Удалить дубликаты.\n"
        << "4 -- Показать количество элементов, минимальный и максимальный элемент.\n"
        << "5 -- Выйти.\n";
}