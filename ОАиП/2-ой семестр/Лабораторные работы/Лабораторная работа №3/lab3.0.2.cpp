#include "lab3.0.h"
#include <iostream>
#include <cstdlib>
#include <limits>

extern int inputInteger()
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

void insert(List** start, int value) {
    List* newP = new List;
    if (newP != nullptr) {
        newP->number = value;
        newP->next = nullptr;
        List* previous = nullptr;
        List* current = *start;
        // Поиск позиции для вставки (сортировка по возрастанию)
        while (current != nullptr && value > current->number) {
            previous = current;
            current = current->next;
        }
        if (previous == nullptr) { // Вставка в начало
            newP->next = *start;
            *start = newP;
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

void deleteAllOccurrences(List** start, int value) {
    List* previous = nullptr;
    List* current = *start;
    while (current != nullptr) {
        if (current->number == value) {
            List* temp = current;
            if (previous == nullptr) { // Удаление первого элемента
                *start = current->next;
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

void deleteDuplicates(List** start) {
    List* current = *start;
    while (current != nullptr && current->next != nullptr) {
        if (current->number == current->next->number) {
            List* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}

int countList(List* start) {
    int count = 0;
    while (start != nullptr) {
        count++;
        start = start->next;
    }
    return count;
}

int findMin(List* strart) {
    if (strart == nullptr) {
        std::cout << "Список пуст.\n";
        return -1; // Значение по умолчанию для пустого списка
    }
    return strart->number; // Первый элемент — минимальный (список отсортирован)
}

int findMax(List* start) {
    if (start == nullptr) {
        std::cout << "Список пуст.\n";
        return -1; // Значение по умолчанию для пустого списка
    }
    while (start->next != nullptr) { // Последний элемент — максимальный
        start = start->next;
    }
    return start->number;
}

void printList(List* current) {
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

bool isEmpty(List* start) {
    return start == nullptr;
}

void instructions() {
    std::cout << "Выберите вариант:\n"
        << "1 -- Вставить элемент в список\n"
        << "2 -- Удалить конкретный элемент\n"
        << "3 -- Удалить дубликаты\n"
        << "4 -- Показать количество элементов, минимальный и максимальный элемент\n"
        << "5 -- Вывести список\n"
        << "6 -- Выйти\n";
}