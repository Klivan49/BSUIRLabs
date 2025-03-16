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
        // ����� ������� ��� ������� (���������� �� �����������)
        while (current != nullptr && value > current->number) {
            previous = current;
            current = current->next;
        }
        if (previous == nullptr) { // ������� � ������
            newP->next = *s;
            *s = newP;
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

void deleteAllOccurrences(ListNodePtr* s, int value) {
    ListNodePtr previous = nullptr;
    ListNodePtr current = *s;
    while (current != nullptr) {
        if (current->number == value) {
            ListNodePtr temp = current;
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
        std::cout << "������ ����.\n";
        return -1; // �������� �� ��������� ��� ������� ������
    }
    return s->number; // ������ ������� � ����������� (������ ������������)
}

int findMax(ListNodePtr s) {
    if (s == nullptr) {
        std::cout << "������ ����.\n";
        return -1; // �������� �� ��������� ��� ������� ������
    }
    while (s->next != nullptr) { // ��������� ������� � ������������
        s = s->next;
    }
    return s->number;
}

void printList(ListNodePtr current) {
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

bool isEmpty(ListNodePtr s) {
    return s == nullptr;
}

void instructions() {
    std::cout << "�������� �������:\n"
        << "1 -- �������� ������� � ������.\n"
        << "2 -- ������� ���������� �������.\n"
        << "3 -- ������� ���������.\n"
        << "4 -- �������� ���������� ���������, ����������� � ������������ �������.\n"
        << "5 -- �����.\n";
}