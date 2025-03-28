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

void insert(ListPtr* start, int value) {
    ListPtr newP = new List;
    if (newP != nullptr) {
        newP->number = value;
        newP->next = nullptr;
        ListPtr previous = nullptr;
        ListPtr current = *start;
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

void deleteAllOccurrences(ListPtr* s, int value) {
    ListPtr previous = nullptr;
    ListPtr current = *s;
    while (current != nullptr) {
        if (current->number == value) {
            ListPtr temp = current;
            if (previous == nullptr) { // �������� ������� ��������
                *s = current->next;
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

void deleteDuplicates(ListPtr* s) {
    ListPtr current = *s;
    while (current != nullptr && current->next != nullptr) {
        if (current->number == current->next->number) {
            ListPtr temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}

int countList(ListPtr s) {
    int count = 0;
    while (s != nullptr) {
        count++;
        s = s->next;
    }
    return count;
}

int findMin(ListPtr s) {
    if (s == nullptr) {
        std::cout << "������ ����.\n";
        return -1; // �������� �� ��������� ��� ������� ������
    }
    return s->number; // ������ ������� � ����������� (������ ������������)
}

int findMax(ListPtr s) {
    if (s == nullptr) {
        std::cout << "������ ����.\n";
        return -1; // �������� �� ��������� ��� ������� ������
    }
    while (s->next != nullptr) { // ��������� ������� � ������������
        s = s->next;
    }
    return s->number;
}

void printList(ListPtr current) {
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

bool isEmpty(ListPtr s) {
    return s == nullptr;
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