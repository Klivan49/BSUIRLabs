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
            std::cout << "\n�������� ����. ����������, ������� ����� �����: ";
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
        // ����� ������� ��� ������� (���������� �� �����������)
        while (current != nullptr && value > current->number) {
            previous = current;
            current = current->next;
        }
        if (previous == nullptr) { // ������� � ������
            newP->next = *start;
            *start = newP;
        }
        else { // ������� � �������� ��� �����
            previous->next = newP;
            newP->next = current;
        }
    }
    else {
        std::cout << value << " �� ������� ������.\n";
    }
}

void deleteAllOccurrences(List** start, int value) {
    List* previous = nullptr;
    List* current = *start;
    while (current != nullptr) {
        if (current->number == value) {
            List* temp = current;
            if (previous == nullptr) { // �������� ������� ��������
                *start = current->next;
            }
            else { // �������� �� �������� ��� �����
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
        std::cout << "������ ����.\n";
        return -1; // �������� �� ��������� ��� ������� ������
    }
    return strart->number; // ������ ������� � ����������� (������ ������������)
}

int findMax(List* start) {
    if (start == nullptr) {
        std::cout << "������ ����.\n";
        return -1; // �������� �� ��������� ��� ������� ������
    }
    while (start->next != nullptr) { // ��������� ������� � ������������
        start = start->next;
    }
    return start->number;
}

void printList(List* current) {
    if (current == nullptr) {
        std::cout << "������ ����.\n";
    }
    else {
        std::cout << "������:\n";
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
    std::cout << "�������� �������:\n"
        << "1 -- �������� ������� � ������\n"
        << "2 -- ������� ���������� �������\n"
        << "3 -- ������� ���������\n"
        << "4 -- �������� ���������� ���������, ����������� � ������������ �������\n"
        << "5 -- ������� ������\n"
        << "6 -- �����\n";
}